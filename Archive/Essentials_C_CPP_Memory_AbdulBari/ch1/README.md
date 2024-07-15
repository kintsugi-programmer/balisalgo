//TODO
PROG {PERFORM INSTRUCTIONS}


PHYSICAL DS => ARRANGE DATA
arr
mat
ll
LOGICAL DS => UTILIZE DATA
stack
queues
tree
graph
hashing
recursion
sorting

TO DO LATER






# C C++ Essentials 
Arrays
Structures
Pointers
Refrences
Parameter Passsing
Classes
Constructors


## Arrays
Arrays : collection of same datatypes
Structures : collection of different datatypes

## Structures
Arrays : collection of same datatypes
Structures : collection of different datatypes

```cpp
#include <iostream>
struct triangle {
    int side1; //size 2 bytes
    int side2;
    int side3;
    // 6bytes max size,right now it doesn't occupy any space in memory

}; //dont forget the semicolon

int main() {
    struct triangle tr0 = {100,100,100}; // here it occupies memory


    struct triangle tr1; // Declaring a structure variable tr1 of type triangle
    tr1.side1 = 10;
    tr1.side2 = 20;
    tr1.side3 = 30;

    // Accessing and printing the sides of the triangle
    std::cout << "Side 1 " << tr1.side1 << std::endl;
    std::cout << "Side 2: " << tr1.side2 << std::endl;
    std::cout << "Side 3: " << tr1.side3 << std::endl;
    
    struct triangle shapes[3]={
        {10,20,30},
        {40,50,60},
        {70,80,90}};

    for (int i = 0; i < (sizeof(shapes)/sizeof(shapes[0])); i++){
    std::cout << "Side "<<i <<"\t"<<shapes[i].side1<<"\t"<<shapes[i].side2<<"\t"<<shapes[i].side3<<std::endl;}

    return 0;
}

// kintsugi-scripter@kintsugi-machine-mint:~/Github/balisalgorithm/Raw/C C++ Essentials$ cd "/home/kintsugi-scripter/Github/balisalgorithm/Raw/C C++ Essentials/" && g++ struct.cpp -o struct && "/home/kintsugi-scripter/Github/balisalgorithm/Raw/C C++ Essentials/"struct
// Side 1 10
// Side 2: 20
// Side 3: 30
// Side 0  10      20      30
// Side 1  40      50      60
// Side 2  70      80      90
```
| Memory Section | Description                                         |
|----------------|-----------------------------------------------------|
| Stack          | Used for local variables and function calls.        | 
| Heap           | Dynamically allocated memory for persistent data.   |
| Code Section   | Stores executable instructions.                     |
| Data Section   | Contains global and static variables.               |
| BSS Section    | Holds uninitialized global and static variables.    |
| Constant Data  | Stores constants and string literals.               |

at Stack section it includes tr0 = {100,100,100} etc..

## Pointers
addresses variables (locators ,location to)
i.e. variable which store addresss 

* location to  
& address of 

```cpp
#include <iostream>

int main()
{
    /* code */
    int a = 10; 
    int *ptr; //declaration
    ptr = &a; //initialization 0x7ffce75b019c
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of a: " << ptr << std::endl;
    std::cout << "Dereferencing of a: " << *ptr << std::endl; //Dereferencing
    return 0;
}

// kintsugi-scripter@kintsugi-machine-mint:~/Github/balisalgorithm/Raw/C C++ Essentials$ cd "/home/kintsugi-scripter/Github/balisalgorithm/Raw/C C++ Essentials/" && g++ pointers.cpp -o pointers && "/home/kintsugi-scripter/Github/balisalgorithm/Raw/C C++ Essentials/"pointers
// Value of a: 10
// Address of a: 0x7ffce75b019c
// Address of a: 0x7ffce75b019c
// Dereferencing of a: 10


```

```c

```

## Refrences
## Parameter Passsing
## Classes
## Constructors




























## Others

### Arrow
Arrow operator -> in C/C++ with Examples
An Arrow operator in C/C++ allows to access elements in Structures and Unions. It is used with a pointer variable pointing to a structure or union. The arrow operator is formed by using a minus sign, followed by the greater than symbol as shown below. 
Syntax:  

(pointer_name)->(variable_name)

Operation: The -> operator in C or C++ gives the value held by variable_name to structure or union variable pointer_name.
Difference between Dot(.) and Arrow(->) operator:  

The Dot(.) operator is used to normally access members of a structure or union.
The Arrow(->) operator exists to access the members of the structure or the unions using pointers.

### Memory
| Memory Section | Description                                              |
|----------------|----------------------------------------------------------|
| Stack          | Area of memory used for local variables and function calls. Memory allocation is static and follows Last-In-First-Out (LIFO) order. |
| Heap           | Dynamically allocated memory used for data that persists beyond the scope of a single function. Memory allocation is dynamic and requires manual management. |
| Code Section   | Also known as the text section, it stores the executable instructions of the program. It is typically read-only and contains the compiled machine code. |
| Data Section   | Contains global and static variables initialized by the program. It is divided into initialized data and uninitialized (or zero-initialized) data sections. |
| BSS Section    | Stands for "Block Started by Symbol." It contains uninitialized global and static variables, initialized to zero or null by default. |
| Constant Data  | Stores constant values used in the program, such as string literals and global constants. It is typically stored in the read-only data segment. |


### Escape sequences in C and CPP
In C++, escape sequences are special sequences of characters that begin with a backslash (`\`). They are used to represent characters that cannot be easily represented or typed directly in source code. Here are the commonly used escape sequences in C++:

1. **`\n`**: Newline
2. **`\t`**: Horizontal tab
3. **`\r`**: Carriage return
4. **`\\`**: Backslash
5. **`\'`**: Single quote
6. **`\"`**: Double quote
7. **`\a`**: Alert (bell)
8. **`\b`**: Backspace
9. **`\f`**: Form feed
10. **`\v`**: Vertical tab
11. **`\?`**: Question mark (used in trigraphs, not commonly used anymore)
12. **`\0`**: Null character (null terminator)
13. **`\xhh`**: ASCII character in hexadecimal representation
14. **`\uhhhh`**: Unicode character in hexadecimal representation (4 digits)
15. **`\Uhhhhhhhh`**: Unicode character in hexadecimal representation (8 digits)
16. **`\ooo`**: ASCII character in octal representation (up to 3 digits)

Example usage:

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello\nWorld!\n";   // Newline
    cout << "This is a\ttab\n";  // Horizontal tab
    cout << "Backslash: \\\n";   // Backslash
    cout << "Single quote: \'\n"; // Single quote
    cout << "Double quote: \"\n"; // Double quote
    cout << "Alert sound: \a\n";  // Alert (bell)
    cout << "Backspace\b\n";      // Backspace
    cout << "Form feed\f\n";       // Form feed
    cout << "Vertical tab\v\n";    // Vertical tab
    cout << "Question mark\?\n";   // Question mark
    cout << "Null character: \0\n";// Null character
    cout << "ASCII in hex: \x41\n";// ASCII character in hexadecimal representation
    cout << "Unicode in hex: \u03A9\n"; // Unicode character in hexadecimal representation
    cout << "Unicode in hex: \U000003A9\n"; // Unicode character in hexadecimal representation
    cout << "ASCII in octal: \101\n"; // ASCII character in octal representation

    return 0;
}
```

Each escape sequence represents a specific control character or special character, allowing for various formatting and representation options within C++ strings.

### " " v/s ' ' in cpp and c
In C and C++, both double quotes (`"`) and single quotes (`'`) are used to represent character literals and string literals, but they have different meanings and usage.

1. **Double Quotes (`"")**:
   - Double quotes are used to represent string literals in C and C++.
   - String literals are sequences of characters enclosed within double quotes. For example: `"Hello, World!"`.
   - String literals are null-terminated, meaning they are followed by a null character (`'\0'`) automatically by the compiler.
   - Double quotes are used when dealing with strings, arrays of characters, or pointers to characters.

2. **Single Quotes (`''`)**:
   - Single quotes are used to represent character literals in C and C++.
   - Character literals are single characters enclosed within single quotes. For example: `'A'`, `'b'`, `'1'`, `'%'`, etc.
   - Unlike string literals, character literals are not null-terminated. They represent individual characters.
   - Single quotes are used when dealing with individual characters.

Example usage:

```cpp
#include <iostream>
using namespace std;

int main() {
    char c = 'A';          // Single character literal
    char str[] = "Hello";  // String literal
    
    cout << "Character: " << c << endl;
    cout << "String: " << str << endl;
    
    return 0;
}
```

In this example, `'A'` is a character literal and `"Hello"` is a string literal.

### Typically Datatypes
Size of char : 1
Size of int : 4
Size of long : 8
Size of float : 4
Size of double : 8

### 32bit vs 64bit system
Sure, here's a compressed version:

1. **32-bit vs 64-bit**: 32-bit systems use 32-bit memory addresses, while 64-bit systems use 64-bit addresses.

2. **Pointers**: 32-bit systems have 32-bit pointers (4 bytes), addressing up to 4 GB; 64-bit systems have 64-bit pointers (8 bytes), up to 16 exabytes.

3. **Data Types**: Most remain the same size, but pointers and `long` may change.

4. **`long` Data Type**: Typically 32 bits in 32-bit systems, potentially 64 bits in 64-bit systems.

5. **`long long` Data Type**: Always 64 bits.

6. **Executable Size**: 64-bit files may be larger due to larger address space.

7. **Performance**: 64-bit systems offer better performance for some tasks due to larger memory and registers.

Transitioning may require software changes for compatibility and optimization.


## Logic
Describe the fundamental principles and reasoning behind the topic.

## Approaches
Detail various methods and strategies used to tackle the topic.

## Diagrams
Provide visual representations such as flowcharts or diagrams for better understanding.

Example Diagram:
![Diagram](diagram.png)

## Pseudocode
Outline high-level code-like descriptions to illustrate the implementation logic.

```plaintext
// Pseudocode example
function exampleFunction(parameter) {
    if (condition) {
        // Do something
    } else {
        // Do something else
    }
}
```

## Special Stuff
Highlight any unique or exceptional considerations relevant to the topic.

## Functions
List the main functions related to the topic.

```cpp
// Sample C++ code for a function
void exampleFunction(int parameter) {
    // Function implementation
}
```

## Helper Functions
Document any supporting functions that aid in the implementation of the topic.

```cpp
// Sample C++ code for a helper function
int helperFunction(int parameter) {
    // Helper function implementation
}
```

## Complexity
Analyze the time and space complexity of the algorithms or solutions related to the topic.

## Corner Cases
Identify and discuss edge scenarios or exceptional cases to consider.

## Approach
- Conduct thorough research before documenting.
- Organize content in a structured and logical manner.
- Provide detailed dry runs for clarity and understanding.

## Notes
- Document detailed dry runs for clarity and understanding.
- Emphasize active learning through code experimentation.
- Engage in problem-solving brainstorming sessions.

This template incorporates C++ code snippets, pseudocode, and placeholders for diagrams to provide a comprehensive documentation structure for a single topic within your library. Fill in the relevant details and content for each section accordingly.

## Others
Logic
ApproachS
DiagramS
Psedocode
Special Stuff
Func
Helper Func
Complexity
Corner Cases

Do Research Man
Code != Transcript
Structured Way
Detailed Dry Run

Notes X
Dry Run OP

Default to Code play Active Learning and Play

Problem solve ,2 pages brainstorm

![Diagram](diagram.png)

```plaintext
// Pseudocode example
function exampleFunction(parameter) {
    if (condition) {
        // Do something
    } else {
        // Do something else
    }
}
```

```cpp
// Sample C++ code for a helper function
int helperFunction(int parameter) {
    // Helper function implementation
}
```
