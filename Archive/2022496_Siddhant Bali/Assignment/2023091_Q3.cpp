#include <iostream>
#include <vector>
#define N -1
using namespace std;

struct two_output {
    int x, y;
    two_output(int y, int x) : x(x), y(y) {}
};

void print_Vector(vector<int> x) {
    for (int i : x) cout << i << " ";
    cout << endl;
}

void print_Matrix(vector<vector<int>> x) {
    for (vector<int> y : x) print_Vector(y);
    cout << endl;
}

int linear_search(vector<int> x, int k){
    for (int i = 0; i<x.size(); i++) if (x[i] == k) return i;
    return -1;
}

two_output get_Node_Coordinates(vector<int> e, int k) {
    int i = linear_search(e, k);
    int y = 0;
    int j = 1;
    while (j <= i + 1) {
        j *= 2;
        y++;
    }
    y--;
    int x = i + 1 - (1 << y);
    return two_output(y, x);
}

int main () {
    vector<int> input;
    int value;
    cout << "Enter level order traversal of the binary tree (-1 for NULL nodes, end input with -999): ";
    while (cin >> value && value != -999)
        input.push_back(value);

    vector<vector<int>> tree;
    int size = input.size();
    int num_levels = 0;
    while (size > 0) {
        size /= 2;
        num_levels++;
    }
    for (int i = 0; i < num_levels; i++) {
        int k = (1 << i) - 1;
        vector<int> sub;
        for (int o = 0; o < (1 << i) && k + o < input.size(); o++) sub.push_back(input[o + k]);
        tree.push_back(sub);
    }
    print_Matrix(tree);
    int a, b;
    cout << "Query->Enter two nodes separated by an {Enter}: " << endl;
    cin >> a >> b;
    two_output a_t = get_Node_Coordinates(input, a);
    two_output b_t = get_Node_Coordinates(input, b);
    if (a_t.y == b_t.y and a_t.x/2 == b_t.x/2) cout << "No";
    else cout << "Yes";
    return 0;
}
