# Smart Pointers

### Syntax
```cpp
std::unique_ptr<type> pointerName{ argument };
```


### Example
```cpp
// In main
void Display(Integer *p){
  if( !p ){
    return;
  }
  std::cout << p->GetValue() << std::endl;
}

Integer * GetPointer(int value){
  Integer *p = new Integer{value};
  return p;
}

void Operate(int value) {
  std::unique_ptr<Integer> p {GetPOinter(value)};
  if (p == nullptr){
    // note that you use reset rather than you declare it again.
    p.reset(new Integer{value} );
  }
  p->SetValue(100);

  // get() function will return the pointer for that class itself.
  Display(p.get());

  // To delete smart pointer you can just simply assign nullptr
  // Because the compiler will choose the assign operator overloading
  // and corresponding constructor accordingly.
  p = nullptr;

  // Note that you can still use reset()
  p.reset(new Integer{});
  *p = __LINE__;
  Display(p);
}

int main() {
  Operate(5);
}