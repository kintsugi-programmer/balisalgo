#include <iostream>
#include <cstdlib>

struct node {
    int key;
    struct node *l;
    struct node *r;
};

void inord(struct node* x){
    if (x==NULL){return;}
    inord(x->l);
    std::cout<<x->key<<" ";
    inord(x->r);

    // notes pending 5
}

//search notes pending 7
int search(struct node* x,int data){if(x==NULL){return 0;}if(x->key==data){return 1;}if(data>x->key){return search(x->r,data);}else{return search(x->l,data);}}
int main() {
    struct node *parent = (struct node*)malloc(sizeof(struct node));
    parent->key = 10;
    parent->l = (struct node*)malloc(sizeof(struct node));
    parent->l->key = 5;
    parent->l->l = NULL;
    parent->l->r = NULL;
    parent->r = (struct node*)malloc(sizeof(struct node));
    parent->r->key = 15;
    parent->r->l = NULL;
    parent->r->r = NULL;

    // Your code logic goes here
    inord(parent);
    std::cout<<search(parent,15);


    return 0;
}
