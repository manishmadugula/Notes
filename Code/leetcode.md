# Tips

- To get faster run-time (in case of lots of i/o bound input) add ios_base::sync_with_stdio(false); cin.tie(null). [Read](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull) on when to use;
- To get an idea of overflow solve - [link](https://leetcode.com/problems/reverse-integer/)


- check overflow
  ```c++
  
  bool check_overflow_add(int x, int y) {
	//Case x is +ve y +ve
	if (x > 0 && y > 0){
		if (x > INT_MAX - y) return true;
	}
	else if (x < 0 && y < 0){
			if (x < INT_MIN - y) return true;
	}
	return false;
    }	


  bool check_overflow_multiply(int x, int y) {
      if (x < 0) x = -1 * x;
      if (y < 0) y = -1 * y;
      if(x == 0 ) return false;
      if (y > INT_MAX / x) return true;
      return false;
  }

  ```

- Questions like find the third max number (in 1,2,2,3) max is 3.
  - Use a set(bst) in c++ cause it is sorted and takes care of duplicates. [link](https://leetcode.com/problems/third-maximum-number/)
  - If duplicates are allowed use a priority queue. [link](https://leetcode.com/problems/kth-largest-element-in-an-array/)

- Sometimes bruteforce is the best solution - [link](https://leetcode.com/problems/can-place-flowers/)


- Sieve of Eratosthenes (To find all the prime numbers less than n). In this method, you first set the prime value ofall numbers to be true. Then, for a variable i starting from 2 to the square root of limit(the number given), you set the value of prime of all the multiples of i to be false.

    ```c++
    int countPrimes(int n) {
        if(n ==0) return 0;
        if(n == 1) return 0;
        if (n == 2) return 0;
        if (n == 3) return 1;
        vector<int> v(n+1,0);
        v[0] = 1;
        v[1] = 1;
        for(int i=2;i<sqrt(n);i++){
            for(int j=i+i;j<=n;j=i+j)
                v[j] = 1;
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(v[i] == 0) count++;
        }
        return count;
        
    }
    ```

Now, all the numbers left whose prime value is true are prme numbers and can be displayed.

- Time complexity for a sqrt function is log(n);
  ```
  1) Start with ‘start’ = 0, end = ‘x’,
  2) Do following while ‘start’ is smaller than or equal to ‘end’.
      a) Compute ‘mid’ as (start + end)/2
      b) compare mid*mid with x.
      c) If x is equal to mid*mid, return mid.
      d) If x is greater, do binary search between mid+1 and end. In this case, we also update ans (Note that we need floor).
      e) If x is smaller, do binary search between start and mid
    Note: The Binary Search can be further optimized to start with ‘start’ = 0 and ‘end’ = x/2. Floor of square root of x cannot be more than x/2 when x > 1.
  ```

- c++ strings are mutable.

- vector's iterator are bidirectional
- list's iterator can't move in ++ or --.
- umap's iterator can't move in ++ or --.
- pair is very useful when you want a container for 2 data types without writing an additional class for it.
  - First element is stored as "first"
  - second as "second"
  - You can create one as {first_int, second_int} too;
- You can insert into a unordered_map<int,pair<int,int>> as
  ```c++
  umap[key] = {val1,val2};
  ```
- it is helpful to use _ before name for member variables.
- Use typedef for long names.


# Dynamic Programming
- Unique Path - 2
  - You can just create an additional row and column to deal with boundary case and that will simplify the implementation a lot.


# STL Containers

## Iterators

## Vector

### Iterators (Random Access Iterators)
- Iterator to the beginning ```v.begin()```
- Iterator to the past-the-end  ```v.end()```
- Iterator to the i index ```v.begin()+i```
- ### **You can perform addition in these iterators like it+3 because it is random access iterator** 


### Get 
- Value from the index - O(1) ```v[1];```
- Iterator from index - O(1) ```v.begin()+i``` 
- Value from iterator ```(*it)```
- Size ```v.size()```

### Add

Single element

- ```v.push_back()```
- In middle using the iterator(before which to insert) ```v.insert(it,val)```
- There is no push front.

Multiple element
- ```c++
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);
  ```
  
### Erase

- To clear all the elements ```v.clear()```
- To erase an element using iterator ```v.erase(it)```
- To erase a range of elements using iterator ```v.erase(it_first, it_last)```
- Remove from the end ```pop_back()```
- There is no pop front.

### Modify
 Single Element

- ```v[index] = val```
- #### Using iterator ```(*it) = val;```

Multiple elements
- ```c++
  std::vector<int> first;
  first.assign (7,100); / 7 ints with a value of 100
  ```

### Initialize

- Fill with a value ```vector<int> v(size,val)```

## Unordered Map
## **IMP -> YOU CANNOT CREATE A MAP OF A MAP (Map as key) (Group Anagrams) by ```unordered_map<unordered_map<string,int>,int> umap();```**
### Iterator (Useful for looping through elements)

- **Notice that an unordered_map object makes no guarantees on which specific element is considered its first element.**
- Iterator to the beginning ```v.begin()```
- Iterator to the past-the-end  ```v.end()```

### Get

- Value from key - O(1) ```v[key]```
- Iterator from key - O(1) ```v.find(key)```
- Value from iterator ```it->second``` or ```(*it).second``` since map contains Pair objects.
- Key from iterator ```it->first```  or ```(*it).first```

### Add
- ```umap.insert(make_pair(1,1))```

### Erase
- To clear all the elements ```v.clear()```
- **To erase by key ```mymap.erase ("France");```**
- To erase an element using iterator  ```mymap.erase ( mymap.begin() );```
- To erase a range of elements using iterator ```mymap.erase ( mymap.find("China"), mymap.end() );```

### Modify
- ```umap[key] = value```
- Using iterator ```it->second = value```


## List (Doubly linked list)

### Iterator (Bidirectional Iterators)
- get the iterator to the head ```l.begin()```
- get the iterator to the back ```l.end()```
- ### **You cannot perform addition in these iterators like it+3 only it++ or it-- because it is bidirectional iterator.**

### Get
- get the front element ```l.front()```
- get the back element ```l.back()```
- (*it)
- ### To get value at an index - Important
  ```c++
  auto it = l.begin();
  advance(it,index);
  (*it)
  ```


### Add
- To add at the front ```l.push_front(val)```
- To add at the back ```l.push_back(val)```
- ### To add in the middle ```l.insert(it,val)```

### Erase
- To clear all the elements ```l.clear()```
- **To erase an element using iterator ```l.erase(it)```**
- To erase a range of elements using iterator ```l.erase(it_first, it_last)```
- To remove the last element ```l.pop_back()```
- To remove the first element ```l.pop_front()```
- **Removes from the container all the elements that compare equal to val. ```l.remove(val)```**
- ### The remove is O(N) but erase is O(1) so be careful when to use what. 
- remove if a condition is met ```l.remove_if(condition)```


### Modify

Multiple Elements
- ```c++
  std::list first;
  first.assign(10,100);
  ```

### Useful Function
The reason these algo are the part of this class and not stl algorithm is because the iterator in list is a bidirectional iterator and stl algo like sort and reverse don't work in them.
- ### ```l1.merge(l2)```
- ### ```l.reverse()```  -> Important
- ### ```l.sort()```  -> Important
- ### ```l.unique()``` -> Important
## Priority Queue
### **By default min queue. If you want max queue.**
```c++
std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
```
### Get
- top of the queue -> pq.top()
- size of the queue -> pq.size()
### Add
- pq.push()

### Erase
- pq.pop()

## Stack

### Get

### Add

### Erase

### Modify

## Ordered Map

### Get

### Add

### Erase

### Modify


## Queue (Use List rather than this.)

## Misc
- Difference b/w queue, list and deque
  - queue can only add at the back. and remove at front.
  - deque (Double ended queue) can add and remove at front and back.
  - list can add and remove anywhere.
  - A list has to allocate memory every single time something is added, and deallocate it when it goes away.
  - A deque, on the other hand, allocates in chunks. It will allocate less often than a list. Think of it as a list, but each memory chunk can hold multiple nodes. 
- forward_list is a singly linked list. where as list is a doubly linked list.
- 1 and 7 are the only happy numbers.



# Important Questions

- LRU Cache
  -  Use a hash<int,pair<int,list<int>>> and a queue(i.e a list).
  -  Use touch function to rearrange cache when necessary.
  
- https://leetcode.com/problems/jump-game/solution/
  - Read this article after solving the jump game question.