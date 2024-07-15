// in C++ we write extra code such that Rectangle class can be used anywhere 

#include <iostream>
using namespace std;
class Rectangle{
private:
    int length;
    int breadth;
public:
//constructors : not mandatory but good style of programming
Rectangle(){length=breadth=0;}// non argument constructor/default constructor
Rectangle(int l,int b);//paramatrised constructor/constructor overloading/constructor member function/header of an function
//falicilators,i.e.functions that play on data meembers of an object
int Area();
int Perimeter();
//accesssor
int getlength(){return length;}
int getbreadth(){return breadth;}
//mutator
void setlength(int l){length=l;}
void setbreadth(int b){breadth=b;}
//deconstructor
~Rectangle();//deconstructor,to destroy anything,used in heaps
};
//:: scope resolution
Rectangle::Rectangle(int l,int b){length=l;breadth=b;}
int Rectangle::Area(){return length*breadth;}
int Rectangle::Perimeter(){return 2*(length+breadth);}
Rectangle::~Rectangle(){cout<<"Deconstructor done"<<endl;} //at end of main function...its automatically called

int main(){
    Rectangle r(10,5);
    cout<<r.Area()<<endl;
    cout<<r.Perimeter()<<endl;
    r.setlength(20);
    cout<<r.getlength()<<endl;
    //at end of main function...its automatically called

}