#include<iostream>
using namespace std; // Added to use cout
// REFERENCE IS ONLY FOR C++
// Reference is an alias to a variable
// It is used to access the value of a variable directly
// It does not have its own memory
// Reference is not a variable, it is just an alias
// Reference is not a pointer
// Reference is not a constant
// Reference must be initialized at the time of declaration


int main(){
    int a=9;
    int &c = a;
    /*
    THIS IS WRONG ;(ERROR: 'c' declared as reference but not initialized)

    int &c;
    c = a;

    */
    c++;
    cout<<a<<endl<<c<<endl;

    int *p,*q;
    p=&a;
    q=&c;
    ++a; // Increment the value of 'a',also the value of 'c' because 'c' is reference to 'a',a,c means the same ,alias man ;0
    cout<<a<<endl; // Output the value of 'a'
    cout<<c<<endl; // Output the value of 'c' which is reference to 'a'
    cout<<*p<<endl; // Output the value pointed by pointer 'p', which is 'a'
    cout<<*q<<endl; // Output the value pointed by pointer 'q', which is 'c' which refers to 'a'
    cout<<p<<endl; // Output the address stored in pointer 'p', which is the address of 'a'
    cout<<q<<endl; // Output the address stored in pointer 'q', which is the address of 'c' which refers to 'a'

     return 0;
 }
// PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\Raw\Func> cd "c:\Users\Siddhant bali\BaliGit\balisalgorithm\Raw\Func\" ; if ($?) { g++ reference.cpp -o reference } ; if ($?) { .\reference }
// 10
// 10
// 10
// 10
// 0xee625ffd64
// 0xee625ffd64
// PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\Raw\Func>
