#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        for(int j=1;j<=i;j++){
            cout << j;
        }
        for(int j=1;j<=(t-i)*2;j++){
            cout << " ";
        }
        for(int j=i;j>=1;j--){
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}