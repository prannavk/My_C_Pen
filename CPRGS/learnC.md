# IMPORTANT NOTES REGARDING C

---

- C Tokens = { Keywords, Identifiers, Constants, Operators }
- Operators = { Arithmetic, Logical, Relational, Bitwise, Assignment, Conditional, Termination, Special }
- Operators are of 3 types:
  - Unary (required only 1 operand)
  - Binary (required 2 operands)
  - Ternary (required 3 operands)
- Arithmetic Operators Set = `{ +, -, \*, /, %, ++, -- }` (++ and -- are unary, rest are binary)
- Bitwise Operators Set = `{ & is AND, | is OR, ^ is XOR , << is Left Shift, >> is Right Shift}`
- Note:
  - For different data types:
    - For int, if(value != 0) true else false
    - For char, if(value != NULL i.e. '\0') true else false
    - For pointer, if(value != NULL pointer) true else false
  - Logical And is denoted by `&&` and bitwise And is denoted by a single ampersand `&`
    - This is the Same with OR, for logical its `||` and for bitwise - `|`
- a << b = `(a * 2 Power b)`.
  - (In left shift, value of 'a' increases as we multiple by 2 Power)
- a >> b = `(a / 2 Power b)`.
  - (In Right shift value of 'b' decreases as we divide by 2 Power)
- Ternary Operators: `c = (a > b)? a : b;`
  - Based on the outcome of the expression to the left of `?`, either of the values are picked after the `?`

## i/o

- scanf(“%X”, &variableOfXType);
  > where %X is the format specifier in C. It is a way to tell the compiler what type of data is in a variable and & is the address operator in C, which tells the compiler to scan the value for this variable, and store it at this address in the memory.
- printf(“%X”, variableOfXType);
  > where %X is the format specifier in C. It is a way to tell the compiler what type of data is in a variable. It prints the data in the variable in that specified format.

## Pointer

- A pointer is a "variable-like" reference that holds a memory address to another variable, array, etc.
- Some tasks are performed more easily with pointers
- Operators are:
  - `*` -> is the Dereference or Indirection operator - (To get the value at an address)
  - `&` -> is the Ampersand operator - (To get the address of a variable)
- The data type of a pointer is the same as the data type of the value, whose address is being stored in it
- You can follow an optional naming convention for pointer variables, where say `var` is the name of a float variable whose pointer i.e. address you want to store. To store its address you will obviously need a float type pointer variable whose identifier name starts with a small 'p' followed by the variable name of value type. i.e. use `Camel` case as:
  ```C
    float var = 3.226;
    float *pVar = &var;
    int accountUpdateFlag = 1;
    int *pAccountUpdateFlag = &accountUpdateFlag
  ```

Note:

> If you are declaring a pointer in 2 steps, i.e. declaring first, then using it later, then its a good practise to store it will NULL while declaring.

```C
  int roll = 7;
  int *pRoll = NULL; // This a good way (Add NULL, instead letting C assign a random garbage address)
  pRoll = &roll;
```

## Pointer Arithmetic

### Increment/Decrement of a Pointer

- Inc/Dec is done by the size of the element pointed (If Integer is pointed, ++ or -- happens by 2 bytes, If Char is pointed, then it happens by 1 byte).
- example:
  ```C
    int *p;
    p++;
    float *fp;
    fp--;
  ```

### Pointer + Integer

- In this case say we try to add a pointer `p` and integer `i`, then `p + i` becomes <b>(p + size of value pointed by p \* i)</b>
- Say we have p's value as 200, and p is an integer pointer, whose size is 2 Bytes then `p + 3` would give us 200 + 3 \* 2 i.e. <b>206</b>
- Bas ye hain ki pointer mein integer ko uske size ke sath multiply karke add karthey hain

### Pointer - Integer

- Same as above, but we substract the value of `i` multiplied by the pointer's size from the pointer variable
- example:
  ```C
    float *q;
    q - 6; // = q - (4 * 6)
  ```

Note:

> The pointer + or - integer operation returns an address and needs to be stored in the pointer variable of the participating pointer type

```C
  double *p, *q;
  double *res1 = p + 7;
  // int *res = p + 7  <-- This is not allowed
```

### Pointer - Pointer

- It basically returns an integer value to show the difference or distance between 2 memory addresses.
- Pointer substraction is possible only among pointer variables of same type (i.e. of same memeory size)
- Say `p` and `q` are 2 pointers, then `p - q` is `[(p - q) / (size of the pointer type)]`.
- example:
  ```C
    double *p, *q;
    int res = (p - q);
  ```
- Say `p` has 480 and `q` has 400, then `res` will store <b>10</b> => ( as (480 - 400) divided by size of double pter i.e. 8 Bytes)

### Comparison

- Between 2 pointers like say (p > q, p <= q, etc) returns true or false if kept in if
- if you want to print, it returns 1 or 0.

Note:

> Addition of 2 Pointers is not possible, as its not allowed and not specified (You'll get a compiler error)

### About void \* (void pointer):

- void\* is type erasure. The machine doesnt know or care what a "bag of bits" represents, which is why malloc just returns a pointer to the beginning of a (now-valid if non-NULL) memory block, which the programmer then casts to specify how those bits are to be interpreted.
- Some Helpful Youtube Videos regarding this:
  - [Why do void \* pointers exist](https://www.youtube.com/watch?v=t7CUti_7d7c)
  - [Why do Header files exist](https://www.youtube.com/watch?v=tOQZlD-0Scc)

### sizeof

- Returns the size of its input in bytes. (Input can be anything).

### Char Constants and ASCII

> ASCII is a 7-bit character set containing 128 characters

- Null is 0
- Tab ('\t') is 9
- Enter ('\t') is 10
- A to Z is 65 to 90
- a to z is 97 to 122
- Character Constants are of 2 types
  - Printable Characters (Whatever can be seen on the screen)
  - Device Control Characters (encodings for character codes like \t, \n, etc)

## ARRAYS

- Collection of data elements of the same type stored consecutively
- Elements of an array can be accessed with the help of indexes
- Note: Address of an element at index `i` i.e. `a[i]`= <b>Base Address of Array + (each element size \* i)</b>
- There are 2 types of arrays:
  ```C
    // Types
    int arr[10]; // -> Normal Array (Gives us 10 memory locations to store 10 integer values)
    int *pArr[10]; // -> Pointer Array (Stores 10 addresses of integers)
  ```
- Array Initialization be like:
  ```C
    int arr[5]; // Gets initialized with 5 random garbage values;
    int arr[3] = {2, 8, 4}; // Gets initialized by 3 hardcoded compiler time values (For dynamic values, need to use a loop and scanf)
    int arr[7] = {22, 48, 6, 8}; // First 4 values gets initialized by the given 4 values, rest values are stored as zeros "0"s.
    int arr[5] = {21, 63, 48, 90, 16, 83, 25}; // gives a compile time error
    int arr[] = {32, 43, 47, 88}; //size of array automatically calculated and taken
    char cha[] = {'v', 'e', 'q', 'o', 'g', 'k'}; // Same with char array
  ```
- To access an element <b>`array_name[index]` and `index[array_name]`</b>, both syntaxes are valid. look at the following example:
  ```C
    int arr[3] = {4, 5, 6};
    printf("%d", arr[1]); // This will print 5
    printf("%d", 1[arr]); // This too will print 5
    printf("%d", *(arr + 1)); // Even this is legal, Here arr gives us the base address (Using pointer arithmetic)
    // Both above are valid
  ```
- Note: Say we have an array `A` , then during pointer arithmetic

  - `A` returns the base address of the array with arithmetic intent dealing with array elements sizes and
  - `&A` returns the base address with arithmetic intent dealing with complete size of the Array.
  - You will see what I mean in the following example:

  ```C
    // Both the below statements are different from each other

    // Say the base address i.e. address of arr[0] is 200, then.....
    printf("%d", *(arr + 1));  // Here, *(arr + 1) gives => (200 + 1 * (1 element size i.e. 2 Bytes)) => 202
    // Output of above statement is data at address 202
    printf("%d", *(&arr + 1)); // Here, *(&arr + 1) gives => (200 + 1 * (Size of array arr i.e. 10 Bytes)) => 210
    // Output of above statement is data at address 210
  ```

## 2D Arrays

- 2D Arrays initilized as `array_name[rows][columns]`
- To store 2D arrays we have 2 schemes:
  - Row Major Order (Used by Default in C)
  - Column Major Order
- In Row Major Order: Basically Address of `A[i][j]` = Base + Size of each element(i \* n + j)
- In Column Major Order: Basically Address of `A[i][j]` = Base + Size of each element(j \* m + i)
- Note: n is number of coulmns and m is number of rows
- Declaration of Multidimensional arrays in C must have bounds for all dimensions except the first
- Here, in 2D Arrays:
  - `A` -> Gives address of first row
  - `A + 1` -> Addition by Size of row
  - `A + or - n` -> Addition/Subtraction by (n \* size of row)
  - `A[0]` -> Gives address of zeroth i.e. first row in 2D Array (or ith row if `A[i]`)
  - `A[0] + 1` -> Addition by size of row
  - `&A` -> Gives Address of Array
  - `&A + 1` -> Addition by size of complete array
  - `&A[2][3]` -> Gives Address of an element
  - `&A[2][3] + 1` -> Addition by size of an element
- Accessing an element inside a 2D array with the help of pointer dereferencing:
  - For `A[i][j]` -> _(_(A + i) + j)

## Type Converions

- Converting the type of 1 variable to another for different purposes
- Its of 2 type: Implicit and Explicit
- <b>Note:</b> Type casting has higher precedence than division (In the below example (double) is executed before division is done)
  ```C
    int a = 5, b = 2;
    double c = (double) a / b;
    // Here a is converted to double first then divided by b. Since b is an int, for compatibility, C implicitly 'promotes' b to a double
  ```

## Structure and Union

### Structure

- Is a User-Defined Data Type
- Used to store collection of heterogenous data elements
- We define one using the 'struct' keyword as:
  ```C
  struct student
  {
    int rno;
    int age;
    float fees;
  };
  ```
- If we try to access a member of a struct using a variable of that struct type, we use `dot` operator and if we try to access using a pointer we use `->`.

  1. structVar.Member (Variable to Member Access)
  2. structPtr -> Member (Pointer to Member Access)

- Note: Pointer Arithmetic using Pointer to struct be like
  - Say 'P' is a pointer to a struct type variable then if we do (P + i), it will add I \* the size of the entire struct memory space. (To calculate the struct memory space we need to add the memory sizes of all its member types)

### Union

- It is an overlapping structure
- The element with the highest memory space gets memory allocation
- Note:
  > Space allocated to union type variable = MAX (size of members)<br/>
  > Space allocated to struct type variable = SUM (size of members)<br/>
- We can use only 1 member at a time.
- If we insert data into 1 member of a union type variable, then it gets allocation. Now if we set data to another member of the same variable, the previously set member's data is lost.
- Consider the union:

  ```C
    union berlin
    {
      int row;
      char div;
    } ub1;

    int main()
    {
      ub1.div = 'B';
      // Above allocation is done and value is stored
      ub1.row = 44;
      // This allocation is done and value is stored, but the value of the div member is lost
      return 0;
    }
  ```

---

## Functions in C

- When we want to write functions in C code we need to ensure the following are implemented/written in the code:
  - Declaration
    - eg: float func_name(int, int, float);
    - eg2: int* fun1(int *); // input and input both are integer pointers
    - eg3: int fun(void);
    - eg4: int fun()
      - both eg 3 and 4 are allowed
    - eg5: void fun();
  - Definition
  - Call
- In functions parameters can be passed to them in 2 ways:
  - Pass by Value
  - Pass by Reference

---

## Storage Classes

- A Process in the memory must have these 4 sections:

  1. Code Section -> Compiled Instructions
  2. Data Section -> Global and Static Variables
  3. Heap Section -> Dynamic Memory Allocation
  4. Stack Section -> Function Activation Records (Local Variables, Function parameters and return address)

- There are 4 characteristics of a variable:

  - Lifetime
  - Scope
  - Initialization
  - Location of storage in memory

- All Local variables are by default of the 'auto' storage class type.
- By default, global int varaibles are initialised with 0 on declaration and local int variables are initialised with a garbage value on initialisation.

- variables with 'register' storage class are stored in the registers of the CPU.
- Say there are 40 'register' variables in the Program and the CPU has only 32 registers, in this case, the remaining are stored in the main memory stack.

- Automatic variables in C are of 2 types:

  1. auto
  2. register

- 'static' variables can be local or global.
- Both local and global 'static' variables are stored in the Data Section and initialised with '0' on declaration by default.
- The scope of a local 'static' variable is during the function or block of code, but its lifetime is during the entire program.
- A static variable is initialised and its memory is allocated when the execution of a program begins and throughout the program the same memory is used.

## FAR (Function Activation Record)

- A Data structure that is activated when a function is invoked
- It includes:
  - Actual Parameters
  - Number of Arguments
  - Return Address
  - Return Value
  - Old Stack Pointer
  - Local Data in Function/Procedure
- This Activation record is created and stored in the stack

## Recursion

- Function calling itself
- Recursive Function should have a base/exit condition for which it does not call itself
- Types Of Recursion:
  1. Direct
     1. Tail Recursion (Very last stmt of fun body is recursive call)
     2. Head Recursion (recursive call should not be the last stmt)
     ```C
      fun f() {
        ---
        ---
        f()
        ---
      }
     ```
  2. Indirect
     ```C
      fun A() {
        B()
      }
      fun B() {
        A()
      }
     ```
  3. Nested (Recursive call in another call)
     ```C
      fun (a, fun(b, c))
     ```

---

## Defining Constants

- We can do it in 2 ways:
  1. using `const` keyword
  - When declaring a variable using `const` keyword, we must provide the value at the time of declaration.
  ```C
    const int a = 7, b = 8; // Legal
    const float pi; // Gives ERROR
  ```
  2. using macro
  - We need to declare these at the top of the program, along with the header file inclusion statements and outside all the functions
  - While defining macros, there is no datatype, no equal to statements and no semicolon
  ```C
    #define NAME value
  ```

## Macros

- When using Macros, even before the compilation starts, the defined token is replaced by the value in the entire program, every place its used.
- Macros can't be used for user defined data types.
- Macros are also preprocessor directives
- we can use macros with functions too like:
  ```C
    #include <stdio.h>
    #define EXPRESSION1(A, B, C) (A * (B + 1) - (C % 223))
    int main() {
      printf("Expression result: %lf\n ", EXPRESSION1(38, 42, 4460));
      return 0;
    }
  ```

## Strings

- Strings in C are char arrays
  ```C
    char A[] = "Hello"; // Stored as H, e, l, l, o, \0 i.e. 6 characters
  ```
- Null characters are automatically added at the end of string to denote the end of string

## Dynamic Memory Allocation

- Dynamic Memory gets allocated in the heap area of the process of the program
- We have 3 functions which are included in the stdlib.h standard library in C. They are:

  1. <b>malloc()</b> - for allocation
     - Used to dynamically allocate a single large block of memory with the specified size
     - It returns a pointer of type void (We need to explicitly type cast into our required type)
     - If space is insufficient, allocation fails and returns a NULL pointer.
     - It doesn't initialize memory i.e. garbage value is printed if we try to print
     - Syntax:
     ```C
      // pointer = (cast-type*)malloc(size_in_bytes)
      int *p = (int*)malloc(sizeof(int));
     ```
  2. <b>calloc()</b> - for allocation
     - In malloc it allocates memory for a single block, with the help of calloc it gives us allocation for multiple blocks of memory
     - calloc stands for 'contiguous allocation'
     - Used to dynamically allocate specified number of blocks of memory of the specified type
     - returns a pointer of type void which needs to be type casted and if space is insufficient, allocation fails and NULL is returned
     - It initializes memory with 0
     ```C
      // pointer = (cast-type*)calloc(n, element_size_in_bytes)
      int *p = (int*)calloc(100, sizeof(int));
     ```
  3. <b>free()</b> - for deallocation
     - Used to deallocated only dynamically allocated spaces and not static memory
     - eg:
     ```C
      int *p = (int*)malloc(sizeof(int));
      free(p);
      // Note: Here p might become a dangling pointer i.e. pointer points to a location which doesn't even exist
      // To remove this dangling pointer the following line will do it
      p = NULL;
     ```

- Using malloc() for data structures

  - Say in Linked List we can have:

  ```C
    struct node {
      char data;
      struct node *next;
    };

    // Inside main or any function or block:
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
  ```

  - Say in Binary Tree we can have:

  ```C
    struct BTnode {
      char data;
      struct BTnode *LChild;
      struct BTnode *LChild;
    };

    // Inside main or any function or block:
    struct BTnode *new_node = (struct BTnode*)malloc(sizeof(struct BTnode));
  ```

## Double Pointer

- A pointer which stores the address of another pointer
- Example:

  ```C
    void main() {
      int A[5] = {1, 2, 3, 4, 5};
      int *p = &A[0];
      int **pp = &p;

      // Say we want to access A[2] i.e. '3', we can do it as either:
      printf("\n%d ", A[2]);
      // or (using pointers)
      printf("\n%d ", *(p + 2));
      printf("\n%d ", *(*pp + 2));
    }
  ```

---

## Useful Links for Youtube Tutorials

https://www.youtube.com/watch?v=N74PmXAYtBU&list=PLbE3-5DBkMUkATaUFgDIpBDbfnym0qvsQ&index=3

https://www.youtube.com/watch?v=q24-QTbKQS8
https://www.youtube.com/watch?v=CHs9WwvEKdg
https://www.youtube.com/watch?v=DplxIq0mc_Y
https://www.youtube.com/watch?v=MIL2BK02X8A
https://www.youtube.com/watch?v=ZdQj0ivvfNs
https://www.youtube.com/watch?v=Vd-4eGnBAK8
https://www.youtube.com/watch?v=t7CUti_7d7c
https://www.youtube.com/watch?v=pS3C0Rk621M
https://www.geeksforgeeks.org/basic-input-and-output-in-c/?ref=lbp
https://www.geeksforgeeks.org/format-specifiers-in-c/
https://www.cs.fsu.edu/~myers/c++/notes/c_io.html
https://www.youtube.com/watch?v=iLZOL-hmr7M
https://www.geeksforgeeks.org/escape-sequence-in-c/
https://unstop.com/blog/escape-sequence-in-c
