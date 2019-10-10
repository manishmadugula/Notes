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
The Scanner.next()/ nextInt() won't consume the newline character so to use nextLine after nextInt you need to first consume newline by an additional nextLine.