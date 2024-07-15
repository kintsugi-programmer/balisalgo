#include <iostream>

using namespace std;

struct avlnode {
    int key;
    struct avlnode* l;
    struct avlnode* r;
    int ht;
};

struct avlnode* newNode(int key) {
    struct avlnode* node = new avlnode();
    node->key = key;
    node->l = nullptr;
    node->r = nullptr;
    node->ht = 1;
    return node;
}

int ht(struct avlnode* node) {
    if (node == nullptr)
        return 0;
    return node->ht;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct avlnode* rRotate(struct avlnode* y) {
    struct avlnode* x = y->l;
    struct avlnode* T2 = x->r;

    x->r = y;
    y->l = T2;

    y->ht = max(ht(y->l), ht(y->r)) + 1;
    x->ht = max(ht(x->l), ht(x->r)) + 1;

    return x;
}

struct avlnode* lRotate(struct avlnode* x) {
    struct avlnode* y = x->r;
    struct avlnode* T2 = y->l;

    y->l = x;
    x->r = T2;

    x->ht = max(ht(x->l), ht(x->r)) + 1;
    y->ht = max(ht(y->l), ht(y->r)) + 1;

    return y;
}

int blcFactor(struct avlnode* node) {
    if (node == nullptr)
        return 0;
    return ht(node->l) - ht(node->r);
}

struct avlnode* insert(struct avlnode* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->l = insert(node->l, key);
    else if (key > node->key)
        node->r = insert(node->r, key);
    else
        return node;

    node->ht = 1 + max(ht(node->l), ht(node->r));

    int blc = blcFactor(node);

    if (blc > 1 && key < node->l->key)
        return rRotate(node);

    if (blc < -1 && key > node->r->key)
        return lRotate(node);

    if (blc > 1 && key > node->l->key) {
        node->l = lRotate(node->l);
        return rRotate(node);
    }

    if (blc < -1 && key < node->r->key) {
        node->r = rRotate(node->r);
        return lRotate(node);
    }

    return node;
}

struct avlnode* minValueNode(struct avlnode* node) {
    struct avlnode* current = node;
    while (current->l != nullptr)
        current = current->l;
    return current;
}

struct avlnode* deleteNode(struct avlnode* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->l = deleteNode(root->l, key);
    else if (key > root->key)
        root->r = deleteNode(root->r, key);
    else {
        if (root->l == nullptr || root->r == nullptr) {
            struct avlnode* temp = root->l ? root->l : root->r;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            struct avlnode* temp = minValueNode(root->r);
            root->key = temp->key;
            root->r = deleteNode(root->r, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->ht = 1 + max(ht(root->l), ht(root->r));

    int blc = blcFactor(root);

    if (blc > 1 && blcFactor(root->l) >= 0)
        return rRotate(root);

    if (blc > 1 && blcFactor(root->l) < 0) {
        root->l = lRotate(root->l);
        return rRotate(root);
    }

    if (blc < -1 && blcFactor(root->r) <= 0)
        return lRotate(root);

    if (blc < -1 && blcFactor(root->r) > 0) {
        root->r = rRotate(root->r);
        return lRotate(root);
    }

    return root;
}

struct avlnode* search(struct avlnode* node, int key) {
    if (node == nullptr || node->key == key)
        return node;
    if (node->key < key)
        return search(node->r, key);
    return search(node->l, key);
}

void inOrd(struct avlnode* node) {
    if (node != nullptr) {
        inOrd(node->l);
        cout << node->key << " ";
        inOrd(node->r);
    }
}

int treeht(struct avlnode* root) {
    if (root == nullptr)
        return 0;
    return root->ht;
}

int main() {
    struct avlnode* root = nullptr;
    int choice, key;

    while (true) {
        cout << "\nAVL Tree Menu :\n";
        cout << "1.Insert a key\n";
        cout << "2.Delete a key\n";
        cout << "3.Key Search\n";
        cout << "4.Display Tree (Inorder Traversal)\n";
        cout << "5.Tree ht\n";
        cout << "6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > 6)
            break;

        if (choice == 1) {
            cout << "Enter key to insert: ";
            cin >> key;
            root = insert(root, key);
            cout << "Key " << key << " inserted into AVL tree\n";
        } else if (choice == 2) {
            cout << "Enter key to delete: ";
            cin >> key;
            root = deleteNode(root, key);
            cout << "Key " << key << " deleted from AVL tree\n";
        } else if (choice == 3) {
            cout << "Enter key to search: ";
            cin >> key;
            if (search(root, key))
                cout << "Key " << key << " found in AVL tree" << "\n";
            else
                cout << "Key " << key << " not found in AVL tree\n";
        } else if (choice == 4) {
            cout << "Inorder traversal of AVL tree: ";
            inOrd(root);
            cout << "\n";
        } else if (choice == 5) {
            cout << "ht of AVL tree: " << treeht(root) << "\n";
        } else if (choice == 6) {
            cout << "Exiting...\n";
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}