//libraries
#include <iostream> //input output stream library
#include <bits/stdc++.h> //standard c++ library

//namespaces
using namespace std; //it helps not write std:: in standard fucntions
//it tells computer,use all names of std namespace without explicit state std:: each time
//with std (standard namespace)
//cout<<"hi";
//else
//std::cout<<"hi";

//single line comment
/*
Multiline comment
*/



//main code start
int main(){
    //Code Starts
    //indentation don't matter

    // cout function (from iostream library)
    // std::cout<<"hi";
    cout<<"hi";
    cout<<endl<<"kintsugi";

    //new line
    cout<< "\n";     //way1 (faster)
    cout<< endl ;    //way2 
    
    int x;
    //cin stream, take user input 
    cin>>x;

    int y;
    //taking multiple inputs
    cin>>x>>y;
    /*
    by     cin>>x>>y;
    we can use any of them for input ways:
    input way 1:
    10 20

    input way 2:
    10
    20

    both kind of inputs are valid :)
    */


   // Datatypes (inbuilt)
   // Declare ways
   // datatype var_name,var_name2,etc;
   // datatype var_name= value;

   int x1;      //int 4bytes
   long x2;     //long (unsigned short 2bytes, long 4bytes, unsigned long 4bytes)
   long long x3; //long long 8bytes
   float x4;    //float 4bytes
   double x5;   //double 8bytes
   // they all have simple cin,cout

   string x6,x7,x8;// String
   cin>> x6 >> x7; //input till space "hi bali"
   getline(cin,x8); //input string till linebreak 
   


 



    
    return 0;//End of code
}