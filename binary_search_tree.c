#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int flag=0;
int myflag=0;
struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *mytree = NULL; 
struct node *temp= NULL;
void insertnode(struct node *tree, int myvalue)
{
    if(flag==0)
    {
        tree->value=myvalue;
        printf("Value Added : %d\n",tree->value);
        tree->left=NULL;
        tree->right=NULL;
        flag=1;
    }
    else
    {  
        while (myflag!=1)
        {
            if(myvalue > tree->value)
            {
                if(tree->right==NULL)
                {
                    tree->right = (struct node *)malloc(sizeof(struct node));
                    tree = tree->right;
                    tree->value = myvalue;
                    printf("Value Added : %d \n",tree->value);
                    tree->left = NULL;
                    tree->right = NULL;
                    myflag=1;
                }
                else
                {
                    tree = tree->right;
                }
            }
            else
            {
                if(tree->left==NULL)
                {
                    tree->left = (struct node *)malloc(sizeof(struct node));
                    tree = tree->left;
                    tree->value = myvalue;
                    printf("Value Added : %d \n",tree->value);
                    tree->left = NULL;
                    tree->right = NULL;
                    myflag=1;
                }
                else
                {
                    tree = tree->left;
                }
            }
        }
        
    }
    myflag=0;
}

void deletenode(struct node *tree,int myvalue)
{
    while (myflag!=1)
    {
        if (myvalue<tree->value)
            tree = tree->left;
        
        else if (myvalue>tree->value)
            tree = tree->right;
        
        else
        {
            if(tree->left==NULL && tree->right==NULL)
            {
                temp->left=NULL;
                temp->right=NULL;
                printf("Deleted\n");
                myflag=1;
            }
            else if (tree->left==NULL)
            {
                printf("\nValue deleted : %d\n",tree->value);
                temp = tree->right;
                tree->value = temp->value;
                tree->left = temp->left;
                tree->right = temp->right;
                myflag=1;
            }
            else if (tree->right==NULL)
            {
                printf("\nValue deleted : %d\n",tree->value);
                temp = tree->left;
                tree->value = temp->value;
                tree->left = temp->left;
                tree->right = temp->right;
                myflag=1;
            }
            else
            {
                temp = tree;
                // printf("\nDEBUG 1\n");
                int tmpflag = 0;
                while (myflag!=1)
                {
                    if(tmpflag==0)
                    {
                        tree = tree->left;
                        tmpflag++;
                    }
                    else
                    {
                        tree = tree->right;
                    }
                    if(tree->left == NULL && tree->right == NULL)
                        myflag=1;
                }
                temp->value = tree->value;
                tree->value = NULL;
                myflag=1;
            }    
        }
        temp = tree;
    }
    if(myflag==0)
        printf("NOT DELETED");
    else
        printf("\nValue Deleted : %d\n",myvalue);
    myflag = 0;
    
}

void displaytree(struct node *tree)
{
    if(tree == NULL || tree->value==NULL)
        return;
    
    printf(" %d ",tree->value);
    displaytree(tree->left);
    displaytree(tree->right);
}
int main(){
    mytree = (struct node *)malloc(sizeof(struct node));
    insertnode(mytree,10);
    insertnode(mytree,5);
    insertnode(mytree,4);
    insertnode(mytree,6);
    insertnode(mytree,7);
    insertnode(mytree,8);
    insertnode(mytree,15);
    insertnode(mytree,18);
    insertnode(mytree,16);
    insertnode(mytree,19);
    displaytree(mytree);
    deletenode(mytree,10);
    displaytree(mytree);
    return 0;
}