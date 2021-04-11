# Smart Pointer

- In the large program, you can forget where the pointer points to.
- So, this can lead to memory leak if someone has forgotton to release the memory.
- There are a lot of tools to detect the memory leak.
- Or you can use the idiom called **Resource Acquision is Initialization (RAII)**.
- With this idiom, the lifetime of a resource is bound to object.
  - when the local object is destroyed, its restructor will automatically release the resource.
- In C++, we can achieve this by having Smart Pointer where it has the poitner to the class while `delete` is called during destruction.
- We also add pointer(->) operator overloading to access the contents of the object.
- We also add asteriks(*) operator overloading to dereference
- Hence, this acts just like the normal pointer.

```cpp
class IntPtr {
  Integer *m_p;
public:
  IntPtr(Integer *p): m_p(p) {

  }
  ~IntPtr() {
    delete m_p;
  }

  // To access the integer object
  IntPtr * operator-> (){
    return m_p;
  }

  // For dereferencing.
  IntPtr & operator* () {
    return *m_p;
  }
}

void CreateInteger() {
  IntPtr p = new Integer;
  p->SetValue(3); // Notice that you have the access to the Integer object.
  // Notice there are no delete call for 'new' statement.
}
```

## Using \<memory\> library for smart pointer.
- `unique_ptr`
  - used when you don't want to share the underlying resource.
  - This means we cannot create a copy of the unique pointer.
  - They're doing this by deleting the copy constructor.
  - However they still have the `move` semantics.
- `share_ptr`
  - used when you want to share the resource.
  - You can create a copy from this pointer.
  - Everytime it creates the copy it will increment the sharing counter.
  - Underlying resouse is released only when this counter becomes zero.


### Example
```cpp
void Process(std::unique_ptr<Integer> ptr) {
  std::cout << ptr->GetValue() << std::endl;
}

int main(){
  // Since it is an unique pointer, if you dont have 'move' function, it will not compile as the Integer object will be copied.
  // However once you have done this, you can no longer use p since you 'moved' it.
  std::unique_ptr<Integer> p (new Integer);
  Process(std::move(p));

  // Insread you should use following:
  std::share_ptr<Integer> p2 (new Integer);
  Process(p2);

}


```

## Further Note
- It is always recommended to use smartpointers rather than raw pointers.
- So that you can prevent the memory leak in the program.