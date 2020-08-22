# ArrayList
- Dynamic resizable array
- To initialize like c++ vector use ```Collection.ncopies()```.
```java
ArrayList<Integer> v = new ArrayList<>(Collections.nCopies(10,0));
```
## Common Methods
- add
- set
- get





# Vector
- Synchronised ArrayList
- Less performant.



# Collection Methods
## Collections.binarySearch(v,6)

binarySearch will returns:

  - index of the search key, if it is contained in the list; otherwise, (-(insertion point) - 1).
  - The insertion point is defined as the point at which the key would be inserted into the list:
    - the index of the first element greater than the key,
    - or list.size(), if all elements in the list are less than the specified key.
  - Note that this guarantees that the return value will be >= 0 if and only if the key is found. 



## Collections.sort(v)
  - To sort complex objects, override compareTo method in the class defination.
## Collections.reverse(v)
