#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<pair<int, int>> findPairs(const vector<int>& arr, int r) {
    vector<pair<int, int>> result;
    unordered_set<int> uniqueElements(arr.begin(), arr.end());

    for (int x : uniqueElements) {
        for (int y : uniqueElements) {
            if (x != y && x % y == r) {
                result.push_back(make_pair(x, y));
            }
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {4, 5, 2, 1, 3};
    int r1 = 2;
    vector<pair<int, int>> pairs1 = findPairs(arr1, r1);

    cout << "Example 1:" << endl;
    cout << "Array: {4, 5, 2, 1, 3}, r = 2" << endl;
    cout << "Ordered pairs with remainder " << r1 << ":" << endl;
    for (const auto& p : pairs1) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    cout << endl;

    vector<int> arr2 = {6, 1, 4, 10, 9};
    int r2 = 2;
    vector<pair<int, int>> pairs2 = findPairs(arr2, r2);

    cout << "Example 2:" << endl;
    cout << "Array: {6, 1, 4, 10, 9}, r = 2" << endl;
    cout << "Ordered pairs with remainder " << r2 << ":" << endl;
    for (const auto& p : pairs2) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}