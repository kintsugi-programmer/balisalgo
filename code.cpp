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

    int x0;      //int 4bytes
    short x1;    //short 2 bytes
    long x2;     //long (unsigned short 2bytes, long 4bytes, unsigned long 4bytes)
    long long x3; //long long 8bytes
    float x4;    //float 4bytes
    double x5;   //double 8bytes
    // they all have simple cin,cout

    string x6,x7,x8;// String dynamic storage ,overhaead 32bytes(x64bit systems)
    cin>> x6 >> x7; //input till space
    getline(cin,x8); //input string till linebreak 

    char x9; // char 1byte
    // total char = 256

    // difference b/w string "" and char ''
    string x10="hi"; //value store in double quotes
    char x11='h'; // value store in single quotes

    bool x12=true;  //bool 1byte

    //sizeof() :show size of any datatype
    cout<<"Size of Int:"<<sizeof(int)<<"bytes\n";

    //conditional statements
    // if else
    if(12<16) cout<<"12<16"<<endl;
    if(12<16) // will work even above true
        cout<<"12<16"<<endl;
    if(12<15) {
        cout<<"12<15"<<endl;
        }
    if(1==2){
        if(2==3) {
            cout<<"1==2==3";
        }
    }
    
    int x13=10,x14=20;
    if (x13<=14) cout<<x13<<endl;
    else if (x14) cout<<x14<<endl;//will work only if above fails
    else cout<<"else";

    /*
    Multiple condition statements
    &   AND
    ||  OR
    !   NOT
    */

   // Switch case statements
   char x15;
   cin>>x15;
   switch(x15){
        case 'a':
            cout<<"You wrote"<<x15<<endl;
            break;

        

   }







 



    
    return 0;//End of code
}