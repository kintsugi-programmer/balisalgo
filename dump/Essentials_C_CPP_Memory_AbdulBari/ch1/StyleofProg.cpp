//Sir's style of programming is to making main is just a manager
// and the actual work is done in other functions
// this is the style of programming that is used in Object Oriented Programming , hIGEST LEVEL OF PROGRAMMING IN C USING STRUCT AND FUCNTIONS
// this is the style of programming that is used in industry
// ALL THE FUNCTIONS ARE RELATED TO THE STRUCTURES

#include<iostream>// stream : flow of data from one place to another. input stream and output stream
struct rectangle{
    int l;
    int b;
};

void initialize(struct rectangle *r,int l,int b){
    r->l=l;
    r->b=b;
}

int area(struct rectangle r){
    return r.l*r.b;
}

void chlen(struct rectangle *r,int l1){
    r->l=l1;
}

int main(){
    struct rectangle r;
    initialize(&r,10,5);
    std::cout<<area(r)<<std::endl;
    chlen(&r,20);
    std::cout<<area(r)<<std::endl;
    return 0;
}