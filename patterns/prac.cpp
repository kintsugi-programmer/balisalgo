
#include<bits/stdc++.h>
using namespace std;
void nForest(int n) {
    for (int i = 0; i <= n-2; i++) {

        // for (int i1=n-1; i1>i;i1--){cout<<" ";}
        // for (int i1=0;i1<i;i1++){cout<<"*";}
        //left half

        

        //middle * only

        for (int i1=0;i1<i;i1++){cout<<"*";}
        for (int i1=n-1; i1>i;i1--){cout<<" ";}
        //right half

        cout<<endl;
        //newline
    }

    //with biggest line ;)
    for (int i = 0; i <= n-1; i++) {
        // for (int i1=0;i1<i;i1++){cout<<" ";}
        // for (int i1=n-1; i1>i;i1--){cout<<"*";}
        //left half

        

        //middle * only
        for (int i1=n-1; i1>i;i1--){cout<<"*";}
        for (int i1=0;i1<i;i1++){cout<<" ";}

        //right half

        cout<<endl;
        //newline
    }

}



int main() {int n;cin >> n;nForest(n);}
