#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int key;
    int value;
    node* next;

    node(int k, int v) : key(k), value(v), next(nullptr) {}
};

struct HashTable {
    int size;
    node** table;

    HashTable(int s) : size(s) {
        table = new node*[size]();
    }

    ~HashTable() {
        for (int i = 0; i < size; ++i) {
            node* current = table[i];
            while (current) {
                node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key, int value) {
        int index = hash(key);
        if (!table[index]) {
            table[index] = new node(key, value);
        } else {
            node* current = table[index];
            while (current->next) {
                current = current->next;
            }
            current->next = new node(key, value);
        }
    }

    int search(int key) {
        int index = hash(key);
        node* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable ht(numsSize);
    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        int complementIndex = ht.search(complement);
        if (complementIndex != -1) {
            int* result = new int[2];
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        ht.insert(nums[i], i);
    }
    *returnSize = 0;
    return nullptr;
}

int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 9;
    int returnSize1;
    int* result1 = twoSum(nums1, 4, target1, &returnSize1);
    if (result1 != nullptr) {
        cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
        delete[] result1;
    }

    int nums2[] = {3, 2, 4};
    int target2 = 6;
    int returnSize2;
    int* result2 = twoSum(nums2, 3, target2, &returnSize2);
    if (result2 != nullptr) {
        cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
        delete[] result2;
    }

    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* result3 = twoSum(nums3, 2, target3, &returnSize3);
    if (result3 != nullptr) {
        cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << endl;
        delete[] result3;
    }

    return 0;
}
