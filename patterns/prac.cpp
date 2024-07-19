#include <bits/stdc++.h>
using namespace std;

void nForest(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // i=2
            for (int i1 = 1; i1 <= i; i1++) { //i1=1,2
                if (i1 % 2 == 0) {
                        cout << "1 ";
                    
                } else if (i1 % 2 != 0) {//avoid extra
                    cout << "0 ";
                }
            }
        } else if (i % 2 != 0) {
            for (int i1 = 1; i1 <= i; i1++) {
                if (i1 % 2 == 0) {
                        cout << "0 ";
                } else if (i1 % 2 != 0){
                    cout << "1 ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    nForest(n);
    return 0;
}
