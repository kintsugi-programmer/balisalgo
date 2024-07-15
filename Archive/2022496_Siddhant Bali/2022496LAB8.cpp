#include <bits/stdc++.h>
using namespace std;

// Define the structure of a node in BST
struct node {
    int data;
    node *left, *right;

    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Search Tree
class bst {
private:
    node* root;

    // function for inserting a node
    node* insert(node* root, int value) {
        if (root==nullptr)
            return new node(value);
        if (value < root->data)
            root->left=insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    // function for deleting a node
    node* funcDelete(node* root, int value){
        if (root == nullptr)
            return root;

        if (value< root->data)
            root->left = funcDelete(root->left, value);
        else if (value > root->data)
            root->right = funcDelete(root->right, value);
        else {
            if (root->left==nullptr) {
                node* temp=root->right;
                delete root;
                return temp;
            } else if (root->right ==nullptr) {
                node* temp=root->left;
                delete root;
                return temp;
            }

            node* temp=findMin(root->right);
            root->data = temp->data;
            root->right = funcDelete(root->right, temp->data);
        }
        return root;
    }

    // Finding the minimum value node in a subtree
    node* findMin(node* node) {
        while (node->left!=nullptr)
            node = node->left;
        return node;
    }

    // Preorder traversal
    void preorder(node* root) {
        if (root==nullptr)
            return;
        cout<<root->data <<" ";
        preorder(root->left);
        preorder(root->right);
    }

    // inorder traversal
    void inorder(node* root) {
        if (root==nullptr)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    // Postorder traversal
    void postorder(node* root) {
        if (root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    // calculate the height
    int findHeight(node* root) {
        if (root==nullptr)
            return -1;

        int leftHeight=findHeight(root->left);
        int rightHeight=findHeight(root->right);

        return max(leftHeight,rightHeight) + 1;
    }

    // Counting no. of nodes in the given tree
    int countnodes(node* root) {
        if (root == nullptr)
            return 0;
        return 1+countnodes(root->left)+countnodes(root->right);
    }

public:

    bst():root(nullptr){} //initialising tree 
    void insert(int value) {
        root=insert(root, value);
    }
    void remove(int value) {
        root=funcDelete(root, value);
    }

    void inorder() {
        inorder(root);
        cout <<"\n";
    }

    void preorder() {
        preorder(root);
        cout <<"\n";
    }

    void postorder() {
        postorder(root);
        cout<< "\n";
    }

    int findHeight() {
        return findHeight(root);
    }

    int countnodes() {
        return countnodes(root);
    }
};

int main() {
    bst tree;
    // Inserting elements into the tree
    tree.insert(64);
    tree.insert(43);
    tree.insert(55);
    tree.insert(19);
    tree.insert(39);
    tree.insert(63);
    tree.insert(79);
    
    // 3-Deleting the node by remove function
    tree.remove(30);//node not present
    tree.remove(63);

    // Traversals -Inorder, Preorder & Postorder
    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout <<"Postorder: ";
    tree.postorder();

    // 5. Height calculation of the Binary Search Tree
    cout << "Height of tree is " << tree.findHeight()<<"\n";

    // 6. Calculating the no. of nodes in the tree
    cout << "Number of nodes: " <<tree.countnodes()<<"\n";

    return 0;
}