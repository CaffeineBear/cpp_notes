## Thrad Functions

1. `get_id()`

2. `native_handle()`
    - returns a type that represents the thread on the corresponding
      platform.
      - Windows: type `handle`
      - Linux: type `pthred_t`
    - they're used for native API platform.

3. `SetThreadDescription()`
    - Since thread id is hard to recognize for human, it will add
      description
    - However, note that this can only used for Windows10 by `<Windows.h>`
      library.
      - Note: only working for some recent version for Windows 10.
    - In Linux: `pthread_setname_np`
    ```cpp
    HANDLE handle = t1.native_handle();
    SetThreadDescription(handle, L"MyThread"); // has to be a wide string.
    ```
4. `std::thread::hardware_concurrency`
    - reutrns the number of cores used by CPU.
    - `int cores = std::thread::hardware_concurrency();`
    - This is important to know maximal perfomring number of threads.
    - Generally, it should equal to the number of cores of the CPU.

5. `this_thread`
    - To obtain the thread id of the scope.
    - `std::this_thread::get_id()`

6. `this_thread::sleep_for`
    - Allows you to add delay and it requires time duration argument.
      - `std::this_thread::sleep_for(std::chrono::seconds(1));`
    - May be useful when you want to animate on the screen.