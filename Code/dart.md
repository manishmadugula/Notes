# General
## Const
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

# List
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



## Misc
- ternary operator is an expression not a statement. if else is a statement.