# Thread Creation, std::thread

- Accepts a callable as constructor argument
- The callable is executed in a separate thread
- Note: The constructor does not wait for the thread to start; it returns
  immediately.
- use `<thread>`

## Example
```cpp
int main(){
  std::thread thDownloader(Downlaod);

  // If we don't want to wait for thread to finish while running thread,
  // uncomment below if join() function is no longer needed.
  // But for main() function you will need join().
  thDownloader.detach();

  // Some other opeations


  if (thDownloader.joinable()){
    // waiting for thread to finish. Otherwise, the main
    // thread will terminate and exit the program before
    // the thread finishes.
    // Call this before the thread object is destroyed.
    thDownloader.join();
  }


  return 0;s
}
```


## How to pass argument to std::thread?
- You can just add argument.
- However, if you need to make sure that you pass as a reference, you need:
  - `std::ref()` or `std::cref()` for constant reference.

## How do we get returned value from the thread?
- There is no way to get it directly, you need make the data global.