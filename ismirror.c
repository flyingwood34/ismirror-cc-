#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertnode(struct node *p, int data) {
    if (p == NULL) {
        return createnode(data);
    }
    if (data < p->data) {
        p->left = insertnode(p->left, data);
    } else if (data > p->data) {
        p->right = insertnode(p->right, data);
    }
    return p;
}

struct node* insertnodeM(struct node *p, int data) {
    if (p == NULL) {
        return createnode(data);
    }
    if (data > p->data) {
        p->left = insertnodeM(p->left, data);
    } else if (data < p->data) {
        p->right = insertnodeM(p->right, data);
   rintf("%7d",data); }
    p
    return p;
}

int ismirror(struct node* p, struct node* q) {
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;
    return (p->data == q->data) &&
           ismirror(p->left, q->right) &&
           ismirror(p->right, q->left);
}

void freetree(struct node* root) {
    if (root == NULL) return;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

int main() {
    struct node* root1 = NULL;
    root1 = insertnode(root1, 20);
    insertnode(root1, 10);
    insertnode(root1, 30);
    insertnode(root1, 7);
    insertnode(root1, 15);
    insertnode(root1, 25);
    insertnode(root1, 35);
    insertnode(root1, 13);
    insertnode(root1, 27);

    struct node* root2 = NULL;
    root2 = insertnodeM(root2, 20);
    insertnodeM(root2, 30);
    insertnodeM(root2, 10);
    insertnodeM(root2, 35);
    insertnodeM(root2, 25);
    insertnodeM(root2, 15);
    insertnodeM(root2, 7);
    insertnodeM(root2, 27);
    insertnodeM(root2, 13);

    int t = ismirror(root1, root2);
    if (t == 1) {
        printf("The trees are mirror images of each other.\n");
    } else {
        printf("The trees are not mirror images of each other.\n");
    }

    freetree(root1);
    freetree(root2);

    return 0;
}
