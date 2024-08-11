//TODO
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct cylinder {
    float r;
    float h;
};

struct triangle {
    int side1; //size 2 bytes
    int side2;
    int side3;
    // 6bytes max size,right now it doesn't occupy any space in memory

}; //dont forget the semicolon

int main() {
    struct cylinder c1={3.0,69.0};
    c1.h=420.0;
    cout<<c1.r<<endl<<c1.h<<endl;
    
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

