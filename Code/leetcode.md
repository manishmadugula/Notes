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

- max of 3 numbers is max(max(a,b),c);

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

- Use vector instead of map in dealing with characters.
- Use vector instead of stack wherever possible.
  - vector.push_back (s.push())
  - vector.pop_back (s.pop())
  - vector.back() (s.top())
  - This trick is useful when dealing with string and you need to process them later. [Example](https://leetcode.com/problems/remove-k-digits/)

- ### IMPORTANT -> While sorting objects in c++
  - Remember to use the following constraint/requirement. The  compare requirement requires that If comp(a,b)==true then comp(b,a)==false. But if you write you  it returns true if b==a thus comp(b,a) == comp(a,b) which does not fulfil the requirement. 
    #### NOT CORRECT WAY
    ```c++
      //NOT CORRECT WAY
      if (da.x() > db.x())
          return false;
      else
        return true;
    ```

    #### CORRECT WAY
    ```c++
      //NOT CORRECT WAY
      return da.x()<db.x();
    ```
    - Refer https://stackoverflow.com/questions/2627166/difference-between-const-reference-and-normal-parameter
    - https://en.cppreference.com/w/cpp/named_req/Compare

## Traverse While Deleting

### Vector/ String
- Use erase-remove idiom (Optimized)
  - Motivation behind this idiom is in vector/ string calling erase multiple times on the same container generates lots of overhead from moving the elements.
  - So a solution is to use remove/remove_if which do not remove elements from the container, but move all elements that don't fit the removal criteria to the front of the range, keeping the relative order of the elements. This is done in a single pass through the data range.  remove returns an iterator pointing to the first of these tail elements so that they can be deleted using a single call to erase.
  - Doing the same using only erase results in as many passes as there are elements to remove. For each of these passes, all elements after the erased element have to be moved, which is more time-consuming than shifting elements in a single pass.
  - Can't be used for set
  ```c++
  v.erase(std::remove_if(v.begin(), v.end(), IsOdd), v.end());
  ```
- Using just erase (Not optimized)
  ```c++

  while(it!=v.end()){
    if(toDelete(it)){
      it = v.erase(it);
    }
    else{
      it++;
    }
  }
  ```
### Set/List
- Using just erase (Not optimized)
  ```c++
  while(it!=s.end()){
    if(toDelete(it)){
      it = s.erase(it);
    }
    else{
      it++;
    }
  }

# Dynamic Programming
- Unique Path - 2
  - You can just create an additional row and column to deal with boundary case and that will simplify the implementation a lot.

- Look at the Boolean Parenthesis problem.
  - Similar Problems
  - Valid Parenthesis String
  - Matrix Multiplication


# STL

## Strings


#### Iterators (Random Access Iterators)
- Iterator to the beginning ```s.begin()```
- Iterator to the past-the-end  ```s.end()```
- Iterator to the i index ```s.begin()+i```
- ### **You can perform addition in these iterators like it+3 because it is random access iterator** 

#### Get 
- Value from the index - O(1) ```s[1];```
- Iterator from index - O(1) ```s.begin()+i``` 
- Value from iterator ```(*it)```
- Size ```s.size()```'
- ### **Get iterator of a character in string ```std::find(s.begin(), s.end(), 'x')``` Remember it is a char not string.**
- ### Substring (Important)
  - ### ```s.substr(firstIndex,length)``` returns substring for [pos, pos+len).
  - ### ```s.substr(index)``` returns substring for pos to end.

#### Add

Single element

- In middle using the iterator(before which to insert) ```s.insert(it,val)```
- There is no push front.

Multiple element
- ```c++
  string x = "Manish";
  string y = "sdf"
  x.insert( x.begin() + 2, y.begin(), y.end());
  ```

- Add at the end or beginning.
- Use + operator ```s+x```

#### Erase

- To clear all the elements ```s.clear()```
- To erase an element using iterator ```s.erase(it)```
- To erase a range of elements using iterator ```s.erase(it_first, it_last)```
-  ## Very Important erase-remove idiom.
-  Look at vector explaination.

#### Modify
 Single Element

- ```s[index] = character_element```
- **Using iterator ```(*it) = val;```**




## Iterators

- Iterators are used to step through the elements of collections of objects. Offer a common interface for all the container types.
- Just like template make algorithm independent of datatype, iterator make algorithm independent of container type.
- Iterator actually denote a certain position in a container.

### Common Operations in iterator
- ``*Iterator`` -> Returns element of current position.
- ``Iterator++`` -> Returns next iterator
- ``Iterator1 == Iterator2`` or ``Iterator1 != Iterator2`` -> If 2 iterators points to same location.
- ``Iterator =`` -> assigns an iterator to the position of element it refers to.

### Iterator vs Pointer
- Iterator are not same as pointer, they can be thought of a special pointer which is designed for a specific container and can iterate efficiently for that container. Their internal behaviour is defined by the container over which they iterate. In fact each container defines its iterator type as a nested class. 

### The logic behind the half open range of iterator i.e [begin(),end())
- We have a simple end criterion for loops that iterate over the elements: They simply march through until they meet end().
- It avoids special case handling for empty ranges, where begin() == end().

### Types of Iterators (Important)

#### Input iterator
- The term input is used from the viewpoint of a program. Information going from the container to the program is considered input
- An input iterator is one that a program can use to read values from a container.
-  It does not allow us to alter the value. So algorithms that require an input iterator are algorithms that don't modify values of the container elements.


#### Output iterator
- They are just like input iterator but not for accessing elements, but for being assigned elements.
- Single-pass and write-only iterator.

#### Forward Iterators
- They are higher in hierarachy than input and output iterators, and contain all the features present in these two iterators.
- They also can only move in forward direction and that too one step at a time.
- Unlike input and output iterators, however, it necessarily goes through a sequence of values in the same order each time we use it

#### Bidirectional Iterator
- they can move in both the directions, that is why their name is bidirectional.

#### Random Access Iterator
 - They are the most powerful iterators. They are not limited to moving sequentially, as their name suggests, they can randomly access any element inside the container. They are the ones whose functionality is same as pointers.

![Iterator](res/iterator_functionality.PNG)

![Iterator](res/iterator.PNG)


### Functions on iterators
- ``dist(Iterator1, Iterator2)``
- ``advance(Iterator1, count)``
- **``prev(Iterator, count=1) ``Used in prev(container.end())**
- ``next(Iterator, count=1)``


### Misc
- Sort and binary search algorithm requires a random access so it can swap 2 non adjacent elements. So linkedlist iterator cannot be used. (That's why linked list provides a sort method in itslef)
- Find needs a ++ operator, it doesnot need a write access but needs a read access.
- You cannot do advance(container.begin(),12);
- You need to first assign container.begin() to a iterator and then use that iterator to advance.

- Compare iterator with a null, it is not straight forward. You need to do ``it != container.end()``


## Containers

### Vector

#### Iterators (Random Access Iterators)
- Iterator to the beginning ```v.begin()```
- Iterator to the past-the-end  ```v.end()```
- Iterator to the i index ```v.begin()+i```
- ### **You can perform addition in these iterators like it+3 because it is random access iterator** 


#### Get 
- Value from the index - O(1) ```v[1];```
- Iterator from index - O(1) ```v.begin()+i``` 
- Value from iterator ```(*it)```
- Size ```v.size()```'
- **Get item with a specific value** ```std::find(vec.begin(), vec.end(), item)```

#### Add

Single element

- ```v.push_back()```
- In middle using the iterator(before which to insert) ```v.insert(it,val)```
- There is no push front.

Multiple element
- ```c++
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);
  ```
  
#### Erase

- To clear all the elements ```v.clear()```
- To erase an element using iterator ```v.erase(it)```
- To erase a range of elements using iterator ```v.erase(it_first, it_last)```
- Remove from the end ```pop_back()```
- There is no pop front.
-  ## Very Important erase-remove idiom.
-  To erase multiple elements from an vector with a certain value, it is not recommended to use for loop and erase each element. Since this is a n^2 solution.
-  Instead we should use erase with stl's remove to get O(n) solution.
-   The way it works is first we call remove on the entire array. Remove doesn't erase the elements from array, it simply shifts the elements with the value to the end of the vector and returns the iterator to the tail of the remaining vector(non inclusive).
-   You can then call erase on the remaining part and erase by range.
-  ### ```v.erase(std::remove(v.begin(),v.end(),7), v.end())``` to erase all occurances of 7 from the vector. **This is called erase-remove idiom of c++**. It is also applicable for strings.

#### Modify
 Single Element

- ```v[index] = val```
- **Using iterator ```(*it) = val;```**

Multiple elements
- ```c++
  std::vector<int> first;
  first.assign (7,100); / 7 ints with a value of 100
  ```

#### Initialize

- Fill with a value ```vector<int> v(size,val)```

### Unordered Map

## **IMP -> YOU CANNOT CREATE A MAP OF A MAP (Map as key) (Group Anagrams) by ```unordered_map<unordered_map<string,int>,int> umap();```** -> You can get around by using a string representation of the map. Also holds for unordered_set

## **IMP -> YOU CANNOT CREATE A MAP OF A Pair of T (pair<T,T> as key) by ```unordered_map<pair<int,int>,int> umap();```** -> You can get around by using a string representation of the pair. Also holds for unordered_set

#### Iterator (Useful for looping through elements)

- **Notice that an unordered_map object makes no guarantees on which specific element is considered its first element.**
- Iterator to the beginning ```v.begin()```
- Iterator to the past-the-end  ```v.end()```

#### Get

- Value from key - O(1) ```v[key]```
- Iterator from key - O(1) ```v.find(key)```
- Value from iterator ```it->second``` or ```(*it).second``` since map contains Pair objects.
- Key from iterator ```it->first```  or ```(*it).first```

#### Add
- ```umap.insert(make_pair(1,1))```

#### Erase
- To clear all the elements ```v.clear()```
- **To erase by key ```mymap.erase ("France");```**
- To erase an element using iterator  ```mymap.erase ( mymap.begin() );```
- To erase a range of elements using iterator ```mymap.erase ( mymap.find("China"), mymap.end() );```

#### Modify
- ```umap[key] = value```
- Using iterator ```it->second = value```


### List (Doubly linked list)

#### Iterator (Bidirectional Iterators)
- get the iterator to the head ```l.begin()```
- get the iterator to the back ```l.end()```
- ### **You cannot perform addition in these iterators like it+3 only it++ or it-- because it is bidirectional iterator.**

#### Get
- get the front element ```l.front()```
- get the back element ```l.back()```
- (*it)
- ### To get value at an index - Important
  ```c++
  auto it = l.begin();
  advance(it,index);
  (*it)
  ```
- ### **To find if an element exist's in a list ```std::find(listOfElements.begin(), listOfElements.end(), element);```**


#### Add
- To add at the front ```l.push_front(val)```
- To add at the back ```l.push_back(val)```
- ### To add in the middle ```l.insert(it,val)```

#### Erase
- To clear all the elements ```l.clear()```
- **To erase an element using iterator ```l.erase(it)```**
- To erase a range of elements using iterator ```l.erase(it_first, it_last)```
- To remove the last element ```l.pop_back()```
- To remove the first element ```l.pop_front()```
- **Removes from the container all the elements that compare equal to val. ```l.remove(val)```**
- ### The remove is O(N) but erase is O(1) so be careful when to use what. 
- remove if a condition is met ```l.remove_if(condition)```


#### Modify

Multiple Elements
- ```c++
  std::list first;
  first.assign(10,100);
  ```

#### Useful Function
The reason these algo are the part of this class and not stl algorithm is because the iterator in list is a bidirectional iterator and stl algo like sort and reverse don't work in them.
- ### ```l1.merge(l2)```
- ### ```l.reverse()```  -> Important
- ### ```l.sort()```  -> Important
- ### ```l.unique()``` -> Important
### Priority Queue
#### **By default min queue. If you want max queue.**
```c++
std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
```
#### Get
- top of the queue -> pq.top()
- size of the queue -> pq.size()
#### Add
- pq.push()

#### Erase
- pq.pop()

### Stack

#### Get

#### Add

#### Erase

#### Modify

### Ordered Map

#### Get

#### Add

#### Erase

#### Modify


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

- https://leetcode.com/problems/binary-tree-maximum-path-sum/
  - Solution is elegant few lines.

- https://leetcode.com/problems/unique-email-addresses/submissions/
  - Solve this to get clarity of strings erase-remove idiom.

- https://leetcode.com/problems/majority-element/
  - Teaches the Boyer-Moore Voting Algorithm
  - ### Boyer-Moore Voting Algorithm
    - Explaination https://leetcode.com/problems/majority-element/solution/
    - For Diagram

- https://leetcode.com/problems/find-the-town-judge/
  - Teaches importance of

- https://leetcode.com/problems/cinema-seat-allocation/
  - Importance of looking at constraints and also bit masking

- https://leetcode.com/problems/cousins-in-binary-tree/
  - Important in knowing the tips for trees
  - https://leetcode.com/problems/cousins-in-binary-tree/discuss/238624/C%2B%2B-level-order-traversal
  - Tip - 1 -> Using nullptr to separate siblings from cousins.
  - Using 2 queues to keep track of levels.

- Boolean Parenthesis DP.
  - Different way of thinking bottom up.(Diagonal)

- https://leetcode.com/problems/flood-fill/
  - You don't need visited set.

- #### IMPORTANT https://leetcode.com/problems/maximum-sum-circular-subarray/
  - Tricky Question (Simple if you know solution).

- https://leetcode.com/problems/valid-parenthesis-string/
  - 3 Solution approaches
    - **2 Stack (best to think and implement). [Link](https://www.youtube.com/watch?v=KuE_Cn3xhxI)**
    - DP (Bad timecomplexity but good to know approach similar to boolean parenthesis). [Link](https://leetcode.com/problems/valid-parenthesis-string/solution/)
    -  **Simple solution (most efficient, hard to think like this) [Link](https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis)** 

- https://leetcode.com/problems/remove-k-digits/
  - Teaches efficient processing of strings.
  - trimming zeros and all.
  - Use vector instead of stack.

- https://leetcode.com/problems/bulb-switcher-iii/
  - Beautiful solution. Simple straight.

- https://leetcode.com/problems/online-stock-span/
  - Couldn't solve
  - Simple solution



# To-Do

- Monotone Queue
  - https://medium.com/@gregsh9.5/monotonic-queue-notes-980a019d5793
  -  Minimum Cost Tree From Leaf Values
  -  Sum of Subarray Minimums 907
  -  Online Stock Span 901
  -  Score of Parentheses 856
  -  Next Greater Element II 503
  -  Next Greater Element I 496
  -  Largest Rectangle in Histogram 84
  -  Trapping Rain Water 42
  -  Daily Temperatures 739

- Dynamic Programming Problems
  - https://leetcode.com/discuss/general-discussion/458695/Dynamic-Programming-Patterns

- Interview Questions
  - Min(Subset) + Max(subset) == k or < k
    - https://leetcode.com/discuss/interview-experience/637356/amazon-apple-facebook-l5-ict4-e5-seattle-april-2020-may-2020-offer-offer-offer
    - https://leetcode.com/discuss/interview-question/268604/Google-interview-Number-of-subsets
    - https://leetcode.com/discuss/interview-question/275785/facebook-phone-screen-count-subsets

  - Is Split Possible in an array
    - https://leetcode.com/discuss/interview-experience/637356/amazon-apple-facebook-l5-ict4-e5-seattle-april-2020-may-2020-offer-offer-offer
    - no constraints
    - splitted array has to be equal in size.
    - geek for geek variations.

  - Merge K Sorted Arrays



# Look at
- https://stackoverflow.com/questions/28138188/why-pass-by-value-and-not-by-const-reference
- https://medium.com/@gregsh9.5/monotonic-queue-notes-980a019d5793