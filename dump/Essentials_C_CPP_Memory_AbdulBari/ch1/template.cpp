//CPP support generic functions(template func) and generic classes(template classes)
//this->a=a to not confuse 
//generic class is class which is for every datatype ,which is template
//templates are used for different datatype
#include<iostream>
using namespace std;
// // Normal Class which can only played with int.not float ,double etc.
// class arth{
//     private:
//     int x,y;
//     public:
//     arth(int x,int y);
//     int add();
//     int sub();
// };

// arth::arth(int x ,int y){this->x=x;this->y=y;} 
//this refers to the members of the class,if just wrot a=a; compiler will think a parameter will be assign to itself only
// a is parameter,this->a is member of class
// int arth::add(){int c=x+y;return c;}
// int arth::sub(){int c=x-y;return c;}


//Template
template<class t>//generic var is t
class arth{
    private:
    t x,y; // obeserve and change to t wherever neccearry,dont blindly change it 
    public:
    arth(t x,t y);
    t add();
    t sub();
};//template<class t> effect ends here at ;

template<class t>
arth<t>::arth(t x ,t y){this->x=x;this->y=y;}
template<class t>
t arth<t>::add(){t c=x+y;return c;}
template<class t>
t arth<t>::sub(){t c=x-y;return c;}

int main(){arth<int> arr1(1,2),arr2(25,3);cout<<arr1.add()<<endl;
arth<float> arr3(1.10,2.33);cout<<arr3.add()<<endl;
arth<char> arr4('A','Z');cout<<(int)arr4.add();//typecast,study overflow??
return 0;}