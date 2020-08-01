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
- Static variables are initialized only once , at the start of the execution. These variables will be initialized first, before the initialization of any instance variables
### Static Methods
- Exists independent of any instances of the class.
- Static methods cannot use non-static fields.
- Operations that don't require any data from the instance of class(this).
- #### **Cannot be overridden by subclass. It won't lead to method overriding but method hiding.** [Link](https://www.java67.com/2012/08/can-we-override-static-method-in-java.html)

### Static class
- Only nested class can be static
- Non-static nested classes (inner classes) have access to other members of the enclosing class, even if they are declared private.
- Static nested classes do not have access to other members of the enclosing class.

### Static and non Static initialization blocks
- The non-static block gets called every time an instance of the class is constructed. The static block only gets called once, when the class itself is initialized, no matter how many objects of that type you create.
  ```java
  public class Test {

      static{
          System.out.println("Static Block");
      }

      {
          System.out.println("Non-static block");
      }

      public static void main(String[] args) {
          Test t = new Test();
          Test t2 = new Test();
      }
  }
  ```

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

## Abstraction 
-  OOP concept which focuses on relevant information by hiding unnecessary detail
- There are many design principles that are based on Abstraction e.g. "coding for interfaces then implementation.
- For example, if you need HashMap, your class should depend upon Map instead of HashMap. Similarly, if you need ArrayList, make sure you should use the List. 

### Abstract Classes
#### Abstract Classes and static methods
-  It’s not welcomed in a object oriented design, because static methods can not be overridden in Java. It’s very rare, you see static methods inside abstract class

#### Abstract Classes and constructor
- An abstract class can declare and define a constructor in Java.
-  Since you can not create an instance of an abstract class, a constructor can only be called during constructor chaining, i.e. when you create an instance of the concrete implementation class. 
- Even if constructor won't be used to initialize abstract class,  it can still be used to initialize common variables, which are declared inside an abstract class, and used by the various implementation. 

### Interfaces
- Interface offers protection with change in requirement or future enhancement.
-  Interface can speed up development process and facilitate communication between two different module even if they are not complete.
- All variables declared inside interface is implicitly public final variable or constants.
- All methods declared inside Java Interfaces are implicitly public and abstract
- In Java its legal for an interface to **extend** multiple interface. **Look carefully, I used the word extend, i.e inherit and not implement. A class cannot extend more than one class.**
  ```java
  interface Session extends Serializable, Clonnable{ }
  ```

- In java 8 and above you can define a body inside interface if the method is static/ default.[Link](https://stackoverflow.com/questions/22713652/can-an-interface-method-have-a-body)

#### Some design points
- Very useful for declaring Constants since all variables are implicitly final public variable.
- Interfaces should only have few methods, maybe one or 2, helps with Interface seggregation principles.
- **Its also a good Object-oriented design principle to "program for interfaces than implementation"** because when you use interface to declare reference variable, method return type or method argument you are flexible enough to accept any future implementation of that interface which could be the much better and high-performance alternative of the current implementation. 

#### Marker Interfaces
- **Marker interface in Java is interfaces with no field or methods or in simple word empty interface in java is called marker interface.**
- Example of marker interface is Serializable, Cloneable, and Remote interface. 
- **Marker interface indicate signal or a command to Compiler or JVM.** So if JVM sees a Class is Serializable it done some special operation on it, similar way if JVM sees one Class is implement Clonnable it performs some operation to support cloning. 
- Apart from using built-in marker interface for making a class Serializable or Cloneable. One can also develop his own marker interface. Marker interface is a good way to classify code. You can create marker interface to logically divide your code and if you have your own tool than you can perform some pre-processing operation on those classes. Particularly useful for developing API and framework like Spring 
- **After Java 5, Annotation is a better way of classifying and commenting, JUnit uses annotation.**


### Abstract Classes vs Interfaces
- **Abstract class an ideal place to provide common or default functionality**

   Interface in Java can only contains declaration. You can not declare any concrete methods inside interface. On the other hand abstract class may contain both abstract and concrete methods, which makes . If you have too many methods inside interface, you are creating pain for all it’s implementation, consider providing an abstract class for default implementation. This is the pattern followed in Java collection package, you can see AbstractList provides default implementation for List interface

- **Java interface can extend multiple interface also Java class can implement multiple interfaces, Which means interface can provide more Polymorphism support than abstract class.**

   By extending abstract class, a class can only participate in one Type hierarchy but by using interface it can be part of multiple type hierarchies. If you choose abstract class over interface than you lost your chance to extend another class. One of the common example, in favor of interface over abstract class is Thread vs Runnable case. If you want to execute a task and need run() method it's better to implement Runnable interface than extending Thread class.

- **Since abstract class can include concrete methods, it’s great for maintenance point of view, particularly when your base class is evolving and keep changing.**

   If you need a functionality across all your implementation e.g. a common method, than, you need to change every single implementation to include that change if  you have chosen interface to describe your base class. Abstract class comes handy in this case because you can just define new functionality in abstract super class and every sub class will automatically gets it. In short, abstract class are great in terms of evolving functionality. If you are using interface, you need to exercise extra care while defining contracts because its not easy to change them once published.

- **One more general rule of when to use abstract class and interface is to find out whether a certain class will form a IS-A hierarchy or CAN-DO-THIS hierarchy.** 

  If you know that you will be creating classes e.g. Circle, Square than it's better to create an abstract class Shape which can have area() and perimeter() as abstract method, rather than defining Shape as interface in Java. On the other hand if you are going to create classes which can do thinks like, can fly, you can use interface Flyable instead of abstract class.

- **Another interesting use of Abstract class and interface is defining contract using interface and providing skeletal using abstract class**

  ```java.util.List``` from Java collection framework is a good example of this pattern. List is declared as interface and extends Collection and Iterable interface and AbstractList is an abstract class which implements List. AbstractList provides skeletal implementation of List interface. **Benefit of using this approach is that it minimize the effort to implement this interface by concrete class e.g. ArrayList or LinkedList.** If you don't use skeletal implementation e.g. abstract class and instead decide to implement List interface than not only you need to implement all List methods but also you might be duplicating common code. **Abstract class in this case reduce effort to implement interface.**

- **Using interface also help while implementing Dependency Injection design pattern and makes testing easy.** Many mock testing framework utilize this behavior.


## Encapsulation
- OOP concept which hides data from the outside world.
- Because of Encapsulation, you can change the internal implementation of HashMap with ease without impacting clients who are using HashMap. For example, in Java 8, the java.util.HashMap changes its implementation to use a binary tree instead of LinkedList to store objects in the same bucket after a certain threshold
- Encapsulation is wrapping, just hiding properties and methods. Encapsulation is used for hide the code and data in a single unit to protect the data from the outside the world. 

### Abstraction vs Encapsulation
- both Abstraction and Encapsulation does hide something, but the key difference is on intent. Abstraction hides details at the design level, while Encapsulation hides details at the implementation level.
- Abstraction is about hiding unwanted details while giving out the most essential details, while Encapsulation means hiding the code and data into a single unit e.g. class or method to protect the inner working of an object from the outside world. In other words, Abstraction means extracting common details or generalizing things.
- **In Java, Abstraction is supported using interface and abstract class while Encapsulation is supported using access modifiers e.g. public, private and protected getters and setters.**

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

![Difference between Method Overriding and Overloading](res/java-1.jpg)
  
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

## Nested Classes
- The Java programming language allows you to define a class within another class. Such a class is called a nested class.
- #### As a member of the OuterClass, a nested class can be declared private, public, protected, or package private.
- #### Outer class can only be declared public or  package private
- #### only nested classes can have static keyword in their class defination.

### Reason to use nested classes
- It is a way to logically group classes that are used only in one place, also leads to more readable and more maintainable code by placing code closer to where it is used.


### Types of Nested Classes
- Nested classes are divided into two categories: static and non-static. Nested classes that are declared static are called **static nested classes**.
- **Non-static nested classes are called inner classes**.

#### Static Nested Classes
- As with static methods and variables, a static nested class is associated with its outer class not with an instance of outer class.
- Like static method and static variables static nested class cannot refer directly to instance variables.
- The static nested class cannot access the outer class' instance properties, it can access static properties (shared by all the instances), which are inside the visibility scope.
-  In effect, a static nested class is behaviorally a top-level class that has been nested in another top-level class for packaging convenience.
-  Static nested classes can be accesed as ```OuterClass.StaticNestedClass```

#### Inner Class/ Non Static Nested Class.
- As with instance methods and variables, an inner class is associated with an instance of its enclosing class and has direct access to that object's methods and fields. 
- Inner classes have access to other members of the enclosing class, even if they are declared private.
- ### **Also, because an inner class is associated with an instance, it cannot define any static members itself.**
- Objects that are instances of an inner class exist within an instance of the outer class.
- Inner Classes are of 2 types local classes and anonymous classes.


## Accessors - Getters and Setters 
- **The advantage of using getters and setters - that only get and set - instead of simply using public fields for those variables, if it is just a simple get and set**
  - Because 2 weeks (months, years) from now when you realize that your setter needs to do more than just set the value, you'll also realize that the property has been used directly in 238 other classes.
  - Encapsulation of behavior associated with getting or setting the property - this allows additional functionality (like validation) to be added more easily later.
  - Providing a debugging interception point for when a property changes at runtime - debugging when and where a property changed to a particular value can be quite difficult without this in some languages.
  - Improved interoperability with libraries that are designed to operate against property getter/setters - Mocking, Serialization, and WPF come to mind.
  - Allowing inheritors to change the semantics of how the property behaves and is exposed by overriding the getter/setter methods
- **Getter and Setter break encapsulation?**
  - Having getters and setters does not in itself break encapsulation. What does break encapsulation is having a getter and a setter for every data member (every field, in java lingo). That is one step away from making all data members public.
  - Bad OO design: public fields.
  - Sort of bad OO design : when getters and setters are used, even when not required. An object can be teared apart by other objects, since they are able to inject any new data into it, through setters. The object simply can’t encapsulate its own state safely enough, since anyone can alter it.
  - Great OO design : used only where they're really required - and that to expose the behaviour of your class instead of a tool to manipulate the data.  For data transfer objects public fields or all getters and setters are not so bad. It is also common to only have getters on object that we dont want others to modify, hence immutable.

## Enums in Java
- In Java, an enum (short for enumeration) is a type that has a fixed set of possible values.
- If we declare a variable of the Enum type, it is guaranteed that the variable will hold one of the declared values. If we try to pass values other than those declared values, the compiler will generate an error.

### Advantages
- Type safety and value safety.
- Guaranteed singleton.
- Ability to use values in switch statement case statements without qualification.
- Built-in sequentialization of values via ordinal().
### Enums as fixed number of constants
```java
public enum SitePointChannel {
    JAVA,
    MOBILE,
    WEB,
    PHP,
    WORDPRESS,
    JAVASCRIPT,
    DESIGN
}
```
- you can assign an enum like ```SitePointChannel channel = SitePointChannel.JAVA;```
- Enums can be used in identity comparisions and switch statement.
- Switch Statement
  ```java
  switch (channel) {
      case JAVA:
          System.out.println("Java, web and desktop technologies");
          break;
      case MOBILE:
          System.out.println("Mobile technologies");
          break;
      case PHP:
          // as usual for switch, once a match was found, the execution
          // "falls through" to the next branch until it hits a break
      case WEB:
      case JAVASCRIPT:
      case WORDPRESS:
          System.out.println("Web technologies");
          break;
      default:
          throw new IllegalArgumentException(
                  "Unknown channel '" + channel + "'.")
          break;
  }
  ```
  It is good practice to list all enum constants (even if some of them don’t do anything) and add a default branch, usually with an exception (in case a new constant gets added and someone misses the switch statement and doesn’t update it.)

### Enums as a class - Important
- Enums are much more like classes.
- When an enum class is created, the compiler will also create instances (objects) of each enum constants.

- ### **Each enumeration constant is an object of its enumeration type**
- Enum constants are not special, they are just, public static final members of their enum type. Internally they are just like
  ```java
  public static final Planet MERCURY = new Planet(3.303e+23, 2.4397e6);
  public static final Planet VENUS = new Planet(4.869e+24, 6.0518e6);
  public static final Planet EARTH = new Planet(5.976e+24, 6.37814e6);
  public static final Planet MARS = new Planet(6.421e+23, 3.3972e6);
  public static final Planet JUPITER = new Planet(1.9e+27, 7.1492e7);
  public static final Planet SATURN = new Planet(5.688e+26, 6.0268e7);
  public static final Planet URANUS = new Planet(8.686e+25, 2.5559e7);
  public static final Planet NEPTUNE = new Planet(1.024e+26, 2.4746e7);
  ```
- The only reason we don’t have to put public static final in is that the compiler fills it in for us.
- They can implement interface just like classses.
- They can have fields and methods.
- The difference is they cannot be created using the new keyword
- They cannot be exetend other classes.
- All enums implicitly extend java.lang.Enum. In Java, a class can only extend one parent and therefore an enum cannot extend any other class (but implement interfaces).


#### Methods in enum
- Extending enums means it has the following methods to use.
  - static ```values()```
    -  returns an array of enum-type variables containing all of the enumeration constants.
  - static ```valueOf(String)```
    - The valueOf(String) method returns an enumeration constant whose value corresponds to the string passed to it or throws an IllegalArgumentException if no constant with the specified name was found.
    - Case sensitive  
  - name()
    - This method returns the name(String) of this enum constant, exactly as declared in its enum declaration.
  - ordinal()
    - This method is used to obtain an enumeration constant’s position in the list of constants. This is called the ordinal value.
  - compareTo(Enum)
    -  This method is used to compare the ordinal value of two constants of the same enumeration. This method returns a negative integer, zero, or a positive integer based on the ordinal positions of the two instances that are being compared

#### Enums with Fields (IMPORTANT)
- Java enumeration constants can have fields, which must be given a value at creation time.
- Keep in mind that as with instances of a regular class, each enumeration constant has its own fields. 
- In order to define values, the enclosing type must have a constructor that accepts parameters.
- ### each enumeration constant is an object of its enumeration type, so a constructor is called for each of the enumeration constants.

```java
public enum Month{
  January(31),
  February(28),
  March(31),
  April(30),
  May(31)

  private int numberOfDays;

  Month(int days){
    this.numberOfDays = days;
  }

}
```

#### Enums with Methods
- Besides the basic method available to all enums you can add custom methods to add additional functionalities.
```java
public enum SitePointChannel {

    JAVA,
    MOBILE,
    WEB,
    PHP,
    WORDPRESS,
    JAVASCRIPT,
    DESING;

    public static SitePointChannel valueOfIgnoreCase(String channelName) {
        channelName = channelName.toUpperCase();
        return valueOf(channelName);
    }

}
```

## Type of class and object.
- ### instanceof 
- ### getClass()
- ### SomeClass.class



# To read
- https://javarevisited.blogspot.com/2012/05/how-to-access-private-field-and-method.html
- https://stackoverflow.com/questions/596462/any-reason-to-prefer-getclass-over-instanceof-when-generating-equals
- https://javarevisited.blogspot.com/2011/04/top-10-java-serialization-interview.html
- https://javarevisited.blogspot.com/2015/10/133-java-interview-questions-answers-from-last-5-years.html
- https://javarevisited.blogspot.com/2012/07/when-class-loading-initialization-java-example.html#:~:text=When%20a%20class%20is%20initialized%20in%20Java,-After%20class%20loading&text=A%20Class%20is%20initialized%20in%20Java%20when%20%3A,method%20of%20class%20is%20invoked.