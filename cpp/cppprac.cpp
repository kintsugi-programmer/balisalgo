// Library for input output
#include<iostream>
// Library for mathematical functions
#include<math.h>
// Library for all standard lib

// meaining of bits/stdc++.h is bits: C++ standard library, stdc: C standard library, h: header file,++: C++ standard library
#include<bits/stdc++.h>

// Namespace for input output
// to shortcut eg: cout instead of std::cout
using namespace std;


// Main function
int main(){
    //cout is used to print the output
    cout<<"Hello World"<<endl<<"This is a C++ program"<<"\n";
    //\n is used to print a new line
    //endl is used to print a new line and flush the buffer
    //<< is used to concatenate the strings

    //cin is used to take input
    int a,b,c;

    cout<<"Enter 3 number: ";
    cin>>a>>b>>c;
    cout<<"The numbers you entered is: "<<a<<b<<c<<endl;

    //Arithmetic operators
    cout<<"The sum of a and b is: "<<a+b<<endl;
    cout<<"The difference of a and b is: "<<a-b<<endl;
    cout<<"The product of a and b is: "<<a*b<<endl;
    cout<<"The division of a and b is: "<<a/b<<endl;
    cout<<"The remainder of a and b is: "<<a%b<<endl;


    //Relational operators
    cout<<"Is a greater than b: "<<(a>b)<<endl;
    cout<<"Is a less than b: "<<(a<b)<<endl;
    cout<<"Is a greater than or equal to b: "<<(a>=b)<<endl;
    cout<<"Is a less than or equal to b: "<<(a<=b)<<endl;
    cout<<"Is a equal to b: "<<(a==b)<<endl;
    cout<<"Is a not equal to b: "<<(a!=b)<<endl;

    //Logical operators
    cout<<"Is a greater than b and b greater than c: "<<(a>b && b>c)<<endl;
    cout<<"Is a greater than b or b greater than c: "<<(a>b || b>c)<<endl;
    cout<<"Is a greater than b: "<<!(a>b)<<endl;


    //Assignment operators
    a+=b;
    cout<<"The value of a after a+=b is: "<<a<<endl;
    a-=b;
    cout<<"The value of a after a-=b is: "<<a<<endl;
    a*=b;
    cout<<"The value of a after a*=b is: "<<a<<endl;
    a/=b;
    cout<<"The value of a after a/=b is: "<<a<<endl;
    a%=b;
    cout<<"The value of a after a%=b is: "<<a<<endl;

    //Increment and Decrement operators
    a++;
    cout<<"The value of a after a++ is: "<<a<<endl;
    a--;
    cout<<"The value of a after a-- is: "<<a<<endl;

    //Bitwise operators
    cout<<"The value of a and b is: "<<(a&b)<<endl;
    cout<<"The value of a or b is: "<<(a|b)<<endl;
    cout<<"The value of a xor b is: "<<(a^b)<<endl;
    cout<<"The value of a left shift b is: "<<(a<<b)<<endl;
    cout<<"The value of a right shift b is: "<<(a>>b)<<endl;

    //Ternary operator
    cout<<"The value of a is: "<<((a>b)?a:b)<<endl;

    //Data types
    int x =10;
    long y = 1000000000000000000;
    long long z = 1000000000000000000;
    float z = 10.5;
    double w = 10.5;
    char ch = 'A';
    string str = "Hello World",str2;
    bool flag = true;
    cout<<"enter string"<<endl;
    getline(cin,str2);
    cin.ignore();
    cout<<"The value of x is: "<<x<<endl;
    cout<<"The value of y is: "<<y<<endl;
    // %d is used to print integer
    // %ld is used to print long
    // %lld is used to print long long
    // %f is used to print float
    // %lf is used to print double
    // %c is used to print character
    // %s is used to print string
    // %b is used to print boolean
    // if ,else if,else statement
    if (x<y && x!=y){x=y;}else if (y!=x && y>x ){y=x;}else{y=0;x=0;}
    //  Refactoring code by simplifying conditions can improve readability and maintainability.
    cout<<"The value of x is: "<<x<<endl;
    cout<<"The value of y is: "<<y<<endl;











}