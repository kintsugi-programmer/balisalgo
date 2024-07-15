#include <iostream>
using namespace std;

float sq(float a, float b) {
    float c = 1; // Initialize c to 1, else torture of garbage values
    for(int i = 0; i < b; i++) {
        c *= a;
    }
    return c;

}
int main (){
    float a,b;
    cin>>a;
    cin>>b;
    cout<<sq(a,b);

    return 0;
}