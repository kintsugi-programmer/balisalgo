#include<iostream>// either use this or #include <stuio.h>

using namespace std;

struct node
{
    int data; //data of the stack
    struct node* nxt; //nxt pointer of stack
};
struct node* newnode(int data){
    node* temp = new node;
    if (temp == nullptr) { //error handling 
        printf("Malloc Fail.\n");
        exit(1);
    }
    //default values
    temp->data = data;
    temp->nxt = nullptr;
    return temp;
};

void push(node** head, int data){
    node* temp1 = newnode(data);
    temp1->nxt = *head; //pervious element head
    *head = temp1; //new head is temp1 ,new element
    cout<<"Push("<<data<<")"<<"\n";

}

void pop(node** head){
    if (*head == nullptr) { //error handling
        cout<<"Empty stack"<<"\n";
        return;
    }
    node* temp2 = *head; //new element
    *head = (*head)->nxt; //previous stack element
    cout<<"Pop("<<temp2->data<<")"<<"\n";
    delete temp2; //memory free
}

void isempty(node* head){
    if (head == nullptr) { //error handling
        cout<<"Empty stack"<<"\n";
        return;
    }
    else {
        cout<<"Stack is not empty"<<"\n";
    }
}

void top(node* head){
    if (head == nullptr) { //error handling
        cout<<"Empty stack"<<"\n";
        return;
    }
    cout<<"Top element is "<< head->data <<"\n";
}

void display(node* head){
    if (head == nullptr) { //error handling
        cout<<"Empty stack"<<"\n";
        return;
    }
    cout<<"Stack: "<< "\n"<<"\n";
    while (head != nullptr) {
        cout<<"|"<<head->data<<"|"<<"\n";
        head = head->nxt;
    }
    cout<<"\n";
}


void enqueue(node** front, node** rear, int data){
    node* temp1 = newnode(data);
    if (*rear == nullptr) {
        *front = *rear = temp1;
    } else {
        (*rear)->nxt = temp1;
        *rear = temp1;
    }
    cout<<"Enqueue("<<data<<")"<<"\n";
}

void dequeue(node** front, node** rear){
    if (*front == nullptr) { 
        cout<<"Empty queue"<<"\n";
        return;
    }
    node* temp = *front;
    *front = (*front)->nxt;
    if (*front == nullptr) {
        *rear = nullptr;
    }
    cout<<"Dequeue("<<temp->data<<")"<<"\n";
    delete temp;
}

void frontElement(node* front){
    if (front == nullptr) { 
        cout<<"Empty queue"<<"\n";
        return;
    }
    cout<<"Front element is "<<(front->data)<<"\n"<<"\n";
}

void displayq(node* front){
    if (front == nullptr) { 
        cout<<"Empty queue"<<"\n";
        return;
    }
    cout<<"Queue:"<<"\n";
    while (front != nullptr) {
        cout <<"|"<< (front->data) <<"|"<< "\n";
        front = front->nxt;
    }
    cout<<"\n";
}


// Function to find the next greater element for each element in the array
void ngc(int arr[], int n) {
    // Create an array to store the next greater elements
    int arr1[n];
    
    // Initialize all elements of arr1 to -1
    for (int i = 0; i < n; i++) {
        arr1[i] = -1;
    }
    
    // Create an empty stack to store indices of array elements
    node* s = nullptr;
    
    // Loop through the array twice to handle circular array
    for (int i = 0; i < 2 * n; i++) {
        // Get the current element of the array
        int num = arr[i % n];// % is used to handle circular array
        
        // Keep popping elements from the stack while the stack is not empty and the current element is greater than the element at the index stored in the stack
        while (s != nullptr && arr[s->data] < num) {
            arr1[s->data] = num; // Update the next greater element for the popped element
            pop(&s); // Pop the element from the stack 
        }
        
        // If we are still within the original array size, push the current index onto the stack
        if (i < n) {
            push(&s, i);
        }
    }
    
    // Print the array containing the next greater elements
    cout << "[";
    for (int i = 0; i < n; i++) {
        if (i != 0)
            cout << ",";
        cout << arr1[i];
    }
    cout << "]" << "\n";
}
int main()
{
    cout<<"Stack"<<"\n";
    node* head = nullptr;
    push(&head, 20);
    push(&head, 30);
    push(&head, 50);
    push(&head, 40);
    display(head);
    top(head);
    pop(&head);
    pop(&head);
    display(head);
    isempty(head);
    pop(&head);
    pop(&head);
    display(head);
    isempty(head);

    cout<<"Queue"<<"\n";

    node* front = nullptr;
    node* rear = nullptr;
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 50);
    enqueue(&front, &rear, 40);
    displayq(front);
    frontElement(front);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    displayq(front);
    frontElement(front);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    displayq(front);
    frontElement(front);

    cout<<"Next Greater Element"<<"\n"<<"\n";

    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ngc(arr, n);

    return 0;
}
