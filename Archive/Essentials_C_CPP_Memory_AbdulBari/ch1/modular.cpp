#include<iostream>
#include<stdio.h>
using namespace std;
// monolithic.cpp to modular.cpp
//modular programming
//modular programming is a software design technique that emphasizes separating the functionality of a program into independent, interchangeable modules, such that each contains everything necessary to execute only one aspect of the desired functionality.
int area(int l, int b){
    return l*b;
}
int perimeter(int l, int b){
    return 2*(l+b);
}

int init(){
    int l=0,b=0; // good practice to initialize variables
    //user interaction
    cout<<"Enter length and breadth of rectangle"<<endl; //cooking plate
    cin>>l>>b;
    int ar= area(l,b);
    //user interaction and processing
    cout<<"Area of rectangle is "<<ar<<endl;//serving plate
    cout<<"Perimeter of rectangle is "<<perimeter(l,b)<<endl;//serving plate
    return 0;
}

int main(){
    init();
    return 0;
}