# Notes

## Competitive Programming Tips

- **use #include<bits/stdc++.h> in competitive programming.**

- see the return type carefully,cast to long if long is expected.

- see constraints in question.

- Dynamic 2D array in cpp
    ```c++
    int** graph = new int*[n];
    for(int i=0;i<n;i++){
        graph[i] = new int[m];
    }
    ```
- ```int* m,n;``` makes m a pointer but n an integer. You need to do as following ```int *m,*n;```. 

- If you are iterating like below
    ```c++
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=i*j;
        }
    }
    ```
- it is better if you do.

    ```c++
    sum=0;
    ans=0;
    for(int i=0;i<n;i++){
        ans+=sum*i;
        sum+=i;
    }
    ```

- If you are asked about find the count of something -> You can optimize the time maybe in some way. No need to go ahead and find all the possible values.

- In cpp accumulate make sure you write the intializer as 0L not 0 if you are trying to sum up long values or else you will get integer overflow.

    ```c++
    accumulate(v.begin(),v.end(),0L);
    ```
- Hash function
  - FOR STRINGS
    ```c++
    unsigned long hashstring(char* str){
    unsigned long hash = 5381;
    int c;
    while(c = *str++){
        hash = ((hash << 5) + hash ) + c;
    }
    return hash%len(array);
    }
    ```

  - FOR INTEGER

    ```c++
    unsigned int hashint( unsigned int x){
    x = ((x>>16)^x)*0x45d9f3b;
    x = ((x>>16)^x)*0x45d9f3b;
    x = ((x>>16)^x);
    return x%len(array);
    }
    ```




- To find missing number in a random sequence of numbers ranging from 1 to N use XOR.

- Trie is better than hashing for string search when it comes to strings cause we don't have to deal with collision and also no hash fucnctiin needs to be calculated. Also we can print words in alphabetical order easily and do prefix search and auto complete with trie

- When crawling through linked list make sure first one is not null.
  
- When deleting tries Remember to make the child of parent 0 too. Else number of child will be wrong and also check if root exists or not.

- Advantages of BST over hash all keys are sorted by just doing inorder traversal. Doing order statistics, finding closest lower and greater elements and range queries,easy to implement.

- Check constraints to determine which datatype to use.

- **lower_bound returns the iterator of first element which is not less than the element specified.**

- **upper bound returns the iterator of the first element greater than the element specified.**

- distance returns the distance between 2 iterators.

- minimum/maximum among some elements
    ```c++
    min({131234,421,244}) //returns 244
    ```

- There is a difference between std::replace and std::string::replace normal replace can't be used with strings.

- To insert an element in a list(linked list) in cpp.
    ```c++
    list<int>::iterator it = list1.begin();
    advance(it,2);
    list1.insert(it, 4);
    ```

- You can't use std::sort to sort std::list, because std::sort requires iterators to be random access, and std::list iterators are only bidirectional. However, std::list has a member function sort that will sort it.

- In c++ pop operation doesn't return a value.

- Instead of front a stack and priority_queue in cpp has top i.e stack1.top() or pq.top() to access the topmost element.

- greater<int> and less<int> can be passed as a function object in comparator field in priority_queue constructor.
    ```c++
    priority_queue<int,vector<int>,greater<int>> minheap;

    priority_queue<int,vector<int>,less<int>> maxheap; // default
    ```

    You can also create a custom comparator and pass that to the above constructor.
    ```c++
    struct CustomCompare{
        bool operator()(int x,int y){
         return x>y;
        }
    };
    ```
    ```c++
    priority_queue<int,vector<int>,CustomCompare> minheap;
    ```

- Priority Queues are limited cause we can't access the element except the ones at the top. So we can use stl's heap algorithms. Use make_heap to convert a vector or array to obey heap rules. Then to insert just insert at back using vector.push_back() then call push_heap on the entire vector push_heap(vector.begin(),vector.end()). To remove the min or max element use pop_heap().

- We can also use custom Comparators with make_heap. **(Remember it has to be passed with parenthesis)**.

    ```c++
    struct CustomCompare{
        bool operator()(int x,int y){
         return x>y;
        }
    };
    
    ...

    make_heap(v.begin(),v.end(),CustomCompare());
    //or use greater<int> or less<int>
    ```

    Also any subsequent push_heap or pop_heap will require the same Comparator. 
    ```c++
    push_heap(v.begin(),v.end(),CustomCompare());
    ```

- You can use lower_bound and upper_bound in set also. Finding something in set is O(log(n)) and in unordered_set is O(1).

- **Use auto instead of specifying the type of operator.**
    ```c++
    for (auto it = graph[n].begin(); it != graph[n].end(); it++)
    ```

- **Use vector.assign to allocate memory to the vectors.**
    
    Eg. For vector of vectors.
    ```c++
    vector<vector<int>> graph;
    graph.assign(5, vector<int>());
    ```
    
    This will initialize the vector of vector with vector<int>.

- [Dijkstra STL](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/).

- Remember to observe indexing order in 2D arrays. Like in case of graphs don't use A[i][j]. Use A[j][i] assuming i as the x axis and j as the y axis.
  
- **Be careful sometimes it is important to initialize to INT_MIN not 0;**

- **While Comparing make sure to initialize min variable with INT_MAX not INT_MIN and max with INT_MAX;**

- take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 10^5.

- In some cases, you might be required to order the operations cleverly so that the numbers do not overflow. For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them. Another approach is to only multiple numbers from k + 1 ... n to calculate the result. Obviously approach 1 is more susceptible to overflows.

- Sum of squares (n*(n+1)*(2n+1))/6

- Kadane's Algorithm is used to find the maximum sum contigious subarray.

- **To initialize a string with a character you need to use std::string s(1,c) where c is the character.**

- You can append 2 strings with + operator
    ```c++
    string m = "Manish";
    string s = "Sunil";
    string x = m + ":" + s;
    cout << x << endl;
    ```

- But you can't append const char * like this.
    ```c++
    cout <<"Manish" + "Sunil" <<endl;
    ```
    **won't work.**

- ### Time Complexity Analysis

  - O(1) < O(LOG(n)) < O(N) < O(NLOG(N)) < O(N*N) <O(N^(LOG(N)))  < O(X^(N))(X IS CONSTANT) < O(N!) <O(N^N) 

  - [Complexity Analysis](https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/)

  - [Master Theorem for subtract and conquer](https://www.geeksforgeeks.org/master-theorem-subtract-conquer-recurrences/)

  - [Time complexity for recurrence relations](https://www.eecis.udel.edu/~saunders/notes/recurrence-relations.pdf)


- **If duplicates are present then summing or XOR can be helpful;**

- **Use string stream to split with space.**

- abs doesn't take input as Unsigned long don't use something like
  
  ```c++
  string A = "1000011011000000111100110";
  string B =  "1010110111001101101000";
  int diff = abs(A.size()-B.size());
  ```
    Instead use
  
  ```c++
  int diff = abs((long long)A.size()-B.size())
    ```

- Bitset is powerful but it has its limitations. To sum 2 binary strings.

  ```c++
  #include<bitset>
    string Solution::addBinary(string A, string B) {
        bitset<32> bitA(A);
        bitset<32> bitB(B);
        bitset<32> bitans(int(bitA.to_ulong() + bitB.to_ulong()));
        // cout << bitA + bitB;
        string answer = bitans.to_string();
        while(1){
            if(answer[0]=='1')
                break;
            answer.erase(0,1);
        }
        return answer;
    }
    ```
    But this solution fails if the bit string is bigger than the max of ulong.



- ### Longest Prefix Which is also a suffix. (LPS) Array

    To find the longest prefix which is also a suffix we need to follow the below rules.

    We form an array in which the values at each index denote the length of the longest prefix which is also a suffix and is not the same as the string itself. i.e for string abcabc ->length of prefix which is also a suffix is 3 (not 6 cause it can't be the string itself).

    - We need to use 2 iterators i and len.
    - Initialize len=0;i=1 and LCS[0]=0;
    - At each iteration we check if A[len] == A[i].
    - If True we increment both i and len. Also we update the LPS[i] = len+1;
    - If False
        - If len is zero then LPS[i]=0 and i++;
        - If len is not zero then len = LPS[len-1];

    Reason
    - First index of LPS Array should have value of zero cause no prefix exist which is not the string(A[0] is a character) itself.

    - len tells the max length of the prefix and also a suffix for substring 0 to i-1.

    - Thus if A[len]==A[i] it means to find the length of largest suffix which is also prefix for string 0 to i just take the value of "len"(length of largest prefix which is also a suffix for string 0 to i-1) and add 1 to it i.e LPS[i] = len + 1; (Can't we write LPS[i] = LPS[i-1]+1?)

    - If len is zero and A[i] doesn't match the first character(A[len=0]) the Longest Prefix that is a suffix is zero as there is nothing less than len(which is also the last index of maximum prefix of string 0 to i-1) to be compared with anything less than i and also since A[i] and A[0] not same so LPS[i]=0;

    - If len is not zero then there can be something in the already matched prefix which can match with the suffix when we add the character at A[i]. **So we cannot do LPS[i]=0 and move ahead**. We need to analyse. We were analysing the strings below index len-1 but unfortunately the character at index len did not match with i. But what if the same pattern till index len-1 exist before in the prefix that starts from 0. i.e considering string ending with len-1 as suffix does there exist a prefix starting at 0. to know that we see LPS[len-1] and we don't yet increment i, we see if the character at index=LPS[len-1] matches with character at i. if yeah then great we just continue with our algorithm else we continue to find the pattern as deep as it goes.

    ![LPS](./LPS.jpg "LPS")



- ### Binary Search

    ```c++
        int binary_search(vector<int> A, int value){
            int low = 0;
            int high = A.size() - 1;
            int mid;
            while(low <= high){
                mid = low + (high - low)/2;
                if(A[mid] == value)
                    return mid;
                else if(A[mid] > value)
                    low = mid + 1; 
                else
                    high = mid - 1;
            }
            return -1; // Important
        }
    ```

    - Binary Search works for any algorithm with order of some type.

    - See the circularly sorted and rotated problem. To deal with overflow you can use mod i.e 
    ```c++
        A[mid]<A[(mid+1)%A.size()] 
        A[mid]<A[(mid-1+A.size())%A.size()]
    ```

- ### Dynamic Programming

  - [FAO formula](https://medium.com/cs-dojo/an-introduction-to-dynamic-programming-89fdd3549d54)
  
  - [DP Book by ByteByByte](Books\Dynamic-Programming-for-Interviews.pdf)

- ### LCM and HCF

  - To find HCF or GCD
      ```c++
      int gcd(int a, int b) 
      { 
          if (a == 0) 
              return b; 
          return gcd(b % a, a); 
      } 
      ```
  - To find LCM
      ```c++
      int lcm(int a,int b){
          return a*b/gcd(a,b);
      }
      ```

  - The fact that gcd(n,m)=gcd(m,n%m) has been implemented in the above code.Now Observe the first 2 iterations:-

      gcd(a,b)–>gcd(b,r)–>gcd(r,b%r)

      r=a%b implies that r<b

      Claim:-r<a/2

      Proof:-(BY CONTRADICATION) Suppose that r>=a/2
      
      Now b>r implies b>=a/2 but since r=a%b this would mean that we are dividing a by a number greater than a/2, hence the quotient must be 1 and remainder must be less than a/2 but we have assumed that r>a/2…

      CONTRADICATION

      HENCE CLAIM WAS CORRECT

      This means that after every 2 iterations a is getting halved …hence it would take O(log(a)) time

- ### Two Pointer
  
  Two Pointers is a pattern where two pointers iterate through the data structure in tandem until one or both of the pointers hit a certain condition. Two Pointers is often useful when searching pairs in a sorted array or linked list.

  Two pointers are needed because with just pointer, you would have to continually loop back through the array to find the answer(O(n*n)).

  Ways to identify when to use the Two Pointer method:

  - It will feature problems where you deal with sorted arrays (or Linked Lists) and need to find a set of elements that fulfill certain constraints.
  
  - [Comparing strings that contain backspaces](https://leetcode.com/problems/backspace-string-compare/submissions/)
  
  - [Remove duplicates from Sorted Array](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/)

  In some questions with 2 arrays you may need to reverse one array and start a pointer from both the arrays. Like finding palindrome in a linked list.

- ### Fast and Slow Pointer
  
  - A pointer algorithm that uses two pointers which move through the array (or sequence/linked list) at different speeds.
  
  
  - How do you identify when to use the Fast and Slow pattern?
  
    - The problem will deal with a loop in a linked list or array
    
    - When you need to know the position of a certain element or the overall length of the linked list. 

# Modulus Properties
- The most obvious definition is: mod(x,y) or x % y gives the remainder when you divide x by y.
- Technique used by many a programmer to work out mod(x,y) when a mod function isn't available i.e. ```mod(x,y)= x-x*int(x/y)```
  
- Properties
    - Addition property
        ```
        (A + B) mod C = (A mod C + B mod C)mod C
        ```
    - Mod of a -ve number
      ```
      (-A) mod C = (-A + C)mod C
      ```
    - **Multiplication property**
      ```
      (A * B) mod C = (A mod C * B mod C) mod C
      ```
    
    - Exponentiation property
      ```
      A^B mod C = ( (A mod C)^B ) mod C
      ```

    - Modular Inverse property
      ```
      A * A^-1) ≡ 1 (mod C) or equivalently (A * A^-1) mod C = 1
      ```
      Only the numbers coprime to C (numbers that share no prime factors with C) have a modular inverse (mod C)

- Non Negative Modulus
    ```
    long long modul(long long p,long long q){
    return (q + (p%q)) % q;
    ```

# Misc Resources

- [Common Patterns in Coding Interviews](https://medium.com/hackernoon/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed)

- [DP Book by ByteByByte](Books\Dynamic-Programming-for-Interviews.pdf)

- [50 Questions by ByteByByte](Books\50-Coding-Interview-Questions.pdf)

- [Ardendertat Blog](http://www.ardendertat.com/2012/01/09/programming-interview-questions/)

- Spoj Most Liked Questions.