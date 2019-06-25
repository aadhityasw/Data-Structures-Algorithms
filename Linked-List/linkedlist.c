#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct numbers
{
    int num;
    struct numbers * prev;
    struct numbers * next;
}number;

number * creatept(int no)
{
    //-------------------------------------------Creation of Node-------------------------------------------
    number *pt = (number *) malloc(sizeof(number));
    pt->next=NULL;
    pt->prev=NULL;
    pt->num=no;
    return(pt);
}

number * appendpt(number * pt,number * ptr)
{
    //-------------------------------------------Appending the Nodes to the list-------------------------------------------
    if(ptr!=NULL)
    {
        ptr->next=pt;
        pt->prev=ptr;
    }
    return(pt);
}

void printptforward(number * start)
{
    //-------------------------------------------Printing Nodes-------------------------------------------
    number * ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->num);
        ptr=ptr->next;
    }
}

void printptreverse(number * end)
{
    //-------------------------------------------Printing Nodes in reverse order-------------------------------------------
    number * ptr;
    ptr=end;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->num);
        ptr=ptr->prev;
    }
}

number * findend(number * start)
{
    //-------------------------------------------Finding the end Point-------------------------------------------
    number *ptr;
    ptr=start;
    while((ptr->next)!=NULL)
    {
        ptr=ptr->next;
    }
    return(ptr);
}

number * searchpt(number * start, int no)
{
    //-------------------------------------------Searching-------------------------------------------
    number *ptr;
    ptr=start;
    while((ptr!=NULL)&&(ptr->num!=no))
    {
        ptr=ptr->next;
    }
    return(ptr);
}

number * insertptfront(number * start,int no)
{
    //-------------------------------------------Insertion in Front-------------------------------------------
    number * ptr;
    ptr=creatept(no);
    start->prev=ptr;
    ptr->next=start;
    start=ptr;
    return(start);
}

number * insertptend(number * end,int no)
{
    //-------------------------------------------Insertion in End-------------------------------------------
    number * ptr;
    ptr=creatept(no);
    end->next=ptr;
    ptr->prev=end;
    end=ptr;
    return(end);
}

void insertptmiddle(number * start, int no)
{
    //-------------------------------------------Insertion in Middle-------------------------------------------
    number *ptr, *pt, *ptr2;
    pt=creatept(no);
    ptr=start;
    while(ptr!=NULL)
    {
        if((pt->num)<=(ptr->num))
        {
            ptr2=ptr->prev;
            pt->next=ptr;
            pt->prev=ptr2;
            ptr2->next=pt;
            ptr->prev=pt;
            break;
        }
        ptr=ptr->next;
    }
}

number * deleteptfront(number * start)
{
    //-------------------------------------------Deletion in Front-------------------------------------------
    number * ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return(start);
}

number * deleteptend(number * end)
{
    //-------------------------------------------Deletion in End-------------------------------------------
    number * ptr;
    ptr=end;
    end=end->prev;
    end->next=NULL;
    free(ptr);
    return(end);
}

bool deleteptmiddle(number * start,int no)
{
    //-------------------------------------------Deletion-------------------------------------------
    number *ptr, *ptr1, *ptr2;
    ptr1=start;
    ptr=start->next;
    bool f=false;
    while(ptr!=NULL)
    {
        if(ptr->num==no)
        {
            ptr2=ptr->next;
            ptr1->next=ptr2;
            ptr2->prev=ptr1;
            f=true;
            break;
        }
        ptr=ptr->next;
    }
    return(f);
}

number * sortpt(number * start)
{
    printf("-------------------------------------------Sorting-------------------------------------------\n");
    number *ptr, *sortedstart, *sortptr, *sortedend;
    int no;
    sortedstart=creatept(start->num);
    ptr=start;
    ptr=ptr->next;
    while(ptr!=NULL)
    {
        no=ptr->num;
        sortedend=findend(sortedstart);
        if(no<=sortedstart->num)
        {
            sortedstart=insertptfront(sortedstart,no);
        }
        else if(no>=sortedend->num)
        {
            sortedend=insertptend(sortedend,no);
        }
        else
        {
            insertptmiddle(sortedstart,no);
        }
        ptr=ptr->next;
    }
    free(start);
    return(sortedstart);
}

number * getinput()
{
    //-------------------------------------------Input-------------------------------------------
    printf("Enter the number of numbers to be entered :- \t");
    int n,i,no;
    scanf("%d",&n);
    printf("Enter the numbers one by one :-\n");
    number *pt, *ptr=NULL, *start;
    for(i=0;i<n;i++)
    {
        scanf("%d",&no);
        pt=creatept(no);
        ptr=appendpt(pt,ptr);
        if(i==0)
        {
            start=ptr;
        }
    }
    return(start);
}

void printoption()
{
    //-------------------------------------------Print the options avalible for the user-------------------------------------------
    printf("Choose an option in order to proceed :-\n");
    printf("1) Print the list of numbers in forward order.\n");
    printf("2) Print the list of numbers in Reverse order.\n");
    printf("3) Insert a number to the front of the list of numbers.\n");
    printf("4) Insert a number to the end of the list of numbers.\n");
    printf("5) Insert a number in its appropriate position in a sorted list of numbers.\n");
    printf("6) Search for a number inside the list of numbers.\n");
    printf("7) Sort the list of numbers in ascending order.\n");
    printf("8) Sort the list of numbers in the descending order.\n");
    printf("9) Delete the first entry in the list of numbers.\n");
    printf("10) Delete the last entry in the list of numbers.\n");
    printf("11) Delete the first occurance of a number from the list of numbers.\n");
    printf("12) Exit the program.\n");
}

void freept(number * start)
{
    //-------------------------------------------Free the declared nodes-------------------------------------------
    number *ptr, *ptr2;
    ptr2=start;
    while(ptr2!=NULL)
    {
        ptr=ptr2;
        ptr2=ptr->next;
        free(ptr);
    }
}

void timelapse()
{
    //-------------------------------------------Relaxation Time-------------------------------------------
    int i=0;
    for(i=0;i<1000;i++);
}

int main()
{
    printf("-------------------------------------------Start of Program-------------------------------------------\n");
    number *start, *end;
    start = getinput();
    end=findend(start);

    int cho,i=1,no;
    do
    {
        printf("-------------------------------------------Round - %d-------------------------------------------\n",i);
        i++;
        printoption();
        printf("Enter your choice :-\t");
        scanf("%d",&cho);
        if(cho==1)
        {
            //-------------------------------------------Printing-------------------------------------------
            printf("The Entered numbers in the forward order are :- \n");
            printptforward(start);
        }
        else if(cho==2)
        {
            //-------------------------------------------Printing in Reverse-------------------------------------------
            printf("The Entered numbers in the reverse order are :- \n");
            printptreverse(end);
        }
        else if(cho==3)
        {
            printf("-------------------------------------------Insertion in Front-------------------------------------------\n");
            printf("Enter the number to be inserted in the front :-\t");
            scanf("%d",&no);
            start=insertptfront(start,no);
            printf("The number has been added in the front.\n");
            printf("The new list of numbers are :-\n");
            printptforward(start);
        }
        else if(cho==4)
        {
            printf("-------------------------------------------Insertion in End-------------------------------------------\n");
            printf("Enter the number to be inserted in the end :-\t");
            scanf("%d",&no);
            end=insertptend(end,no);
            printf("The number has been added in the end.\n");
            printf("The new list of numbers are :-\n");
            printptforward(start);
        }
        else if(cho==5)
        {
            printf("-------------------------------------------Insertion-------------------------------------------\n");
            printf("Enter the number to be inserted in the list :-\t");
            scanf("%d",&no);
            if(no<=start->num)
            {
                start=insertptfront(start,no);
            }
            else if(no>=end->num)
            {
                end=insertptend(end,no);
            }
            else
            {
                insertptmiddle(start,no);
            }
            printf("The number has been added.\n");
            printf("The new list of numbers are :-\n");
            printptforward(start);
        }
        else if(cho==6)
        {
            printf("-------------------------------------------Searching-------------------------------------------\n");
            printf("Enter the number to be searched :-\t");
            scanf("%d",&no);
            number * ptr;
            ptr=searchpt(start,no);
            if(ptr!=NULL)
            {
                printf("The entered number %d is present in the list of numbers and is found in location %p.\n",no,ptr);
            }
            else
            {
                printf("The entered number %d could not be found in the list of numbers.\n",no);
            }
        }
        else if(cho==7)
        {
            //-------------------------------------------Sorting-------------------------------------------
            start=sortpt(start);
            end=findend(start);
            printf("Sorting has been performed on the list of numbers.\n");
            printf("The numbers in ascending order are :-\n");
            printptforward(start);
        }
        else if(cho==8)
        {
            //-------------------------------------------Reverse Sorting-------------------------------------------
            start=sortpt(start);
            end=findend(start);
            printf("Sorting has been performed on the list of numbers.\n");
            printf("The numbers in descending order are :-\n");
            printptreverse(end);
        }
        else if(cho==9)
        {
            printf("-------------------------------------------Deletion in Front-------------------------------------------\n");
            no=start->num;
            start=deleteptfront(start);
            printf("The number has been deleted from the front of the list.\n");
            printf("The deleted number is :-\t%d\n",no);
            printf("The new list of numbers are :-\n");
            printptforward(start);
        }
        else if(cho==10)
        {
            printf("-------------------------------------------Deletion in End-------------------------------------------\n");
            no=end->num;
            end=deleteptend(end);
            printf("The number has been deleted from the end of the list.\n");
            printf("The deleted number is :-\t%d\n",no);
            printf("The new list of numbers are :-\n");
            printptforward(start);
        }
        else if(cho==11)
        {
            printf("-------------------------------------------Deletion-------------------------------------------\n");
            printf("Enter the number to be Deleted from the list :-\t");
            scanf("%d",&no);
            bool f=false;
            if(no==start->num)
            {
                start=deleteptfront(start);
                f=true;
            }
            else if(no==end->num)
            {
                end=deleteptend(end);
                f=true;
            }
            else
            {
                f=deleteptmiddle(start,no);
            }
            if(f==true)
            {
                printf("The number %d was found in the list and has thus been deleted from the list.\n",no);
                printf("The new list of numbers are :-\n");
            }
            else
            {
                printf("The entered number %d could not be found in the list of numbers.\n",no);
                printf("Please enter a valid number that is present in the list of numbers.\n");
                printf("The list of numbers are :-\n");
            }
            printptforward(start);
        }
        else if(cho==12)
        {
            printf("\t\tThank You\n");
            printf("-------------------------------------------End of Program-------------------------------------------\n");
            freept(start);
            break;
        }
        else
        {
            printf("-------------------------------------------Invalid Input-------------------------------------------\n");
            printf("You have entered an invalid input.\n");
            printf("Please choose a valid option.\n");
            continue;
        }
        timelapse();
    }while(cho!=12);
}