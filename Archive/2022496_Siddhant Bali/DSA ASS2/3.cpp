#include <iostream>

using namespace std;

long long maxSushiPlates(char recipe[], int nb, int ns, int nc, int pb, int ps, int pc, long long r) {
    long long low = 0, high = 1e15; // Set high initial value to avoid overflow
    long long maxPlates = 0;

    // Binary search to find the maximum number of plates that can be prepared within budget
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long moneyNeeded = max(0LL, mid * (recipe[0] == 'B' ? pb : recipe[0] == 'S' ? ps : pc) - nb) * pb +
                                max(0LL, mid * (recipe[0] == 'B' ? pb : recipe[0] == 'S' ? ps : pc) - ns) * ps +
                                max(0LL, mid * (recipe[0] == 'B' ? pb : recipe[0] == 'S' ? ps : pc) - nc) * pc;
        if (moneyNeeded <= r) {
            maxPlates = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return maxPlates;
}

int main() {
    char recipe[] = "BBBSSC";
    int nb = 6, ns = 4, nc = 1;
    int pb = 1, ps = 2, pc = 3;
    long long r = 4;

    cout << "Output: " << maxSushiPlates(recipe, nb, ns, nc, pb, ps, pc, r) << endl;

    char recipe2[] = "BSC";
    nb = 1, ns = 1, nc = 1;
    pb = 1, ps = 1, pc = 3;
    r = 1000000000000;

    cout << "Output: " << maxSushiPlates(recipe2, nb, ns, nc, pb, ps, pc, r) << endl;

    return 0;
}
