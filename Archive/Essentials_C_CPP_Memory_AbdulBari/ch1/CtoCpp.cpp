//Class and Constructors

/*
struct to class
data members to be private
all functions inside the class,remove common arguements and parameters
data members to be public

default constructor : declarations as well as initialization

at main
classname obj;
r.func();
*/

#include<iostream>// stream : flow of data from one place to another. input stream and output stream
class rectangle{
    private:
        int l;
        int b;
    public:
        rectangle(int l,int b){
            this->l=l;
            this->b=b;
}

int area(){
    return l*b;
}

void chlen(int l1){
    l=l1;
}
};

int main(){
    rectangle r(5,10);
    std::cout<<r.area()<<std::endl;
    r.chlen(20);
    std::cout<<r.area()<<std::endl;
    return 0;
}