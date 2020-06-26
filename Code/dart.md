# Dart

## Const
- const modifies *values*. You can use it when creating collections, like ```const [1,2,3]```, and when constructing objects like ```const Point(2,3)```. Here, const means that the object's entire deep state can be determined entirely at compile time and that the object will be frozen and completely immutable.
- a const variable is a compile-time constant.
- Const variables are implicitly final.
- Instance variables can be final but not const.
- If the const variable is at the class level, mark it static const.
 
## Final
- A final variable can be set only once.
-  Final instance variables must be initialized before the constructor body starts — at the variable declaration, by a constructor parameter, or in the constructor’s initializer list.
-  

## Strings
- **Concatenation works even on line breaks**
    ```dart
    var s1 = 'String '
    'concatenation'
    " works even over line breaks.";
    assert(s1 ==
        'String concatenation works even over '
            'line breaks.');

    var s2 = 'The + operator ' + 'works, as well.';
    assert(s2 == 'The + operator works, as well.');
    ```

- raw string ```var s = r'In a raw string, not even \n gets special treatment.';```
  

- multiline strings
  ```dart
    var s1 = '''
    You can create
    multi-line strings like this one.
    ''';

    var s2 = """This is also a
    multi-line string.""";
  ```

## List
- ### spread operator with null check.
  ```dart
    var list = [1, 2, 3]; 
    var list2 = [0, ...?list];
    assert(list2.length == 4);
  ```

- ### collection if
    ```dart
    var nav = [
    'Home',
    'Furniture',
    'Plants',
    if (promoActive) 'Outlet'
    ];
    ```

- ### collection for
    ```dart
    var listOfInts = [1, 2, 3];
    var listOfStrings = [
    '#0',
    for (var i in listOfInts) '#$i'
    ];
    assert(listOfStrings[1] == '#1');
    ```

## Functions
- Functions are objects with type Function which inherits from Object.
- Functions can be assigned to variables and passed to other function's arguments.
- **You can also call an instance of a Dart class as if it were a function. (Callable Classes).**


- **Type annotations isn't necessary for dart.** But recommended.
    ```dart
    isNoble(atomicNumber) {
    return _nobleGases[atomicNumber] != null;
    }
    ```
    is inferred as
    ```dart
    bool isNoble(int atomicNumber) {
    return _nobleGases[atomicNumber] != null;
    }
    ```

- **For one line function**
    ```dart
    bool isNoble(int atomicNumber) => _nobleGases[atomicNumber] != null;
    ```
    - => expr syntax is a shorthand for { return expr; }.
    - **Only an expression—not a statement—can appear between the arrow (=>) and the semicolon (;). For example, you can’t put an if statement there, but you can use a conditional expression.**

- **Anonymous Functions**
     You can also create a nameless function called an anonymous function, or sometimes a lambda or closure. 

    ```dart
    var list = ['apples', 'bananas', 'oranges'];
    list.forEach((item) {
    print('${list.indexOf(item)}: $item');
    });
    ```

- A function can have two types of parameters: required and optional. The required parameters are listed first, followed by any optional parameters. Optional parameters can be named or positional. **Flutter only uses named parameter.**

- **To define named parameters**,in a function, use {} inside function argument.
    ```dart
    void enableFlags({bool bold, bool hidden}) {...}
    ```

- **Cascade syntax**
  ```dart
    void main() {
    querySelector('#sample_text_id')
    ..text = 'Click me!'
    ..onClick.listen(reverseText);
    }
  ```
  The .. syntax in the preceding code is called a cascade. With cascades, you can perform multiple operations on the members of a single object.
  #### **Nested Cascade**
  ```dart
  final addressBook = (AddressBookBuilder()
      ..name = 'jenny'
      ..email = 'jenny@example.com'
      ..phone = (PhoneNumberBuilder()
            ..number = '415-555-0100'
            ..label = 'home')
          .build())
    .build();
  ```

- **You can define functions inside other functions**
    ```dart
    somefunction(){
        void printElement(int element) {
        print(element);
        }

        var list = [1, 2, 3];

        // Pass printElement as a parameter.
        list.forEach(printElement);
    }
    ```

- ### Lexical scope
    Dart is a lexically scoped language, which means that the scope of variables is determined statically, simply by the layout of the code. You can “follow the curly braces outwards” to see if a variable is in scope.

    ```dart
    bool topLevel = true;

    void main() {
    var insideMain = true;

    void myFunction() {
        var insideFunction = true;

        void nestedFunction() {
        var insideNestedFunction = true;

        assert(topLevel);
        assert(insideMain);
        assert(insideFunction);
        assert(insideNestedFunction);
        }
    }
    }
    ```
    Notice how nestedFunction() can use variables from every level, all the way up to the top level.

- ### VIMP ->**Lexical closures**
    - A closure is a function object that has access to variables in its lexical scope, even when the function is used outside of its original scope.
    - Functions can close over variables defined in surrounding scopes. In the following example, makeAdder() captures the variable addBy. Wherever the returned function goes, it remembers addBy.
    ```dart
        /// Returns a function that adds [addBy] to the
    /// function's argument.
    Function makeAdder(int addBy) {
    return (int i) => addBy + i;
    }

    void main() {
    // Create a function that adds 2.
    var add2 = makeAdder(2);

    // Create a function that adds 4.
    var add4 = makeAdder(4);

	assert(add2(3) == 5);
	assert(add4(3) == 7);
	}
	```


- You can also assign a function to a variable
    ```dart
    var loudify = (msg) => '!!! ${msg.toUpperCase()} !!!';
    assert(loudify('hello') == '!!! HELLO !!!');
    ```

## Operators
- **as**  (Typecast)
- **is**  (True if the object has the specified type)
  - The result of obj is T is true if obj implements the interface specified by T
- **is!** (False if the object has the specified type)
- **~/**  (Divide, returning an integer result)
- **await**
- **expr1 ?? expr2**  (If expr1 is non-null, returns its value; otherwise, evaluates and returns the value of expr2.)
- ?. (Just like a dot operator but left operand can be null)
  - foo?.bar selects property bar from expression foo unless foo is null (in which case the value of foo?.bar is null)

## For Loops
- Foreach methods in iterator
  ```dart
  arr.forEach((elem)=>elem.doSomething());
  ```
- Typical for - in loop
  ```dart
  for(var element in arr){
    element.doSomething();
  }
  ```
- Where
  ```dart
  candidates
    .where((c) => c.yearsExperience >= 5)
    .forEach((c) => c.interview());
  ```

## Class
### Mixin Based Inheritance
- https://medium.com/flutter-community/dart-what-are-mixins-3a72344011f3
-every class (except for Object) has exactly one superclass, but  a class body can be reused in multiple class hierarchies.

### Object's Type
```${a.runtimeType}```

### Object Initialization
- If you initialize an instance variable where it is declared (instead of in a constructor or method), the value is set when the instance is created, which is before the constructor and its initializer list execute.

### Constructors



- #### Typical
  ```dart
  Point(int x, int y){
    this.x = x;
    this.y = y;
  }
  ```

- #### Syntactic Sugar
  ```dart
  Point(this.x, this.y)
  ```


- #### Named Constructors
  ```dart
  Point.origin(){
    x = 0;
    y = 0;
  }
  ```

- #### Redirecting Constructors
  ```dart
  class Point.fromXAxis(double x) : this(x,0);
  ```

- #### Initializer List
  ```dart
  Point(int m, int n) 
    : x = m,
      y = n;
  ```
  - **Initializer lists are handy when setting up final fields.**

- #### Constructors aren’t inherited
  - Subclasses don’t inherit constructors from their superclass. A subclass that declares no constructors has only the default (no argument, no name) constructor.

- #### Default Order of execution of constructor
  - Initializer List
  - Superclass's no-argument constructor
  - main class's no-arg constructor

- #### Calling superclass's non-default constructor.
  ```dart
    Employee(Map data) : super(data) {
      print('in Employee');
    }
  ```  
  - Arguments to the superclass constructor do not have access to this. For example, arguments can call static methods but not instance methods.

- #### Constant constructor (If your class produces objects that never change.)
  - Make sure you have all instance vars as final.
  ```dart
  class ImmutablePoint {
    static final ImmutablePoint origin =
        const ImmutablePoint(0, 0);

    final double x, y;

    const ImmutablePoint(this.x, this.y);
  }
  ```
  - flutters stateless widgets can be all marked with const constructors.

- #### Factory Constructor
  A factory constructor allows you more control about what the constructor returns. It can return an instance of a subclass or an already existing (cached) instance.








### Methods

### Abstract Class
- Can't be Instantiated.
  ```dart
  // This class is declared abstract and thus
  // can't be instantiated.
  abstract class AbstractContainer {
    // Define constructors, fields, methods...

    void updateChildren(); // Abstract method.
  }
  ```

-  But if you want your abstract class to appear to be instantiable define factory constructor. Example where it might be useful.
    ```dart
    abstract class WidgetService {
      WidgetService _cached; 
        factory WidgetService(String type) {
          switch(type) {
            case 'a': return new ConcreteWidgetServiceA();
            case 'b': return new ConcreteWidgetServiceA();
            default: return _cached ??= new DummyWidgetServiceA();
          }
        }
        Widget getWidget();
        void saveWidget(Widget widget);
    }
    ```

### Implicit Interfaces
- Every class implicitly defines an interface containing all the instance members of the class and of any interfaces it implements. If you want to create a class A that supports class B’s API **without inheriting B’s implementation**, class A should implement the B interface.
- A class implements one or more interfaces by declaring them in an **implements** clause and then providing the APIs required by the interfaces. For example: ```class Point implements Comparable, Location {...}```

### Inheritance
- Use extends to create a subclass, and super to refer to the superclass

### Overiding an operator
```dart
class Vector {
  final int x, y;

  Vector(this.x, this.y);

  Vector operator +(Vector v) => Vector(x + v.x, y + v.y);
  Vector operator -(Vector v) => Vector(x - v.x, y - v.y);
}
```
- If you override ==, you should also override Object’s hashCode getter.
- You may have noticed that != is not an overridable operator. The expression e1 != e2 is just syntactic sugar for !(e1 == e2).


### Extension methods are a way to add functionality to existing libraries. 

### IMPORTANT -> Mixin Vs Interface Vs Inheritance (with vs implements vs extends)

#### Implements Is For Forcing Behavior Via Interface
In OOP, an interface is something that enforces the deriving class to implement a set list of public fields and methods.

But unlike other traditional programming languages like C# and JAVA, **Dart does not have explicit interface types.** **Each class, by default, defines its own interface composed of public fields and methods. So, every class can act as an interface in Dart.**

We use the implements keyword to implement an interface. Also, a class can implement multiple interfaces.

```dart
class A {
  doA();
}

class B{
  doB();
}

class C{
  doC();
}

class D implements A,B,C{
  ...
}
```

In the example above, class D implements classes A, B and C therefore it must implement the public methods and fields of those classes.

Furthermore, since Dart does not have explicit interfaces, we use the abstract class as an interface.

#### Extends Is For Sharing Behavior Via Inheritance

In OOP, inheritance implies sharing of behavior between classes. We can not share features with an interface. So, when we implement a class, we can not share it’s behavior. If you want to share the behavior across these two classes, you should use the extends keyword.

```dart
class A {
  doA() {
    print('A');
  }
}

class B extends A {  
}

main() {
  var b = B();
  b.doA();
}
```

Unlike implementing multiple interfaces, Dart only supports single inheritance. So, you can not extend from multiple classes.

#### With Is For Mixin
In OOP, a mixin is a class that contains methods for use by other classes. Unlike the interface and inheritance approach, a mixin doesn’t have to be the parent class of those other classes.

So a mixin neither imposes usage restriction nor forces type restriction.

```dart
mixin A{
  doA(){
    print("Mixin A");
  }
}

mixin B{
  doB(){
    print("Mixin B");
  }
}

class C with A,B{
  //override if you want to
  @override
  doA(){
    print("Overridden A");
  }

  //doB still can be called without implementing.
}
```

- A class can use multiple mixins.
- mixins declares no constructors. 
- In Dart, a class can also be used as mixin if the class is constructor-less. 
- You can also enforce a mixin to be usable for certain types classes only by using the the on keyword when defining the mixin.

  ```dart
  mixin Z on D {
    doZ() { }
  }

  class D {
    doD() {
      print('d');
    }
  }

  //Can't do this!
  class E with Z {

  }

  //Can do this!
  class F extends D with Z {

  }
  ```

#### Summary
- Implements for enforcing behaviors.
- Extends for sharing behaviors of single class.
- Mixins for sharing behaviors from multiple reusable types.

## Library
- identifiers that start with an underscore (_) are visible only inside the library.
- Every Dart app is a library, even if it doesn’t use a library directive.
- Libraries can be distributed using packages.  
- Use import to specify how a namespace from one library is used in the scope of another library. The only required argument to import is a URI specifying the library. 
- For built-in libraries, the URI has the special dart: scheme. eg-> ```dart:html```
- The package: scheme specifies libraries provided by a package manager such as the pub tool. eg-> ```package:test/test.dart```

### Specifying a Library Prefix.
If you import two libraries that have conflicting identifiers, then you can specify a prefix for one or both libraries. For example, if library1 and library2 both have an Element class, then you might have code like this:
```dart
import 'package:lib1/lib1.dart';
import 'package:lib2/lib2.dart'; as lib2

//lib1
Element elem = Element();

//lib2
lib2.Element elem = lib2.Element();
```

### Importing a part of library
```dart
//Only imports foo
import 'package:lib\lib.dart' show foo;
//Imports all but bar
import 'package:lib2\lib2.dart' hide bar;

```
## Misc
- ternary operator is an expression not a statement. if else is a statement.