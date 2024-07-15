#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
    Node *Top_Node;
    int size;
    const int MAX_SIZE = 100;

public:
    Stack() {
        Top_Node = nullptr;
        size = 0;
    }

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack full. Cannot push." << endl;
            return;
        }
        Node *New_Node = new Node();
        New_Node->data = x;
        New_Node->next = Top_Node;
        Top_Node = New_Node;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack empty. Cannot pop." << endl;
            return;
        }
        Node *temp = Top_Node;
        Top_Node = Top_Node->next;
        delete temp;
        size--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack empty." << endl;
            exit(1);
        }
        return Top_Node->data;
    }

    bool isEmpty() {
        return Top_Node == nullptr;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }
};

int partition(int* array, int* array_2, int lo, int hi) {
    int pivot = array[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
            swap(array_2[i], array_2[j]);
        }
    }
    swap(array[i + 1], array[hi]);
    swap(array_2[i + 1], array_2[hi]);
    return i + 1;
}

void quickSort(int* array, int* array_2, int lo, int hi) {
    if (lo < hi) {
        int q = partition(array, array_2, lo, hi);
        quickSort(array, array_2, lo, q - 1);
        quickSort(array, array_2, q + 1, hi);
    }
}


void Print_Array(int x[], int y) {
	cout<<"[";
	for (int i = 0; i < y; i++) {
		if (x[i] == 0) continue;
		cout << x[i] << ", ";
	}
	cout << "]" << endl;
}

int battle(int health[], int a, int b){
    if(health[a] > health[b]){
        health[a]--;
        health[b] = 0;
        return a;
    }
    else if(health[a] < health[b]){
        health[a] = 0;
        health[b]--;
        return b;
    }
    else{
        health[a] = health[b] = 0;
        return -1;
    }
}

int main(){
    string team;
    Stack encountered;
    int* positions;
    int* health;
    int* indexes;
    int size;
    cout <<"Enter number of heroes: \n";
    cin >> size;

    positions = new int[size];
    health = new int[size];
    indexes = new int[size];

    cout<<"Enter positions of  heroes: \n";

    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        positions[i] = x;
    }
    cout<<"Enter health of heroes: \n";
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        health[i] = x;
    }
    cout <<"Enter team formation: \n";
    cin >> team;
    for (int i = 0; i < size; i++)
    {
        indexes[i] = i;
    }

    quickSort(indexes, positions, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        int index = indexes[i];

        if(team[index] == 'R'){
            encountered.push(index);
        }
        else{
            while (!encountered.isEmpty())
            {
                int winner = battle(health, index, encountered.top());
                if(winner == -1){
                    encountered.pop();
                    break;
                }
                else if(winner == index){
                    encountered.pop();
                }
                else{
                    break;
                }
            }
        }
    }
    cout << "Output: ";
    Print_Array(health, size);
    return 0;
}