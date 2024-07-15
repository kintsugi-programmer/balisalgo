// Lab 11
// Siddhant Bali
// 2022496

#include <iostream>
#include <cstdlib>

using namespace std;

// ll node struct 
struct node {
    int key;
    int val;
    node* nxt;
    // cons
    node(int k, int v) : key(k), val(v), nxt(nullptr) {}
};

// hash table structure
struct hasht {
    int size;
    node** table;
    
    // cons
    hasht(int s) : size(s) {
        table = new node*[size]();
    }
 
    // free memory deconstructor
    ~hasht() {
        for (int i = 0; i < size; ++i) {
            node* curr = table[i];
            while (curr) {
                node* nxt = curr->nxt;
                delete curr;
                curr = nxt;
            }
        }
        delete[] table;
    }

    // index ca: hash function
    int hash(int key) {
        return key % size;
    }

    // insert key-val pair
    void insert(int key, int val) {
        int idx = hash(key);
        if (!table[idx]) {
            table[idx] = new node(key, val);
        } else {
            // node* curr = table[idx];
            // while (curr->nxt) { 
            //     curr = curr->nxt;
            // }
            // curr->nxt = new node(key, val);
            node* curr = table[idx];
            while (curr->nxt) {
                curr = curr->nxt;
            }
            curr->nxt = new node(key, val);
        }
    }

    // search if key in ht or not
    int search(int key) {
        int idx = hash(key);
        node* curr = table[idx];
        while (curr) {
            if (curr->key == key) {
                return curr->val;
            }
            curr = curr->nxt;
        }
        return -1;
    }
};

// two sum function
int* twoSum(int* no, int noSize, int target, int* finalSIZE) {
    hasht ht(noSize);
    for (int i = 0; i < noSize; ++i) {
        int complement = target - no[i];
        int complementidx = ht.search(complement);
        if (complementidx != -1) {
            int* result = new int[2];
            result[0] = complementidx;
            result[1] = i;
            *finalSIZE = 2;
            return result;
        }
        ht.insert(no[i], i);
    }
    *finalSIZE = 0;
    return nullptr;
}

//driver code and test cases
int main() {

    // //custom input
    // // Taking input from the user
    // int size;
    // cout << "Enter the size of the array: ";
    // cin >> size;

    // int* nums = new int[size];
    // cout << "Enter " << size << " integers separated byspace: ";
    // for (int i = 0; i < size; ++i) {
    //     cin >> nums[i];
    // }

    // int target;
    // cout << "Enter the target sum: ";
    // cin >> target;

    // // Finding the two indices
    // int finalSize;
    // int* result = twoSum(nums, size, target, &finalSize);

    // // Outputting the result
    // if (result != nullptr && finalSize == 2) {
    //     cout << "Indices of the two numbers whose sum is equal to the target: "
    //          << result[0] << " and " << result[1] << endl;
    //     delete[] result;
    // } else {
    //     cout << "No two numbers found whose sum is equal to the target." << endl;
    // }
    cout << "Outputs:" << endl;
    //Test case 1
    int no1[] = {2, 7, 11, 15};
    int target1 = 9;
    int finalSIZE1;
    cout << "Input: [2, 7, 11, 15],target is 9" << endl;
    int* result1 = twoSum(no1, 4, target1, &finalSIZE1);
    if (result1 != nullptr) {
        cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
        delete[] result1; //freeh
    }

    // delete[] nums; // free
    // return 0;
    // //Test case 3
    // int no3[] = {3, 3};
    // int target3 = 6;
    // int finalSIZE3;
    // cout << "Input: [3, 3],target is 6" << endl;
    // int* result3 = twoSum(no3, 2, target3, &finalSIZE3);
    // if (result3 != nullptr) {
    //     cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
    //     delete[] result3; //freeh
    // }
    
    //Test case 2
    int no2[] = {3, 2, 4};
    int target2 = 6;
    int finalSIZE2;
    cout << "Input: [3, 2, 4],target is 6" << endl;
    int* result2 = twoSum(no2, 3, target2, &finalSIZE2);
    if (result2 != nullptr) {
        cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
        delete[] result2; //freeh
    }
    //Test case 3
    int no3[] = {3, 3};
    int target3 = 6;
    int finalSIZE3;
    cout << "Input: [3, 3],target is 6" << endl;
    int* result3 = twoSum(no3, 2, target3, &finalSIZE3);
    if (result3 != nullptr) {
        cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
        delete[] result3; //freeh
    }

    return 0;
}
