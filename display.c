#include"main.h"
#include<string.h>

void inorder(Node *root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d(%c) ",root->data,root->color==RED ?'R':'B');
    inorder(root->right);
}
void displayTree(Node*root,char*branch,int level)
{
     if(root==NULL)
    return;
    char newPrefix[200];
    strcpy(newPrefix,branch);
    if(level==1)
    strcat(newPrefix,"│   ");
    else if(level==0)
    strcat(newPrefix,"      ");
    displayTree(root->right,newPrefix,0);
    printf("%s",branch);
    
        if(level==1)
        printf("└──");
        else if(level==0)
        printf("┌──");
        
    
    printf("%d(%c)\n",root->data,root->color==RED ? 'R' : 'B');
    strcpy(newPrefix,branch);
    
    if(level==1)
    strcat(newPrefix,"      ");
    else if(level==0)
    strcat(newPrefix,"│   ");
    
    displayTree(root->left,newPrefix,1);
    
}