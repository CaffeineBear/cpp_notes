# Task Based Concurrency

- You can add high level concurrency rather than calling thread directly.
- This is called **task**.
- For this you need `async` from the library `future`
  - This returns a object type called future.
  - It accepts any callable.
- You should return a future value from `async` otherwise it will be
  blocked as it creates a temporary object. This makes the execution to be
  synchronous which is not we want.
- `asyc` return a value immediately.



## Syntax
```cpp
future<return_type> async (Callable,  args);
```

<center> Or </center>

```cpp
future<return_type> async (lauch_policy, Callable, args);
```
- If it cannot create a thread, it will throw an exception.



## Launch Policy
1. `std::launch::deferred` - the task is executed synchronously
2. `std::launch::async`    - the task is executed asynchronously

- if you haven't put a launch policy, it might not always create a thread.
  - Depending on the compiler.
- `std::future<void> result = std::async(std::launch::async, Downloader);`


## Task Arguments & return value
- By default arguments are passed by value.
- To pass by reference, you should use `std::ref` or `std::cref`.
- With high level concurrency, it is easy to return a value from the task
  unlike the raw thread call.
  - this return value is available through `std::future` object.

### Example
```cpp
int main(){
  // future type should be the type of parameter that the task returns.
  std::future<void> result = std::async(Downloader);


  // Some other operations...

  // This will make the main() function to wait thread. It is just like
  // join.
  result.get();
}
```

## std::future
- used for communication between threads.
- has a shared state that can be accesssed in a different thread.
- it is internally created through `std::promise` object.
  - `std::promise` -> input  channel
  - `std::future`  -> output channel
- Since the thread reading shared state have to wait until future is ready,
  Promise/future pair allows us to safely share data between threads.
- Once the result from the future is retrieved via `get()`, the future will
  become invalid to access.
  - To check whether it is valid to `get()` you can use `valid()`

## Wait function in std::future
- `wait()` : similar to `get()` but it doesn't return anything.
  - they both current thread until what future has finished its task.
- `wait_for(duration)` : periodically checks and returns a future status.
  - `future_status::deferred`:
    - task is deferred. you can't wait on it because the task will execute
      synchronously
  - `future_status::ready`:
    - A shared state is ready.
  - `future_status::timeout`:
    - task is not finished with specified duration.
  - You can put this with loop.
- `wait_until()` will wait until specific time.

## Promise.
- a way to store a value or exception and aka *shared state*.
- This can later be accessed by a future object.
- operations in a promise are synchronized therefore thread-safe.
- Note: a promise object can only be used once.
- Example:
  ```cpp
  std::promise<int> data;
  std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));

  // some operation ...

  data.set_value(10);
  ```
- thread execution will not be run until the data on the promise is set if
  you call future from the promise.

## Exception in Promise.
- You can cross communicate between threads
-

### Example
```cpp
int Operation(std::promise<int> & data) {
	using namespace std::chrono_literals;
	auto f = data.get_future() ;
	try {
		std::cout << "[Task] Waiting for count\n";
		auto count = f.get();
		std::cout << "[Task] Count acquired.\n";
		int sum{};
		for (int i = 0; i < count; ++i) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(300ms);//std::chrono::seconds(1)
		}
		return sum;
	}catch(std::exception &ex) {
		std::cout << "[Task] Exception:" << ex.what() << std::endl;
	}
}
int main() {
	using namespace std::chrono_literals ;
	std::promise<int> data ;
	std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));
	std::this_thread::sleep_for(1s) ;
	std::cout << "[main] Setting the data in promise\n";
	try {
    // deliverately throwing exception.
		throw std::runtime_error{"Data not available"} ;
		data.set_value(10);
		if (result.valid()) {
			auto sum = result.get();
			std::cout << sum << std::endl;
		}
	}catch(std::exception &ex) {
    // Set exception on other thread
		data.set_exception(std::make_exception_ptr(ex)) ;
	}

}
```