# Dynamic Array -> std::vector
- user implemented dynamic array requires manual operations for the memory
  management.
- `std::vector` will save your time.
- it is a class template -> you can store any types


## Example
```cpp
std::vector<int> data{1,2,3};
for(int i = 0; i < 5; ++i){
  data.push_back(i*10);
}

// Access
for(int i = 0; i < data.size(); ++i){
  std::cout << data[i] << endl;
}
for(int x: data){
  std::cout << x << endl;
}

// You can also use -> begin(), end(),
auto it = data.begin();
while(it != data.end()){
  std::cout << *it << endl;
  ++it; // you can also do it = it + 5;
}

//Delete
// data.erase(it);

// Insert
it = data.begin() + 5;
data.insert(it, 500);


```