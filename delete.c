#include"main.h"

Node *search(Node *root,int data)
{
    Node *current =root;
    while(current!=NULL)
    {
        if(data==current->data)
        {
            return current;
        }
        else if(data<current->data)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }

    }
    return NULL;

}

Node *minimum(Node *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    while(node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}
void transplant(Node **root,Node *nodetoreplace,Node *replacementnode)
{

    if(nodetoreplace->parent==NULL)
    {
        *root=replacementnode;
    }
    else if(nodetoreplace==nodetoreplace->parent->left)
    {
        nodetoreplace->parent->left=replacementnode;
    }
    else
    {
        nodetoreplace->parent->left=replacementnode;
    }
    if(replacementnode!=NULL)
    {
        replacementnode->parent=nodetoreplace->parent;
    }
}
void deleteNode(Node **root,int data)
{
    Node*nodeToDelete=search(*root,data);
    if(nodeToDelete==NULL)
    {
        printf("Node not found\n");
        return;
    }
    Node*replacementNode=NULL;
    Node*parentnode=NULL;
    Node*successor=NULL;
    Color deleteNodeColor=nodeToDelete->color;
    /* Case 1 No left child*/
    if(nodeToDelete->left==NULL)
    {
        replacementNode=nodeToDelete->right;
        parentnode=nodeToDelete->parent;

        transplant(root,nodeToDelete,replacementNode);
        
    }
    //Case 2 No right child/

    else if(nodeToDelete->right==NULL)
    {
        replacementNode=nodeToDelete->left;
        parentnode=nodeToDelete->parent;
        transplant(root,nodeToDelete,replacementNode);
    }
    //Case 3 Two children/
    //Node*successor=minimum(nodeToDelete->right);
    else
    {
        successor=minimum(nodeToDelete->right);
        deleteNodeColor=successor->color;
        replacementNode=successor->right;
        if(successor->parent==nodeToDelete)
        {
            parentnode=successor;
            if(replacementNode!=NULL)
            replacementNode->parent=successor;
        }
        else
        {
            parentnode=successor->parent;
            transplant(root,successor,successor->right);
            successor->right=nodeToDelete->right;
            successor->right->parent=successor;
        }
        transplant(root,nodeToDelete,successor);
        successor->left=nodeToDelete->left;
        successor->left->parent=successor;
        successor->color=nodeToDelete->color;
    }
    free(nodeToDelete);
    if(deleteNodeColor==BLACK)
    {
        if(replacementNode!=NULL && replacementNode->color==RED)
        {
            replacementNode->color=BLACK;
        }
        else
        fixDeletion(root,replacementNode,parentnode);
    }
    if(*root!=NULL)
    (*root)->color=BLACK;
    
}
Node *getSibling(Node *node)
{
    if(node==NULL || node->parent==NULL)
    {
        return NULL;
    }
    if(node==node->parent->left)
    {
        return node->parent->right;
    }
    return node->parent->left;
}
int hasRedchild(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->left!=NULL && node->left->color==RED)
    {
        return 1;
    }
    if(node->right!=NULL && node->right->color==RED)
    {
        return 1;
    }
    return 0;
}
void fixDeletion(Node **root,Node *currentnode,Node *parentnode)
{
    if(parentnode==NULL)
    {
        return;
    }
    Node *siblingNode=NULL;
    if(currentnode==parentnode->left)
    {
        siblingNode=parentnode->right;
    }
    else
    {
        siblingNode=parentnode->left;
    }
    if(siblingNode!=NULL && siblingNode->color==RED)
    {
        parentnode->color=RED;
        siblingNode->color=BLACK;
        if(currentnode==parentnode->left)
        {
            leftRotate(root,parentnode);
        }
        else
        {
            rightRotate(root,parentnode);
        }
       
    }
    else if(siblingNode!=NULL && siblingNode->color==BLACK && !hasRedchild(siblingNode))
    {
        siblingNode->color=RED;
        if(parentnode->color==RED)
        {
            parentnode->color=BLACK;
        }
        else
        {
            if(parentnode->parent!=NULL)
            {
                fixDeletion(root,parentnode,parentnode->parent);
            }
        }
    }
}