/**
 * (b) (5 marks) Use your stack implementation from above and solve the following problem:-
Given a circular integer array nums (i.e., the next element of nums[nums.length -
1] is nums[0]), return the next greater number for every element in nums. The next
greater number of a number x is the first greater number to its traversing order
next in the array, which means you could search circularly to find its next greater
number.
Input: [1,2,3,4,3]
Output: [2,3,4,-1,4]
 * 
*/

#include <iostream>

using namespace std;

// Node structure for stack
template <typename T>
struct Node {
    T data;
    Node* next;
};

// Stack class
template <typename T>
class Stack {
private:
    Node<T>* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(T newData) {
        Node<T>* newNode = new Node<T>;
        newNode->data = newData;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            exit(1);
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

// Function to find the next greater elements in a circular array
void nextGreaterElements(int nums[], int n) {
    int result[n];
    Stack<int> s;

    // Initialize result array with -1
    for (int i = 0; i < n; ++i)
        result[i] = -1;

    // First traversal to find next greater elements
    for (int i = 0; i < n * 2; ++i) {
        int num = nums[i % n];
        while (!s.isEmpty() && nums[s.top()] < num) {
            result[s.top()] = num;
            s.pop();
        }
        if (i < n) s.push(i);
    }

    // Output the result
    cout << "Next greater elements for each element in the circular array: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int nums[] = {1, 2, 3, 4, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    nextGreaterElements(nums, n);

    return 0;
}
