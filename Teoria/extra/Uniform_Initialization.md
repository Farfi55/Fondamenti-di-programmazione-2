# Uniform Initialization in C++

copiato da <https://www.geeksforgeeks.org/uniform-initialization-in-c/>, dove potete trovare anche altri esempi

Uniform initialization is a feature in C++ 11 that allows the usage of a consistent syntax to initialize variables and objects ranging from primitive type to aggregates. In other words, it introduces brace-initialization that uses braces `{}` to enclose initializer values. The syntax is as follows:

`type var_name{arg1, arg2, ....arg n}`

### Following are some of the examples of the different ways of initializing different types:

```cpp
// uninitialized built-in type
int i;    

// initialized built-in type
int j=10; 

// initialized built-in type
int k(10);

// Aggregate initialization
int a[]={1, 2, 3, 4} 

// default constructor
X x1; 

// Parameterized constructor
X x2(1); 

// Parameterized constructor with single argument
X x3=3; 

// copy-constructor
X x4=x3; 
```

### If initialized using brace initialization, the above code can be re-written as:

```cpp
int i{};     // initialized built-in type, equals to int i{0};

int j{10}; // initialized built-in type

int a[]{1, 2, 3, 4} // Aggregate initialization

X x1{}; // default constructor

X x2{1}; // Parameterized constructor;

X x4{x3}; // copy-constructor
```
