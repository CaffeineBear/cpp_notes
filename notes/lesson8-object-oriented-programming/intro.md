# OOP
- Object is instance of a class.


## Composition
- has-a relation.
- e.g. Car has an engine and uses its implementation to move


## Inheritance
- is-a relationship
- e.g. Cat is an animal. An animal will eat, speak and move.

## Syntax
```cpp
class<child_class> : <access_modifier><base_class>
```
e.g. `class Dog :public Animal`.



## Access Modifers.
- `private`: accessible only wihtin the class
  - If the child is inherited with private access modifier, all the
    members are converted as private. However, the child will never
    allow access to the parent's private member.
- `public`: accessible to everyone.
  - If the child is inherited with public, it will not allow to access
    private member of the parent however, it will allow to access both
    protected and public members.
- `protected`: accessible only to child class
  - If the child is inherited with protected, the public and protected
    members of parents are becoming protected. The private members still
    remains as private members
- See the summary in the table.
- Note: public inheritance is more common.
- If the access modifer is not specified, the default one is used.
  - if the child is a structure: inheritance will be public.
  - if the child is a class    : inheritance will be private.
  - it does not matter the base is a class or structure.


### Access Modifers Table
| Child Access Modifier \ Base Member | public    | private   | protected |
| ----------------------------------  | --------- | --------- | --------- |
| public                              | public    | private   | protected |
| private                             | private   | private   | private   |
| protected                           | protected | private   | protected |

<br />
<br />
<br />

## Object Construction
- The base executes constructor first then to the child.
- For destructor, the child will executed first then to the base.
- Base data members will be part of child object regardless whether it is
  a private member.
- To call a parent public function, it should specify the scope. For
  example, the Checking account needs to call `Account::Withdraw()` to
  use the parent's withdrawing method.
- It is also important to call base class constructor because otherwise
  the compiler will call the default constructor which we don't want.
- However, the `using` statement will allow you to have all base
  base constructor are inherited to child.
  - e.g. `using Account::Account`