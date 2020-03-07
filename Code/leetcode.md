# Tips

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