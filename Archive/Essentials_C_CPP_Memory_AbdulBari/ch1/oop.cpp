//monolithic.cpp to modular.cpp to structfunc.cpp to oop.cpp
#include<iostream>
#include<stdio.h>
using namespace std;
// c : functions
// cpp : struct,class


// This is object orientation.

// So what is an object ?writing the data members and all the member functions together at a single place.
// We can define a class and we can create its object.
// So these are object.
// Object will have its properties and methods that its member functions.
// So what i have written a structure here.
// Yes, you can write structure also in place of class in C++.

// in CPP ,structure and class are same ,only difference is ,
//in structure ,everything is public,
//in class ,everything is private default
struct Rectangle {int length;int breadth;
//}; LET ALL THE FUNCTIONS BE INSIDE THE STRUCTURE

// // modular.cpp to structfunc.cpp
// void initialize (Rectangle *r, int l, int b){
//     r->length=l;
//     r->breadth=b;
// }
void initialize (int l,int b){ 
    length=l;
    breadth=b;
}

// // int area(int l, int b){
// //     return l*b;
// // }
// int area(){ // directly access length and breadth
//     return length*breadth;
// }

// int area(struct Rectangle r){
//     return r.length*r.breadth;
// }
int area(){
    return (length*breadth);
}

// // int perimeter(int l, int b){
// //     return 2*(l+b);
// // }
// int perimeter(Rectangle r){
//    return 2*(r.length+r.breadth);
int perimeter(){
    return 2*(length+breadth);
// }
}
};

// Class same as Structure
class Rectangle1 {
public:
    int length;int breadth;

//}; LET ALL THE FUNCTIONS BE INSIDE THE STRUCTURE

// // modular.cpp to structfunc.cpp
// void initialize (Rectangle *r, int l, int b){
//     r->length=l;
//     r->breadth=b;
// }
void initialize (int l,int b){ 
    length=l;
    breadth=b;
}

// // int area(int l, int b){
// //     return l*b;
// // }
// int area(){ // directly access length and breadth
//     return length*breadth;
// }

// int area(struct Rectangle r){
//     return r.length*r.breadth;
// }
int area(){
    return (length*breadth);
}

// // int perimeter(int l, int b){
// //     return 2*(l+b);
// // }
// int perimeter(Rectangle r){
//    return 2*(r.length+r.breadth);
int perimeter(){
    return 2*(length+breadth);
// }
}
};

//for struct
int init(){
    //int l=0,b=0; // good practice to initialize variables
    Rectangle r={0,0};

    //user interaction
    cout<<"Enter length and breadth of rectangle"<<endl; //cooking plate
    //cin>>l>>b;
    //cin>>r.length>>r.breadth;
    int l,b;
    cin>>l>>b;
    //initialize(&r,l,b);
    r.initialize(l,b);

    //int ar= area(l,b);
    //int ar= area(r);
    int ar= r.area();
    //user interaction and processing
    cout<<"Area of rectangle is "<<ar<<endl;//serving plate
    //cout<<"Perimeter of rectangle is "<<perimeter(l,b)<<endl;//serving plate
    //cout<<"Perimeter of rectangle is "<<perimeter(r)<<endl;//serving plate
    cout<<"Perimeter of rectangle is "<<r.perimeter()<<endl;
    return 0;
}

//for class
int init2(){
    //int l=0,b=0; // good practice to initialize variables
    Rectangle r;//in class we cant initialize like in structures

    //user interaction
    cout<<"Enter length and breadth of rectangle"<<endl; //cooking plate
    //cin>>l>>b;
    //cin>>r.length>>r.breadth;
    int l,b;
    cin>>l>>b;
    //initialize(&r,l,b);
    r.initialize(l,b);

    //int ar= area(l,b);
    //int ar= area(r);
    int ar= r.area();
    //user interaction and processing
    cout<<"Area of rectangle is "<<ar<<endl;//serving plate
    //cout<<"Perimeter of rectangle is "<<perimeter(l,b)<<endl;//serving plate
    //cout<<"Perimeter of rectangle is "<<perimeter(r)<<endl;//serving plate
    cout<<"Perimeter of rectangle is "<<r.perimeter()<<endl;
    return 0;
}

int main(){init();init2();return 0;}