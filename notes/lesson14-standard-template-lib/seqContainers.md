# std::array

- wrapper over C-style static array
- supports iterators
- know about its size.
- provides random access
- canbe used with C functions
- cannot grow.
- use `<array>` library
- `data()` function returns a pointer to the internal array.
  - this pointer can be passed to C functions.

## Iterators
- pointer like objects
- allow to access elements by their position.
- overloaded operators are provided
- created through `begin()` and `end()` functions
  - `end()` points beyond the last element.
  - so never deference end operator.

# std::vector
- behaves like a dynamic array
- provides random access
- not good for insertion/deletion but you can still do it
  - `coll.insert(coll.begin(), 100)` -> inserting 100 at beginning.
- efficient for addition/removal at the end.
  - removing is `coll.pop_back()` rather than `coll.erase(coll.end())` because the end poisition is beyond the storage.
- include `<vector>`

# std::deque
- good for implementing queues.
- Efficient for addition/removal at both ends.
- grows automatically
- provides random access
- not good for insertion/deletion.
- include `<deque>`
- functions
  - `push_front()` and `push_back()`
  - `insert`, `erase` and `pop_back()`.
  - also allows `pop_front()`


# std::list
- a two way linked list
- efficient for insertion/deletion anywhere
- does not provide random access
- `insert()` and `erase()` takes constant time.

# std::forward_list
- one way linked list
  - only has `push_front()`.
- small memory footprint
- efficient for insertion and deletion.
  - `insert_after()` because it only knows about front node
  - `erase_after()`
- does not support for size
- elements are added at the front.