#include"main.h"

Node *createNode(int data)
{
    Node *new=malloc(sizeof(Node));
    if(new==NULL)
    {
        return NULL;
    }
    new->data=data;
    new->color=RED;
    new->left=NULL;
    new->right=NULL;
    new->parent=NULL;

    return new;
}

Node *BSTinsert(Node *root,Node *newNode)
{
    if(root==NULL)
    {
        return newNode;
    }
    Node *current=root;
    Node *parent=NULL;
    while(current!=NULL)
    {
        parent=current;
        if(newNode->data<current->data)
        {
            current=current->left;
        }
        else if(newNode->data>current->data)
        {
            current=current->right;
        }
        else
        {
            printf("Duplicate data is not allowed!\n");
            free(newNode);
            return root;
        }
    }
    newNode->parent=parent;
    if(newNode->data<parent->data)
    {
        parent->left=newNode;
    }
    else
    {
        parent->right=newNode;
    }
    return root;
}
