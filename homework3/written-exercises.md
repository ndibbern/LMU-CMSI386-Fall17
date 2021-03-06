# CMSI 386 - HW 3

1. (5 pts) Given the C++ declaration:

   ```c++
   struct {
     int n;   // 4bytes -> 4 x 8 bits
     char c;  // 1byte  -> 8 bits
   } A[10][10];
   ```

   On your machine, find the address of `A[0][0]`  and `A[3][7]` . Explain why these values are what you found them to be.

   output:

   ```sh
   0x1043040a0
   0x1043041c8
   ```

   These values correspond to 4365238432 and 4365238728 in decimal respectively, which are separated by 296 bits.

   $(3 * 10  + 7) * 8 = 296$.

   Each entry in the array takes up 8 bytes. Even though a struct that takes up 5 bytes is stored in each position, data alignment or *padding*, which increases the system's performance due to the way the CPU handles memory. struct-padding is done differently by different compilers. To access the location of the struct in the 3,7 location, because c++ stores the elements of an array sequentially, this is equivalent to the array location $3*10+7$ passed the first entry at A\[0][0] corresponding to memory address  $(3 * 10  + 7) * 8 + A[0][0]$.

2. (5 pts) Explain the meaning of the following C++ declarations:

   ```c++
   double *a[n]; //1
   double (*b)[n]; //2
   double (*c[n])(); //3
   double (*d())[n]; //4
   ```
   1. An array of n pointers to memory locations storing doubles
   2. A pointer to an array containing n doubles
   3. An array containing n pointers to memory locations storying functions with return type double
   4. A function that returns a pointer to an array containing n doubles

3. Consider the following declaration in C++:

   ```c++
   double (*f(double (*)(double, double[]), double)) (double, ...);
   ```

   Describe rigorously, in English, the type of f.

   `f` is a function that returns a pointer to `double (double, ...)`, which is a function that takes a `double` followed by `varargs` and returns a `double`.

   The parameters of `f` are `(double (*) (double, double[]), double)`, a pointer to a function that takes a `double` and an array `double[]` and returns `double` as the first argument, and a `double` as the second argument.

4. What happens when we “redefine” a field in a C++ subclass? For example, suppose we have:

   ```c++
   class Base {
   public:
     int a;
     std::string b;
   };

   class Derived: public Base {
   public:
     float c;
     int b;
   };
   ```

   Does the representation of a Derived object contain one b field or two? If two, are both accessible, or only one? Under what circumstances? Tell the story of how things are.

   The derived object has one `b` field of type `int`, however it has access to its parents `b` field trough the syntax `Parent::field`, in this case `Base::b` . This is possible in this case because Base's b field is public.

5. What does the following C++ program output?

   ```c++
   #include <iostream>
   int x = 2;
   void f() { std::cout << x << '\n'; }
   void g() {
     int x = 5;
     f();
     std::cout << x << '\n'; }
   int main() {
     g();
     std::cout << x << '\n';
   }
   ```

   ##### Output:

   ```sh
   2
   5
   2
   ```

   Verify that the answer you obtained is the same that would be inferred from apply the rules of static scoping. If C++ used dynamic scoping, what would the output have been?

   In general **Static** means before you run, **Dynamic** means while you run

   ##### Statically Scoped

   A *block* defines a new scope. Variables can be declared in that scope, and aren't visible from the outside. However, variables outside the scope -- in enclosing scopes -- are visible unless they are overridden.

   ##### Dynamically Scoped

   We first look for a local definition of a variable. If it isn't found, we look up the calling stack for a definition. The output would be:

   ```sh
   5
   5
   2
   ```

6. Suppose you were asked to write a function to scramble (shuffle) a given array, in a mutable fashion. Give the function signature for a shuffle function for (a) a raw array, and (b) a std::array.

   ```c++
   void shuffle (int& arr[]) {
    ...
   }

   template<std::size_t SIZE>
   void shuffle(std::array<int, SIZE>& arr) {
   ...
   }
   ```

   ​
