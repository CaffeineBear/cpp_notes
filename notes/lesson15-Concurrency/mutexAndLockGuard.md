# Mutex and Lockguard

## Mutex

- While one thread is chaning data, it is possible that the other thread changes the same data simultaneously.
- This is called **race condition**
  - two threads race each other to access the data.
- `mutex` will allow to block if other thread is accessing it.

### Example
```cpp
std::list<int> gData;
const int SIZE = 1000000000;
std::mutex g_Mutex;
void Download() {
  for (int i = 0; i < SIZE; i++) {
    g_Mutex.lock();
    g_Data.push_back(i);
    g_Mutex.unlock();
  }
}

void Download2() {
  for (int i = 0; i < SIZE; i++) {
    g_Mutex.lock();
    g_Data.push_back(i);
    g_Mutex.unlock();
  }
}

int main() {
  std::thread thDownloader(Download);
  std::thread thDownloader2(Download2);
  thDownloader.join();
  thDownloader2.join();
  return 0;
}

```

## Deadlock
- It is a situation where one of mutex prematurely locked the thread and returned without unlocking.
- To resolve this, we can use **Resource Aquisition is Initializaion** idiom.
  - Meaning local object lock automatically and unlock with destructor.
  - In C++, you can use `lock_guard`.

## lock_guard
- if you call this you don't need to lock and unlock by yourself.
- **Note**: in general locking should be avoided because when you lock
  resource, the other thread is in sleep state and we are not utilizing
  CPU enough.
  - For example, Instead of thread sharing the same resource, we can make
    the list separately and combine those later.

### Example
```cpp
std::lock_guard<std::mutex> mtx(g_Mutex);
```