# To print for debugging in Java
- Override the toString.
- ### To print Arrays just use 
  ```java
  System.out.println(Arrays.toString(arry));
  ```
- Collections would have inbuilt implementation of toString so they will be printed as usual.

# Conversions
- Streams API can be very useful for conversions
  - All Collections have an instance method ```list.stream()``` to convert to stream
  - To convert arrays to streams, use ```Arrays.stream(arr)```
- Opposite of ```boxed()``` is ```mapToInt(i->i)```
- ### ```toArray()``` can be used to convert List/Stream to Array. The toArray List/Stream requires a generator Function when dealing with Objects like Integer ```(Integer[])arrayList2.toArray(Integer[]::new);```
  - The Above method reference can also be replaced by a lambda ```value -> new Integer[value]```
- ```Arrays.asList(arr)``` can be Used to convert ArrayList to Object Array, but keep in mind you still need to call the constructor of ArrayList
## Convert from Primitive Arrays to ArrayList (IMPORTANT)
```java
ArrayList<Integer> arr = 
(ArrayList<Integer>)Arrays.stream(primitiveArray2).boxed().collect(Collectors.toList());
```

## Convert from Object Arrays to ArrayList (IMPORTANT)
```java
ArrayList<Integer> convArrayList2 = new ArrayList<>(Arrays.asList(objectArray2));
```
```java
ArrayList<Integer> convArrayList3 = 
(ArrayList<Integer>) Arrays.stream(objectArray2).collect(Collectors.toList());
```

## Convert from primitive Array to Integer Array
```java
Integer[] convIntegerArray = (Integer[])Arrays.stream(primitiveArray2).boxed().toArray(Integer[]::new);
```

## Convert from Object Array to Primitive Array
```java
int[] convIntArray = (int[]) Arrays.stream(objectArray2).mapToInt(i->i).toArray();
```

## Convert from ArrayList to Integer Array
```java
Integer[] convIntegerArray = (Integer[])arrayList2.toArray(Integer[]::new);
```

## Convert from ArrayList to Primitive Array
```java
int[] convArrayListToIntArray = (int[]) arrayList2.stream().mapToInt(i->i).toArray();
```

## Convert String to String Builder
```java
StringBuilder sB = new StringBuilder(s);
```

## Convert String Builder to String
```java
stringBuilder.toString()
```

## Convert a String to Character Array
```java
char[] charArray = s.toCharArray();
```

## Convert a Character Array to String
```java
String x = new String(charArray);
```

## String to Integer
```Integer.valueOf("123")```;

## String to Int
```Integer.parseInt("123)```

# Sorting an Array

# Sorting a Collection

# Reversing a Collection

# Searching an Array Binary Search

# Searching a Collection Binary Search

# Arrays
- length : ```arr.length``` (It's a property not a method)

## Wherever possible use Plain Arrays since they are easy to dereference, but you loose on printing and other convertion.

## Setting is simple
```java
int a[2] = 2;
```

## Removing at i index
- Create a new array and copy and don't copy ith element.
- Use Streams
```java
//Removing the item at i'th index from an Array
int[] arr = {1,2,3,4,5,6,7};
//Remove item at 3rd index i.e 4
ArrayList<Integer> arrayList = (ArrayList<Integer>) Arrays.stream(arr).boxed().collect(Collectors.toList());
arrayList.remove(3);
arr = arrayList.stream().mapToInt(i->i).toArray();
System.out.println(Arrays.toString(arr));
```

# ArrayList in Java
- Add at the end
  ```arr.add(Obj)```
- Add the beginning
  ```arr.add(0,Obj)```
- Add at idx
  ```arr.add(idx,Obj)```
- Get
  ```arr.get(idx)```
- Find
  ```arr.indexOf(Obj)```
  ```arr.contains(Obj)```
- SubList
  ```arr.subList(start_indx, end_idx_exclusive)```
- Update
  ```arr.set(idx,Obj)```
- Remove
  ```arr.remove(idx)``` (Remove idx)
  ### ```arr.remove(Integer.valueOf(1))``` (Remove first occurance of 1)
- ### Remove all Occurances
  ```arr.stream().filter(x->x!=1).collect(Collectors.toList())```

## To dereference a value in ArrayList
- Don't use []
```java
list.get(idx);
```

## Initialize an ArrayList with a specific size and default value
```java
List<Integer> list = new ArrayList<>(Collections.nCopies(num, default_val)); 
```

# LinkedList in JAVA
- Add at the end 
  - ```list.add(Obj)```
  - ```list.addLast(Obj)```
- Add at the beginning
  - ```list.add(0,Obj)```
  - ```list.addFirst(Obj)```
- Insert in middle
  - ```list.add(idx,Obj)```
- Pop at the front
  - ```list.remove(0)```
  - ```list.removeFirst()```
- Pop at the back
  - ```list.remove(list.size()-1)```
  - ```list.removeLast()```
- Remove from middle
  - ```list.remove(idx)```
- Remove an Object
  - ```list.remove(Obj)```
- Update at index
  - ```list.set(idx,1)```
- Get at first
  - ```list.getFirst()```
  - ```list.get(0)```
- Get at last
  - ```list.getLast()```
  - ```list.get(list.size()-1)```
- Get and remove first
  - ```list.pollFirst()```
- Get and remove last
  - ```list.pollLast()```

# HashMap in Java
- Check if a key exists
  ```map.containsKey(key)```
- Insert/Update a Key and Value
  ```map.put(Key, Value)```
- Remove a Key
  ```map.remove(Key)```
- Get a Key
  ```map.get(Key)```

# HashSet in Java
- Add in HashSet
  ```set.add(Obj)```
- Check if a Obj exists
  ```set.contains(Obj)```
- Remove from HashSet
  ```set.remove(Obj)```

# Priority Queue in JAVA
- Add in Priority Queue
  ```pq.add(Obj)```
- See the top element
  ```pq.peek(Obj)```
- Remove the top and return it's value
  ```pq.poll(Obj)```
- Removes a single instance of specified instance from the queue
  ```pq.remove(Obj)```
- Decrease key operation
  - First remove the old Obj and insert the updated value.

# String
- ### Remove all occurrences of char from string
  ```s.replace('x','');```
- ### Length ```s.length()```
- Convert to char[] ```s.toCharArray()```
- ```"Java".compareToIgnoreCase("JAVA")```
- ```str.toUpperCase()```

## To dereference a character from string or string builder
- Don't use []
```java
char c = str.charAt(idx);
```

## Set a character in string
```java
//Convert to String Builder
StringBuilder sB = new StringBuilder(s);
sB.setCharAt(idx,val);
```

## Split for delimitting
- Will return a String[]
- ### take care of empty strings since they can be source of lot of bugs.
  ```java
  String str = "Hello";
  String regex = "l";
  str.split(regex); //["He", "", "o"]
  ```

## Regex Matching
  ```java
  "Java".matches("[a-zA-Z].v.");
  ```

## substring() 
-  is used to create a substring from this string.

  ```java
  str.substring(start_idx, end_idx_non_inclusive)
  ```

## Check if a string is substring
```java
str.contains(substring);
```

## Index Of
  - Return the first Index of character ```"Java".indexOf('a')```
  - Return the index of first occurance of substring ``` "Java".indexOf("av")```
  - Returns the index of first occurance of character after index idx ```"Java".indexOf('a', 2)```
  - Returns the index of first occurance of substring after index idx ```"Java".indexOf("av", 2)```


# String Builder

# Random in JAVA

# Math in JAVA

# Graph Problems in JAVA

# Binary Search in JAVA
