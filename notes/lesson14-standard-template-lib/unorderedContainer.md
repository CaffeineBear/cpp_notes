# Unordered Containers

- Internally implemented as a hashtable.
- values are stored in undefined order.
- fast search, insertion/deletion but may degrade over a period of time.
  - when a load factor (entries/capacity) approaches certain value,
    the hash table will grow and it will be rehashed.
    - meaning, a new key is generated for existing entries.
- `unordered_set`
  - values act as a key.
- `unordered_map`
  - key and values are stored as a pair
- You cannot modify the value with iterator.
- Eventhough there are multiple entries in the same bucket, the
  performance of the unordered set for searches will be much better than
  associative containers set.
