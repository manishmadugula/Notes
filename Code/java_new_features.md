# Var in Java 10
- In Java 10, the var keyword allows local variable type inference, which means the type for the local variable will be inferred by the compiler, so you don’t need to declare that.
- Instead of 
  ```java
  MAP<String,String> map=new HashMap<String,String>(); 
  MAP<User,List<String>> listofMovies=new HashMap<>();
  ```
  you can now use

  ```java
  var map=new HashMap<String,String>();
  var listofMovies=new HashMap<User,List<String>>();
  ```
- Each statement containing the var keyword has a static type which is the declared type of value(Unlike in js). This means that assigning a value of a different type will always fail. 
  ```java
  var id=0;// At this moment, compiler interprets 
  //variable id as integer.
  id="34"; // This will result in compilation error 
  //because of incompatible types: java.lang.String 
  //can't be converted to int.
  ```

- You cannot initialize a var variable to null. 
- polymorphic behavior does not work with the var keyword. Say doctor and engineer inherit the person class. You can't do
  ```java
  var p=new Doctor(); // In this case, what should be
  //the type of p; it is Doctor or Person?
  p=new Engineer(); // Compilation error saying
  //incompatible types
  ```