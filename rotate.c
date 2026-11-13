#include"main.h"

void leftRotate(Node **root,Node *currentnode)
{
    if(currentnode==NULL || currentnode->right==NULL)
    {
        return;
    }
    Node *rightchild=currentnode->right;

    currentnode->right=rightchild->left;

    if(rightchild->left!=NULL)
    {
        rightchild->left->parent=currentnode;
    }
    rightchild->parent=currentnode->parent;

    if(currentnode->parent==NULL)
    {
        *root=rightchild;
    }
    else if(currentnode==currentnode->parent->left)
    {
        currentnode->parent->left=rightchild;
    }
    else
    {
        currentnode->parent->right=rightchild;
    }
    rightchild->left=currentnode;
    currentnode->parent=rightchild;
}

void rightRotate(Node **root,Node *currentnode)
{
    if(currentnode==NULL || currentnode->left==NULL)
    {
        return;
    }
    Node *leftchild=currentnode->left;
    currentnode->left=leftchild->right;

    if(leftchild->right!=NULL)
    {
        leftchild->right->parent=currentnode;

    }
    leftchild->parent=currentnode->parent;

    if(currentnode->parent==NULL)
    {
        *root=leftchild;
    }
    else if(currentnode==currentnode->parent->left)
    {
        currentnode->parent->left=leftchild;
    }
    else
    {
        currentnode->parent->right=leftchild;
    }
    leftchild->right=currentnode;
    currentnode->parent=leftchild;

}