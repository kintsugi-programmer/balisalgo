# Patterns
## Table of Contents
- [Patterns](#patterns)
  - [Table of Contents](#table-of-contents)
  - [Tips](#tips)
  - [Pattern - 1: Rectangular Star Pattern](#pattern---1-rectangular-star-pattern)
  - [Pattern - 2: Right-Angled Triangle Pattern](#pattern---2-right-angled-triangle-pattern)
  - [Pattern - 3: Right-Angled Number Pyramid](#pattern---3-right-angled-number-pyramid)
  - [Pattern - 4: Right-Angled Number Pyramid - II](#pattern---4-right-angled-number-pyramid---ii)
  - [Pattern - 5: Inverted Right Pyramid](#pattern---5-inverted-right-pyramid)
  - [Pattern - 6: Inverted Numbered Right Pyramid](#pattern---6-inverted-numbered-right-pyramid)
  - [Pattern - 7: Star Pyramid TO BE REView](#pattern---7-star-pyramid-to-be-review)
  - [Pattern - 8: Inverted Star Pyramid](#pattern---8-inverted-star-pyramid)
  - [Pattern - 9: Diamond Star Pattern](#pattern---9-diamond-star-pattern)
  - [Pattern - 10: Half Diamond Star Pattern](#pattern---10-half-diamond-star-pattern)
  - [Pattern - 11: Binary Number Triangle Pattern](#pattern---11-binary-number-triangle-pattern)
  - [Pattern - 12: Number Crown Pattern](#pattern---12-number-crown-pattern)
  - [Pattern - 13: Increasing Number Triangle Pattern](#pattern---13-increasing-number-triangle-pattern)
  - [Pattern - 14: Increasing Letter Triangle Pattern](#pattern---14-increasing-letter-triangle-pattern)
  - [Pattern - 15: Reverse Letter Triangle Pattern](#pattern---15-reverse-letter-triangle-pattern)
  - [Pattern - 16: Alpha-Ramp Pattern](#pattern---16-alpha-ramp-pattern)
  - [Pattern - 17: Alpha-Hill Pattern](#pattern---17-alpha-hill-pattern)
  - [Pattern - 18: Alpha-Triangle Pattern](#pattern---18-alpha-triangle-pattern)
  - [Pattern - 19: Symmetric-Void Pattern](#pattern---19-symmetric-void-pattern)
  - [Pattern - 20: Symmetric-Butterfly Pattern](#pattern---20-symmetric-butterfly-pattern)
  - [Pattern - 21: Hollow Rectangle Pattern](#pattern---21-hollow-rectangle-pattern)
  - [Pattern - 22: The Number Pattern \*\*\*\*\* HARDD ;0](#pattern---22-the-number-pattern--hardd-0)

## Tips
Just Break stuff, assign line nos ,see both test cases and make patterns ;0

take care of n=critical points like 1,0 etc
```
    if (n==1){cout<<1;}else{//whole code}
```

i did every ques 1st by my own.ie.all ;)
It's a game of How fast you debug ;0

There are 4 general rules for solving a pattern-based question:
1. We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
2. Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
3. We print the ‘*’ inside the inner loop.
4. Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.

In this particular problem, we run the outer loop for N times since we have N rows to be printed, the inner loop.

You are better than 100%
Runtime 14 ms

Use:
```cpp
else if (i1 % 2 != 0) { //avoid extra cases }
```

just pos of 
```
            end--;
            cout<<end<<" ";
```
can reduce extra var usage and major impact on loop

Start by small and play and debug and debug.

[Patterns](#patterns)

## Pattern - 1: Rectangular Star Pattern
```
Example 1:
Input: N = 3
Output: 
* * *
* * *
* * *


Example 2:
Input: N = 6
Output:
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
```

```
//Pattern-1: Rectangular Star Pattern


// There are 4 general rules for solving a pattern-based question: 

// We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
// Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
// We print the ‘*’ inside the inner loop.
// Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.
// In this particular problem, we run the outer loop for N times since we have N rows to be printed, the inner loop 



#include<bits/stdc++.h>
using namespace std;

void nForest(int n) {
	// Write your code here.
        // This is the outer loop which will loop for the rows.

	for(int i=0;i<n;i++){
        // This is the inner loop which here, loops for the columns
        // as we have to print a rectangular pattern.
		for(int i1=0;i1<n;i1++){
			std::cout<<"* ";
		}
        // As soon as N stars are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
		std::cout<<"\n";
	}
}


int main() {
        // Here, we have taken the value of n as 5.
    // We can also take input from the user.
    int n;
    cin >> n;
    nForest(n);
}

```
[Patterns](#patterns)

## Pattern - 2: Right-Angled Triangle Pattern

```
Input Format: N = 3
Result: 
* 
* * 
* * *

Input Format: N = 6
Result:
* 
* * 
* * *
* * * *
* * * * *
* * * * * *
```

```
//Pattern-2: Right-Angled Triangle Pattern

#include<bits/stdc++.h>
using namespace std;

void nForest(int n) {
	// Write your code here.
        // This is the outer loop which will loop for the rows.

	for(int i=0;i<n;i++){
        // This is the inner loop which here, loops for the columns
        // as we have to print a rectangular pattern.
		for(int i1=0;i1<=i;i1++){
			std::cout<<"* ";
		}
        // As soon as N stars are printed, we move to the
        // next row and give a line break otherwise all stars
        // would get printed in 1 line.
		std::cout<<"\n";
	}
}


int main() {
        // Here, we have taken the value of n as 5.
    // We can also take input from the user.
    int n;
    cin >> n;
    nForest(n);
}

```
[Patterns](#patterns)

## Pattern - 3: Right-Angled Number Pyramid

```
Input Format: N = 3
Result: 
1
1 2 
1 2 3

Input Format: N = 6
Result:
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
```

```
// Pattern - 3: Right-Angled Number Pyramid
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for(int i=1;i<n+1;i++){
		for(int i1=1;i1<=i;i1++){
			std::cout<<i1<<" ";
		}
		std::cout<<"\n";
	}
}
int main() {int n;cin >> n;nForest(n);}
```
[Patterns](#patterns)

## Pattern - 4: Right-Angled Number Pyramid - II
```
Result: 
1
2 2 
3 3 3

Input Format: N = 6
Result:
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6
```

```
// Pattern - 4: Right-Angled Number Pyramid - II
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for(int i=1;i<n+1;i++){
		for(int i1=1;i1<=i;i1++){
			std::cout<<i<<" ";
		}
		std::cout<<"\n";
	}
}
int main() {int n;cin >> n;nForest(n);}

```
[Patterns](#patterns)

## Pattern - 5: Inverted Right Pyramid
```
Input Format: N = 3
Result: 
* * *
* * 
*

Input Format: N = 6
Result:
* * * * * *
* * * * * 
* * * * 
* * * 
* * 
* 
```

```
// Pattern - 4: Right-Angled Number Pyramid - II
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for(int i=n;i>=1;i--){
		for(int i1=i;i1>=1;i1--){
			std::cout<<"* ";
		}
		std::cout<<"\n";
	}
}
int main() {int n;cin >> n;nForest(n);}

```
[Patterns](#patterns)

## Pattern - 6: Inverted Numbered Right Pyramid
```
Input Format: N = 3
Result: 
1 2 3
1 2
1

Input Format: N = 6
Result:
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2 
1
```

```
// Pattern - 6: Inverted Numbered Right Pyramid
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for(int i=n;i>=1;i--){
		for(int i1=1;i1<=i;i1++){
			std::cout<<i1<<" ";
		}
		std::cout<<"\n";
	}
}
int main() {int n;cin >> n;nForest(n);}

```
[Patterns](#patterns)

## Pattern - 7: Star Pyramid TO BE REView
```
Input Format: N = 3
Result: 
  *  
 *** 
*****   
Input Format: N = 6
Result:
     *     
    ***    
   *****   
  *******  
 ********* 
***********
```

```
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {

    for (int i = 0; i <= n-1; i++) {

        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        for (int i1=0;i1<i;i1++){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only

        for (int i1=0;i1<i;i1++){cout<<"*";}
        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        //right half

        cout<<endl;
        //newline
    }

}
int main() {int n;cin >> n;nForest(n);}
```
[Patterns](#patterns)

## Pattern - 8: Inverted Star Pyramid
```
Input Format: N = 3
Result: 
*****  
 ***
  *   
Input Format: N = 6
Result:     
***********
 *********
  *******
   ***** 
    ***    
     *
```

```

#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {

    for (int i = 0; i <= n-1; i++) {
        for (int i1=0;i1<i;i1++){cout<<" ";}

        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only
        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        for (int i1=0;i1<i;i1++){cout<<" ";}

        //right half

        cout<<endl;
        //newline
    }

}
int main() {int n;cin >> n;nForest(n);}
```
[Patterns](#patterns)

## Pattern - 9: Diamond Star Pattern
```
Input Format: N = 3
Result: 
  *  
 ***
***** 
*****  
 ***
  *   
Input Format: N = 6
Result:   
     *
    ***
   ***** 
  *******
 *********
***********  
***********
 *********
  *******
   ***** 
    ***    
     *
```

```

#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for (int i = 0; i <= n-1; i++) {

        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        for (int i1=0;i1<i;i1++){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only

        for (int i1=0;i1<i;i1++){cout<<"*";}
        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        //right half

        cout<<endl;
        //newline
    }

    for (int i = 0; i <= n-1; i++) {
        for (int i1=0;i1<i;i1++){cout<<" ";}

        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only
        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        for (int i1=0;i1<i;i1++){cout<<" ";}

        //right half

        cout<<endl;
        //newline
    }

}



int main() {int n;cin >> n;nForest(n);}
```
[Patterns](#patterns)

## Pattern - 10: Half Diamond Star Pattern
```
Input Format: N = 3
Result: 
*  
**
***  
**
*   
Input Format: N = 6
Result:   
*
**
*** 
****
*****
******  
*****
****
***    
**
*
```

```

#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for (int i = 0; i <= n-2; i++) {

        // for (int i1=n-1; i1>i;i1--){cout<<" ";}
        // for (int i1=0;i1<i;i1++){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only

        for (int i1=0;i1<i;i1++){cout<<"*";}
        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        //right half

        cout<<endl;
        //newline
    }

    //with biggest line ;)
    for (int i = 0; i <= n-1; i++) {
        // for (int i1=0;i1<i;i1++){cout<<" ";}
        // for (int i1=n-1; i1>i;i1--){cout<<"*";}
        //left half

        
        cout<<"*";
        //middle * only
        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        for (int i1=0;i1<i;i1++){cout<<" ";}

        //right half

        cout<<endl;
        //newline
    }

}



int main() {int n;cin >> n;nForest(n);}
```
[Patterns](#patterns)

## Pattern - 11: Binary Number Triangle Pattern

You are better than
100%
Runtime
14 ms

use
: else if (i1 % 2 != 0) {//avoid extra cases

start by small and play and debug and debug

```
Input Format: N = 3
Result: 
1
01
101

Input Format: N = 6
Result:   
1
01
101
0101
10101
010101
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // i=2
            for (int i1 = 1; i1 <= i; i1++) { //i1=1,2
                if (i1 % 2 == 0) {
                        cout << "1 ";
                    
                } else if (i1 % 2 != 0) {//avoid extra
                    cout << "0 ";
                }
            }
        } else if (i % 2 != 0) {
            for (int i1 = 1; i1 <= i; i1++) {
                if (i1 % 2 == 0) {
                        cout << "0 ";
                } else if (i1 % 2 != 0){
                    cout << "1 ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}

```
[Patterns](#patterns)

## Pattern - 12: Number Crown Pattern
```
Input Format: N = 3
Result: 
1    1
12  21
123321

Input Format: N = 6
Result:   
1          1
12        21
12       321
1234    4321
12345  54321
123456654321
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i = 1; i <= n; i++) {
        //loop1
        for(int i1=1;i1<=i;i1++){cout<<i1;}
        //(n-i)*2
        int sp=((n-i)*2);
        for(int i1=1;i1<=sp;i1++){cout<<" ";}
        //loop2rev
        for(int i1=i;i1>0;i1--){cout<<i1;}
        cout<<"\n";
    }
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


//code-runner.runInTerminal
```
[Patterns](#patterns)

## Pattern - 13: Increasing Number Triangle Pattern

```
Input Format: N = 3
Result: 
1
2 3
4 5 6

Input Format: N = 6
Result:   
1
2  3
4  5  6
7  8  9  10
11  12  13  14  15
16  17  18  19  20  21
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    int s1 =1;
    for (int i = 1; i <= n; i++) {
        
        for (int i1 = 1; i1 <= i; i1++)
        {
            /* code */
            cout<<s1<<" ";
            s1++;
        }
        

        cout<<"\n";
    }
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


//code-runner.runInTerminal
```
[Patterns](#patterns)

## Pattern - 14: Increasing Letter Triangle Pattern

```
Input Format: N = 3
Result: 
A
A B
A B C

Input Format: N = 6
Result:   
A
A B
A B C
A B C D
A B C D E
A B C D E F
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =0; i < n; i++)
    {
        /* code */
        for (char i1 = 'A'; i1 <= 'A'+i; i1++)
        {
            /* code */
            cout<<i1<<" ";
        }
        cout<<"\n";
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


//code-runner.runInTerminal
```
[Patterns](#patterns)

## Pattern - 15: Reverse Letter Triangle Pattern
```
Input Format: N = 3
Result: 
A B C
A B
A

Input Format: N = 6
Result:   
A B C D E F
A B C D E 
A B C D
A B C
A B
A
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =n; i >= 1; i--)
    {
        /* code */
        for (char i1 = 'A'; i1 <= 'A'+i-1; i1++)
        {
            /* code */
            cout<<i1<<" ";
        }
        cout<<"\n";
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


//code-runner.runInTerminal
```
[Patterns](#patterns)

## Pattern - 16: Alpha-Ramp Pattern
```
Input Format: N = 3
Result: 
A
B B
C C C

Input Format: N = 6
Result:   
A 
B B
C C C
D D D D
E E E E E
F F F F F F
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    char i1 = 'A';
    for (int i =0; i < n; i++)
    {
        /* code */
        
        for (int i2=1;i2<=i+1;i2++)
        {
            /* code */
            cout<<i1<<" ";
        }
        i1+=1;
        cout<<"\n";
        
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


```
[Patterns](#patterns)

## Pattern - 17: Alpha-Hill Pattern
```
Input Format: N = 3
Result: 
  A  
 ABA 
ABCBA


Input Format: N = 6
Result:   
     A     
    ABA    
   ABCBA   
  ABCDCBA  
 ABCDEDCBA 
ABCDEFEDCBA
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =1; i <= n; i++)
    {   
        for (int i1 = n-i; i1 > 0; i1--)
        {
            /* code */
            cout<<" "<<" ";
        }

        char s = 'A';
        for (char i1 = 'A'; i1 < 'A'+i ; i1++)
        {
            /* code */
            cout<<s<<" ";
            s++;
        }
        s--;
        for (char i1 = 'A'+i-1; i1 > 'A' ; i1--)
        {
            /* code */
            s--;
            cout<<s<<" ";
            
        }
        
        

        cout<<"\n";   
    }
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}


//code-runner.runInTerminal
```
[Patterns](#patterns)

## Pattern - 18: Alpha-Triangle Pattern
just pos of 
```
            end--;
            cout<<end<<" ";
```
can reduce extra var usage and major impact on loop



```
Input Format: N = 3
Result: 
C
B C
A B C

Input Format: N = 6
Result:   
F
E F
D E F
C D E F
B C D E F
A B C D E F
```

```
#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =1; i <= n; i++)
    {
        char end = 'A'+n;
        
        for (char start=end-i;start<end;start++)
        {   
            /* code */
            cout<<start<<" ";
        }
        
        cout<<"\n";
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
```

```
Sample Input 1:
3
Sample Output 1:
C
C B 
C B A
Sample Input 2 :
1
Sample Output 2 :
A
```

```

#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =1; i <= n; i++)
    {
        char end = 'A'+n;
        for (int i1 = 1; i1 <= i; i1++)
        {
            /* code */
            end--;
            cout<<end<<" ";
            
        }
        
        
        cout<<"\n";
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
[Patterns](#patterns)
```
## Pattern - 19: Symmetric-Void Pattern
It's a game of How fast you debug ;0
```
Input Format: N = 3
Result: 
******
**  **
*    *
*    *
**  **
******

Input Format: N = 6
Result:   
************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************
```

```

#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i =n; i >0; i--)
    {
        for (int i1 = i; i1 > 0; i1--)
        {
            /* code */
            cout<<"*"<<" ";
        }
        for (int i1 = (n-i)*2 ; i1 >0; i1--)
        {
            /* code */
            cout<<"  ";
        }


        for (int i1 = i; i1 > 0; i1--)
        {
            /* code */
            cout<<"*"<<" ";
        }
        cout<<"\n";
        
    }
    for (int i =1; i <= n; i++)
    {
        for (int i1 = 0; i1 < i; i1++)
        {
            /* code */
            cout<<"*"<<" ";
        }
        for (int i1 = (n-i)*2 ; i1 >0; i1--)
        {
            /* code */
            cout<<"  ";
        }


        for (int i1 = 0; i1 < i; i1++)
        {
            /* code */
            cout<<"*"<<" ";
        }
        cout<<"\n";
        
    }
    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
```
[Patterns](#patterns)

## Pattern - 20: Symmetric-Butterfly Pattern
```
Input Format: N = 3
Result: 
*    *
**  **
******
**  **
*    *


Input Format: N = 6
Result:   
*          *
**        **
***      ***
****    ****
*****  *****
************
*****  *****
****    ****
***      ***
**        **
*          *
```

```

#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
        for (int i =1; i <= n; i++)
    {
        for (int i1 = 0; i1 < i; i1++)
        {
            /* code */
            cout<<"*"<<" ";
        }
        for (int i1 = (n-i)*2 ; i1 >0; i1--)
        {
            /* code */
            cout<<"  ";
        }


        for (int i1 = 0; i1 < i; i1++)
        {
            /* code */
            cout<<"*"<<" ";
        }
        cout<<"\n";
        
    }
        for (int i =n-1; i >0; i--)
    {
        for (int i1 = i; i1 > 0; i1--)
        {
            /* code */
            cout<<"*"<<" ";
        }
        for (int i1 = (n-i)*2 ; i1 >0; i1--)
        {
            /* code */
            cout<<"  ";
        }


        for (int i1 = i; i1 > 0; i1--)
        {
            /* code */
            cout<<"*"<<" ";
        }
        cout<<"\n";
        
    }

    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
```
[Patterns](#patterns)

## Pattern - 21: Hollow Rectangle Pattern
```
Input Format: N = 3
Result: 
***
* *
***

Input Format: N = 6
Result:   
******
*    *
*    *
*    *
*    *
******
```

```

#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    if (n==1){cout<<"*";}else{
    for (int i1=1; i1 <= n; i1++)
        {
            cout<<"*";
        }
        cout<<"\n";
        for (int i =1; i <= n-2; i++)
    {   cout<<"*"; 
        for (int i1=1;i1<=n-2;i1++){cout<<" ";}
        cout<<"*";
        cout<<"\n";
    }
    for (int i1=1; i1 <= n; i1++)
        {
            cout<<"*";
        }}

    
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
```
[Patterns](#patterns)

## Pattern - 22: The Number Pattern ***** HARDD ;0

Just Break stuff, assign line nos ,see both test cases and make patterns ;0

take care of n=critical points like 1,0 etc
```
    if (n==1){cout<<1;}else{//whole code}
```

i did every ques 1st by my own.ie.all ;)
It's a game of How fast you debug ;0

This problem is not generally asked in the interviews but it is good to practice such problems for the sake of logic building. 

we take the minimum distance of the current cell from each of the ends of the square ( min(1,3,3,5) ) and make the current cell value equal to that number. 

The distance of the current cell from the top can be written as the row number i.e, i.
The distance of the current cell from the left can be written as the column number i.e, j.
The distance of the current cell from the right can be written as (2*n-2) - j.
The distance of the current cell from the bottom can be written as (2*n-2) - i.

```
Input Format: N = 3
Result: 
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3

Input Format: N = 6
Result:   
6 6 6 6 6 6 6 6 6 6 6 
6 5 5 5 5 5 5 5 5 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 2 1 2 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 5 5 5 5 5 5 5 5 6 
6 6 6 6 6 6 6 6 6 6 6
```

```
#include <bits/stdc++.h>
using namespace std;
// 6 6 6 6 6 6 6 6 6 6 6 

// 6 5 5 5 5 5 5 5 5 5 6    1
// 6 5 4 4 4 4 4 4 4 5 6    2 
// 6 5 4 3 3 3 3 3 4 5 6    3
// 6 5 4 3 2 2 2 3 4 5 6    4

// 6 5 4 3 2 1 2 3 4 5 6 

// 6 5 4 3 2 2 2 3 4 5 6    4
// 6 5 4 3 3 3 3 3 4 5 6    3
// 6 5 4 4 4 4 4 4 4 5 6    2
// 6 5 5 5 5 5 5 5 5 5 6    1

// 6 6 6 6 6 6 6 6 6 6 6


// 3 3 3 3 3 

// 3 2 2 2 3    1

// 3 2 1 2 3 

// 3 2 2 2 3    1

// 3 3 3 3 3
void nForest(int n) {
    if (n==1){cout<<1;}else{
    int p =n-2;
    for (int i=n*2-1;i>=1;i--){cout<<n;}
    cout<<"\n";

    for (int i=1;i<=p;i++){
        int x = n;
        //rev count till i times
        for (int i1=1;i1<=i;i1++){cout<<x;x--;}
        //constant till p-i-1 times
        for (int i1=1;i1<=n*2-i*2-1;i1++){cout<<x;}
        //count till i times
        x++;
        for (int i1=1;i1<=i;i1++){cout<<x;x++;}


        // for (int i1=i;i1>=1;i1--){cout<<x;x--;}
        // for (int i1=p-i;i1>=1;i1--){cout<<x;}
        // for (int i1=i;i1>=1;i1--){cout<<x;x++;}
        cout<<"\n";
    }

    for (int i=n;i>=1;i--){cout<<i;}
    for (int i=2;i<=n;i++){cout<<i;}
cout<<"\n";
    for (int i=p;i>=1;i--){
        int x = n;
        for (int i1=1;i1<=i;i1++){cout<<x;x--;}
        for (int i1=1;i1<=n*2-1-i*2;i1++){cout<<x;}
        x++;
        for (int i1=1;i1<=i;i1++){cout<<x;x++;}
        cout<<"\n";
    }
    for (int i=n*2-1;i>=1;i--){cout<<n;}
    cout<<"\n";

    }
}

// mei kalyug mein rehke ,satyug ko dhunndh raha hun,i am wrong
// jo maanta hai unke liye hai ,jo nhi maanta unke liye nhi

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
```

Done ;0
[Patterns](#patterns)