#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Node structure for chaining
struct Node {
    int key;
    int value;
    Node(int k, int v) : key(k), value(v) {}
};

// Hashtable class
class HashTable {
private:
    vector<list<Node>> table;
    int size;
    int capacity;
    float loadFactorThreshold;

    // Hash function
    int hash(int key) {
        return key % capacity;
    }

    // Re-hash function (increase table size and rehash all elements)
    void rehash() {
        int oldCapacity = capacity;
        capacity *= 2;
        vector<list<Node>> newTable(capacity);

        for (int i = 0; i < oldCapacity; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                int index = hash(it->key);
                newTable[index].push_back(*it);
            }
        }

        table = move(newTable);
    }

public:
    // Constructor
    HashTable(int initialCapacity, float loadFactor) : capacity(initialCapacity), size(0), loadFactorThreshold(loadFactor) {
        table.resize(capacity);
    }

    // Insertion operation
    void insert(int key, int value) {
        if ((float)size / capacity > loadFactorThreshold) {
            rehash();
        }

        int index = hash(key);
        table[index].push_back(Node(key, value));
        size++;
    }

    // Deletion operation
    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                size--;
                break;
            }
        }
    }

    // Search operation
    int search(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value;
            }
        }
        return -1; // Key not found
    }

    // Helper function to solve the problem
    vector<int> twoSum(vector<int>& nums, int target) {
        HashTable ht(nums.size(), 0.75);
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (ht.search(complement) != -1) {
                result.push_back(ht.search(complement));
                result.push_back(i);
                return result;
            }
            ht.insert(nums[i], i);
        }

        return result; // No solution found
    }
};

int main() {
    HashTable ht(10, 0.75);

    // Example usage
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = ht.twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
