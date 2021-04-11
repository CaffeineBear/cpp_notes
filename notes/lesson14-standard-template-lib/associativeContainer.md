# Associative Containers

## std::set/std::multi_set
- Implemented as a binary tree
- Fast search
- Value acts as a key
  - does not allow duplicates for `std::set` but `std::multi_set` does.
- Elements are sorted in order
- No random access
- Elements cannot be modified directly.
- To erase element, you need to either provide iterator or provide a value.
- `find()` function will return non end() iterator position if it found
  element.
- you can choose comparator from `<functional>` library
  - e.g. `#include <functional>`
- To search in `multi_set`, you need to use `equal_range()` which returns
  a pair object that indicates first occurence iterator position and next key position.


## std::map / std::multi_map
- implemented as a binary tree.
- it will rather sort based on the key.
- stored as a key and value pair.
- fast search
- no random access
- keys cannot be modified directly.
  - but values can.
- `multimap` supports

### Example

```cpp
// Initialization
std::map<int, std::string> m {
  {1, "Superman" },
  {2, "Superman2" },
  {3, "Superman3" }
};


// insertion.
m.insert(std::pair<int, std::string>(8, "Aquaman"));
m.insert(std::makepair(9, "Aquaman2"));
m.insert(std::makepair(9, "Aquaman3")); // only allowed in multi-set.
// only insert will add new entries for multi_set.
// for assignment it will change the value.
m[0] = "Flash";

// Erase
m.earse(0);

// iteration
for(const auto &x : m){
  std::cout << x.first << ":" << x.second  << endl;
}

// Search
auto itr = m.find(1);
if(itr != m.end() ){
  std::cout << "found the key" << std::endl;
}
auto someValue = m[1];

// Careful with [] operator because it will create a new element if the
// key doesn't exist.
auto someValue2 = m[10]; // this will create empty value at key 10.
```


# std::hash
- to store classes in the containers, you should overload: `==, <, >` and
  `!=`.
- to create custom hash function, you need to overload `operator()`.
  - inside you might call `std::hash`

