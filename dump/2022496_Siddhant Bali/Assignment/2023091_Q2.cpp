#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    struct Node* LT, * RT;
};

Node* New_node(int key)
{
    Node* temp=new Node;
    temp->key=key;
    temp->LT=temp->RT=NULL;
    return (temp);
}

int Burn_Tree_funct(Node* root, int target, vector<Node*>& v)
{
    if (root == NULL) {
        return 0;
    }

    if (root->key == target) {
        cout << root->key << endl;
        if (root->LT != NULL) {
            v.push_back(root->LT);
        }
        if (root->RT != NULL) {
            v.push_back(root->RT);
        }
        return 1;
    }

    int a=Burn_Tree_funct(root->LT, target, v);

    if (a == 1) {
        int v_Size=v.size();
        while (v_Size--) {
            Node* temp=v.front();

            cout << temp->key << " , ";
            v.erase(v.begin());

            if (temp->LT != NULL)
                v.push_back(temp->LT);

            if (temp->RT != NULL)
                v.push_back(temp->RT);
        }

        if (root->RT != NULL)
            v.push_back(root->RT);

        cout << root->key << endl;

        return 1;
    }

    int b=Burn_Tree_funct(root->RT, target, v);

    if (b == 1) {
        int v_Size=v.size();

        while (v_Size--) {
            Node* temp=v.front();

            cout << temp->key << " , ";
            v.erase(v.begin());

            if (temp->LT != NULL)
                v.push_back(temp->LT);

            if (temp->RT != NULL)
                v.push_back(temp->RT);
        }

        if (root->LT != NULL)
            v.push_back(root->LT);

        cout << root->key << endl;

        return 1;
    }

    return 0;
}

void Burn_Tree(Node* root, int target)
{
    vector<Node*> v;

    Burn_Tree_funct(root, target, v);

    while (!v.empty()) {
        int v_Size=v.size();
        while (v_Size > 0) {
            Node* temp=v.front();

            cout << temp->key;
            if (temp->LT != NULL) {
                v.push_back(temp->LT);
            }
            if (temp->RT != NULL) {
                v.push_back(temp->RT);
            }

            if (v.size() != 1)
                cout << " , ";

            v.erase(v.begin());
            v_Size--;
        }
        cout << endl;
    }
}

int main()
{
    /*     12
         / \
        13  10
           / \
         14   15
         / \ / \
        21 22 23 24

 */

    Node* root=New_node(12);
    root->LT=New_node(13);
    root->RT=New_node(10);

    root->RT->LT=New_node(14);
    root->RT->RT=New_node(15);

    root->RT->LT->LT=New_node(21);
    root->RT->LT->RT=New_node(24);
    root->RT->RT->LT=New_node(22);
    root->RT->RT->RT=New_node(23);
    int targetNode=14;

    Burn_Tree(root, targetNode);

    return 0;
}
