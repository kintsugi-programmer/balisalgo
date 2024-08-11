#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
void swap1(int a,int b){ //pass by value
    int temp;
    temp=a;
    a=b;
    b=temp;
    //WAHT HAPPENS IN FUNCTION STAYS IN FUNCTION
    //NO ACTUAL SWAP
    //PASS BY VALUE
    //PASS BY VALUE IS USED TO PASS THE COPY OF THE ACTUAL ARGUMENT
    //IT IS USED TO PASS THE ARGUMENTS TO THE FUNCTION
    //WHATEVER CHANGES MADE TO THE ARGUMENTS IN THE FUNCTION DOES NOT REFLECT BACK TO THE ACTUAL ARGUMENTS
    cout<<"a="<<a<<" b="<<b<<endl;
}
void swap2(int *a,int *b){ //pass by address
    int temp = *a;
    *a=*b;
    *b=temp;
    cout<<"a="<<*a<<" b="<<*b<<endl;
}
void swap3(int &a,int &b){ //pass by reference
    int temp;
    temp=a;
    a=b;
    b=temp;
    cout<<"a="<<a<<" b="<<b<<endl;
}
int main(){
    int num1=10,num2=20;
    swap1(num1,num2);// good practice to use different variable names
    printf("num1=%d num2=%d\n",num1,num2);//no actual swap
    swap2(&num1,&num2);
    printf("num1=%d num2=%d\n",num1,num2);//actual swap
    num1=10,num2=20;
    swap3(num1,num2);
    printf("num1=%d num2=%d\n",num1,num2);//actual swap


    return 0;
}