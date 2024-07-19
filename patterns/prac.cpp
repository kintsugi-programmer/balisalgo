#include <bits/stdc++.h>
using namespace std;
// 6 6 6 6 6 6 6 6 6 6 6 

// 6 5 5 5 5 5 5 5 5 5 6    1
// 6 5 4 4 4 4 4 4 4 5 6    2 
// 6 5 4 3 3 3 3 3 4 5 6    3
// 6 5 4 3 2 2 2 3 4 5 6    4

// 6 5 4 3 2 1 2 3 4 5 6 

// 6 5 4 3 2 2 2 3 4 5 6    4
// 6 5 4 3 3 3 3 3 4 5 6    3
// 6 5 4 4 4 4 4 4 4 5 6    2
// 6 5 5 5 5 5 5 5 5 5 6    1

// 6 6 6 6 6 6 6 6 6 6 6


// 3 3 3 3 3 

// 3 2 2 2 3    1

// 3 2 1 2 3 

// 3 2 2 2 3    1

// 3 3 3 3 3
void nForest(int n) {
    if (n==1){cout<<1;}else{
    int p =n-2;
    for (int i=n*2-1;i>=1;i--){cout<<n;}
    cout<<"\n";

    for (int i=1;i<=p;i++){
        int x = n;
        //rev count till i times
        for (int i1=1;i1<=i;i1++){cout<<x;x--;}
        //constant till p-i-1 times
        for (int i1=1;i1<=n*2-i*2-1;i1++){cout<<x;}
        //count till i times
        x++;
        for (int i1=1;i1<=i;i1++){cout<<x;x++;}


        // for (int i1=i;i1>=1;i1--){cout<<x;x--;}
        // for (int i1=p-i;i1>=1;i1--){cout<<x;}
        // for (int i1=i;i1>=1;i1--){cout<<x;x++;}
        cout<<"\n";
    }

    for (int i=n;i>=1;i--){cout<<i;}
    for (int i=2;i<=n;i++){cout<<i;}
cout<<"\n";
    for (int i=p;i>=1;i--){
        int x = n;
        for (int i1=1;i1<=i;i1++){cout<<x;x--;}
        for (int i1=1;i1<=n*2-1-i*2;i1++){cout<<x;}
        x++;
        for (int i1=1;i1<=i;i1++){cout<<x;x++;}
        cout<<"\n";
    }
    for (int i=n*2-1;i>=1;i--){cout<<n;}
    cout<<"\n";

    }
}

// mei kalyug mein rehke ,satyug ko dhunndh raha hun,i am wrong
// jo maanta hai unke liye hai ,jo nhi maanta unke liye nhi

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}