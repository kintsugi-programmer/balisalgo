#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle {int length;int breadth;};

// modular.cpp to structfunc.cpp
void initialize (Rectangle *r, int l, int b){
    r->length=l;
    r->breadth=b;
}

// int area(int l, int b){
//     return l*b;
// }

int area(struct Rectangle r){
    return r.length*r.breadth;
}
// int perimeter(int l, int b){
//     return 2*(l+b);
// }

int perimeter(Rectangle r){
    return 2*(r.length+r.breadth);
}

int init(){
    //int l=0,b=0; // good practice to initialize variables
    Rectangle r={0,0};

    //user interaction
    cout<<"Enter length and breadth of rectangle"<<endl; //cooking plate
    //cin>>l>>b;
    //cin>>r.length>>r.breadth;
    int l,b;
    cin>>l>>b;
    initialize(&r,l,b);

    //int ar= area(l,b);
    int ar= area(r);
    //user interaction and processing
    cout<<"Area of rectangle is "<<ar<<endl;//serving plate
    //cout<<"Perimeter of rectangle is "<<perimeter(l,b)<<endl;//serving plate
    cout<<"Perimeter of rectangle is "<<perimeter(r)<<endl;//serving plate
    return 0;
}

int main(){
    init();
    return 0;
}