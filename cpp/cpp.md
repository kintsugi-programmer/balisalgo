# cpp
## Index
- [cpp](#cpp)
  - [Index](#index)
  - [C++ Basic Input/Output](#c-basic-inputoutput)
    - [Including Libraries](#including-libraries)
    - [Skeleton of a C++ Program](#skeleton-of-a-c-program)
    - [Output with `cout`](#output-with-cout)
    - [Input with `cin`](#input-with-cin)
    - [Including All Standard Libraries](#including-all-standard-libraries)
    - [Key Points](#key-points)
  - [Datatypes](#datatypes)
    - [Data Types in C++](#data-types-in-c)
    - [Input and Output](#input-and-output)
    - [Comments](#comments)
    - [Memory Usage](#memory-usage)
    - [Key Points](#key-points-1)
    - [Explanation:](#explanation)
  - [If Else Conditional Statements](#if-else-conditional-statements)
    - [Basic Syntax of Nested if-else](#basic-syntax-of-nested-if-else)
    - [Key Takeaways](#key-takeaways)
  - [Switch Case](#switch-case)
  - [What are arrays, strings?](#what-are-arrays-strings)
    - [Arrays:](#arrays)
    - [Strings:](#strings)
  - [For loops](#for-loops)
    - [For Loop Overview:](#for-loop-overview)
    - [Example:](#example)
    - [Nested For Loops:](#nested-for-loops)
    - [Example:](#example-1)
    - [Conditionals Inside For Loops:](#conditionals-inside-for-loops)
    - [Customizing For Loops:](#customizing-for-loops)
    - [Example:](#example-2)
  - [While Loops](#while-loops)
    - [While Loop Basics:](#while-loop-basics)
    - [Example: Calculating Factorial](#example-calculating-factorial)
    - [Do-While : Run 1 time (even if condition is not true)](#do-while--run-1-time-even-if-condition-is-not-true)
    - [Best Practices and Optimization:](#best-practices-and-optimization)
    - [Example: Using `break` and `continue`](#example-using-break-and-continue)
    - [Summary:](#summary)
  - [Functions](#functions)
    - [Functions in C++](#functions-in-c)
      - [What are Functions?](#what-are-functions)
      - [Types of Functions](#types-of-functions)
      - [Passing Parameters](#passing-parameters)
      - [Arrays and Functions](#arrays-and-functions)
    - [Key Takeaways](#key-takeaways-1)
      - [Code](#code)

## C++ Basic Input/Output

### Including Libraries
- libraries provide pre-built functions and tools for us to use in our code.
- **#include<iostream>**: Used for input and output operations.
- **#include<math.h>**: Used for mathematical functions.

### Skeleton of a C++ Program
- **Main Function**: The entry point of the program.
```cpp
#include<iostream>

int main() {
    // Your code here
    return 0;
}
```

### Output with `cout`
- **std::cout**: Used to display output.
- **Using std Namespace**:
```cpp
#include<iostream>

int main() {
    std::cout << "Hello, World!";
    return 0;
}
```
- **Newline Character**: Use `\n` or `std::endl` for new lines.
```cpp
#include<iostream>

int main() {
    std::cout << "Hello, World!\n";
    std::cout << "Hello, again!" << std::endl;
    return 0;
}
```
- **Using `namespace std`**:
```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

### Input with `cin`
- **std::cin**: Used to take input from the user.
```cpp
#include<iostream>
using namespace std;

int main() {
    int x; 
    cin >> x; //The program waits for user input.
    //You enter a value (e.g., 10) and press Enter.
    //cin reads the entered value and stores it in the variable x.
    cout << "Value of x: " << x; ////You enter a value (e.g., 10) and press Enter.
    return 0;
}
```
- **Multiple Inputs**: To accept multiple inputs, we can simply use the >> operator with cin for each variable we want to receive input for. 
- Inputs can be
  - 12 13
  - 12
    13
```cpp
#include<iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}
```

```
3 4
```
```
Value of x: 3 and y: 4
```
```
3
4
```
```
Value of x: 3 and y: 4

```

### Including All Standard Libraries
- **#include<bits/stdc++.h>**: A shortcut to include almost all standard libraries C++.
1. `#include` is a preprocessor directive that includes the contents of a specified file into the program.
2. `<bits/stdc++.h>` is a non-standard header that includes all standard C++ libraries, primarily used in GCC.
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}
```

### Key Points
- **#include<iostream>**: For basic input/output operations.
- **std::cout**: For output.
- **std::cin**: For input.
- **\n vs std::endl**: `\n` is faster as it doesn't flush the output buffer and just insert a newline character.std::endl insert a newline character and flush the output buffer.\n is a simple escape sequence that inserts a newline character, which is a low-level operation that directly moves the cursor to the beginning of the next line in the output.Flushing the buffer can be a more costly operation in terms of performance, especially when you're printing a large amount of text.


- **using namespace std**: Simplifies code but use cautiously to avoid naming conflicts.
- **#include<bits/stdc++.h>**: Convenient but may affect compile time.

## Datatypes
### Data Types in C++

1. **Integer (`int`)**:  
   - Used to store whole numbers.  
   - Example: `int x = 10;`  
   - Range: Typically from -2^31 to 2^31-1 (4 bytes, 32 bits).  

2. **Long (`long`)**:  
   - Used for larger integers.  
   - Example: `long x = 1000000000;`  
   - Range: Typically from -2^63 to 2^63-1 (8 bytes, 64 bits).  

3. **Long Long (`long long`)**:  
   - Used for even larger integers.  
   - Example: `long long x = 1000000000000000;`  
   - Range: Typically from -2^63 to 2^63-1 (8 bytes, 64 bits).  

4. **Float (`float`)**:  
   - Used to store numbers with decimals.  
   - Example: `float x = 5.6;`  
   - Range: Approximately ±3.4E-38 to ±3.4E+38 (4 bytes, 32 bits).  

5. **Double (`double`)**:  
   - Used for larger floating-point numbers.  
   - Example: `double x = 5.6;`  
   - Range: Approximately ±1.7E-308 to ±1.7E+308 (8 bytes, 64 bits).  

6. **String (`string`)**:  
   - Used to store sequences of characters.  
   - Example: `string s = "Hello";`  
   - To read an entire line: `getline(cin, s);`  
   - Size varies based on content; typically uses 1 byte per character.  

7. **Character (`char`)**:  
   - Used to store single characters.  
   - Example: `char ch = 'A';`  
   - Enclosed in single quotes.  
   - Size: 1 byte (8 bits).  



### Input and Output
- **Reading input**:
  - Integers: `cin >> x;`
  - Floating points: `cin >> x;`
  - Strings: `cin >> s;` (reads up to the first space)
  - Entire line: `getline(cin, s);`

- **Printing output**:
  - `cout << x;`

### Comments
- **Single-line comment**: `// This is a comment`
- **Multi-line comment**: 
  ```cpp
  /* This is a 
     multi-line comment */
  ```

### Memory Usage
- Different data types consume different amounts of memory.
- Choose data types based on the range of values you need to store.
- `int` for small numbers, `long` for larger numbers, `long long` for very large numbers, `float` for decimal numbers, `double` for larger decimal numbers, and `char` for single characters.

### Key Points
- Use the appropriate data type to save memory.
- `int` is suitable for most integer operations.
- `long` and `long long` are used when `int` is not sufficient.
- `float` and `double` are used for floating-point operations.
- `char` for single characters and `string` for text.
- `getline(cin, str_var);` reads the entire line into a string.

By following these guidelines, you can effectively manage and utilize different data types in your programs.
Sure, here is a single C++ program that includes examples of all the mentioned data types and concepts:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Integer example
    int x = 10;
    cout << "Integer x: " << x << endl;

    // Long example
    long y = 1000000000;
    cout << "Long y: " << y << endl;

    // Long Long example
    long long z = 1000000000000000;
    cout << "Long Long z: " << z << endl;

    // Float example
    float f = 5.6;
    cout << "Float f: " << f << endl;

    // Double example
    double d = 1234567.89;
    cout << "Double d: " << d << endl;

    // String example
    string s = "Hello, World!";
    cout << "String s: " << s << endl;

    // Getline example for string input
    cout << "Enter a line of text: ";
    string line;
    getline(cin, line);
    cout << "You entered: " << line << endl;

    // Character example
    char ch = 'A';
    cout << "Character ch: " << ch << endl;

    // Input examples
    cout << "Enter an integer: ";
    int inputInt;
    cin >> inputInt;
    cout << "You entered: " << inputInt << endl;

    cout << "Enter a float: ";
    float inputFloat;
    cin >> inputFloat;
    cout << "You entered: " << inputFloat << endl;

    cout << "Enter a string: ";
    string inputString;
    cin >> inputString; // This will only take the first word
    cout << "You entered: " << inputString << endl;

    // Clear the input buffer before using getline again
    cin.ignore();

    // Full Line String enter
    cout << "Enter a full line of text: ";
    string fullLine;
    getline(cin, fullLine);
    cout << "You entered: " << fullLine << endl;

    cout << "Enter a character: ";
    char inputChar;
    cin >> inputChar;
    cout << "You entered: " << inputChar << endl;

    return 0;
}
```

### Explanation:
- The code includes examples of `int`, `long`, `long long`, `float`, `double`, `string`, and `char`.
- It demonstrates how to take input and print output for each type.
- It uses `getline` to read an entire line of text.
- It includes the necessary `#include` statements and uses the `std` namespace.

## If Else Conditional Statements

**Conditional Statements in Programming**

Conditional statements are fundamental in programming, allowing decisions based on certain conditions. They enable different blocks of code to execute depending on whether specific conditions are met.

**The `if-else` Statement**

- **`if` statement:** Executes a block of code only if a certain condition is true.
- **`else` statement:** Executes a block of code if the `if` condition is false.

**Flow of Control:**

1. If the condition in the `if` statement is true, the code inside the `if` block executes.
2. If the condition is false, the code inside the `else` block (if present) executes.

**Example:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int age = 10;

    if (age >= 18) {
        cout << "You are an adult." << endl;
    } else {
        cout << "You are not an adult." << endl;
    }
}
```

**Output:**

```
You are not an adult.
```

**Simplifying Code with `else if`**

When you need to check multiple conditions, use `else if` statements to streamline your code.

```
marks
                            |
                            v
                 +----------------------+
                 | marks smaller than 25|
                 +----------------------+
                   /                  \
                TRUE                 FALSE
                 /                      \
                v                        v
          +----------+        +------------------------+
          | GRADE: F |        | marks greater than or  |
          +----------+        | equal to 25 but smaller|
                              |    than or equal to 44?|
                              +------------------------+
                                /                    \
                              TRUE                  FALSE
                               /                      \
                              v                        v
                        +----------+        +------------------------+
                        | GRADE: E |        | marks greater than 44  |
                        +----------+        | but smaller than or    |
                                            |    equal to 49?        |
                                            +------------------------+
                                              /                    \
                                            TRUE                  FALSE
                                             /                      \
                                            v                        v
                                      +----------+        +------------------------+
                                      | GRADE: C |        | marks greater than 49  |
                                      +----------+        | but smaller than or    |
                                                          |    equal to 59?        |
                                                          +------------------------+
                                                            /                    \
                                                          TRUE                  FALSE
                                                           /                      \
                                                          v                        v
                                                    +----------+        +------------------------+
                                                    | GRADE: B |        | marks greater than 59  |
                                                    +----------+        | but smaller than or    |
                                                                        |    equal to 70?        |
                                                                        +------------------------+
                                                                          /                    \
                                                                        TRUE                  FALSE
                                                                         /                      \
                                                                        v                        v
                                                                  +----------+            +---------------+
                                                                  | GRADE: A |            | INVALID MARKS |
                                                                  +----------+            +---------------+
```

**Example: Grading Students Based on Marks**
```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 54;

    if (marks < 25) {
        cout << "Grade: F" << endl;
    } 
    if (marks >= 25 && marks <= 44) {
        cout << "Grade: E" << endl;
    } 
    if (marks >= 45 && marks <= 49) {
        cout << "Grade: D" << endl;
    } 
    if (marks >= 50 && marks <= 59) {
        cout << "Grade: C" << endl;
    } 
    if (marks >= 60 && marks <= 69) {
        cout << "Grade: B" << endl;
    } 
    if (marks >= 70) {
        cout << "Grade: A" << endl;
    } 
    else {
        cout << "Invalid marks entered." << endl;
    }

    return 0;
}
```
- At Above all if block will run
- Benefit of if else that if one block run then other else/else if blocks are skipped ;0 Like Below

```cpp
#include <iostream>
using namespace std;

int main() {
    int marks = 54;

    if (marks < 25) {
        cout << "Grade: F" << endl;
    } else if (marks >= 25 && marks <= 44) {
        cout << "Grade: E" << endl;
    } else if (marks >= 45 && marks <= 49) {
        cout << "Grade: D" << endl;
    } else if (marks >= 50 && marks <= 59) {
        cout << "Grade: C" << endl;
    } else if (marks >= 60 && marks <= 69) {
        cout << "Grade: B" << endl;
    } else if (marks >= 70) {
        cout << "Grade: A" << endl;
    } else {
        cout << "Invalid marks entered." << endl;
    }

    return 0;
}
```

**Output:**

```
Grade: C
```

**Refactored Code for Better Readability:**
We can refactor the code, we can remove the lower bounds and check only the upper bounds for each grade as the code flow is such that we move along the conditions only after satisfying the previous one.

```cpp
#include <iostream>

int main() {
    int marks = 54;
    char grade;

    if (marks < 25) {
        grade = 'F';
    } else if (marks <= 44) {
        grade = 'E';
    } else if (marks <= 49) {
        grade = 'D';
    } else if (marks <= 59) {
        grade = 'C';
    } else if (marks <= 69) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'A';
    } else {
        grade = 'X'; // Use 'X' to indicate invalid marks
    }

    std::cout << "Grade: " << grade << std::endl;
    
    return 0;
}
```

**Output:**

```
Grade: C
```

### Basic Syntax of Nested if-else
```

if(condition1)
{
    // Code to be executed 
    if(condition2)
    {
        // Code to be executed
    }
    else
    {
         // Code to be executed
    }
}
else
{
    // code to be executed
}
```

### Key Takeaways

- Conditional statements like `if`, `else`, and `else if` are essential for controlling the flow of your program.
- `if` statements execute code based on whether a condition is true.
- `else` statements handle the case when the `if` condition is false.
- `else if` statements allow for checking multiple conditions sequentially.
- Refactoring code by simplifying conditions can improve readability and maintainability.

Mastering these basics is crucial for any aspiring programmer to write dynamic and responsive code.

## Switch Case
**Switch Case Statements Overview**

**1. Use Cases:**
- **If-Else Statements:** Flexible, handle complex conditions and branching logic, used for non-enumerable conditions or various blocks of code based on conditions.
- **Switch Statements:** Simplify cases with multiple exact matches, making code cleaner and structured.

**2. Basic Structure:**
- Used to compare a variable against multiple distinct values.
- Commonly used for evaluating integer or character values.

```
+--------+
    | START  |
    +--------+
         |
         v
    +----------+
    | switch : |
    +----------+
         |
         v
    +--------------+    TRUE    +-------------+    +-------+
    | case         |----------->| statement 1 |--->| break |----+
    | condition 1  |            +-------------+    +-------+    |
    +--------------+                                            |
         | FALSE                                                |
         v                                                      |
    +--------------+    TRUE    +-------------+    +-------+    |
    | case         |----------->| statement 2 |--->| break |----+
    | condition 2  |            +-------------+    +-------+    |
    +--------------+                                            |
         | FALSE                                                |
         v                                                      |
    +--------------+    TRUE    +-------------+    +-------+    |
    | case         |----------->| statement 3 |--->| break |----+
    | condition 3  |            +-------------+    +-------+    |
    +--------------+                                            |
         | FALSE                                                |
         v                                                      |
    +-----------+            +------------------+               |
    | DEFAULT   |----------->| Default Statement|---------------+
    +-----------+            +------------------+               |
                                                                |
                                                                |
    +-------------------------+                                 |
    | Code after Switch-Case  |<--------------------------------+
    +-------------------------+
         |
         v
    +--------+
    |  END   |
    +--------+
```

**Example: Day of the Week**
```cpp
#include <iostream>
using namespace std;

int main() {
    int day = 4;

    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid";
    }

    return 0;
}
// Output: Thursday
```

- **cout<<" INside Check"; is part of switch() {} but when break run whole SWITCH BLOCK SKIPPED ;0**
  ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        int day = 4;

        switch (day) {
            case 1:
                cout << "Monday";
                break;
            case 2:
                cout << "Tuesday";
                break;
            case 3:
                cout << "Wednesday";
                break;
            case 4:
                cout << "Thursday";
                break;
            case 5:
                cout << "Friday";
                break;
            case 6:
                cout << "Saturday";
                break;
            case 7:
                cout << "Sunday";
                break;
            cout<<" INside Check";

        }
        cout<<" Check";
        return 0;
    }

    // Output: Thursday Check

  ```
**Key Points:**
- **Break Statement:** Ensures exit after the matching case, preventing the execution of subsequent cases.
- **Default Case:** Acts as a safety net if none of the cases match.after default you need break to stop statements(non case statements) below it and in switch block 

**3. Requirements:**
- **Constant Expression:** Switch expression must result in a constant value (including constants and arithmetic operations).

**Example: Constant Expression**
```cpp
#include <iostream>
using namespace std;

int main() {
    const int x = 10;
    const int y = 5;

    switch (x + y) {
        case 15:
            cout << "Result is 15." << endl;
            break;
        case 20:
            cout << "Result is 20." << endl;
            break;
        default:
            cout << "No match found." << endl;
    }

    return 0;
}
// Output: Result is 15.
```

- **Integer or Character Types:** Only handles int or char values.

**Example: Character Type**
```cpp
#include <iostream>
using namespace std;

int main() {
    char grade = 'B';

    switch (grade) {
        case 'A':
            cout << "Excellent!" << endl;
            break;
        case 'B':
            cout << "Good!" << endl;
            break;
        default:
            cout << "Not specified." << endl;
    }

    return 0;
}
// Output: Good!
```

**4. Considerations:**
- **Break Keyword:** Important to exit the switch statement; without it, subsequent cases execute.
- **Optional Default Case:** Executes if none of the cases match; can be omitted if not needed.
- **No Duplicate Case Values:** Each case value must be unique.

**Example: Duplicate Case**
```cpp
#include <iostream>
using namespace std;

int main() {
    int day = 2;

    switch (day) {
        case 1:
            cout << "Monday." << endl;
            break;
        case 2:
            cout << "Tuesday." << endl;
            break;
        case 2:  // Duplicate case, not allowed
            cout << "Duplicate case." << endl;
            break;
        default:
            cout << "Invalid day." << endl;
    }
    return 0;
}
```

**5. Nested Switch Statements:**
- Possible but discouraged due to complexity and readability issues.

**Example: Nested Switch**
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 2;
    int y = 3;

    switch (x) {
        case 1:
            cout << "x is 1." << endl;
            switch (y) {
                case 1:
                    cout << "y is 1." << endl;
                    break;
                default:
                    cout << "y is not 1." << endl;
            }
            break;
        default:
            cout << "x is not 1." << endl;
    }

    return 0;
}
```

By understanding these points, you can effectively utilize switch statements for specific scenarios, ensuring clean and readable code.

## What are arrays, strings?

### Arrays:
- Arrays are used to store multiple elements of the same data type sequentially.
- Each element in the array is accessed using an index (starting from 0).
- Useful when you have a large number of similar data items (e.g., integers) to store.
- Can be modified and accessed using index references.
- 2D arrays are used to store elements in rows and columns, useful for matrix and grid-based problems.

### Strings:
- Strings are sequences of characters stored in contiguous memory.
- Each character in the string has an index starting from 0.
- Length of a string can be obtained using `.size()` or `.length()` functions.
- Characters in a string can be accessed and modified using their respective indices.
- Strings are immutable in C++ (individual characters can be modified, but the whole string cannot be reassigned directly).

Sure, here's a simple example that combines both arrays and strings in C++:
Input

i love it 
```cpp
cin >> arr1[0] >> arr1[1] >> arr1[2];
```
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Example of an integer array
    int arr[5] = {3, 4, 5, 7, 2};
    int arr1[3];
    cin >> arr1[0] >> arr1[1] >> arr1[2];

    // Accessing and printing elements of the array
    cout << "Elements of the integer array: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //2D Array
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    arr2D[1][2] = 10;
    cout << "Elements of the 2D integer array: ";

    // Modifying an element in the array
    arr[3] += 10;
    cout << "Modified element at index 3: " << arr[3] << endl;

    // Example of a string
    string str = "Hello, World!";
    str[str.size() - 1] = '.';

    // String size
    int size = str.size();

    // Accessing and printing characters of the string
    cout << "Characters of the string: ";
    for (int i = 0; i < str.size(); ++i) {
        cout << str[i] << " ";
    }
    cout << endl;

    // Modifying a character in the string
    str[7] = 'E';  // Changing 'W' to 'E'
    cout << "Modified string: " << str << endl;

    return 0;
}
// Input: 1 2 3

// Output
// Elements of the integer array: 3 4 5 7 2 
// Elements of the 2D integer array: Modified element at index 3: 17
// Characters of the string: H e l l o ,   W o r l d . 
// Modified string: Hello, Eorld.

```

In this example:
- The integer array `arr` is initialized with values and then accessed and modified.
- The string `str` is initialized with a phrase and then characters are accessed and modified.

This demonstrates basic operations with arrays and strings in C++. Let me know if you have any specific questions or if there's anything else you'd like to explore!

## For loops
Here are the summarized notes on the for loop in C++:

### For Loop Overview:
- **Definition:** A control structure used to execute a block of code repeatedly based on a condition.
- **Components:**
  1. **Initialization:** Declaring and initializing a loop variable (counter).
  2. **Condition:** Checking a condition to decide whether to continue looping.
  3. **Increment/Decrement:** Updating the loop variable after each iteration.
  
### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << "Hey, Striver, this is the " << i << "'th iteration" << endl;
    }
    return 0;
}
```
- **Output:**
```
Hey, Striver, this is the 1'th iteration
Hey, Striver, this is the 2'th iteration
Hey, Striver, this is the 3'th iteration
Hey, Striver, this is the 4'th iteration
Hey, Striver, this is the 5'th iteration
Hey, Striver, this is the 6'th iteration
Hey, Striver, this is the 7'th iteration
Hey, Striver, this is the 8'th iteration
Hey, Striver, this is the 9'th iteration
Hey, Striver, this is the 10'th iteration 
```
Wow Eg :
```cpp
#include <iostream>
using namespace std;

int main() {
    int i;
    for (i = 1; i >=-10; i = i-1) {
        cout << "Hey, Striver, this is the " << i << "'th iteration" << endl;
    }
    return 0;
}

// Hey, Striver, this is the 1'th iteration
// Hey, Striver, this is the 0'th iteration
// Hey, Striver, this is the -1'th iteration
// Hey, Striver, this is the -2'th iteration
// Hey, Striver, this is the -3'th iteration
// Hey, Striver, this is the -4'th iteration
// Hey, Striver, this is the -5'th iteration
// Hey, Striver, this is the -6'th iteration
// Hey, Striver, this is the -7'th iteration
// Hey, Striver, this is the -8'th iteration
// Hey, Striver, this is the -9'th iteration
// Hey, Striver, this is the -10'th iteration

```
### Nested For Loops:
- Allows one for loop to be inside another.
- Useful for iterating through multi-dimensional data structures like 2D arrays.
  
### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }
    return 0;
}
```
- **Output:**
```
i = 0, j = 0
i = 0, j = 1
i = 0, j = 2
i = 1, j = 0
i = 1, j = 1
i = 1, j = 2
i = 2, j = 0
i = 2, j = 1
i = 2, j = 2
```

### Conditionals Inside For Loops:
- Allows including conditional statements (if, else if, else) inside for loops.
- Executes different code blocks based on certain conditions during each iteration.

### Customizing For Loops:
- Offers flexibility in how the loop is structured, including customizing the increment step for specific patterns or iterations.

### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 25; i += 5) {
        cout << "i = " << i << endl;
    }
    return 0;
}
```
- **Output:**
```
i = 1
i = 6
i = 11
i = 16
i = 21
```

These notes cover the basics and variations of using for loops in C++. Let me know if there's anything specific you'd like to explore further!

## While Loops
Here are the key points about while loops in programming:

### While Loop Basics:
- **Purpose**: Executes a block of code repeatedly as long as a specified condition is true.
- **Syntax**:
  ```cpp
  while (condition) {
      // body of the loop
  }
  ```
- **Execution**: The condition is evaluated first; if true, the loop body executes. After each iteration, the condition is re-evaluated.
- **Termination**: Loop terminates when the condition becomes false.

### Example: Calculating Factorial
```cpp

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int factorial = 1;

    while (n > 0) {
        factorial *= n;
        n--;
    }

    cout << "Factorial of 5 is: " << factorial << endl;
    return 0;
}

```
Output:
```
Factorial of 5 is: 120
```

### Do-While : Run 1 time (even if condition is not true)
```cpp

#include <iostream>
using namespace std;

int main() {
    int n = 0;

    do {
        cout<<"yay";
    }while (n>0);



    return 0;
}


// Output: yay
```

### Best Practices and Optimization:
- **Termination Conditions**: Essential to prevent infinite loops.
- **Optimization**: Use `break` to exit loops prematurely and `continue` to skip iterations.

### Example: Using `break` and `continue`
```cpp
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int target = 6;

// Using 'break' to exit the loop early when the target is found
for (int num : numbers) {
    if (num == target) {
        cout << "Target found: " << target << endl;
        break; // Exit the loop immediately
    }
    cout << "Checking: " << num << endl;
}

// Using 'continue' to skip specific elements
for (int num : numbers) {
    if (num % 2 == 0) {
        continue; // Skip even numbers
    }
    cout << "Odd number: " << num << endl;
}
```
Output:
```
Checking: 1
Checking: 2
Checking: 3
Checking: 4
Checking: 5
Target found: 6
Odd number: 1
Odd number: 3
Odd number: 5
Odd number: 7
Odd number: 9
```

### Summary:
While loops are fundamental for iterating over data and executing code based on specific conditions. They are crucial for controlling flow in algorithms and programs, ensuring efficient execution and preventing infinite loops.

## Functions
Certainly! Here are detailed study notes based on the script you provided:

### Functions in C++

#### What are Functions?
- Functions in C++ are blocks of code that perform a specific task.
- They are used to modularize code, improve readability, and promote code reusability.

#### Types of Functions
1. **Void Functions**: 
   - Functions that do not return a value (`void` keyword).
   - Used when the function performs actions without needing to return a result.
   - Example: 
     ```cpp
     void printName(string name) {
         cout << "Hello, " << name << endl;
     }
     ```

2. **Return Functions**:
   - Functions that return a value of a specified type.
   - Used when the function computes and returns a result.
   - Example:
     ```cpp
     int sum(int a, int b) {
         return a + b;
     }
     ```

3. **Parameterized and Non-Parameterized Functions**:
   - **Parameterized Functions**: Functions that accept parameters.
     ```cpp
     void printNumber(int num) {
         cout << "Number: " << num << endl;
     }
     ```
   - **Non-Parameterized Functions**: Functions that do not accept parameters.
     ```cpp
     void greet() {
         cout << "Hello, World!" << endl;
     }
     ```

#### Passing Parameters
- **Pass by Value**: 
  - Copies the actual value of an argument into the formal parameter of the function.
  - Changes made to the parameter inside the function have no effect on the argument.
  - Example:
    ```cpp
    void addFive(int num) {
        num += 5;
        cout << "Inside function: " << num << endl;
    }
    ```
  
- **Pass by Reference**:
  - Passes the address of the actual argument to the function parameter.
  - Changes made to the parameter inside the function affect the argument.
  - Example:
    ```cpp
    void addTen(int &num) {
        num += 10;
        cout << "Inside function: " << num << endl;
    }
    ```

#### Arrays and Functions
- Arrays are passed to functions by default as pointers (pass by reference).
- Example:
  ```cpp
  void modifyArray(int arr[], int size) {
      for (int i = 0; i < size; ++i) {
          arr[i] *= 2;
      }
  }
  ```

### Key Takeaways
- **Modularization**: Functions help break down complex tasks into smaller, manageable parts.
- **Readability**: Well-named functions improve code comprehension, especially for others or future self.
- **Reusability**: Functions reduce redundancy by allowing code to be reused across different parts of a program.
- **Parameter Passing**: Understanding when to pass by value or reference is crucial for efficient and effective programming.


#### Code
```
#include <iostream>
using namespace std;

// Void function example
void printName(string name) {
    cout << "Hello, " << name << endl;
}

// Return function example
int sum(int a, int b) {
    return a + b;
}

// Pass by value example
void addFive(int num) {
    num += 5;
    cout << "Inside addFive function: " << num << endl;
}

// Pass by reference example
void addTen(int &num) {
    num += 10;
    cout << "Inside addTen function: " << num << endl;
}

// Function to modify an array
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;
    }
}

int main() {
    // Void function call
    printName("Alice");

    // Return function call
    int result = sum(3, 4);
    cout << "Sum: " << result << endl;

    // Pass by value example
    int num1 = 10;
    addFive(num1);
    cout << "Outside addFive function: " << num1 << endl;

    // Pass by reference example
    int num2 = 20;
    addTen(num2);
    cout << "Outside addTen function: " << num2 << endl;

    // Array and function example
    int myArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    modifyArray(myArray, size);

    cout << "Modified Array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}
```
These notes cover the fundamental concepts of functions, parameter passing methods, and their application in C++. If you have any specific questions or need further explanation on any topic, feel free to ask!