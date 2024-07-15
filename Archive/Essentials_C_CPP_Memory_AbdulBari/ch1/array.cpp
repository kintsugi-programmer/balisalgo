
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];// expression should contain constant value else it will fill garbage values
    // garbage values are not assigned by user,and are random values which are present in memory and non zero ,filled by system in non initialized variables

   
    cout<<"size of array"<<sizeof(arr)/sizeof(arr[0])<<endl; // Size of array i.e. no of elements in array
    cout << "sizeof(arr)" << sizeof(arr) << endl; // Size of array i.e. no of elements in array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){ // Output array in forward direction
        cout << arr[i] << " ";
        printf("%d ", arr[i]);
    }

    for(int i = n - 1; i >= 0; i--){ // Output array in reverse direction
        cout << arr[i] << " ";
        printf("%d ", arr[i]);
    }

    int arr2[10] = {1, 2, 3, 4, 5}; // rest all elements will be 0 by default, n>= entries in array
    //c is subset of c++ so we can use printf
    for(int i = 0; i < 10; i++){
        printf("%d ", arr2[i]);
    }

    //cpp specific
    for(int x : arr2){
        cout << x << " ";
    }
    return 0;
}

/*
### Typically Datatypes
Size of char : 1
Size of int : 4
Size of long : 8
Size of float : 4
Size of double : 8

*/