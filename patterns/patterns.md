# Patterns

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

Start by small and play and debug and debug.

## Table of Contents
- [Patterns](#patterns)
  - [Table of Contents](#table-of-contents)
  - [Pattern-1: Rectangular Star Pattern](#pattern-1-rectangular-star-pattern)
  - [Pattern-2: Right-Angled Triangle Pattern](#pattern-2-right-angled-triangle-pattern)
  - [Pattern - 3: Right-Angled Number Pyramid](#pattern---3-right-angled-number-pyramid)
  - [Pattern - 4: Right-Angled Number Pyramid - II](#pattern---4-right-angled-number-pyramid---ii)
  - [Pattern-5: Inverted Right Pyramid](#pattern-5-inverted-right-pyramid)
  - [Pattern - 6: Inverted Numbered Right Pyramid](#pattern---6-inverted-numbered-right-pyramid)
  - [Pattern - 7: Star Pyramid TO BE REView](#pattern---7-star-pyramid-to-be-review)
  - [Pattern - 8: Inverted Star Pyramid](#pattern---8-inverted-star-pyramid)
  - [Pattern - 9: Diamond Star Pattern](#pattern---9-diamond-star-pattern)
  - [Pattern - 10: Half Diamond Star Pattern](#pattern---10-half-diamond-star-pattern)
  - [Pattern - 11: Binary Number Triangle Pattern](#pattern---11-binary-number-triangle-pattern)

## Pattern-1: Rectangular Star Pattern
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

## Pattern-2: Right-Angled Triangle Pattern

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

## Pattern-5: Inverted Right Pyramid
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

