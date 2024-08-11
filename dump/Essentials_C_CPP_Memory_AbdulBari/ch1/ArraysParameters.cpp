#include<iostream>
using namespace std;
void fun(int arr[]){ //Arrays are always passed by address ,not by value
    cout<<sizeof(arr)/sizeof(int)<<endl; //Size of pointer is printed


}

int* heap_arr(int n){ //[] was old way of passing array in C++98 which is not recommended now. Use * instead
    int *ptr = new int[n];
    for(int i=0;i<n;i++){
        ptr[i] = i;
    }
    return ptr;
}

void fun_accurate( int arr[],int n){ //Arrays are always passed by address ,not by value  
    cout<<n/sizeof(int)<<endl; //Size of pointer is printed
}

void other_fun_accurate( int *arr,int n){ //Arrays are always passed by address ,not by value  
    cout<<n/sizeof(int)<<endl; //Size of pointer is printed
}

void change(int arr[]){//Arrays are always passed by address ,not by value

    arr[0] = 100;//This will change the original array because it is passed by address.arr[] is also a pointer
}

int main(){
    int arr[] = {1,2,3,4,5};
    
    fun(arr); //fun(&arr[0]
    /*
    In the fun function, when you calculate the size of 
    the array using sizeof(arr)/sizeof(int), it doesn't 
    work as expected. arr is passed as a pointer, not 
    an array, so sizeof(arr) gives the size of the pointer, 
    not the size of the array. Therefore, it will always print 
    the size of a pointer divided by the size of an integer, 
    which is not what you intend. To pass the array by reference, 
    you should use a reference to an array in the function parameter.
    
    */

    cout<<sizeof(arr)/sizeof(int)<<endl;
    fun_accurate(arr,sizeof(arr));
    other_fun_accurate(arr,sizeof(arr));

    int *ptr = arr;
    cout << "Array elements are: ";
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i:arr) //Range based for loop for array ONly in C++11.not in pointers
        cout << i << " ";

    
    cout << endl;
    change(arr);//This will change the original array because it is passed by address.arr[] is also a pointer
    cout << "Changed Array elements using pointer: ";
    for(int i=0; i<5; i++){
        cout << *(ptr+i) << " "; //ptr[i] is same as *(ptr+i)
    }
    cout << endl;
    

    //Heap array
    int *ptr2,siz = 5;
    ptr2 = heap_arr(siz);
    for(int i=0; i<siz; i++)
        cout << *(ptr2+i) << " ";
    

    return 0;
}

/* 
PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1> cd "c:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1\" ; if ($?) { g++ ArraysParameters.cpp -o ArraysParameters } ; if ($?) { .\ArraysParameters }
ArraysParameters.cpp: In function 'void fun(int*)':
ArraysParameters.cpp:4:18: warning: 'sizeof' on array function parameter 'arr' will return size of 'int*' [-Wsizeof-array-argument]
    4 |     cout<<sizeof(arr)/sizeof(int)<<endl; //Size of pointer is printed
      |                 ~^~~~
ArraysParameters.cpp:3:14: note: declared here
    3 | void fun(int arr[]){ //Arrays are always passed by address ,not by value
      |          ~~~~^~~~~
2
5
5
5
Array elements are: 1 2 3 4 5
1 2 3 4 5
Changed Array elements using pointer: 100 2 3 4 5
0 1 2 3 4
PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1>
 */