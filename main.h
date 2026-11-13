#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
typedef enum
{
    RED,
    BLACK
}Color;
typedef struct node
{
    int data;
    Color color;
    struct node *left;
    struct node *right;
    struct node *parent;
}Node;

Node *createNode(int data);
Node *BSTinsert(Node *root,Node *newNode);
void inorder(Node *root);
void leftRotate(Node **root,Node *currentNode);
void rightRotate(Node **root,Node *currentNode);
void inorder(Node *root);
void displayTree(Node*root,char*branch,int level);
Node *getGrandParent(Node *currentNode);
Node *getUncle(Node *currentnode);
void fixinsertion(Node **root,Node *currentnode);
Node *search(Node *root,int data);
Node *minimum(Node *node);
void transplant(Node **root,Node *nodetoreplace,Node *replacementnode);
void deleteNode(Node **root,int data);
void fixDeletion(Node **root,Node *currentnode,Node *parentnode);
Node *getSibling(Node *node);
int hasRedchild(Node *node);

#endif
