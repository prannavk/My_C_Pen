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
    q + 6; // = q + (4 * 6)
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
    double *res = (p - q);
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

---

## Continue Where you left off

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
