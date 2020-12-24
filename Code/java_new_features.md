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

# Functional Interfaces
- An interface with only a single abstract method. Can have multiple default implementations.
- Comparator interface is a functional interface

```java
public interface PrintInterface {
    void printMe(String message);
    default void sampleDefaultImplementation(){
        System.out.println("Just to show you can have
         default implementation inside the interfaces and still be called functional interfaces");
    }
}
```
## Built-In Functional Interfaces

### Consumer Interface
- Takes a single argument and returns no result.
```void accept(T t)```
- Powerful, Can write code like
```java
  List<Integer> list = List.of(1,2,3,4,56,78,8);
  list.forEach(System.out::println);
```

#### Chaining Consumers using andThen
- We can chain multiple consumer interfaces together to occur one after the other, say there is a list of strings and we want to first print them as is, and then print them in upperCase:
- andThen also returns another consumer so you can call andThen again and keep doing.
```java
  List<String> list = List.of("a", "b", "c", "d", "e");
  Consumer<String> print = System.out::println; //Method reference
  Consumer<String> printUpperCase = item -> System.out.println(item.toUpperCase(Locale.ROOT));
  list.forEach(print.andThen(printUpperCase).andThen(print));//
```

### Supplier Interface
- Takes no input and supplies a value.

```java
  Supplier<Double> randomGenerator = Math::random; //Method reference
  //Could also have done ()->return Math.random(); // lambda way
  System.out.println(randomGenerator.get());
```

### Function Interface
- Map a value to different Value.
```java
  Function<String, Integer> map = str -> str.length();
  System.out.println(map.apply("Happy new year"));
```
- Has an identity function, which returns itself.
```java
Function.identity() //m->m
```

### Composing Function Interface
```java
  Function<String, String> replaceColon = str -> str.replace(':', '=');
  Function<String, String> addBraces = str -> '{' + str + '}';

  Function<String,String> combinedFunction = replaceColon
                                              .andThen(addBraces);
  
  System.out.println(combinedFunction.apply("This is the sample string : Hello"));
```

### Predicate Interaface
- Takes a condition and returns a boolean to signify if the condition is true or false.
```java
  Predicate<String> isLongerThanFive = str -> str.length()>5;
  System.out.println(isLongerThanFive.test("Hello"));
```

# Lambda
- Functional Interfaces + Anonymous Classes + Syntanctic Sugar = Lambda Interfaces.
- Will return an instance/object of the anonymous class whose single non default abstract method's implementation is within lambda's implementation. 
- Lambda doesn't require the type of parameter.
- Lambda doesn't require the ```()``` brackets if there is a single parameter, only when there are no parameter or more than one parameter then it requires the ```()``` brackets
- Lambda also doesn't require the ```{}``` brackets if the body of the method contains a single statement.
- Return keyword is not needed in lambda, if it can be derived from context.
  ```java
    Printer p = x -> System.out.println(x);
  ```
  ```java
    SomeRandomInterface p = (x,y) -> {
      someRandomMethod(x);
      someOtherRandomMethod(y);
    }
  ```
- In the lambda expression, we can access the local variables in the enclosing method.
- We can access static fields in the enclosing class, if it is a static method, and both instance fields and static fields in case of non static methods.
- The value of this in lambda classes represent the current instance of the class containing the non static method which invoked the lambda.
- You cannot change the value of fields (local/static/instance fields) that you capture, inside the lambda.

## Method References : V.IMPORTANT
- The lambdas which can be implemented in a single line can also be replaced by a method reference.
- They can be very useful in spawning threads, see the example below.
- It is important to know a method reference is also a lambda expression so it creates an object of type functional interface.
  ```java
  PrintInterface p = System.out::println; 
  //same as Printer p = x -> System.out.println(x);
  ```
- Method reference is used to refer method of functional interface.
- It is compact and easy form of lambda expression.
- You can convert to method reference from intelliJ (Alt + Enter)
### There are following types of method references in java:
#### Reference to a Static Method
- ```ContainingClass::staticMethodName```
- Ex : ```System.out::println```
```java
public class MethodReference2 {  
    public static void ThreadStatus(){  
        System.out.println("Thread is running...");  
    }  
    public static void main(String[] args) {  
        Thread t2=new Thread(MethodReference2::ThreadStatus);  
        t2.start();       
    }  
}
```

#### Reference to an Instance Method
- ```containingObject::instanceMethodName```
```java
public class InstanceMethodReference2 {  
    public void printnMsg(){  
        System.out.println("Hello, this is instance method");  
    }  
    public static void main(String[] args) {  
    Thread t2=new Thread(new InstanceMethodReference2()::printnMsg);  
        t2.start();       
    }  
}  
```

#### Reference to a Constructor
- Tricky to understand, in the below example when the getMessage is invoked, it essentially creates a new object of Message Object.
- ```ClassName::new```
```java
interface Messageable{  
    Message getMessage(String msg);  
}  
class Message{  
    Message(String msg){  
        System.out.print(msg);  
    }  
}  
public class ConstructorReference {  
    public static void main(String[] args) {  
        Messageable hello = Message::new;  
        hello.getMessage("Hello");  
    }  
}  
```


## Differences between anonymous class vs lambda
### The value of this.
- In case of lambda, this represent the current instance of the class containing the non static method which invoked lambda.
- In case of anonymous classes, this represent the instance of the anonymous class.
### Instance fields
- We cannot have state inside the lambda expression, so there are no fields.
- Anonymous inner class can have state, and thus have instance fields.

```java
public class LambdaDemo {
    int x = 1;
    public void nonStaticShow(){
        greet(x -> System.out.println(x + this.x));

        greet(new PrintInterface() {
            int r = 2;
            @Override
            public void printMe(String message) {
                System.out.println(this.r);
            }
        });
    }

    public static void greet(PrintInterface printer){
        printer.printMe("Hello from Lambda Demo");
    }
}

```



# Streams
- Streams are wrappers around a data source, allowing us to operate with that data source and making bulk processing convenient and fast.

## Creating a stream

### Stream method of Collection interface
```java
Stream<Movie> streamInstance = collection.stream();
```

### Static method stream of the Arrays class
- Array instances don't have stream method like Collection instances, but arrays class has the static method stream().
```java
int[] arr = {1,2,3,4,5,6,7};
Arrays.stream(arr).forEach(System.out::println);
```

### Stream class's static ```of``` method
- You can create a stream of arbitrary number of items
```java
Stream.of(1,2,3,4,5,6,7).forEach(System.out::println);
```

### Infinite generation of streams using generator function

```java
Stream<Double> stream = Stream.generate(()->Math.random());
```
- The above method when used with forEach/map etc. will generate a stream of infinite numbers. 
```java
Stream.generate(()->Math.random())
      .forEach(System.out::println);
```
- You can limit the above generator to few numbers using ```limit()```
```java
Stream.generate(()->Math.random())
      .limit(100)
      .forEach(System.out::println);
```

- The above method allows you give any generator and not have all the items in memory and do a lazy evaluation.

### Infinite generation using iterate function
- Will use previous value to get the new value.
```java
Stream.iterate(1,x -> x+1)
      .limit(10)
      .forEach(System.out::println);
```

### Primitive Streams
- Use IntStream instead of Stream class for static factory methods like generate and iterate, because it is more performant
- Similarly we have DoubleStream and LongStream.

#### Range Method
- Generates a range of integers, end is exclusive
```java
IntStream.range(0,10).forEach(System.out::println);
```

## Types of stream methods
### Intermediate Operation
- filter, map, flatmap,limit, skip, sorted, distinct, peek

### Terminal Operation
- If you don't call terminal operation, nothing is done.
#### Reducers
- count
- max
- min
- anyMatch
- allMatch
- noneMatch
#### Collectors
- forEach, collect

## Transform values of stream

### Map
- Takes a ```Function Interface<V,U>```, which transforms a stream of type T to stream of type U.
```java
movies.stream()
      .map(x->x.getTitle())
      .forEach(System.out::println);
```

### FlatMap
- Used to flatten a Stream<Collection<Objects>> to a Stream<Objects>.
- FlatMap expects you to return the stream of flattened objects.
```java
List<List<Integer>> list = new ArrayList<>(List.of(
                new ArrayList<>(List.of(1,2,3,45)),
                new ArrayList<>(List.of(6,783,485)),
                new ArrayList<>(List.of(11,21,32,145))
        ));

list.stream()
    .flatMap(n -> n.stream())
    .forEach(System.out::println);
```
- To flatten nested levels of collection/array objects use flatMap multiple times as shown below.

```java
List<List<List<Integer>>> list = new ArrayList<>(List.of(
                                      new ArrayList<>(List.of(
                                          new ArrayList<>(List.of(1,2,3,45)),
                                          new ArrayList<>(List.of(6,783,485)),
                                          new ArrayList<>(List.of(11,21,32,145))
                                      )),
                                      new ArrayList<>(List.of(
                                          new ArrayList<>(List.of(1,2,3,45)),
                                          new ArrayList<>(List.of(6,783,485)),
                                          new ArrayList<>(List.of(11,21,32,145))
                                      ))
                              ));

list.stream()
    .flatMap(n -> n.stream()
                   .flatMap(m -> m.stream()))
    .forEach(System.out::println);
```

## Filtering stream
- simply returns a filtered stream of the same type. where objects satisfy the predicate supplied in the filter method.
```java
movies.stream()
      .filter(x->x.getLikes()>10)
      .forEach(x-> System.out.println(x.getTitle()));
```

## Slicing stream

### Limit, Skip
- Useful in pagination
- Say we want to display 10 items per page, we can do
```java
int pageSize = 10;
int pageNumber=3;
Stream.iterate(1,x->x+1)
        .skip((pageNumber-1)*pageSize)
        .limit(pageSize)
        .forEach(System.out::println);
```

### takeWhile and dropWhile
- takes/drops items from the stream till the condition is true and the drop/takes the rest.

## Order/sort the items of stream

### Default compareTo
```java
//list of integers
list.stream()
    .sorted()
    .forEach(System.out::println);
```

### Custom Comparator

```java
//list of integers
list.stream()
    .distinct()
    .sorted((x,y)-> (int)(1.1*y-x))//Custom comparator
    .forEach(System.out::println);
```


## Unique value only
### Distinct method
```java
list.stream()
    .distinct()
    .sorted((x,y)-> (int)(1.1*y-x))//Custom comparator
    .forEach(System.out::println);
```


## Peek Method
- Intermediate Function, usually used for debugging.

```java
list.stream()
    .flatMap(l->l.stream())
    .peek(m-> System.out.println("flatMap : " + m))
    .distinct()
    .peek(m-> System.out.println("distinct : " + m))
    .sorted()
    .peek(m-> System.out.println("sorted : " + m))
    .forEach(System.out::println);
```

## Optional Class
- Represent an object which may or maynot have a value.
- You need to call the get method of the optional to get the value.

### get
- If a value is present, returns the value, otherwise throws NoSuchElementException.
- Be careful since an exception is thrown if there is not valid value.
```java
System.out.println(l.stream().findFirst().get());
```

### isPresent()
- Returns true if the value is present.
```java
System.out.println(l.stream().findFirst().isPresent());
```

### ifPresent(Consumer<? super T>)
- Runs the code in consumer if the value is present

### ifPresentOrElse(Consumer<? super T>, Runnable)
```java
l.stream().findFirst().ifPresentOrElse(System.out::println,()->System.out.println("Value is not present"));
```



## Simple Reducers

### Count
- Return the number of elements in stream, returns Long

### anyMatch
- Returns a boolean if any element in the stream which matches the condition. Takes predicate as input

### allMatch
- Returns true if all element in the stream, matches the given condition. Takes predicate as input

### noneMatch
- Returns true if none of the elements in the stream matches the given condition.

### findFirst / findAny
- Returns an Optional describing the first element of this stream, or an empty Optional if the stream is empty. If the stream has no encounter order, then any element may be returned.

### max/ min
- Returns the maximum element of this stream according to the provided Comparator. Also returns an Optional
```java
        System.out.println(movies.stream().max((x,y)->x.getLikes()-y.getLikes()).get().getTitle());
        //System.out.println(movies.stream().max(Comparator.comparing(Movie::getLikes)).get().getTitle());
```

## General Purpose reduce
- We can use ```reduce``` to perform any general reduce operation on the stream of objects, like add them all or multiply them etc.
- ```reduce``` returns an optional, because sometimes there can be empty stream.
```java
int t = list.stream().reduce((x,y)->x+y).get();
```
- There is an overloaded reduce which takes an initial value, but returns an actual object rather than optional.
```java
int t = list.stream().reduce(2,Integer::sum);
```


## Collectors Class
- Implement various useful reduction operations, such as accumulating elements into collections, summarizing elements according to various criteria, etc.
- Can also join strings by a delimitter
- If we want to collect the objects of a stream into a datastructure like List or Set etc.

### Convert to List
```java
List<Movie> filterList = movies.stream().filter(movie -> movie.getLikes()>15).collect(Collectors.toList());
```

### Convert to Set
```java
Set<Movie> filterSet = movies.stream().filter(movie -> movie.getLikes()>15).collect(Collectors.toSet());
```

### Convert to Map
```java
Map<String, Integer> filterMap = movies.stream().filter(movie -> movie.getLikes()>15)
.collect(Collectors.toMap(Movie::getTitle, Movie::getLikes));
```

### Summing to Int
```java
movies.stream().collect(Collectors.summingInt(Movie::getLikes));
```

### Summarizing the statistics 
- Returns the following statistics 
- IntSummaryStatistics{count=3, sum=60, min=10, average=20.000000, max=30}
```java
movies.stream().collect(Collectors.summarizingInt(Movie::getLikes))
```

### Joining values using delimitter (IMPORTANT)
- returns a string with all concatenated items in string.
```java
movies.stream().map(Movie::getTitle).collect(Collectors.joining(" , "));
```


### groupingBy
- ```Map<groupingAttribute, Collector>```, default collector (downstream collector) is list, collector can be any of the above, counting, set, mapping etc. 
```java
//group Map<Genre, List of Movies>
var s1 = movies.stream().collect(Collectors.groupingBy(Movie::getGenre));

//group Map<Genre, Set of Movie>
var s2 = movies.stream().collect(Collectors.groupingBy(Movie::getGenre, Collectors.toSet()));

//group Map<Genre, Number Of elements in this group>
var s3 = movies.stream().collect(Collectors.groupingBy(Movie::getGenre, Collectors.counting()));

//group Map<Genre, Concatenated String of movie name>
var s4 = movies.stream().collect(Collectors.groupingBy(Movie::getGenre,
                                 Collectors.mapping(Movie::getTitle,
                                 Collectors.joining())));
```

### partition items
- Similar to group by, but partition based on a condition rather than a attribute value.
- In both groupingBy and paritionBy and mapping we can provide downstream collectors, which perform additional actions on top of the collected value.
```java
//partition Map<Boolean, List of movies>
Map<Boolean, List<Movie>> s = movies.stream().collect(Collectors.partitioningBy(m->m.getLikes()>10));

//partition Map<Boolean, Concatenated String of movie name>
Map<Boolean, String> s2 = movies.stream().collect(Collectors.partitioningBy(m->m.getLikes()>10,
                                                  Collectors.mapping(Movie::getTitle,
                                                  Collectors.joining(","))));

```


