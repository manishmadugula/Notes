- [Datatypes](#datatypes)
  - [Primitive Datatypes](#primitive-datatypes)
- [Access Modifiers](#access-modifiers)
  - [For Classes and Interfaces.](#for-classes-and-interfaces)
  - [For Methods/fields](#for-methodsfields)
- [Non Access Modifiers](#non-access-modifiers)
  - [Static](#static)
    - [Static Variable](#static-variable)
    - [Static Methods](#static-methods)
    - [Static class](#static-class)
    - [Static and non Static initialization blocks](#static-and-non-static-initialization-blocks)
  - [Final](#final)
    - [Instance Variable](#instance-variable)
    - [For Variable](#for-variable)
    - [For Method](#for-method)
    - [For Class](#for-class)
- [Compile time constant must be](#compile-time-constant-must-be)
- [Abstract](#abstract)
  - [Method](#method)
  - [Class](#class)
- [Object Oriented Programming](#object-oriented-programming)
  - [Class Initialization](#class-initialization)
    - [When is a class loaded in java](#when-is-a-class-loaded-in-java)
    - [When is a class initialized](#when-is-a-class-initialized)
    - [How is a class initialized](#how-is-a-class-initialized)
      - [If static initialization](#if-static-initialization)
      - [Some more points](#some-more-points)
      - [Some examples](#some-examples)
  - [Constructor](#constructor)
    - [IMPORTANT - Having only Private constructors](#important---having-only-private-constructors)
  - [this and super](#this-and-super)
  - [Inheritance](#inheritance)
  - [Abstraction](#abstraction)
    - [Abstract Classes](#abstract-classes)
      - [Abstract Classes and static methods](#abstract-classes-and-static-methods)
      - [Abstract Classes and constructor](#abstract-classes-and-constructor)
    - [Interfaces](#interfaces)
      - [Some design points](#some-design-points)
      - [Marker Interfaces](#marker-interfaces)
    - [Abstract Classes vs Interfaces](#abstract-classes-vs-interfaces)
  - [Encapsulation](#encapsulation)
    - [Abstraction vs Encapsulation](#abstraction-vs-encapsulation)
  - [Polymorphism](#polymorphism)
    - [Method Overriding](#method-overriding)
    - [Method Overloading](#method-overloading)
    - [Early Binding (Static binding)](#early-binding-static-binding)
    - [Late Binding (Dynamic Binding)](#late-binding-dynamic-binding)
  - [Nested Classes](#nested-classes)
    - [Reason to use nested classes](#reason-to-use-nested-classes)
    - [Types of Nested Classes](#types-of-nested-classes)
      - [Static Nested Classes](#static-nested-classes)
      - [Inner Class/ Non Static Nested Class.](#inner-class-non-static-nested-class)
  - [Accessors - Getters and Setters](#accessors---getters-and-setters)
  - [Enums in Java](#enums-in-java)
    - [Advantages](#advantages)
    - [Enums as fixed number of constants](#enums-as-fixed-number-of-constants)
    - [Enums as a class - Important](#enums-as-a-class---important)
      - [Methods in enum](#methods-in-enum)
      - [Enums with Fields (IMPORTANT)](#enums-with-fields-important)
      - [Enums with Methods](#enums-with-methods)
  - [Type of class and object.](#type-of-class-and-object)
- [Collections](#collections)
  - [HashMap](#hashmap)
    - [Rehashing / Exceeding Load Factor](#rehashing--exceeding-load-factor)
    - [```capacity = number of buckets * load factor```](#capacity--number-of-buckets--load-factor)
  - [HashTable (Deprecated)](#hashtable-deprecated)
  - [Concurrent HashMap](#concurrent-hashmap)
    - [You can also deal with such situation using replace API on concurrentHashMap which will update the hashMap with newValue only if the oldValue matches the currentValue.](#you-can-also-deal-with-such-situation-using-replace-api-on-concurrenthashmap-which-will-update-the-hashmap-with-newvalue-only-if-the-oldvalue-matches-the-currentvalue)
  - [LinkedHashMap](#linkedhashmap)
  - [TreeMap](#treemap)
  - [ConcurrentSkipListMap](#concurrentskiplistmap)
  - [IdentityHashMap](#identityhashmap)
  - [EnumMap](#enummap)
    - [ConcurrentModificationException](#concurrentmodificationexception)
  - [WeakHashMap](#weakhashmap)
  - [SynchronizedMap](#synchronizedmap)
- [JVM](#jvm)
  - [Class Loader](#class-loader)
  - [Runtime Data Areas](#runtime-data-areas)
    - [Method Area / Perm Gen Space (JAVA-8 Metaspace) (Shared - Not Thread Safe)](#method-area--perm-gen-space-java-8-metaspace-shared---not-thread-safe)
    - [Heap (Shared - Not Thread Safe)](#heap-shared---not-thread-safe)
    - [PC Register (Isolated Per Thread) i.e Thread Safe](#pc-register-isolated-per-thread-ie-thread-safe)
    - [Java Stack (Isolated Per Thread) i.e Thread Safe](#java-stack-isolated-per-thread-ie-thread-safe)
    - [Native Method Stack (Isolated Per Thread) i.e Thread Safe](#native-method-stack-isolated-per-thread-ie-thread-safe)
  - [Execution Engine](#execution-engine)
    - [Interpreter](#interpreter)
    - [Just in Time Compiler (JIT)](#just-in-time-compiler-jit)
    - [Hotspot Profiler/VM](#hotspot-profilervm)
    - [Garbage collector](#garbage-collector)
    - [AOT Compiler](#aot-compiler)
- [Garbage Collector](#garbage-collector-1)
  - [Types of garbage collections](#types-of-garbage-collections)
  - [Based on hypothesis](#based-on-hypothesis)
  - [Terminology](#terminology)
    - [Live Objects](#live-objects)
    - [Dead Objects](#dead-objects)
  - [Steps](#steps)
    - [Mark](#mark)
    - [Sweep](#sweep)
    - [Compaction](#compaction)
  - [Heap space division](#heap-space-division)
    - [Young Generation](#young-generation)
      - [Eden Space](#eden-space)
      - [Survivor Space](#survivor-space)
    - [Old/ Tenured Generation](#old-tenured-generation)
  - [GC Types based on implementation.](#gc-types-based-on-implementation)
    - [Performace of GC](#performace-of-gc)
      - [Latency](#latency)
      - [Throughput](#throughput)
    - [Serial GC](#serial-gc)
    - [Concurrent GC (Low Latency GC)](#concurrent-gc-low-latency-gc)
    - [Parallel GC](#parallel-gc)
    - [G1 Garbage First GC (Java 9 onwards default)](#g1-garbage-first-gc-java-9-onwards-default)
  - [Finalize Method.](#finalize-method)
  - [Debug GC](#debug-gc)
- [String](#string)
  - [String Pool](#string-pool)
  - [Why Strings are immutable](#why-strings-are-immutable)
  - [Useful Methods](#useful-methods)
    - [indexOf](#indexof)
    - [lastIndexOf](#lastindexof)
    - [contains](#contains)
    - [substring](#substring)
  - [Regular Expressions](#regular-expressions)
    - [matches](#matches)
    - [Find occurances of a pattern in a string using regular expression](#find-occurances-of-a-pattern-in-a-string-using-regular-expression)
  - [Good Practises](#good-practises)
- [StringBuffer](#stringbuffer)
- [StringBuilder](#stringbuilder)
  - [append](#append)
  - [concat](#concat)
- [Java Language Features](#java-language-features)
  - [Weak Reference](#weak-reference)
  - [Soft Reference](#soft-reference)
  - [Annotations](#annotations)
    - [Where it can be used](#where-it-can-be-used)
    - [Built-In Annotations](#built-in-annotations)
  - [User Input](#user-input)
  - [Regex](#regex)
- [To read](#to-read)

# Datatypes
## Primitive Datatypes
- Byte -> 1 byte -128 to 127
- ### It is important to note negative sign has one more possible value.
- Char -> **(Unicode 16)**2 byte 0 to 65535 **'\u00A9' needs hex code for each of the 4 places.**
- Short -> 2 byte -32768 to 32767
- Int -> 4 byte -2147483648 to 2147483647
- Long -> 8 bytes -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 **need to append L at the end.**
- float -> 4 bytes
    **If you write float x = 233.3 it will through an error. You need to do float x = 233.3f or float x = (float) 233.3;**
- double -> 8 bytes
- boolean -> 1 bit (true or false)


# Access Modifiers
- Default access modifier in Java is package-protected, visible to all classes within the package not outside of package.
- ### protected access modifier also allows non-subclass which are part of the same package
- It is important to note, a class member is accessible outside the subpackage by inheritance only. Can't do
  ```java
    public class subClass{
      SuperClassDifferentPackage supclass= new SuperClassDifferentPackage(2);
      public int sampleInt(){
        //Not allowed
        return supclass.protectedInt;
      }
    }
  ```

## For Classes and Interfaces.
- ### Top Level (not inner class or nested class) class or interface cannot be private cause then it is useless as it cannot be accessed by anything outside.[link](http://net-informations.com/java/cjava/private.htm)
- ### Top Level class or interface  cannot be protected. [Link](https://stackoverflow.com/questions/3869556/why-can-a-class-not-be-defined-as-protected#:~:text=The%20answer%20why%20protected%20class,it%20will%20inherit%20will%20class.&text=Similarly%2C%20A%20top%20level%20class%20can't%20be%20private.)
  - To understand this, let's look at what a protected method/field is, a protected method/field is visible to all the classes within the package and class in other packages which are subclasses to the class(current class) containing the protected method/field.
  - It is important to note that the only way a class outside the package was able to inherit the current class is because the current class is public.
  - No let us try to identify what it means for the class to be protected, it should be visible to all the classes within the package and all the packages(not class cause we are one step above method level) which inherit from current package, the above statement doesn't make sense in Java, since there are no concept of package inheritance, essentially rendering protected == package private (default access modifier).
- implicit modifiers for interfaces are public static final for fields and public for methods.
- 2 public class cannot be in the same file.

## For Methods/fields
- methods declared public in superclass must be public in all the subclasses.
- ### methods declared protected in superclass must be declared protected/public in all subclasses. i.e you cannot decrease the scope, you can increase it though.
  - A subclass should always satisfy the contract of the superclass. Liskov Substitution principle.
  - The visibility of methods is part of this contract. So anything publicly visible in the superclass should be public in the subclass as well.
- ### methods declared private are not inherited.
- main method has to be public else it cannot be called by Java Interpreter.

# Non Access Modifiers
## Static
### Static Variable
- Exists independent of any instances of the class.
- Only one copy exists regardless of number of instances.
- Static variables are initialized only once , when the class loads [See below for when a class is loaded](#when-is-a-class-loaded-in-java). These variables will be initialized first, before the initialization of any instance variables
### Static Methods
- Exists independent of any instances of the class.
- Static methods cannot use non-static fields.
- Operations that don't require any data from the instance of class(this).
- ### **Cannot be overridden by subclass. It won't lead to method overriding but method hiding.** [Link](https://www.java67.com/2012/08/can-we-override-static-method-in-java.html)
  - In practice it means that the compiler will decide which method to execute at the compile time, and not at the runtime, as it does with overridden instance methods.
  - Overriding in Java simply means that the particular method would be called based on the run time type of the object and not on the compile time type of it (which is the case with overriden static methods). Okay... any guesses for the reason why do they behave strangely? Because they are class methods and hence access to them is always resolved during compile time only using the compile time type information.
  - Why this matters? The advantage of dynamic binding is that it allows us to write code that is generic and you don't have to recompile all the source code that is dynamically bonded, It is probably the basis of dependency injection.
  - If you use super classes's reference to call the static method of a subclass's body it will call super classes's static method, instead of calling subclasses. (No dynamic binding takes place). Can't use superclass reference to call subclasses's method implementation.

### Static class
- Only nested class can be static
- Non-static nested classes (inner classes) have access to other members of the enclosing class, even if they are declared private.
- Static nested classes do not have access to other members of the enclosing class.

### Static and non Static initialization blocks
- The non-static block gets called every time an instance of the class is constructed. The static block only gets called once, when the class itself is initialized, no matter how many objects of that type you create. 
- ### Both static and non-static initializer runs before the constructor runs.
- ### Used for initialization not for declaration.
  ```java
  public class Test {
      public static final StaticClass timevarman;
      static{
          //Used for initialization not for declaration.
          timevarman = new StaticClass();
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
- ### A Final Instance Variable has to be initialized before the constructor ends, you can initializ it in non-static initializer or inside the constructor, but not within any other method.
- ### Declaring them as static final will help you to create a CONSTANT. Only one copy of variable exists which can’t be reinitialize.
### For Variable
- Final variable can be explicitly initialized only once i.e reference variable declared final can never be reassigned.
- The data within the final object can change so the state of the object can change not the reference of the object. (i.e when you are declaring the variable as final, it is the reference which is final, not the underlying object).
### For Method
- Final method can't be overridden by subclass.
- ### It is important to note that a private method cannot be inherited, a final method can be inherited, just not overriden.
### For Class
- Final class can't be inheritted.

# Compile time constant must be
- declared final
- primitive or String
- initialized within declaration
- initialized with constant expression

# Abstract
## Method
- Method declared without any body.
- Body is provided by subclass.
- abstract method can't be final.
- ends with a semicolumn.
## Class
- Class having one or more abstract method has be declared abstract.
- Any class extending the abstract class has to implement all its methods else be declared abstract itself.

```java
public abstract class AbstractClassExample {
    abstract void abstractMethod();

    int returnOne(){
        return 1;
    }

}
```

# Object Oriented Programming

- Every class inherits from Object class of Java.
- Use IntelliJ's Generate to generate code for getter and setter in class.

## Class Initialization
### When is a class loaded in java
- Class loading is done by ClassLoaders in Java which can be implemented to eagerly load a class as soon as another class references it or lazy load the class until a need of class initialization occurs. If Class is loaded before its actually being used it can sit inside before being initialized. I believe this may vary from JVM to JVM. While its guaranteed by JLS that a class will be loaded when there is a need of static initialization.

### When is a class initialized
- After class loading, initialization takes place which means initializing all static members of the class.
- A class is initialized when
  - An instance of class is created using new/reflection.
  - A Static method of class is invoked.
  - A Static field of class is assigned.
  - ### A Static field of class is used which is not a compile time constant. Use of compile time constant doesn't trigger class initialization.
  - if Class is a top-level class and an assert statement lexically nested within the class is executed.

### How is a class initialized
#### If static initialization
- static block of super classes
- static block of current class
- If new is used inside the static block
  - Then non-static block is also initialized followed by constructor. 
    ```java
    public class CurrentClass {

        public static final CurrentClass staticmembervariable;

        {
            System.out.println("Non Static Block");
        }

        static{
            System.out.println("Static Block");
            staticmembervariable = new CurrentClass();
        }

        private CurrentClass(){
            System.out.println("Constructor block");
        }
    }

    public class Main{
        public static void main(String[] args) {
            System.out.println("progRAM STARTED");
            //(Class is initialized here since a non compile time constant is called)
            System.out.println(StaticClass.staticmembervariable);
        }
    }

    //Prints out
    /*progRAM STARTED
    Static Block 
    Non Static Block
    Constructor Block
    */
    ```
#### Some more points
- Classes are initialized from top to bottom so field declared on top initialized before field declared in bottom.
- ###  If Class initialization is triggered due to access of static field, only Class which has declared static field is initialized and it doesn't trigger initialization of super class or sub class even if static field is referenced by Type  of Sub Class, Sub Interface or by implementation class of interface (see below example)
- ### Interface initialization in Java doesn't cause super interfaces to be initialized.
-  ### Static fields are initialized before non-static fields in Java.
   Static fields are initialized during static initialization of class while non static fields are initialized when an instance of the class is created.
- ### non-static fields are initialized by constructors in Java. sub class constructor implicitly call super class constructor before doing any initialization, which guarantees that non static or instance variables of super class is initialized before sub class.

#### Some examples
- ```NotUsed o = null;``` this class is not used, should not be initialized on hitting this code.
- The following example ->
  ```java
  class Parent{
    //Not a compile time constant since no final.
    protected static String familyName = "Madugula";
    {
      System.out.println("Non static block in super class is intialized");
    }
    static{
      System.out.println("static block in Super class is intialized");
    }
  }
  class Child extends Parent{
    {
      //never called
        System.out.println("Child non static block");
    }
    static {
      //never called
        System.out.println("Child static block");
    }
  }
  class Main{
     public static void main(String[] args) {
        System.out.println("progRAM STARTED");
        System.out.println(Child.familyName);
    }
  }

  //Prints
  /*
  progRAM STARTED
  static block in Super class is intialized
  Madugula
  */
  ```
  - Here class initialization occurs because static field is accessed which is not a compile time constant. had you declare "familyName" **compile time constant using final keyword in Java, class initialization of super class would not have occurred**.
  - Only super class is initialized even though static field is referenced using sub type.

- ### The following example -> Singleton Holder Pattern.
  ```java
  public class OuterClass {
    public static int x = 23;
    static {
        System.out.println("Outer Class initialized");
    }

    private static class InnerClass {
        static {
            System.out.println("Inner Class initialized");
            s = new OuterClass();
        }
        private static OuterClass s;
    }
    
    public static OuterClass getInstance() {
        return InnerClass.s;
    }
  }

  public class Main{
    public static void main(String[] args) {
        System.out.println("progRAM STARTED");
        //This is where Outer class was intialized.
        System.out.println(OuterClass.x);
        System.out.println("Break");
        //This is where Inner class was intialized.
        System.out.println(OuterClass.getInstance());
    }
  }
  //Prints
  /*
  progRAM STARTED
  Outer Class initialized
  23
  Break
  Inner Class initialized
  */
  ```
  - Even if the Outer Class is initialized, the InnerClasses's initialization was deferred till it was actually used. i.e on line ```System.out.println(OuterClass.getInstance());```

## Constructor
- Use IntelliJ's Generate to generate code for constructors.
- ### **Constructors are not class members and thus aren't inherited.**

  - Constructors are special and have same name as class name. So if constructors were inherited in child class then child class would contain a parent class constructor which is against the constraint that constructor should have same name as class name. 

  - Constructor is a block of code that allows you to create an object of class and has same name as class with no explicit return type.

  - A parent class constructor is not inherited in child class and this is why super() is added automatically in child class constructor if there is no explicit call to super or this.

- ### Call one constructor inside another constructor. this should be the first statement in constructor body.
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
- ### You cannot call this and super inside the constructor as both has to be called in first line, also this will call super anyways inside it so doesn't make sense.
- RULE_OF_THUMB -> Don't use setters or other methods in constructors. 
- java compiler puts a default call to super() if we don't add it, and it is always the non-arg super that is inserted by compiler.
- Abstract class are still a super class and it's constructor are run when someone makes an instance of its subclass.


### IMPORTANT - Having only Private constructors
- ### Because a class must call its super class constructor always. If the super class constructor can't be accessed, then the sub class can't be initialized. - Thus classes without public/protected constructors cannot be subclassed.(Unless both subclass and superclass are nested inside the same class).
- Also a package local constructor cannot be used in another package.

## this and super
- super is used to access methods and variable of parent class as well as its constructor.
- this is used to  access methods and variable of current class as well as its constructor.
- super and this can be used anywhere inside a class **except static areas/methods.**

## Inheritance
- ### to call super class methods inside subclass use ```super.methodName();```

## Abstraction 
-  OOP concept which focuses on relevant information by hiding unnecessary detail
- There are many design principles that are based on Abstraction e.g. "coding for interfaces then implementation.
- For example, if you need HashMap, your class should depend upon Map instead of HashMap. Similarly, if you need ArrayList, make sure you should use the List. 

### Abstract Classes
#### Abstract Classes and static methods
-  ### It’s not welcomed in a object oriented design, because static methods can not be overridden in Java. It’s very rare, you see static methods inside abstract class

#### Abstract Classes and constructor
- ### An abstract class can declare and define a constructor in Java.
-  Since you can not create an instance of an abstract class, a constructor can only be called during constructor chaining, i.e. when you create an instance of the concrete implementation class. 
- Even if constructor won't be used to initialize abstract class,  it can still be used to initialize common variables, which are declared inside an abstract class, and used by the various implementation. 

### Interfaces
- Interface offers protection with change in requirement or future enhancement.
-  Interface can speed up development process and facilitate communication between two different module even if they are not complete.
- All variables declared inside interface is implicitly public final variable or constants.
- All methods declared inside Java Interfaces are implicitly public and abstract
- ### An interface cannot implement another interface in Java.
  - In Java its legal for an interface to **extend** multiple interface. **Look carefully, I used the word extend, i.e inherit and not implement. A class cannot extend more than one class.**
  -  An interface can extend any number of interfaces but one interface cannot implement another interface, because if any interface is implemented then its methods must be defined and interface never has the definition of any method.
  ```java
  interface Session extends Serializable, Clonnable{ }
  ```

- In java 8 and above you can define a body inside interface if the method is static/ default.[Link](https://stackoverflow.com/questions/22713652/can-an-interface-method-have-a-body). But these static methods cannot be overridden just like any other class.

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

   By extending abstract class, a class can only participate in one Type hierarchy but by using interface it can be part of multiple type hierarchies. If you choose abstract class over interface than you lost your chance to extend another class.
  - ### One of the common example, in favor of interface over abstract class is Thread vs Runnable case. If you want to execute a task and need run() method it's better to implement Runnable interface than extending Thread class.

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
  - ### must not throw new or broader checked exception.
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
  - ### static, private and final methods and variables are resolved using static binding which makes there execution fast because no time is wasted to find correct method during runtime. (Doubt?? if this is applicable to Java)

### Late Binding (Dynamic Binding)
  - Late binding functions, methods, variables and properties are detected and checked only at the run-time. It implies that the compiler does not know what kind of object or actual type of an object or which methods or properties an object contains until run time. The biggest advantages of Late binding is that the Objects of this type can hold references to any object, but lack many of the advantages of early-bound objects.

  ```java
    object FS = null;
    FS = CreateObject("Scripting.FileSystemObject");
  ```

  - Above code does not require a reference to be set beforehand, the instance creation and type determination will just happen at runtime.
  - ### It is important to note that the Late binding can only be used to access type members that are declared as Public. Accessing members declared as Friend or Protected Friend resulted in a run-time error.
  - Static Binding uses type, while dynamic binding uses actual object to bind. 
  

## Nested Classes
- The Java programming language allows you to define a class within another class. Such a class is called a nested class.
- #### As a member of the OuterClass, a nested class can be declared private, public, protected, or package private.
- #### Outer class can only be declared public or  package private
- #### only nested classes can have static keyword in their class defination.
- All outer classes are static by the defination of class, so doesn't make sense to define them static explicitly. (There is always going to be one class per class).

### Reason to use nested classes
- It is a way to logically group classes that are used only in one place, also leads to more readable and more maintainable code by placing code closer to where it is used.
- No other class should use this class.


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
    DESIGN;
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
- ### The difference is they cannot be created using the new keyword
- They cannot be exetend other classes.
- ### All enums implicitly extend java.lang.Enum. In Java, a class can only extend one parent and therefore an enum cannot extend any other class (but implement interfaces).


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
- ### ENUM Values are comma separated. And also when there are fields and methods, the list of enum constants must end with a semicolon.
- ### each enumeration constant is an object of its enumeration type, so a constructor is called for each of the enumeration constants.

```java
public enum Month {

    JANUARY(31),
    FEBRUARY(28),
    MARCH(31),
    APRIL(30),
    MAY(31),
    JULY(31),
    AUGUST(31),
    SEPTEMBER(30),
    OCTOBER(31),
    NOVEMBER(30),
    DECEMBER(31);

    private int numberOfDays;

    Month(int days){
        this.numberOfDays = days;
    }

    public int getDays(){
        return numberOfDays;
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


# Collections 

## HashMap
- It uses a tree instead of linkedlist to make sure in worst case item retrieval is O(log(n)) for collisions.
- Accepts null
  ```java
    HashMap<Integer, String> hashMap = new HashMap<Integer, String>();
    hashMap.put(null, "value");
    System.out.println(hashMap.get(null));
    //Prints
    //"value"
    ```
- ### HashMap in Java stores both key and value object as Map.Entry in a bucket.

- ### Map.Entry has the following fields ex->
  ```java
  {
    int hash = 11314241,
    Key key = {"Manish"},
    Integer value = 24,
    Node next = null
    //If tree is used left and right nodes.
  }
  ```
  ![](res/hashmap_java.jpg)
- ### HashMap is not thread safe.
- To be a key hashmap has to implement both hashCode() and equals method( to resolve collisons).
- When we pass Key and Value object  to put() method on Java HashMap, HashMap implementation calls **hashCode** method on Key object and applies returned hashcode into its own hashing function to find a bucket location for storing Entry object. Objects like String, Integer, and other wrapper classes (Double) are good candidates for key since they are immutable and also implement the hashCode method.
- **Your non immutable custom object can also be the key if it implements the hashCode and equals contract and a few fields which are used to calculate the hashCode implementation for you object are defined final i.e its hashCode should not vary once the object is inserted into Map. If the custom object is Immutable than this will be already taken care because you can not change it once created.**


### Rehashing / Exceeding Load Factor
- If a hashmap's size exceeds a given threshold which is the **load factor**, say .75, it will re-size itself, creating a new array of buckets, twice the size of the previous bucket array and then **it starts putting old elements in the new bucket array.** This process is called **Rehashing**. The HashMap cannot be used in a multithreaded environment, since if 2 threads trigger rehashing this can lead to race conditions.

  ### ```capacity = number of buckets * load factor```

[Working of hashmap](https://www.geeksforgeeks.org/internal-working-of-hashmap-java/#:~:text=As%20HashMap%20also%20allows%20null,null%20will%20always%20be%200.&text=hashCode()%20method%20is%20used,of%20object%20in%20integer%20form.&text=In%20HashMap%2C%20hashCode()%20is,and%20therefore%20calculate%20the%20index.)
## HashTable (Deprecated)
- HashTable doesn't accept null
  ```java
  Hashtable<Integer, String> hashTable = new Hashtable<Integer, String>();
  hashTable.put(null, "342");
  //Exception -> java.lang.NullPointerException
  ```

- ### HashMap is thread safe.
- ### Has synchronised keyword on all public methods. So it is going to cause overhead on read and writes to maps. 


## Concurrent HashMap
- Reads don't require a lock, so full concurrency during retrieval. Most retrieval operations are not blocked even if other threads are writing to it, unless both read and write are in the same segment. 
- Writes require the lock at a granular level called segments, this makes sures reads are rarely blocked.
- ### Does not fail-fast. Won't cause ConcurrentModificationException (Look at EnumMap).
- Null key isn't allowed, unlike HashMap since, on map.get(null) returns null, it is not sure, if null is mapped to null value or if null is not mapped. In HashMap it is allowed since we can use contains() call to check it it has value, but in concurrent Map values can changes in between API calls so null isn't allowed.
- No guarantee on operation times, can be O(Log(N)) sometimes during collision.(Trees used instead of linked list).
- Multiple operations are not atomic. Will still need to use synchronized/ Atomic Types sometimes.
  - Say we are trying to run the following method in multiple threads
  ```java

    static Map<String, Integer> orders = new ConcurrentHashMap<>();
    
    
    //Not thread safe
    static void processOrder(){
      for(String city : orders.keySet()){
        for(int i=0; i<50;i++){
          //The combination of below 2 operations are not atomic.
          Integer x = orders.get(city);
          //another thread can overwrite city's value before we are going to write to it.
          orders.put(city, x+1);
        }
      }
    }
  ```

  This causes synchronization issues, one easy fix is to just write get and put in synchornized block, instead for incrementing it you can use AtomicInteger.getAndIncrement() operation which is more performant and also atomic.
  ```java
  static Map<String, AtomicInteger> orders = new ConcurrentHashMap<>();
    
    
  //thread safe
  static void processOrder(){
    for(String city : orders.keySet()){
      for(int i=0; i<50;i++){
        //Atomic operation.
        orders.get(city).getAndIncrement();
        
      }
    }
  }
  ```
  ### You can also deal with such situation using replace API on concurrentHashMap which will update the hashMap with newValue only if the oldValue matches the currentValue.
  ```replace(K key, V oldValue, V newValue)```



## LinkedHashMap
- ### It is similar to hashMap, but with Iteration guaranteed to be in order of insertion order.
- Maintains a doubly linked list to keep track of insertion order.

## TreeMap
- Iteration is ordered according to natural sorted order
- ### Keys should implement Comparable if they are Custom Object. Else exception will be thrown.(ClassCastException). You can instead pass a custom comparator in constructor.
- Uses red-black tree to make sure bst is balanced.
- Also implements methods which returns the closest match to the key.
- Log(N) is complexity
- Implementation of SortedMap and NavigableMap Interfaces

## ConcurrentSkipListMap
- A scalable concurrent implementation of SortedMap and ConcurrentNavigableMap
- This is equivalent of TreeMap in concurrent world.
- Guarantees O(Log(N)).
- Parallel reads are very rarely blocked, and writes only lock on segments. Just like ConcurrentHashMap
- Keys sorted on natural order.

## IdentityHashMap
- Instead of .equals method, it uses "==" operator to check implement reference equality.
- not synchronised
- Uses System.identityHashCode(key) instead of key.hashCode().
- ### The memory footprint is smaller than HashMap since there are no Entry/Nodes, this is useful incase of dealing with interned strings, since all strings which are equal refer to same object unless created using new.

## EnumMap
- Takes enum as a key
- Null key is not permitted 
- not synchronised
- ### Does not fail-fast. Won't cause ConcurrentModificationException
### ConcurrentModificationException
- It happens when a read is happening from a Map, and if the currentThread/ someOtherThread is also trying to write to the map, the ConcurrentModificationException comes.
- #### It can also come in single threaded application
  ```java
  Map<String,Integer> m = new HashMap<String,Integer>();
  m.put("user1",2);
  m.put("user2",2);
  m.put("user3",2);
  Iterator<String> iter = m.keySet().iterator();
  while(iter.hasNext())
  {
      iter.next();
      m.put("user7",6);
  }
  //Causes Exception, won't cause exception in case of EnumMap.
  ```

## WeakHashMap
- Elements in weak hashmap can be reclaimed by the garbage collector. The weak hashmap has the weak reference to the object, and if there are no other strong reference to the object then garbage collector will destroy that item.
- Uses in case of lookup/cache. As the lifetime of cache entries are determined by external refernces to the key.

## SynchronizedMap
- ### A convinient decorator to create a fully synchronized map.
- It is gonna make all the public methods synchronised and thus is similar to HashTable. 
- This is not recommended.



# JVM
[Link for video](https://www.youtube.com/watch?v=ZBJ0u9MaKtM&t=2s)
![JVM](res/JVM_java.PNG)
## Class Loader

![Class-Loader](res/class_loader_java.PNG)

## Runtime Data Areas
![Runtime Data Areas](res/method_heap_area_java.PNG)
![Runtime Data Areas](res/register_stack_java.PNG)

### Method Area / Perm Gen Space (JAVA-8 Metaspace) (Shared - Not Thread Safe) 
- (Shared - Not Thread Safe)
- class/static variables
- byte code
- class level constant pool
- ?reflection uses this area.
- #### Moved to metaspace in java 8, native OS Memory, as much memory/virtual memory as there is available for operating system.
- before java 8 -> (64 MB - Default) change using -XX:MaxPermSize, if low perm size you get java.lang.OutOfMemoryError:PermGen

### Heap (Shared - Not Thread Safe)
- (Shared - Not Thread Safe)
- Object data is stored.
- Every time you instantiate an object your object is stored in heap.
- Instance variables etc.
- Tuned using -Xms (Minimum) and -Xmx (Maximum)
- Default Xms is 1/4 of memory.

### PC Register (Isolated Per Thread) i.e Thread Safe
- Contains the Program counter, i.e pointer to the next instruction to be executed per thread, In image above T1 is program counter for thread 1.

### Java Stack (Isolated Per Thread) i.e Thread Safe
- Contains stack frame corresponding to current method execution per thread. In above image, T1 has 3 methods, method 1 calling method 2 and it calling method 3 in turn.
- local variables inside a method.
- operand stacks/ scratch area.
- parameters, return values.
- For each thread we have a unique stack.
- Depth controlled using -Xss. If too much stack then we get StackOverFlow Error.

### Native Method Stack (Isolated Per Thread) i.e Thread Safe
Suppose you are trying to load a dll, and calling a method inside that dll, we use Native Method Stack.

## Execution Engine
![Execution Engine](res/execution_engine_java.PNG)

### Interpreter
- Takes bytecode, looks at it and finds out what native operation has to be done and executes that native operation using Native Method Interface(JNI) and native methods are in .dll/.so files.
### Just in Time Compiler (JIT)
- JIT Compiler on the fly, compiles the repeated code (hotspots) (so they won't be interpretted again and again) to native machine code.
### Hotspot Profiler/VM
- It keeps the eye on bytecode that is running and identifies hotspots for use by the JIT Compiler.
### Garbage collector
- Cleans up unused classes, objects in memory areas.

### AOT Compiler
- The primary motivator behind using AOT in Java is to bypass the interpreter. It is generally faster for the machine to execute machine code than it is to execute the code via the bytecode interpreter.


# Garbage Collector
- Java provides automatic memory management using program management.
- Garbage collection is carried by a daemon thread called Garbage collector.
- We cannot force gc to happen (but calling System.gc() might trigger it).
- ```java.lang.outOfMemoryError``` heap space is full. Even with Garbage Collector you can have memory leaks.

## Types of garbage collections
- There are 2 types of garbage collections, minor(eden space) and major(across the heap).
- Both are stop the world garbage collection.

## Based on hypothesis
- Most objects soon become unreachable.
- Objects which are going to live an extending period of time usually don't refer to freshly created objects.

## Terminology
### Live Objects
- Reachable objects
### Dead Objects
- Unreachable objects

## Steps
### Mark
- Garbage collector walks through object graph, and marks reachable object as reachable.

### Sweep
- unreachable objects are deleted.

### Compaction
- arrange everything in order, defragmentation. Make allocation contigious. Takes time.

## Heap space division
- Java garbage collectors are generational collectors.
- Below is a diagram of heap.
![](res/generational_collectors.jpg)
### Young Generation
- Place where objects are created initially.

#### Eden Space
- The space where objects are created.

#### Survivor Space
- When eden space is full, a minor garbage collection kicks in and moves reachable objects from eden to survivor space.
- There are 2 survivor space.
- The below pic shows the state of the heap after the first cycle of minor gc.
![](res/gc_ani1.jpg)
- As time passes now more objects are added to eden space and some objects in survivor space become unreachable. And when eden space becomes full again, it triggers another minor gc across eden and survivor and are moved to survivor space 2.
![](res/gc_ani2.jpg)
- The presence of 2 survivors spaces is to avoid an additional compaction step.
- Similarly there is toggling/reordering of survivor spaces occurs in alternative minor gc cycle till a threshold is reached. At the end of that threshold all the survivor objects are moved to old/tenured generation.

### Old/ Tenured Generation
- Objects which survives for a long time.
- When old generation becomes almost full/reaches a threshold ```(-XX:MaxTenuringThreshold)``` we run major gc.
- Will block the application execution and is very heavy operation.



## GC Types based on implementation.

### Performace of GC
#### Latency
- How quickly an application responds with requested piece of data.
- How fast a website is loaded or how fast a query is returned.
- Application that requires high responsiveness, large pauses in time are not acceptable. 
#### Throughput
- Maximize the amount of work by application over a period of time.
- Batch Processing or total db queries in an hour.
- High pauses are acceptable. Since we focus on benchmarks over longer period of time.
- Based on above 

Based on the discussion above we should choose gc that is apt for us.

### Serial GC
- Single thread for all mark, sweep and compaction
- Stops the world at all steps.
- for basic application/ console apps.

### Concurrent GC (Low Latency GC)
- Performs GC along with application execution.
- Does not wait for old generation to be full.
- ### Stops the world only during mark/re-mark step.
- Application demands short pauses not long pauses.

### Parallel GC
- Uses multiple cores of CPU.
- Multiple thread doing mark/sweep/compaction.
- It doesn't run at the same time as application.
- ### (NOT SURE) The GC Actions stops the world at all steps but the execution is fast.
- Doesn't trigger till GC is near full.
- Application demands high throughput.

### G1 Garbage First GC (Java 9 onwards default)
- Tunable GC Pauses.
- Low pauses in fragmentation
- Parallelism and Concurrency Together
- Better heap utilization
- Divides the heap into small regions of memory, each of these region can be eden/survivor/tenured.
- It dynamically selects a region to act as young generation in the next gc cycle, Regions with most unreachable places will be collected first

![](res/gc_types.jpg)

You can configure the gc to use in the flag passed.
![](res/gc_flags.jpg)


## Finalize Method.
- This method is called when the object is garbage collected.
- But it is not recommended to put dbconnection.close kind of the important methods. Since the object can stay in heap for a long time and the dbconnection will be consuming the memory till that time. So better to remove expensive resources once you know you no longer need it.
- If you recreate the object during finalizer. The object is recreated and is not garbage collected, to avoid permanent object persistence there is a contract which says an object's finalizer can only be run once.

## Debug GC
- You can print details of gc using ```-Xloggc:gc.log```.
- jvisualvm

# String

- Backed by character array.
- It is immutable ```s1.toUpperCase()``` doesn't modify the string s1 but returns a new String with upperCase letters.
- Using code like ```String s = "This " + 20 + "is" + Boolean.valueOf(true)"; ``` was discouraged since these kinds of statements lead to creation of lots of intermediate String objects. This issue is no longer an issue since these statements are now implemented using StringBuilder.

## String Pool
- ### Strings are stored in a separate memory pool in permGen space(<Java 1.7) or main heap(>=Java1.8) called string pool. Each string you create is cached/interned if it is created using string literal.
  ```java
  //Creating string using a string literal. 
  String s1 = "Hello";  //Caches the s1 object.
  String s2 = "Hello"; //JVM, searches the permGen space to see if it already has "Hello" object, and returns its reference if it is found.
  ``` 
  Both s1 and s2 in above code point to same object. You can test this by checking ```s1==s2```.
- ### Strings created using new keyword/ constructor are not interned
  ```java
  String s1 = "Hello";
  String s2 = new String("Hello"); // Not gonna search for the cached string.
  System.out.println("are references equal? :" + (s1 == s2).toString()); //Prints false.
  ```
  s1 and s2 are not pointing to same object.


- ### You can explictly tell JVM to intern the object created using new by using intern keyword.
  ```java
  String s1 = "Hello";
  String s2 = new String("Hello").intern();
  s1 == s2 //prints true.
  ```

## Why Strings are immutable
- To preserve the strings cached in string pool, it is restricted to modify the string since that same string object might be being used in multiple other places and changing it will lead to unexpected results.
- By making it immutable, Strings are immutable.
- Since Strings are immutable, their hashcode are cached(inside object itself) and this improves performance.

## Useful Methods
### indexOf
- Used to find the index of substring.
- Use indexOf(substring, fromIndex) to find additional occurance of the substring. By default returns the first found index.

### lastIndexOf
- Find the last index of a substring in a string.

### contains
- boolean, if a given string contains a substrings.

### substring
- returns a new string which is a substring of the given string.
  ```java
    s1.substring(startIndex,endIndex);
  ```
- ### endIndex is non inclusive
- ### Pecular behavior of substring is that if startIndex/endIndex is too large it throws arrayIndexOutOfBounds Exception. But if the startIndex == length of string, it doesn't throw an exception just returns an empty string. 
- Till Java 1.7, substring operation was a source of memory leak. The substring method was actually storing the reference of the original string and was using offset parameter in String to return substring.

## Regular Expressions

### matches


### Find occurances of a pattern in a string using regular expression
```java
        String s = "HelloHelloafsdafa fasfasfasfHellohello";
        Pattern pattern = Pattern.compile("(H|h)ello");
        Matcher matcher = pattern.matcher(s);
        int occurances =0;
        while (matcher.find()){
            occurances++;
        }
        System.out.println(occurances); //Prints 4
```

## Good Practises
- If you are trying to compare 2 strings, one of which can be null(Maybe a return value from other function). Compare using the other String.
  ```java
  class Main{
    static final SUCCESS = "success";

    void process(){

      string s = getString(); // may return null
      if(SUCCESS.equal(s)){ //Instead of s!=null && s.equal(SUCCESS)
        ...
      }
      else{
        ...
      }

    }
    String getString(){
      return null;
    }

  }
  ```

- String is not a good way to store passwords, since string are created and cached in string pool for some time. Use a char array, and after you are done using the password, set char array elements to 0.


# StringBuffer
- mutable character array, similar to strings.
- synchronised implementation.


# StringBuilder
- not synchronised.
- Use stringBuilder when you want to concat large number of strings or do lots of changes to string.
## append
- Example ->
  ```java
    StringBuilder s = new StringBuilder("This ").append(20).append("is").append(true);
  ```
## concat



# Java Language Features
## Weak Reference
- If no other reference is available for the object pointed by weak reference, the object is marked for garbage collection.

## Soft Reference
- Like weak reference, but the garbage collection will wait till there is need to perform garbage collection, if heap is getting full.


## Annotations
- Special type of keyword used to embed instructions for JAVA Compiler
- Embed Instructions for source code processing tools
- Embed meta data which can be read at runtime by Java Application or third party tools
  - Spring etc.
  - Java library will access the annotation at runtime via Java Reflection.

### Where it can be used
- Above a / Infront of a
  - class declaration
  - member variable declaration
  - constructor
  - method
  - parameter
  - static method
  - static parameter

- Annotations are usually designed to be used with one of the above places, not all.

### Built-In Annotations
- @Override
- @Deprecated //Source code processing.
- @SuppressWarnings 

## User Input

- The Scanner.next()/ nextInt() won't consume the newline character so to use nextLine after nextInt you need to first consume newline by an additional nextLine.

- ```java 
  String text = new Scanner( source ).useDelimiter("\\A").next();
  ```
    One line, one class. The only tricky is to remember the regex ```\A```, which matches the beginning of input. This effectively tells Scanner to tokenize the entire stream, from beginning to (illogical) next beginning. As a bonus, Scanner can work not only with an InputStream as the source, but also a File, Channel, or anything that implements the new java.lang.Readable interface. For example, to read a file:

    ```java
    String text = new Scanner( new File("poem.txt") ).useDelimiter("\\A").next();
    ```

- you can accommodate a specific character set with Scanner example you can pass a charset to the constructor.



## Regex
![](res/regex.jpg)

# To read

- https://javarevisited.blogspot.com/2012/05/how-to-access-private-field-and-method.html
- https://stackoverflow.com/questions/596462/any-reason-to-prefer-getclass-over-instanceof-when-generating-equals
- https://javarevisited.blogspot.com/2011/04/top-10-java-serialization-interview.html
- https://javarevisited.blogspot.com/2015/10/133-java-interview-questions-answers-from-last-5-years.html
- https://javarevisited.blogspot.com/2012/07/when-class-loading-initialization-java-example.html#:~:text=When%20a%20class%20is%20initialized%20in%20Java,-After%20class%20loading&text=A%20Class%20is%20initialized%20in%20Java%20when%20%3A,method%20of%20class%20is%20invoked.