## Concurrency

- Two Types
    - MultiProcessing 
        - Communication -> (IPC)
        
    - MultiThreading  
        - Communication -> (Shared Memory)
        - Faster to Start
        - Low OverHead
        - Difficult to Implement
        - Can't run over distributed systems.

### Threading 

- Thread object can't be copied only moved;

    ```c++
    std::thread t2 = std::move(t1);
    ```

- To print identification number of current thread use.

    ```c++
    std::this_thread::get_id();
    ```

- For any thread t1 do 
    ```c++
    t1.get_id();
    ```

- Ideally create as many thread as the number of cores. If you do more you run into problem of OverSubscription. There will be lots of context switching. You can get idea of optimal number of threads to use by using ->
    ```c++
    std::thread::hardware_concurrency();
    ```

- To make sure an exception in main thread doesn't kill the other threads enclose the main thread code in try catch block.

    ```c++
    void function_1(){
        for(int i=0;i<40000;i++)
                cout << i << " : ";
    }

    int main(){
        std::thread t1(function_1);
        try{
                for(int i=0;i<100;i++){
                        if(i==50)
                                throw "Exception";
                        cout << i << " ";
                }
        }
        catch(...){}
        t1.join();
        return 0;
    }
    ```

- Alternatively, we can also perform **"Resource Aquisition is Initialization"** approach. We create a wrapper class around thread and in destructor of wrapper class we call join.

 
- Parameters are always passed by value to thread so if you want to pass by reference you need to wrap the paramter by std::ref or pass it as pointer.
    ```c++
    std::string m = "Hello";
    std::thread(function_1,std::ref(m));
    ```
    
    - If you won't use the m in main thread you can wrap it in move which will move the parameter from main thread to child thread so program is more safe and efficient.
        ```c++
        std::string m = "Hello";
        std::thread(function_1,std::move(m));
        ```

### Passing Functor to threads in c++

Say we have a functor
  ```c++
    class Fctor{
      public:
      void operator()(){
          std::cout << "Hello" <<std::endl
    };
  ```
  We can pass it to thread as
  ```c++
  Fctor f1;
  std::thread t1(f1);
  ```
  We cannot do it inline as
  ```c++
  std::thread t1(Fctor());
  ```
  This is not creating a thread t1. Instead we are declaring a function with function name t1 which returns a thread and has a single parameter which is a pointer to another function with no parameter and returns a functor. 

  If you want inline you can do
  ```c++
  std::thread t1((Fctor()))
  ```

### Passing parameter to thread

```c++
void function_1(std::string msg){
    std::cout << msg <<std::endl;
}
int main(){
    std::string s ="Hello";
    std::thread t1(function_1,s)
}
```

**By default the parameter is passed by value to the thread. To pass it by reference we need to do 2 things. Make sure the function passed to thread takes reference and also pass the paramter to thread by enclosing it within std::ref().**

```c++
void function_1(std::string& msg){
    std::cout << msg <<std::endl;
}
int main(){
    std::string s ="Hello";
    std::thread t1(function_1,std::ref(s))
}
```

This std::ref creates a reference wrapper for the thread. Thus the child and main thread are sharing the memory. **We can also avoid all this by just passing pointer to thread.**

Incase we don't want shared behavior and only want thread to access the data. We can use move wrapper. It will move the string s from main to thread. 

```c++
void function_1(std::string& msg){
    std::cout << msg <<std::endl;
}
int main(){
    std::string s ="Hello";
    std::thread t1(function_1,std::move(s))
}
```

### Ideal number of threads to create.
Creating too many threads causes a lot of context switching. This degrades the performance of the program this is refered as oversubscription. C++ library provides the following function.
```c++
std::thread::hardware_concurrency();
```
It gives an Idea of how many thread truly the os supports.

### Printing Thread Identification Number.
```c++
    std::this_thread::get_id();
```

### Moving Thread Ownership

You cannot assign / copy one thread to another via ```std::thread t2 = t1``` but if you want to transfer ownership of t1 to t2 you can do ```std::thread t2 = std::move(t1);```

### Race Condition.
If outcome of the program depends on the relative execution order of one or more threads. It is not good for program. We can use mutex to syncronize the access of the shared resource say in the following code.
```c++
void function_1(){
    for(int i=0;i<100;i++)
        cout <<"From t1 "<< i << endl;
}

int main(){
    std::thread t1(function_1);
    for(int i=0;i<100;i++){
        cout << "From main : "<< i << endl;
    }
    t1.join(); // Needed as the if main exits then thread t1 is never run.
    return 0;
}
```
the output comes pretty messed up sometimes as both the threads are competing for the shared resource i.e stdout. We can use mutex to syncronize the access of stdout as follows.

```c++
std::mutex mu;
void function_1(){
    for(int i=0;i<100;i++)
    {
        std::lock_guard<std::mutex> lk(mu);
        cout <<"From t1 "<< i << endl;
    }
}
int main(){
    std::thread t1(function_1);
    for(int i=0;i<100;i++){
        std::lock_guard<std::mutex> lk(mu);
        cout << "From main : "<< i << endl;
    }
    t1.join();
    return 0;
}
```
In the Above code we are using RAII (Resource Aquisition is Initialization) approach i.e whenever mutex mu will go out of scope the mutex always unlocks even in case of exception. 

Also ideally we should make sure no other function or thread calls cout we need to bound cout with the mutex. As follows - 

```c++
class LogF{
    std::mutex m;
    ofstream f;

    public:
        LogF(){
            f.open("log.txt");
        }
        void shared_print(string s){
            std::lock_guard<mutex> locker(m);
            f << s <<endl;
        }
};

void function_1(LogF &l){
    for(int i=0;i<100;i++)
        l.shared_print(std::string("From t1 : "+ to_string(i)));
}

int main(){
    LogF l;
    std::thread t1(function_1,std::ref(l));
    for(int i=0;i<100;i++)
        l.shared_print(std::string("From main : " + to_string(i)));
    t1.join();
    return 0;
}
```

In the above case make sure never to leak f to outside code. Like follows.

```c++
ofstream getStream(){return f;}
```

or

```c++
void processf(void user_function(ofstream&)){
    user_function(f);
}
```

To Make sure you don't have data race condition
 - Use mutex to syncronize the data.
 - Never leak the data to outside code.
 - Design interface appropriately eg-stack example given [here](https://youtu.be/3ZxZPeXPaM4?list=PL5jc9xFGsL8E12so1wlMS0r0hTQoJL74M&t=541).


### DeadLock

If one thread has ownership of one mutex say m1 and requires m2 to complete its work and another thread already took ownership of m2 and want m1 to complete its work. None of the threads can finish thus causing deadlock.

To prevent deadlock

  - We have to make sure every thread locks mutexes in same order.
  
  - Use the std::lock -> 
    ```c++
    std::lock(m1,m2);
    std::lock_guard<mutex> locker1(m1,std::adopt_lock);
    std::lock_guard<mutex> locker2(m2,std::adopt_lock);
    ```
    It has some dead lock avoidance algorithm.
 
  - If possible only have one mutex locked at a time.
    ```c++
    {
            std::lock_guard<mutex> locker1(m1);
            //Do some stuff.
    }
    {
            std::lock_guard<mutex> locker1(m2);
            cout << "Hello" <<endl;
    }
    ```

  - Try not to lock mutex and call some user function. Cause then you would not know if user function will lock another mutex.

  - Provide heirarchy of mutexes.


## Conditional Variables

- To talk between 2 thread we need a mechanism to send an event b/w the 2 threads. Conditional variables offer this mechanism. If we don't use Conditional Variables we may have to keep polling a boolean if the polling thread can continue it's work or not as follows.

```c++
class CVTest{
	
	std::mutex m;
	bool isWorkDone = false;

public:
	void loadData() {
		cout << "Fetch the data from database" << endl;
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "Data is fetched" << endl;
		lock_guard<std::mutex> lg(m);
		isWorkDone = true;
	}

	void mainWork() {
		
		cout << "Performing some independent work" << endl;
		m.lock();
		while (!isWorkDone) {
			m.unlock();
			this_thread::sleep_for(std::chrono::milliseconds(100));
			cout << "polling" << endl;
			m.lock();
		}
		m.unlock();
		cout << "Process the fetched data" << endl;
	
	}

};


int main() {
	
	CVTest cv;
	std::thread t1(&CVTest::mainWork, &cv);
	std::thread t2(&CVTest::loadData, &cv);
	t1.join();
	t2.join();
	return 0;
}

```
- If you run the above code you will see how many times we poll. and also aquire and reaquire the lock. This leads to waste of cpu cycles.

- We need a better mechanism to achieve this, like if somehow Thread 1 could just block by waiting for an Event to get signaled and another Thread could signal that Event and make Thread 1 continue. It would have save many CPU cycles and gave better performance. Solution is to use conditional variable

```c++
class CVTest {

	std::mutex m;
	std::condition_variable c;
	bool isDataLoaded = false;
public:
	void loadData() {
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::lock_guard<std::mutex> lg(m);
		isDataLoaded = true;
		c.notify_one();
	}

	void mainTask(){
		cout << "Do some independent task" << endl;
		std::unique_lock<mutex> ul(m);
		//Polling is only called twice once when the wait is first encountered and once to check for spurious wake ups.
		c.wait(ul, [this] {cout << "polling" << endl; return isDataLoaded; });
		cout << "Do processing in data " << endl;
	}
};

int main() {
	CVTest cv;
	std::thread t2(&CVTest::mainTask, &cv);
	std::thread t1(&CVTest::loadData, &cv);
	t1.join();
	t2.join();
	return 0;
}
```

### Working of Conditional Variable

- Thread 1 calls the wait on condition variable, which internally acquires the mutex and check if required condition is met or not.
- If not then it releases the lock and waits for Condition Variable to get signaled ( thread gets blocked). Condition Variable’s wait() function provides both these operations in atomic manner.
- Another Thread i.e. like Thread 2 signals the Condition Variable when condition is met.
- Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes. It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met or if it is **spurious call**. If more than one thread was waiting then notify_one will unblock only one thread.
- If it was a **spurious call** then it again calls the wait() function.


### Spurious Wakeups

- it means a thread can wakeup from its waiting state without being signaled or interrupted or timing out. To make things correct, awakened thread has to verify the condition that should have caused the thread to be awakened. And it must continue waiting if the condition is not satisfied.


## std::future and std::promise

- std::future is a class template and its object stores the future value.
- std::promise is a class template and it's object promises to set the associated std::future object's value in future.
- A std::promise object shares data with its associated std::future object.

![Complete Flow diagram](res/promise.png)

```c++
// The parameter has to be a pointer to promise object.
void func(std::promise<int>* pr_obj) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Setting the promise object " << std::endl;
	pr_obj->set_value(3);
}
int main() {
	std::promise<int> promise_obj;
	std::future<int> future_obj = promise_obj.get_future();
	std::thread t1(func, &promise_obj);
	cout << " recieved the data after processing .... " << future_obj.get() << endl;
	t1.join();
	return 0;
}
```

## std::async

- it is a function template that accepts a callback as an argument and potentially executes them asynchronously.

- It returns ```std::future<T>``` which stores the value returned by the async function. 

- We can fire the async in the 3 modes
    - std::launch::async
        - Guarantees async behavior. The function will execute in a separate thread.
    - std::launch::deferred
        - Non async behavior i.e **function will be called only when the other thread calls get on the future to access shared state.**
        - ### **IMPORTANT ->** i.e the function won't even be called if we don't call get in the future returned. 
        - In case of deferred the function will not run in a separate thread.

    - std::launch::async | std::launch::deferred - Default behavior - launch policy depends on the load of the system.


- std::async() does following things,

    - It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
    - Then passes the std::promise object to thread function and returns the associated std::future object.
    - When our passed argument function exits then its value will be set in this promise object, so eventually return value will be available in std::future object.

In the below case the function won't even be called
```c++
std::string func(std::string x) {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << "second thread" << endl;
	return std::string("Hello ") + x;
}
int main() {
	std::future<string> f_obj = std::async(std::launch::deferred ,func, std::string("Manish"));
	this_thread::sleep_for(std::chrono::milliseconds(4000));
	cout << "The value is " << endl;
	return 0;
}
```

Using launch::async

```c++
std::string func(std::string x) {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	cout << "second thread" << endl;
	return std::string("Hello ") + x;
}
int main() {
	std::future<string> f_obj = std::async(std::launch::async, func, std::string("Manish"));
	this_thread::sleep_for(std::chrono::milliseconds(4000));
	cout << "The value is " << f_obj.get() << endl;
	return 0;
}
```

- ## Important Insight -> Future returned by std:async can block in its destructor, they are special futures.

The future, that is created by std::async, waits in its destructor, until its work is done. An other word for waiting is blocking. The future blocks the progress of the program in its destructor. The becomes obvious, in case you use fire and forget futures.

```c++
int main(){

  std::cout << std::endl;

  std::async(std::launch::async,[]{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "first thread" << std::endl;
    });
    
  std::async(std::launch::async,[]{
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::cout << "second thread" << std::endl;}
    );
  
  std::cout << "main thread" << std::endl;  

}
```

The above code is run sequentially not asyncronously.
 Although I create in the main-thread two promises, which are executed in separate threads, the threads run in sequence one after the other. 


 The key issue is, that the by std::async created thread is waiting in its destructor until the associated promise is done, can not  be solved. The problem can only be mitigated. In case you bind the future to a variable, the blocking will take place at the time point, when the variable goes out of scope. 


 ```c++
 int main(){

  std::cout << std::endl;

  auto first= std::async(std::launch::async,[]{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "first thread" << std::endl;
    });
    
  auto second= std::async(std::launch::async,[]{
    std::this_thread::sleep_for(std::chrono::seconds(1));  
    std::cout << "second thread" << std::endl;}
    );
  
  std::cout << "main thread" << std::endl;  
}
 ```
Now, the output of the program matches our intuition, because the three threads are executed in parallel.
# Misc

## Passing class members as thread argument

```c++
 class Dummy{
    public:
        int x;

        Dummy(int x) : x(x) {}

        void dummy_method(int r){
            x = x+r;
        }

};

int main(){

    Dummy d(42);
    std::thread t(&Dummy::dummy_method,&d,2);
    t.join();
    cout << d.x <<endl;

}
```

## Passing reference to the std::thread

- Use std::ref as stated above.
- The following code will fail

```c++
void func(int &s)
{
    int & x = const_cast<int &>(s);
    x = 23;
}

int main(){
    int x = 24;
    std::thread t(func, x);
    t.join();
    cout << x <<endl;
    return 0;
}
```
If you don't mention (void func(const int &) it gives an error.
Reason -> Not mentioning const mean you are doing int & x = 24; since the thread are passed copy by value
which is not allowed as the right hand side i.e 24 is an rvalue which cannot be assigned to a lvalue refer
ence. https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c. But const lvalue re
ferences can hold rvalues. So changing it to const works.


## How not to pass argument
- Don’t pass addresses of variables from local stack or heap to thread’s callback function. Because it might be possible that local variable in Thread 1 goes out of scope but Thread 2 is still trying to access it through it’s address. In such scenario accessing invalid address can cause unexpected behaviour.



## Create thread using Resource Allocation is Initialization (Revisit)

```c++
class ThreadWrapper{

    std::thread &m_thd; //Thread Objects can't be copies thus we need to store it as reference.

    public:
        ThreadWrapper(std::thread &thd) : m_thd(thd) {}

        ~ThreadWrapper(){
            if(m_thd.joinable())
                m_thd.join();
        }
};

int main(){

    std::thread t1([](){
        for(int i=0;i<20;i++)
            std::cout << i << "From Thread " << std::this_thread::get_id() <<std::endl;
    });

    ThreadWrapper TW(t1);
    return 0;
}
*/
```

## Proper Usage of Join/ Detach

```c++
int main(){

    std::thread t1([](){
        for(int i=0;i< 2300;i++)
            std::cout << i << "From thread id" << std::this_thread::get_id() <<std::endl;
    });

    //  t1.join();
    //  t1.join();//This will cause program to terminate.

    //Instead do
    if(t1.joinable()) t1.join();
    if(t1.joinable()) t1.join();

    for(int i=0;i<100;i++)
        std::cout << i << "From Main Thread" << std::this_thread::get_id() <<std::endl;

    return 0;
}
```

## Cout is not thread safe?? (Maybe a race condition)
```c++
void func(){
    std::cout << "Inside Thread ID :" << std::this_thread::get_id() <<" "<<endl;
}

int main(){

    std::thread t1(
            [](){
                std::cout << "Inside Thread ID :" << std::this_thread::get_id() <<" "<<endl;
            }
            );
    std::thread t2(func);

    std::cout << "Inside Main Thread :" << std::this_thread::get_id() << endl;
    t1.join();
    t2.join();
    return 0;
}

```