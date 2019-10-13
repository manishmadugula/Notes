# Datatypes
## Primitive Datatypes
- Byte -> 1 byte -128 to 127
- Char -> **(Unicode 16)**2 byte 0 to 65535 **'\u00A9' needs hex code for each of the 4 places.**
- Short -> 2 byte -32768 to 32767
- Int -> 4 byte -2147483648 to 2147483647
- Long -> 8 bytes -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 **need to append L at the end.**
- float -> 4 bytes
    **If you write float x = 233.3 it will through an error. You need to do float x = 233.3f or float x = (float) 233.3;**
- double -> 8 bytes
- boolean -> 1 bit (true or false)


# Access Modifiers
## For Classes and Interfaces.
- class or interface cannot be private cause then it is useless as it cannot be accessed by anything outside.[link](http://net-informations.com/java/cjava/private.htm)
- class or interface  cannot be protected as there is no way to make any particular class outside of the package to access it since it can just inherit it and start accessing it making it useless.
- implicit modifiers for interfaces are public static final for fields and public for methods.
- 2 public class cannot be in the same file.

## For Methods
- methods declared public in superclass must be public in all the subclasses.
- methods declared protected in superclass must be declared protected in all subclasses.
- methods declared private are not inherited.
- main method has to be public else it cannot be called by Java Interpreter.

# Non Access Modifiers
## Static
### Static Variable
- Exists independent of any instances of the class.
- Only one copy exists regardless of number of instances.
### Static Methods
- Exists independent of any instances of the class.
- Static methods cannot use non-static fields.
- Operations that don't require any data from the instance of class(this).

## Final
### Instance Variable
- Cannot be intialized inside a method as it can be called multiple times but can be initialized inside a constructor.
### For Variable
- Final variable can be explicitly initialized only once i.e reference variable declared final can never be reassigned.
- The data within the final object can change so the state of the object can change not the reference of the object.
### For Method
- Final method can't be overridden by subclass.
### For Class
- Final class can't be inheritted.


# Abstract
## Method
- Method declared without any body.
- Body is provided by subclass.
- abstract method can't be final.
- ends with a semicolumn.
## Class
- Class having one or more abstract method has be declared abstract.
- Any class extending the abstract class has to implement all its methods else be declared abstract itself.

# User Input
- The Scanner.next()/ nextInt() won't consume the newline character so to use nextLine after nextInt you need to first consume newline by an additional nextLine.

- ```java 
  String text = new Scanner( source ).useDelimiter("\\A").next();
  ```
    One line, one class. The only tricky is to remember the regex ```\A```, which matches the beginning of input. This effectively tells Scanner to tokenize the entire stream, from beginning to (illogical) next beginning. As a bonus, Scanner can work not only with an InputStream as the source, but also a File, Channel, or anything that implements the new java.lang.Readable interface. For example, to read a file:

    ```java
    String text = new Scanner( new File("poem.txt") ).useDelimiter("\\A").next();
    ```

    you can accommodate a specific character set with Scanner example you can pass a charset to the constructor.

# Object Oriented Programming

- Every class inherits from Object class of Java.
- Use IntelliJ's Generate to generate code for getter and setter in class.

## Constructor
- Use IntelliJ's Generate to generate code for constructors.
- ### **Constructors are not class members and thus aren't inherited.**

  - Constructors are special and have same name as class name. So if constructors were inherited in child class then child class would contain a parent class constructor which is against the constraint that constructor should have same name as class name. 

  - Constructor is a block of code that allows you to create an object of class and has same name as class with no explicit return type.

  - A parent class constructor is not inherited in child class and this is why super() is added automatically in child class constructor if there is no explicit call to super or this.

- Call one constructor inside another constructor. this should be the first statement in constructor body.
    ```java
    public class Account{
        int m;
        int n;
        public Account(){
            this(1,1);
        }
        public Account(int x, int y){
            this.m = x;
            this.n = y;
        }
    }
    ```
- Call super class constructor in subclass using super. super() has to be the first line in the constructor.
- You cannot call this and super inside the constructor as both has to be called in first line, also this will call super anyways inside it so doesn't make sense.
- RULE_OF_THUMB -> Don't use setters or other methods in constructors. 
- java compiler puts a default call to super() if we don't add it, and it is always the non-arg super that is inserted by compiler.
- Abstract class are still a super class and it's constructor are run when someone makes an instance of its subclass.

## this and super
- super is used to access methods and variable of parent class as well as its constructor.
- this is used to  access methods and variable of current class as well as its constructor.
- super and this can be used anywhere inside a class **except static areas/methods.**

## Inheritance
- to call super class methods inside subclass use ```super.methodName();```

## Polymorphism
### Method Overriding
  - same name and parameters but super class method overriden by sub class.
  - Fancy names
    - Run time polymorphism. which method to call is decided by JVM at run-time. 
    - dynamic polymorphism
    - late binding or dynamic binding
    - dynamic method dispatch
  - Use @Override decorator on top of Overloaded method is good practise as compiler will show an error if method is not overrided properly
  - only inherited methods can be overriden.
  - ### return type can be a subclass of return type in super class.
  - ### constructors and private methods can't be overriden.
  - ### final methods can't be overriden.
  - ### it can't have a lower access modifier.
    - if parent is protected then child cannot be private but it can be public.
  - must not throw new or broader checked exception.
### Method Overloading
  - ### same name different parameters.
  - ### If name is same, parameters is same but return type or access modifier is different it would throw error.
  - Fancy names
    - Compile time Polymorphism, compiler decides which method to call based on method name, return type and argument list.
    - known as static polymorphism.
    - early binding or static binding.
    - static method dispatch

![Difference between Method Overriding and Overloading](res\java-1.jpg)
  
### Early Binding (Static binding)
  - Early Binding, methods, functions and properties are detected and checked during compile time and perform other optimizations before an application executes. The biggest advantage of using early binding is for performance and ease of development.
  ```java
    System.IO.FileStream FS ;
    FS = new System.IO.FileStream("C:\\temp.txt", System.IO.FileMode.Open);
  ```
  Above code, create a variable FS to hold a new object and then assign a new object to the variable. Here type is known before the variable is exercised during run-time, usually through declarative means. The FileStream is a specific object type, the instance assigned to FS is early bound. Early Binding is also called static binding or compile time binding.

### Late Binding (Dynamic Binding)
  - Late binding functions, methods, variables and properties are detected and checked only at the run-time. It implies that the compiler does not know what kind of object or actual type of an object or which methods or properties an object contains until run time. The biggest advantages of Late binding is that the Objects of this type can hold references to any object, but lack many of the advantages of early-bound objects.

  ```java
    object FS = null;
    FS = CreateObject("Scripting.FileSystemObject");
  ```

  - Above code does not require a reference to be set beforehand, the instance creation and type determination will just happen at runtime.
  - ### It is important to note that the Late binding can only be used to access type members that are declared as Public. Accessing members declared as Friend or Protected Friend resulted in a run-time error.