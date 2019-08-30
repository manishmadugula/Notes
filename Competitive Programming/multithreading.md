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