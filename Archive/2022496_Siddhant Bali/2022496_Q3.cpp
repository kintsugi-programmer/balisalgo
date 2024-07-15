#include <iostream>
#include <string>
using namespace std;


bool Can_Prepare(string recipe, long long n_b, long long n_s, long long n_c, int p_b, int p_s, int p_c, long long r, long long mid) {
    long long Bread_Count = 0, Salmon_Count = 0, Corn_Count = 0;
   
for (int i = 0; i < recipe.size(); ++i) {
    char ch = recipe[i];

        if (ch == 'B') Bread_Count++;
        if (ch == 'S') Salmon_Count++;
        if (ch == 'C') Corn_Count++;
    }
    
   
    long long Bread_Needed = max(0LL, Bread_Count * mid - n_b);
    long long Salmon_Needed = max(0LL, Salmon_Count * mid - n_s);
    long long Corn_Needed = max(0LL, Corn_Count * mid - n_c);

    
    long long cost = Bread_Needed * p_b + Salmon_Needed * p_s + Corn_Needed * p_c;

    
    return cost <= r;
}

long long Max_Sushi_Plates(string recipe, int n_b, int n_s, int n_c, int p_b, int p_s, int p_c, long long r) {
    long long lo = 0, hi = 1e12; 
    long long result = 0;
    
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (Can_Prepare(recipe, n_b, n_s, n_c, p_b, p_s, p_c, r, mid)) {
            result = mid; 
            lo = mid + 1;
        } else {
            hi = mid - 1; 
        }
    }
    
    return result;
}

int main() {
    //test cases

    string recipe = "BBBSSC";
    int n_b = 6, n_s = 4, n_c = 1;
    int p_b = 1, p_s = 2, p_c = 3;
    long long r = 4;
    cout << Max_Sushi_Plates(recipe, n_b, n_s, n_c, p_b, p_s, p_c, r) << endl;
    
    recipe = "BSC";
    n_b = 1, n_s = 1, n_c = 1;
    p_b = 1, p_s = 1, p_c = 3;
    r = 1000000000000;
    
    cout << Max_Sushi_Plates(recipe, n_b, n_s, n_c, p_b, p_s, p_c, r) << endl;
    return 0;
}
