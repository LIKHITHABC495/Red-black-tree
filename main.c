#include"main.h"

int main()
{
    Node *root=NULL;
    Node *newNode=NULL;
    int choice,data;
    while(1)
    {
        printf("\n=========================================================\n");
        printf("             RED BLACK TREE MENU         ");
        printf("\n=========================================================\n");
        printf("1. Insertion\n2. Inorder Traversal\n3. Display Tree\n4. Delete\n5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:

            printf("Enter the data:");
            scanf("%d",&data);
            newNode=createNode(data);
            if(newNode==NULL)
            {
                printf("Memory Allocation Failed!\n");
                break;
            }
            root=BSTinsert(root,newNode);
            fixinsertion(&root,newNode);
            Node *temp=search(root,data);
            printf("Node inserted successfully\n");
            break;

            case 2:

            if(root==NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                printf("Inorder Traversal : ");
                inorder(root);
                printf("\n");
            }
            break;
            case 3:

            if(root==NULL)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("\nRed Black Tree:\n");
                displayTree(root,"",-1);
            }
            break;

            case 4:
            if(root==NULL)
            {
                printf("Tree is empty!\n");
                break;
            }
            printf("Enter the data to delete: ");
            scanf("%d",&data);
            deleteNode(&root,data);
            printf("Deletion completed\n");
            break;

            case 5:
            printf("Exiting....\n");
            exit(0);

        default:
        printf("Invalid Choice!\n");
        }
    }
    return 0;
}