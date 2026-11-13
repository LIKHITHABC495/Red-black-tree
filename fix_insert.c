#include"main.h"

Node *getGrandParent(Node *currentNode)
{
    if(currentNode==NULL || currentNode->parent==NULL)
    {
           return NULL;
    }
    return currentNode->parent->parent;
}
Node *getUncle(Node *currentnode)
{
    Node *grandparent=getGrandParent(currentnode);

    if(grandparent==NULL)
    {
        return NULL;
    }
    if(currentnode->parent==grandparent->left)
    {
        return grandparent->right;
    }
    else
    {
        return grandparent->left;
    }
}
void fixinsertion(Node **root,Node *currentnode)
{
    Node *parentNode=NULL;
    Node *grandparent=NULL;
    Node *uncleNode=NULL;

    while(currentnode!=*root && currentnode->parent!=NULL && currentnode->parent->color ==RED)
    {
        parentNode=currentnode->parent;
        grandparent=getGrandParent(currentnode);
        if(grandparent==NULL)
        {
            break;
        }
        if(parentNode==grandparent->left)
        {
            uncleNode=grandparent->right;
            if(uncleNode!=NULL && uncleNode->color==RED)
            {
                parentNode->color=BLACK;
                uncleNode->color=BLACK;
                grandparent->color=RED;
                currentnode=grandparent;
            }
            else if(currentnode==parentNode->right)
            {
                leftRotate(root,parentNode);
                currentnode=parentNode;
                parentNode=currentnode->parent;
            }
            else
            {
                parentNode->color=BLACK;
                grandparent->color=RED;
                rightRotate(root,grandparent);
            }
        }
        else
        {
            uncleNode=grandparent->left;
            if(uncleNode!=NULL && uncleNode->color==RED)
            {
                parentNode->color=BLACK;
                uncleNode->color=BLACK;
                grandparent->color=RED;

                currentnode=grandparent;
            }


            else if(currentnode==parentNode->left)
            {
                rightRotate(root,parentNode);
                currentnode=parentNode;
                parentNode=currentnode->parent;
            }
            else
            {
                parentNode->color=BLACK;
                grandparent->color=RED;

                leftRotate(root,grandparent);
            }
        }
    }
    (*root)->color=BLACK;
}