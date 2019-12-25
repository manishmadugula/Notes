# Introduction

- a template is a model that serves as a pattern for creating similar objects

# Function templates

- A simple function template is as follows:
    ```c++
    template<typename T>
    T max(T x,T y){
        return (x>y) ? x : y;
    }
    ```

- You can name your placeholder types almost anything you want, so long as it’s not a reserved word. However, in C++, it’s customary to name your template types the letter T.

- In order to make this work, we need to tell the compiler two things: First, that this is a template definition, and second, that T is a placeholder type. We can do both of those things in one line, using what is called a template parameter declaration:

  ```c++
  template <typename T> 
  ```
- **To create a template type parameter, use either the keyword typename or class.**

- To use this template type

    ```c++
    int main(){
        int i = max(3, 7); // returns 7
        double d = max(6.34, 18.523); // returns 18.523
        char ch = max('a', '6'); // returns 'a'
        return 0;
    }
    ```
    **Note that you don’t need to explicitly specify the template type in the function name (e.g. the <int> part of max<int>) so long as the compiler can deduce it from the parameter types.**

# Function Templates Instances

- C++ does not compile the template function directly. Instead, at compile time, when the compiler encounters a call to a template function, it replicates the template function and replaces the template type parameters with actual types. The function with actual types is called a function template instance.
- Say we have
    ```c++
    template <typename T> // this is the template parameter declaration
    const T& max(const T& x, const T& y)
    {
        return (x > y) ? x : y;
    }
    ```
    and we call it as
    ```c++
    int i{ max(3, 7) }; // calls max(int, int)
    ```
    Complier automatically creates a template instance for max(int,int)
    ```c++
    const int& max(const int &x, const int &y)
    {
        return (x > y) ? x : y;
    }
    ```
    This is now a “normal function” that can be compiled into machine language.

- The compiler is smart enough to know it only needs to create one template instance per set of unique type parameters (per file). It’s also worth noting that if you create a template function but do not call it, no template instances will be created.

# Template Classes

- Creating template classes works pretty much identically to creating template functions
  ```c++
    template <class T> // This is a template class, the user will provide the data type for T
    class Array
    {
    private:
        int m_length;
        T *m_data;
    
    public:
        Array()
        {
            m_length = 0;
            m_data = nullptr;
        }
    
        Array(int length)
        {
            m_data = new T[length];
            m_length = length;
        }
    
        ~Array()
        {
            delete[] m_data;
        }
    
        void Erase()
        {
            delete[] m_data;
            // We need to make sure we set m_data to 0 here, otherwise it will
            // be left pointing at deallocated memory!
            m_data = nullptr;
            m_length = 0;
        }
    
    
        T& operator[](int index)
        {
            assert(index >= 0 && index < m_length);
            return m_data[index];
        }
    
        // The length of the array is always an integer
        // It does not depend on the data type of the array
        int getLength(); // templated getLength() function defined below
    };
    
    template <typename T> // member functions defined outside the class need their own template declaration
    int Array<T>::getLength() { return m_length; } // note class name is Array<T>, not Array
  ```

 **Note that each templated member function declared outside the class declaration needs its own template declaration. Also, note that the name of the templated array class is Array<T>, not Array -- Array would refer to a non-templated version of a class named Array.**

 ## Important Problem 
 
 - If we split template class declaration (.h) and defination (.cpp) into 2 files as below

    ```c++
    //Array.h
    template <class T>
    class Array
    {
    private:
        int m_length;
        T *m_data;
    public:
        int getLength();
    };
    ```

    ```c++
    //Array.cpp
    #include "Array.h"
 
    template <typename T>
    int Array<T>::getLength() { return m_length; }
    ```

    we run into linking error. In order for the compiler to use a template, it must see both the template definition (not just a declaration) and the template type used to instantiate the template. Also remember that C++ compiles files individually. When the Array.h header is #included in main, the template class definition is copied into main.cpp. When the compiler sees that we need two template instances, Array<int>, and Array<double>, it will instantiate these, and compile them as part of main.cpp. However, when it gets around to compiling Array.cpp separately, it will have forgotten that we need an Array<int> and Array<double>, so that template function is never instantiated. Thus, we get a linker error, because the compiler can’t find a definition for Array<int>::getLength() or Array<double>::getLength().

# Template non-type parameters
A template non-type parameter is a special type of parameter that does not substitute for a type, but is instead replaced by a value. A non-type parameter can be any of the following:

- A value that has an integral type or = enumeration
- A pointer or reference to a class object
- A pointer or reference to a function
- A pointer or reference to a class member function
- std::nullptr_t

```c++
template <class T, int size> // size is the non-type parameter
class StaticArray
{
private:
    // The non-type parameter controls the size of the array
    T m_array[size];
 
public:
    T* getArray();
	
    T& operator[](int index)
    {
        return m_array[index];
    }
};
```

# Function template specialization(Same for class)

- function template specialization (sometimes called a full or explicit function template specialization) to create a specialized version of the print() function for type. simply define the specialized function (if the function is a member function, do so outside of the class definition), replacing the template type with the specific type you wish to redefine the function for. 

```c++
template <>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
}
```

# Variadic Templates

```c++
template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << t <<std::endl ;

    func(args...) ;
}
```