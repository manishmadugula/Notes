# decltype
- decltype is a way to specify a type: You give it an expression, and decltype gives you back a type which corresponds to the type of the expression. Specifically, decltype(e) is the following type:
  - If e is the name of a variable, i.e. an "id-expression", then the resulting type is the type of the variable.
  - Otherwise, if e evaluates to an lvalue of type T, then the resulting type is T &, and if e evaluates to an rvalue of type T, then the resulting type is T.
  
```c++
int foo();
int n = 10;

decltype(n) a = 20;             // a is an "int" [id-expression]

decltype((n)) b = a;            // b is an "int &" [(n) is an lvalue]

decltype(foo()) c = foo();      // c is an "int" [rvalue]

decltype(foo()) && r1 = foo();  // int &&
decltype((n)) && r2 = n;        // int &
```

# constexpr (Need to see more)

The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time. Such variables and functions can then be used where only compile time constant expressions are allowed.


# type traits
[Determine if a type passed in the template arrow is pointer etc./...](https://blog.galowicz.de/2016/02/18/what_is_a_type_trait/)

