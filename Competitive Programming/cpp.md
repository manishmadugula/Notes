## Pointers
- Pointer is just an address
- Types of pointer doesn't matter much. Pointer for all types is just a number which holds an address.
- Type of pointer is used to read and write to memory pointed by pointer.
- If deallocating an array use delete[] keyword.
- 32 bit machine size of pointers is 4 bytes and 8 bytes in 64 bit machine.
- Little and big endian are two ways of storing multibyte data-types ( int, float, etc). In little endian machines, last byte of binary representation of the multibyte data-type is stored first. On the other hand, in big endian machines, first byte of binary representation of the multibyte data-type is stored first. Suppose integer is stored as 4 bytes (For those who are using DOS based compilers such as C++ 3.0 , integer is 2 bytes) then a variable x with value 0x01234567 will be stored as following. When above program is run on little endian machine, gives “67 45 23 01” as output , while if it is run on big endian machine, gives “01 23 45 67” as output.

- While dereferencing use bracket to surround. We don't want to increment first then dereference we want to dereference first then increment.
```c++
    *v++ vs (*v)++
```

- Pointer arithematic relies upon the type used. if char* doing ```*((int *) p + 4) doing + 8``` will move 8 bytes . if int * doing ```*((int *) p + 4)``` moves 4*4 bytes.

## References
- Pointers and References are pretty similar as to what the computer will do with them. but semantically they are different in how we use them.
- Syntax Sugar on top of pointer.

- You can't make a reference and set it to null. 

- Also when you create a reference you need it to set it to something.

- References have to reference a new variable. not gonna occupy memory.

- References are like aliases.

- If you create a reference for one variable you cannot set it to later reference to another variable.

    ```c++
    int a = 2;
    int b = 9;
    int& ref = a;
    ref = b;
    ```

    By doing the above you set a = value of b.

- there is no such thing called Reference Arithmetic

- References typically appear on the skin of an object, and pointers on the inside.

- Use references -> In function parameters and return types.

- Use Pointers -> Use pointers if pointer arithmetic or passing NULL-pointer is needed. For example for arrays (Note that array access is implemented using pointer arithmetic). To implement data structures like linked list, tree, etc and their algorithms because to point different cell, we have to use the concept of pointers.

- There is no such thing as dereferencing a reference.
- References work similar to const pointers ```int* const a```(not to be confused with pointer to a const int).

## new
- integer ```int *a =new int;```
- array ```int *b = new int[30]```
- class ```Entity *c = new Entity()```
- array of class ```Entity *c = new Entity();```
- new is just another operator so we can overload it.

- It calls the objects constructor unlike malloc.
- new goes with delete which is also a operator.
- **new with array operator new[] is a different operator so it has to be deallocated with ```delete []``` instead of ```delete```**
- Placement new can be used to allocate to a specific memory.

## Smart Pointers
- Used to automatic new and delete i,e memory management.
- A bit of overhead.
- wrapper around a raw pointer.
- #include <memory> to include smart pointers.
- **Unique Pointer**
    - unique_ptr is a scoped ptr.
    - When it goes out of scope it gets deleted.
    - You can't copy a unique_ptr.
    - [Passing unique_ptr to a function](https://stackoverflow.com/questions/8114276/how-do-i-pass-a-unique-ptr-argument-to-a-constructor-or-a-function/8114913)
    - To create a unique_ptr use ->
        ```c++
        std::unique_ptr<Entity> e = make_unique<Entity>("Manish",23);
        ```
    - low overhead

- **Shared Pointer**
    - Most cases it uses reference counting. You keep count of how many reference you have and as soon as it gets to zero it is deleted.
    - **To create a shared_ptr use** ->
        ```c++
        std::shared_ptr<Entity> e = make_shared<Entity>("Manish",23);
        ```
        This above method using make_shared is better. If you use new the compiler has to make 2 allocation one for entity and one for control block.
    - Can be copied.

- **Weak Pointer**
    - same as shared_ptr but it won't keep the reference count. You can assign it to a shared_ptr and it won't increase the ref count.
    - You can ask a weak ptr is the object expired or still valid.


## r_value and l_value
- [Important Link](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c)

- [Link](https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners)


## Type Punning
- Treat one block of memory differently than it actually is. We need to get that type as a pointer and cast it to different poitner and then dereference it.

    ```c++
    struct Entity{
        int x,y;
        int * GetArray(){
            //Typically you create a new array in heap maybe and do copy which is redundant. This is the better way.
            return &x;
        }
    }
    int main(){
        Entity a = {1,3};
        int * arr = a.GetArray();
        int l = arr[1];
        //or if you want to have complete control till byte level.
        int m = *(int*)((char*)&e + 4)

    }
    ```

- Used case can be above where to return the array we didn't have to create a new array and waste space. Or if we just want to covert a Class into raw bytes and make operation in it or pass it as a stream.



## Implicit Conversion and Explicit Keyword.
- Not good practice. Just be aware it exists.
- Implicit means kind of means automatic. Compiler is allowed to do one implicit conversion without you needing to do casting.
    ```c++
    class Entity{
        private:
            std::string m_name;
            int m_age;
        public:
            Entity(const char * name) : m_name(name),m_age(-1){ }
            Entity(int age) : m_name("Unknown"),m_age(age){  } 
    };

    void Print(const Entity& e){
        cout << e.m_age <<endl;
    }

    int main(){
        //Instead of Entity a = Entity("Manish"); 
        Entity a = "Manish"; //Implicit Conversion
        Entity b = 23;
        Print(23); // Implicit Conversion
        std::string Name = "Sunil";
        Print(Name) //Won't work as c++ can't do 2 implicit conversion.
        //This requires one conversion from string to const char* and then const char * to Entity.
    }
    ``` 
    It implicitly takes 23 and coverts it into Entity because **there is a constructor that takes 23 and makes it into Entity**.

- Explicit Keyword in front of constructor will disable the implicit conversion for that constructor.
    ```c++
    class Entity{
        private:
            std::string m_name;
            int m_age;
        public:
            explicit Entity(int age) : m_name("Unknown"),m_age(age){  } 
    };

    void Print(const Entity& e){
        cout << e.m_age <<endl;
    }

    int main(){
        //wont work -> Entity b = 23;
        // Has to call constructor.
        Entity b = Entity(23);//Or Entity b(23);
        //or do explicitly cast.
        Entity c = (Entity)23;
    }
    ```

## Type Casting (Explicit)
### C Style
- ```c++
    double val = 13.23;
    int a = (int)(val+2.421);
  ```
### C++ Style
- All cast except dynamic cast are just syntactic sugar.
- static_cast
    ```c++
    double val = 13.23;
    int a = static_cast<int>(val+2.421);
    ```
- reinterpret_cast does type punning discussed above.
    ```c++
    double value =23.34;
    reinterpret_cast<Another_Class>(value);
    //Reinterpretted the data at value into the pointer to Another_Class instance.
    ```
- dynamic_cast does run-time checking and only cast if it is possible to cast else it returns null.

- const_cast removes or add const.

- Helps in searching for all casting at the same time easily. And also reading the code.

## Variable Initialization in C++

- Copy Initialization ```int value1 = 1;``` -> initializes an object from an explicit set of constructor arguments 
- Direct Initialization ```int value1(1);``` -> initializes an object from another object.

- Uniform Initialization ```int value1 {1};```

### Related to classes
- List Initialization ```std::string s{'a','b','c'};```
- Aggregate Initialization ```int a[]={1, 2, 3, 4};```
- Default Constructor ```X x1;```
- Parameterised Constructor ```X x1(1,2,3);```
- Parametrized constructor with single argument ```X x3=3;```
- Copy Constructor ```X x4 = x3;```

### Brace Intialization
- ```c++
    std::vector<int> v { 1, 2, 3 };
    std::map<int, std::string> m { {1, "one"}, { 2, "two" }};
    int* arr2 = new int[3]{ 1, 2, 3 };    
    int arr1[3] { 1, 2, 3 };
    int i { 42 };
    double d { 1.2 };    
  ```
  ```c++
    class foo
    {
      int a_;
      double b_;
    public:
      foo():a_(0), b_(0) {}
      foo(int a, double b = 0.0):a_(a), b_(b) {}
    };

    foo f1{}; 
    foo f2{ 42, 1.2 }; 
    foo f3{ 42 };
  ```


## Scope and Lifetime
- Scope is anything from function scope or if statement or for or just an empty scope.
- As soon as we move out of scope all the objects inside the function or scope are destroyed.
- **Very Important**
    ```c++
    int CreateArray(){
        int arr[24];
        return arr;
    }
    ```
    **Won't work. As soon as we exit the function the arr object is destroyed as it is allocated on the stack, not in heap.**

- **Very Important**
    [Leveraging the power automatic destruction in stack](https://youtu.be/iNuTwvD6ciI?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&t=373)

    This method is used in unique_pointers, timer functions, mutex locking. See the video to understand.

## Objected Oriented Programming

### Class

- **There is a semi-colon at the end of the class bracket.**
    ```c++
    class Player{
        int x,y;
        int speed;
    };
    ```
- By default class makes everything private.

- **Every non-static method gets an instance of class which is calling it.**

- **Struct vs Class**

    - A class is private by default.
    - A struct is by default public.
    - structs exist in c++ cause it wants to have backwards compatibility with c.

### Visibility
- Helps in organizing code.
- 3 Types private, protected, public.
- private -> Only this class or a friend can access these private members. Not even inherited classes.
- protected -> all subclasses along the heirarchy can access these variables.
- **friend allows you to reverse private.**

### this keyword
- you can only access this keyword in a non static member function.
- this is a const pointer to the object instance.  Entity* const type.
- const at the right hand side of pointer mean you can't reassign "this" to any other object. like this = nullptr.
- in const method this isn't just ```Entity * const```. It is a pointer to a const Entity. So type of this is ```const Entity * const``` 




### Constructor

- Special Method which gets called every time we create an object.
- Doesn't have return type.
- Name must match the name of class.
- if you want it to be used make it public.
- Primitive types in c++ is not initialized to zero automatically like in JAVA.
- Supports Overloading. i.e Same name different arguments.
- Won't run if you don't instantiate an object. If you use static methods of an object it won't run.
- It also runs when we use new keyword.(not malloc).
- If you don't want to use constructor make it private(hide default constructor). Or assign the constructor to delete.
    ```c++
    class Example{
        public:
            Example() = delete
    };
    ```
    or
    ```c++
    class Example{
        private:
            Example(){};
        public:
            Example() = delete
    };
    ```

### Member Initializer List
-   [Link](https://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/)

- Kind of like using direct initialization or uniform initialization in c++11.

- **There is a difference between initialization and assignment. Member initializer lists allow us to initialize our members rather than assign values to them.**
    ```c++
    class Example{
        public:
            Example(){
                cout << "Created Example!"<<endl;
            }
            Example(int v){
                cout << "Created Example with" << x <<" ! "<<endl;
            }
    };
    class Entity{
        private:
            //This part of code is also run and Example is created.
            std::string Name;
            Example m_Example;
        public:
            Entity(){
                Name = "Manish";
                m_Example = Example(7);//It was already initialized now just assigned.
            }
    }
    int main(){
        Entity e0;
        std::cin.get();
    }
    ```
    Above code is just like
    ```c++
    string Name;
    Example m_Example;
    Name = "Manish";
    m_Example = Example(7);//It was already initialized now assigned to new "Example".
    ```

    This is create Example twice as when we create Entity, An example object is created with its default constructor. Then when the constructor is run we again create another Example object with x=7. So we will see 2 print statements.
    However if we do the following it will be only initialized twice.
    ```c++
    class Entity{
        private:
            std::string m_name;
            Example m_Example;
        public:
            Entity() :m_name("Manish"),m_Example(Example(7)) {
                //No need to do any assignments.
            }
    }
    ```

- **This is the only way to initialize members that require values upon initialization, such as const or reference members, and it can be more performant than assigning values in the body of the constructor.**
    ```c++
    class Something
    {
    private:
        const int m_value;
    
    public:
        Something()
        {
            m_value = 1; // error: const vars can not be assigned to
        } 
    };
    ```


- **Member initializer lists work both with fundamental types and members that are classes themselves.**
    ```c++
    class A
    {
    public:
        A(int x) { std::cout << "A " << x << "\n"; }
    };
    
    class B
    {
    private:
        A m_a;
    public:
        B(int y)
            : m_a(y-1) // call A(int) constructor to initialize member m_a
        {
            std::cout << "B " << y << "\n";
        }
    };
    
    int main()
    {
        B b(5);
        return 0;
    }
    ```

- **variables in the initializer list are not initialized in the order that they are specified in the initializer list. Instead, they are initialized in the order in which they are declared in the class.**

    For best results, the following recommendations should be observed:
    1) Don’t initialize member variables in such a way that they are dependent upon other member variables being initialized first (in other words, ensure your member variables will properly initialize even if the initialization ordering is different).
    2) Initialize variables in the initializer list in the same order in which they are declared in your class. This isn’t strictly required so long as the prior recommendation has been followed, but your compiler may give you a warning if you don’t do so and you have all warnings turned on.

    ```c++
    class Entity{
        private:
            int m_Int;
            std::string m_Name;
        public:
            Entity()
            :m_Name("Unknown"),m_Int(0)  // m_Int will be intialized first cause it is defined first in the class
            {

            }
            Entity(std::string name):m_Name(name){

            }
    };
    ```

- For Arrays  in c++11
    ```c++
    class Something
    {
    private:
        const int m_array[5];
    
    public:
        Something(): m_array { 1, 2, 3, 4, 5 } // use uniform initialization to initialize our member array
        {
        }
    
    };
    ```

- In c++11 for all use uniform initialization
    ```c++
    class Something
    {
    private:
        const int m_value;
    
    public:
        Something(): m_value { 5 } // Uniformly initialize our member variables
        {
        } 
    };
    ```

### Initialization in Classes.

- Each instance of the class gets its own copy of myInt. The place to initialize those is in a constructor:
    ```c++
    class Foo {
        private:
          int myInt;
        public:
            Foo() : myInt(1) {}
        };
    ```

- A class variable is one where there is only one copy that is shared by every instance of the class.
    ```c++
    class Foo {
        private:
           static int myInt;
    };
    int Foo::myInt = 1;
    ```


### **Create or Instantiate Objects.**

- 2 Ways to create -> Stack or heap.
- **Stack**
    - Default Constructor ```Entity e;```
    - Parameterised Constructor ```Entity e("name");``` or something like this ```Entity e = Entity("name");```
    - Objects created on stack are only alive within that block (can be if or for or even **empty brackets**).
    - Stack memory is also small in size 1 or 2 MB.

- **Heap**
    - Default Constructor ```Entity *entity = new Entity;``` or ```Entity *entity = new Entity();```
    - Parameterised Constructor ```Entity *entity = new Entity("name");```
    - Allocating on heap takes longer.
    - You need to manually free the memory.
### Destructor
- Called when object is deleted.
- Helps clear initialized memory.
- ~ in front of Class Name. ~Example(){}


### Inheritance
- Inherit using
    ```c++
    class Entity{
        public:
            int x,y;
            
            void Move(float xa,float ya){
                x+=xa;
                y+=ya;
            }
    };

    class Player : public Entity{
        public:
            const char* name;
            void PrintName(){
                cout << name <<endl;
            }
    };
    ```

- [Types of inheritances](https://www.bogotobogo.com/cplusplus/private_inheritance.php)

- The above was an example of public inheritance. In public inheritance all public and protected variables and methods are inherited as public and protected respectfully. But no private methods or variables are inherited.

- In protected inheritance public and protected are inherited as protected.

- In private all methods and variables be it public protected or private are inherited by subclass as private method or variables.

### Virtual Functions
- allows us to override methods in subclasses.

- It also works if you don't mark them virtual but problem arises when you try to use polymorphism.

- Uses dynamic dispatch which compilers implement via v-table. It is a mapping of all virtual function of base class so we can map them to the correct overriden function at runtime.

- additional memory taken by v-table.

- write virtual in base class and override in derived class -> good practise.

- See code.
    ```c++
    class Entity{
        public:
            std::string GetName(){return "Entity";};
    };

    class Player : public Entity{
        private:
            std::string m_Name;
        public:
            Player(const std::string &name)
            : m_Name(name){}

            std::string GetName(){ return m_Name;}
    };

    int main(){
        //Works fine.
        Entity e;
        std::cout << e.GetName() <<std::endl;
        Player p("Manish");
        std::cout << p.GetName() <<std::endl;

        //Things crumble if we use polymorphism.
        Entity q = new Player("sunil");
        std::cout << q.GetName()<<std::end;
        //The above statement prints "Entity" not "sunil".
        // It calls the method related to the type not the actual object.
    }
    ```

    To fix the issue use virtual keyword. Compiler has to realize that the object which is actually calling the method is a Player. Mark function in base class as **virtual** and also the derived class as **override**(not required but helps with maintainability).

    ```c++
    class Entity{
        public:

            virtual std::string GetName(){return "Entity";};;
    };

    class Player : public Entity{
        private:
            std::string m_Name;
        public:
            Player(const std::string &name)
            : m_Name(name){}


            std::string GetName() override { return m_Name;}
    };
    ```


### Pure Virtual Function / Interfaces.

- Interface is a class which only has function declarations and expects the derived class to implement those methods.

- It can't be instantiated.

    ```c++
    class Entity{
        public:
            //Makes the entire Entity un-instantiated.
            virtual std::string GetName() = 0;
    };

    class Player : public Entity{
        private:
            std::string m_Name;
        public:
            Player(const std::string &name)
            : m_Name(name){}

            //If you comment out the below line even this class can't be instantiated.
            std::string GetName() override { return m_Name;}
    };
    ```

- A class can only be instantiated if it does't have virtual functions and also implements all the virtual functions of the base class.


## Static 
- Local Scope

    - There is a difference between scope and lifetime. Scope tells where we can access a variable. lifetime is when a variable dies i.e cleaned out of memory.

    - Static local variable allows us to declare a variable with life-time of entire program but its scope is limited to be inside the block{}(function or if statement or for etc) surrounding it.

    - won't be visible outside function.

    - Useful in creating SingleTon Class.

        ```c++
        class Singleton{
            public:
                static Singleton& Get(){
                    static SingleTon instance;
                    return instance;
                }
                void Hello();
                //Make constructor private and also copy private.
        };
        ```

        First time we call Get() it will create Singleton Instance rest of the time it returns the same instance. We declared "instance" as static extending its lifetime to as long as program runs.
                    



- Outside of class or function i.e in a space you define global variables.

    - linkage of the static symbol will be internal. It is only going to be visible to the translation unit you defined it in.

    - It is kind of like declaring a variable/function private but for a translation unit. Linker or any other translational unit cannot see it.
    
    - If there is a header file with a static variable/function then every file which includes this header file can then use those static variable or function.
    
    - Try mark the functions and variables static unless you don't need to access them across various translational units. 





- Inside of class

    - **Static Variable**

        - Across all instances created of that class there will be only 1 variable shared between them.

        - **Static data members declarations in the class declaration are not definition of them. The declaration in an implementation file outside of the header is required because otherwise every translation unit that includes this header would define its own object. This would violate the One Definition Rule. We want a single instance accessible from all Translational Units.**
            
            code in Example.h
            ```c++
            struct Example {
                static int x;
                int y;
            };
            ```
             code in any **one** file which includes this header., you need to define it. **Defining it allocates the memory for it. Creating Objects won't allocate the memory for static variable.**

            ```c++
            int Example::x;
            ``` 

        - **The only data you can declare and define inside the class is integral static constants.**

            ```c++
            struct Example {
                const static int x=1;
                int y;
            };

            int main() {
                Example a;
                a.y = 34;
                cout << a.x << a.y << endl;
                return 0;
            }
            ```

        - Its like 2 variables which belong to namespace of "Example". Therefore it makes more sense to refer to static class variables as follows.

            ```c++
            Example::x=23;
            ```

            and not

            ```c++
            a.x=23;//a is an object of Example class.
            ```
        

    - **Static Method**
    
        - Need not be initialized to be called.
        
        - Don't have access to a class instance and variables.
        


        - Cannot refer to class instance.

        - Better to call as 
            ```c++
            Example::StaticMethod();
            ```
            not
            ```c++
            a.StaticMethod();
            ```

## Enum
- These are nothing but integers (**by default 32 bit you can redefine it to be unsigned  char or long,cannot be float or double**). Help us group together integers and make sure we don't use integers which are invalid.

```c++
enum Log : unsigned char{
   Error=0, Warn=1, Info=2 
};

int main(){
    //If you use here any value apart from 0,1,2 it will give error.
    Log l = 1;
    if (l == 0){
        .....
    }
    else if(l == 1){
        .....
    }
    else {
        .....
    }
}

```

## Const
- ```const int a = 6``` -> You cannot change the value of a.
  

- When dealing with pointers we can change 2 things. The value of the object that is pointed by pointer and also the object that is pointed by pointer.

- ```const int *a = new int; or int const* a=new int // both are same. ```  You cannot change the value pointed by a. This ```*a=3``` is invalid. However you can reassign a to another **const** integer address -> ```a=&b```.

- ```int* const a = new int ``` has opposite functionality. You can change a i.e ```*a=3``` is valid but it has to point to the same integer address. ```a=&b``` is invalid.

- ```const int* const a = new int``` has both. You cannot change either the value of integer pointed by a or the address of integer pointed by a. 

- 3rd usage of const has to do with classes and its method. It works only in case of classes.
  ```c++
  class Entity{
      private:
        int m_X,m_Y;
      public:
        int GetX() const{
            //You cannot make any changes to this object instance i.e m_X and m_Y.
            return m_X;
        }
  };
  ```

- Most Getters need have const. As they don't modify the instance variables.

- This is particularly important in following case. Your PrintEntity will show an error if const is not defined in the GetX() method. As it expects the function GetX() to not modify e as e is a const Reference.
  ```c++
  class Entity{
      private:
        int m_X,m_Y;
      public:
        int GetX() const{
            //You cannot make any changes to this object instance i.e m_X and m_Y.
            return m_X;
        }
  };
  void PrintEntity(const Entity& e){
      std::cout << e.GetX() <<std::endl;
  }
  ```

- ```const int * A;``` -> "A is a pointer to an int that is constant."
(or, depending on how you prefer to write it)
```int const* A;``` -> "A is a pointer to a const int"
but both are the same as explained in the video.

- ```int * const A;``` -> "A is a const pointer to an int."

- ```const int* const A;``` -> "A is a const pointer to an int that is constant".

## Mutable

- It is a reverse of const when it comes to classes.

    ```c++
    class Entity{
      private:
        int m_X,m_Y;
        mutable int noOfTimesGetCalled=0;
      public:
        int GetX() const{
            //You can make changes to this variable as it is mutable even though the method is const.
            noOfTimesGetCalled++;
            return m_X;
        }
    };
    ```

- 2nd used case is with lambdas
    ```c++
    int x = 10;
    auto f = [=]()
    {
        x++;
        cout << x <<endl;
    };
    ```
    Is not allowed. However if we define this lamda as mutable we can change x even if it is passes as value.
    ```c++
    int x = 10;
    auto f = [=]() mutable
    {
        x++;
        cout << x <<endl;
    };
    ```
## Copying and Copy Constructor



## Arrays

- Contiguous block of data.
- **Using sizeof(array)/sizeof(int) will only work with arrays allocated by stack.**
- you can't have ```int a[size];```. Size has to be known at compile time for stack allocated arrays.
- You can bypass the above by using ```static const int size = 4; int a[size];``` or constexpr.
- Latest c++ standard uses ```std::array<int , 4> a; cout <<a.size(); ``` and has size featuers and bound checking.



## String

- wide characters -> 2 bytes.
- c style string ``` const char* str="hello";```
- null termination character helps in knowing size of string
- in c++ single quote is character type and "" becomes String literal.
- **'\0' is same as 0.**
- wstring
- use strlen strcpy for c style strings.
- **if you want to check if something is in a string or not use->**
  ```c++
    std::string name = "Manish";
    bool contains = name.find("an") != std::string::npos;
  ```
- When passing a string as read only pass it by const reference i.e ```void func(const std::string&  string)```. Won't get copied and non modifiable unknowingly.

## String Literal.
- surrounded by double quotes.
- Stored always in read only parts of memory.
- Even ```char arr[3]="ab"``` the "ab" is in read only even though we can change arr. Additional memory is allocated for arr which is modifiable in this case.
- If declared like ```char *``` We can't edit it.
- If declared like ```char a[]``` we can edit.
- Appending R in front of string literal lets you ignore escape characters and use code like->
    ```c++
    const char* name = R"(Line1
    Line2
    Line3
    Line4)"
    ```
- If you use ```wchar_t* name2=L"Manish";```
- If you use ```char16_t* name2=u"Manish";```
- If you use ```char32_t* name2=U"Manish";```
- If you use ```std::wstring name2 = L"Manish";```
- If you use ```std::u32string name2 = U"Manish";```

## Operators and Operator Overloading
- mathematical operators, dereference, arrow, +=, & operator, << , new, delete, comma operator, paranthesis, == operator.
- [Link](https://en.cppreference.com/w/cpp/language/operators)
- Operator is just a function.
- Operator overloading should be minimal.
- **Important Example showing operator overloading**
    ```c++
    #include<iostream>
    #include<string>
    using namespace std;

    struct Vector2 {
            float x, y;
            Vector2(float x, float y) : x(x), y(y) {}

            Vector2 operator+(const Vector2& a) const
            {
                return Vector2(this->x + a.x, this->y + a.y);
            }

            Vector2 operator*(const Vector2& a) const
            {
                return Vector2(this->x * a.x, this->y * a.y);
            }

            bool operator==(const Vector2& b) const 
            {
            return (this->x == b.x && this->y == b.y);
            }

            bool operator~=(const Vector2& b) const 
            {
            return ~(*this==b);
            }

            Vector2 Add(const Vector2& a) const {
                return operator+(a);
            }

            Vector2 Multiply(const Vector2 & a) const {
                return operator*(a);
            }


    };

    std::ostream& operator<<(std::ostream& stream, const Vector2 &a) {
        stream << to_string(a.x) << " " << to_string(a.y) << endl;
        return stream;
    }


    int main() {
        Vector2 position(1.0f, 3.0f);
        Vector2 speed(2.0f, 51.6f);
        Vector2 powerup(1.1f, 1.1f);
        Vector2 result = position + speed * powerup;
        cout << result;
        //Presidence is still valid.
        cin.get();
    }
    ```


## Compilation and Linking
- A translation unit is the basic unit of compilation in C++. It consists of the contents of a single source file, plus the contents of any header files directly or indirectly included by it, minus those lines that were ignored using conditional preprocessing statements. A single translation unit can be compiled into an object file, library, or executable program.

- extern keyword is gonna make the compiler look for the symbol in some other(external) translation unit.