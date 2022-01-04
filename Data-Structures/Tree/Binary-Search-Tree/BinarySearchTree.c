#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct numbers
{
    int data;
    struct numbers * left;
    struct numbers * right;
}tree;

void printoption()
{
    //-------------------------------------------Print the options avalible for the user-------------------------------------------
    printf("Choose an option in order to proceed :-\n");
    printf("1) Traverse the tree in-order.\n");
    printf("2) Traverse the tree in pre-order.\n");
    printf("3) Traverse the tree in post-order.\n");
    printf("4) Insert a number into the tree.\n");
    printf("5) Delete a number from the tree.\n");
    printf("6) Search for a number inside the tree.\n");
    printf("7) Exit the program.\n");
}

tree * creatept(int no)
{
    //-------------------------------------------Creation of Node-------------------------------------------
    tree * pt;
    pt=(tree*)malloc(sizeof(tree));
    pt->data=no;
    pt->left=NULL;
    pt->right=NULL;
    return(pt);
}

bool insertpt(tree * node, int no)
{
    //-------------------------------------------Insertion-------------------------------------------
    if(node->data==no)
    {
        return(false);
    }
    else if(node->data<no)
    {
        if(node->right==NULL)
        {
            tree * pt;
            pt=creatept(no);
            node->right=pt;
            return(true);
        }
        else
        {
            return(insertpt(node->right,no));
        }
    }
    else
    {
        if(node->left==NULL)
        {
            tree * pt;
            pt=creatept(no);
            node->left=pt;
            return(true);
        }
        else
        {
            return(insertpt(node->left,no));
        }
    }
}

tree * getinput()
{
    //-------------------------------------------Input-------------------------------------------
    printf("Enter the number of numbers to be entered into the tree :- \t");
    int n,i,no;
    scanf("%d",&n);
    printf("Enter the numbers one by one :-\n");
    tree *pt, *root;
    for(i=0;i<n;i++)
    {
        scanf("%d",&no);
        pt=creatept(no);
        if(i==0)
        {
            root=pt;
        }
        else
        {
            insertpt(root,no);
        }
    }
    return(root);
}

void preorder(tree * node)
{
    //-------------------------------------------Printing Nodes in pre-order-------------------------------------------
    if(node!=NULL)
    {
        printf("%d\n",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(tree * node)
{
    //-------------------------------------------Printing Nodes in in-order-------------------------------------------
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }
}

void postorder(tree * node)
{
    //-------------------------------------------Printing Nodes in post-order-------------------------------------------
    if(node!=NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\n",node->data);
    }
}

void freept(tree * node)
{
    //-------------------------------------------Free the declared nodes-------------------------------------------
    if(node!=NULL)
    {
        freept(node->left);
        freept(node->right);
        free(node);
    }
}

tree * searchpt(tree * node, int no)
{
    //-------------------------------------------Searching-------------------------------------------
    if(node==NULL)
    {
        return(node);
    }
    else
    {
        if(node->data==no)
        {
            return(node);
        }
        else if (node->data>no)
        {
            return(searchpt(node->left,no));
        }
        else
        {
            return(searchpt(node->right,no));
        }
    }
}

 int * traversept(tree * node)
 {
    //-------------------------------------------Traversing-------------------------------------------
    static int i=0;
    static int *arr;
    if(i!=0)
    {
        arr[i]=node->data;
        i++;
    }
    arr=traversept(node->left);
    arr=traversept(node->right);
    return(arr);
 }
/*
bool deletept(tree * node, int no)
{
    //-------------------------------------------Deletion-------------------------------------------
    if(node==NULL)
    {
        return(false);
    }
    else
    {
        if(node->data<no)
        {
            return(deletept(node->right,no));
        }
        else if(node->data>no)
        {
            return(deletept(node->left,no));
        }
        else
        {
            tree * ptr;
            ptr=node;
            static int *arr;
            arr=traversept(node);
            int i,n;
            n=sizeof(arr)/sizeof(int);
            bool f;
            for(i=0;i<n;i++)
            {
                f=insertpt(ptr,arr[i]);
            }
            return(true);
        }
    }
}
*/

void timelapse()
{
    int i=0;
    for(i=0;i<1000;i++);
}

int main()
{
    printf("-------------------------------------------Start of Program-------------------------------------------\n");
    tree * root;
    root = getinput();
    int cho,i=1,no;
    bool f;
    do
    {
        printf("-------------------------------------------Round - %d-------------------------------------------\n",i);
        i++;
        printoption();
        printf("Enter your choice :-\t");
        scanf("%d",&cho);
        switch(cho)
        {
            case 1 :
                printf("-------------------------------------------Traversing in In-Order-------------------------------------------\n");
                printf("The tree traversed in an in-order format is as follows :- \n");
                inorder(root);
                break;
            case 2 :
                printf("-------------------------------------------Traversing in Pre-Order-------------------------------------------\n");
                printf("The tree traversed in an pre-order format is as follows :- \n");
                preorder(root);
                break;
            case 3 :
                printf("-------------------------------------------Traversing in Post-Order-------------------------------------------\n");
                printf("The tree traversed in an post-order format is as follows :- \n");
                postorder(root);
                break;
            case 4 :
                printf("-------------------------------------------Insertion-------------------------------------------\n");
                printf("Enter the nuber to be inserted :-\t\n");
                scanf("%d",&no);
                f=insertpt(root,no);
                if(f==true)
                {
                    printf("The number %d has been inserted into the tree.\n",no);
                }
                else
                {
                    printf("The number %d cannot be inserted into the tree as it is already present in the tree.\n",no);
                }
                break;
            /*case 5 :
                printf("-------------------------------------------Deletion-------------------------------------------\n");
                printf("Enter the nuber to be deleted :-\t\n");
                scanf("%d",&no);
                f=deletept(root,no);
                if(f==true)
                {
                    printf("The number %d has been deleted from the tree.\n",no);
                }
                else
                {
                    printf("The number %d cannot be deleted from the tree as it is not present in the tree.\n",no);
                }
                break;*/
            case 6 :
                printf("-------------------------------------------Searching-------------------------------------------\n");
                printf("Enter the nuber to be searched :-\t\n");
                scanf("%d",&no);
                tree * pt;
                pt=searchpt(root,no);
                if(pt!=NULL)
                {
                    printf("The number %d has been found in the tree at the address %p.\n",no,pt);
                }
                else
                {
                    printf("The number %d cannot be found in the tree.\n",no);
                }
                break;
            case 7 :
                printf("\t\tThank You\n");
                printf("-------------------------------------------End of Program-------------------------------------------\n");
                freept(root);
                break;
            default :
                printf("-------------------------------------------Invalid Input-------------------------------------------\n");
                printf("You have entered an invalid input.\n");
                printf("Please choose a valid option.\n");
        }
        timelapse();
    }while(cho!=7);
}