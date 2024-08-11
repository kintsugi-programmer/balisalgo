// TODO : Pointers in C++ 
// Pointer is a variable that stores the address of another variable
// It is a data type that holds the address of another data type
// It is used to access the memory location of a variable
// It is used to access the value of a variable indirectly

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct triangle {
    int a;
    int b;
    int c;
};

int main(){
    /* code */
    int a = 10; 
    int *ptr; //declaration
    ptr = &a; //initialization

    // *  and & are unary operators and are used to dereference and address of operator respectively ONLY THAT TIME ,ONLY FOR POINTERS
    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Address of a: " << ptr << std::endl;
    std::cout << "Dereferencing of a: " << *ptr << std::endl;

    
    
    // Pointer to pointer   
    int **q;
    q = &ptr;
    std::cout << "Address of ptr: " << &ptr << std::endl;
    std::cout << "Address of ptr: " << q << std::endl;
    std::cout << "Value of a: " << **q << std::endl;

    // Pointer to Array
    int arr[] = {1,2,3,4,5}; //arr is a pointer to the first element of the array
    // arr is a pointer to the first element of the array
    // Array created in stack
    int *p;
    p=arr;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Value of arr: " << arr[i] << std::endl;
        std::cout << "Value of arr: " << p[i] << std::endl;
        std::cout << "Address of arr: " << &arr[i] << std::endl;
        std::cout << "Address of arr: " << p+i << std::endl;
    }

    //Array created in heap using malloc C
    int *ptrarr = (int *)malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        ptrarr[i] = i+1;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Value of ptrarr: " << ptrarr[i] << std::endl;
        std::cout << "Address of ptrarr: " << &ptrarr[i] << std::endl;
    }
    free (ptrarr);//free the memory allocated by malloc C
    //very important to free the memory allocated by malloc C in projects to avoid memory leaks


    //array created in heap using new operator C++
    int *ptrarr1 = new int[5];
    for (int i = 0; i < 5; i++)
    {
        ptrarr1[i] = i+1;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Value of ptrarr1: " << ptrarr1[i] << std::endl;
        std::cout << "Address of ptrarr1: " << &ptrarr1[i] << std::endl;
    }
    delete [] ptrarr1; //delete the memory allocated by new operator C++
     



    // Clang Malloc
    // #include<stdlib.h> 
    int *p3;
    p3=(int *)malloc(5*sizeof(int)); //malloc returns void pointer so we need to typecast it to int pointer
    // syntax: (type *)malloc(size)

    // C++ new operator ,used to allocate memory at runtime
    p3=new int[5]; //new operator returns pointer to the first element of the array

    int *ptr1;
    float *ptr2;
    char *ptr3;
    double *ptr4;
    triangle *ptr5;
    cout<<sizeof(ptr1)<<endl;
    // size of pointer is same for all data types .ie size o pointer is independent of data type
    // size of pointer is 8 bytes in 64 bit system
    // size of pointer is 4 bytes in 32 bit system

    cout<<sizeof(ptr2)<<endl;
    cout<<sizeof(ptr3)<<endl;
    cout<<sizeof(ptr4)<<endl;
    cout<<sizeof(ptr5)<<endl; 

    // Pointer to structure
    /*
    in C , we use          operator to access the members of the structure using pointer
    in C++ , we use          operator to access the members of the structure using pointer

    In C++,its not mandatory to write stueture keyword before the structure variable
    triangle *ptr; right
    Struct triangle t; right
    Since C++ is object oriented programming language,we can use the structure variable directly
    
    In C,its mandatory to write struture keyword before the structure variable
    triangle *ptr; wrong
    Struct triangle t; right


    
    */

    // dynamic memory allocation
    struct triangle *ptr6;
    ptr6 = (struct triangle *)malloc(sizeof(struct triangle));
    ptr6->a = 10;
    ptr6->b = 20;
    ptr6->c = 30;
    cout<<ptr6->a<<" "<<ptr6->b<<""<<ptr6->b<<endl;
    return 0;}