# Summary from O Notation

- a `vector` is good for random access but not for insertion and deletion
- `deque` is preferred when elements needs to be inserted and removed from
  the both ends.
- use `list` if frequent insertions and deletions are required.
  - use `forward_list` for memory constrained environment.
- use **associative** containers if lookup/search is important
- use **unordered** containers if elements don't need to be ordered. else,
  use set/map.