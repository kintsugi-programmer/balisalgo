#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s="";
        string s1="";
        cin>>s>>s1;
        string a1=string(1, s1[0])+s[1]+s1[2];
        string b1=string(1, s[0])+s1[1]+s[2];  
        cout << a1<< " " << b1 <<endl;
    }
    return 0;
}