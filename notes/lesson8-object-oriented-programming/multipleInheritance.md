# Multiple Inheritance
- When you want to use behaviours from two different classes.


## Diamon Inheritance
- In diamon inheritance, one class is derived from the two different
  derived classes which are inherited from a common class.
- So it forms like a diamond shape.
- let us call this common class be an ancestor class.
- When instantiating a class with diamond inheritance, its object has the
  two ancestor class which are the same.
- This will also cause to lead ambiguos access of a member function since
  there are two of same type ancestor is instanciated, it is not clear to
  call from which ancestor it needs.
- To resolve this, we need `virtual` statements in both parent classes.
  - e.g.
  - `class OutputStream: virtual public Stream{ /* some code */ };`
  - `class InputStream: virtual public Stream{ /* some code */ };`

- Hence, there is only one instance of stream object.
- We also need to call an ancestor contructor from the grandchild because
  we defined an ancestor to be virtual, its constructor will not be invoked
  by children.