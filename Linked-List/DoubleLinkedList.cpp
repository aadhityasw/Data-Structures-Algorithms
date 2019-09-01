#include<iostream>
using namespace std;

template<class temp>
class Node
{
    //-------------------------------------------Creation of Node-------------------------------------------
    public :
        temp data;
        Node<temp> *next;
        Node<temp> *prev;
};

template<class temp>
class Linkedlist
{
    public :
        Node<temp> *start, *ptr, *end;

        Linkedlist()
        {
            start = NULL;
            end = NULL;
        }

        void insertFront()
        {
            //-------------------------------------------Insertion in Front-------------------------------------------
            Node<temp> *newnode = new Node<temp>();
            cout<<"Enter the element : ";
            cin>>newnode->data;
            newnode->next = NULL;
            newnode->prev = NULL;
            if(start == NULL)
            {
                start = newnode;
                end = start;
            }
            else
            {
                newnode->next = start;
                start->prev = newnode;
                start = newnode;
            }
        }

        void insertEnd()
        {
            //-------------------------------------------Insertion in End-------------------------------------------
            Node<temp> *newnode = new Node<temp>();
            cout<<"Enter the element : ";
            cin>>newnode->data;
            newnode->next = NULL;
            newnode->prev = NULL;
            if(start == NULL)
            {
                start = newnode;
                end = start;
            }
            else
            {
                ptr = start;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
                newnode->prev = ptr;
                end = newnode;
            }
        }

        void insertMiddle()
        {
            //-------------------------------------------Insertion in Middle-------------------------------------------
            int index, i=0;
            bool flag = false;
            Node<temp> *newnode = new Node<temp>();
            ptr = start;
            if(start==NULL)
            {
                cout<<"Enter the element : ";
                cin>>newnode->data;
                newnode->next = NULL;
                newnode->prev = NULL;
                start = newnode;
                end = start;
            }
            else
            {
                cout<<"Enter the index at which the element has to be inserted : ";
                cin>>index;
                if(index!=0)
                {
                    while(ptr->next!=NULL and flag==false)
                    {
                        if(i==index-1)
                        {
                            flag = true;
                            break;
                        }
                        ptr = ptr->next;
                        i++;
                    }
                }
                if(flag==true)
                {
                    cout<<"Enter the element : ";
                    cin>>newnode->data;
                    ptr->next->prev = newnode;
                    newnode->next = ptr->next;
                    ptr->next = newnode;
                    newnode->prev = ptr;
                }
                else
                {
                    cout<<"Invalid index"<<endl;
                }
            }
            
            
        }

        void printList()
        {
            //-------------------------------------------Printing Nodes-------------------------------------------
            cout<<"The nodes in the list are : ";
            ptr = start;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<'\t';
                ptr = ptr->next;
            }
            cout<<endl;
        }

        void printReverse()
        {
            //-------------------------------------------Printing Nodes in reversed order-------------------------------------------
            cout<<"The nodes in the list in the reversed order : ";
            ptr = end;
            while(ptr!=NULL)
            {
                cout<<ptr->data<<'\t';
                ptr = ptr->prev;
            }
            cout<<endl;
        }

        void deleteFront()
        {
            //-------------------------------------------Deletion in Front-------------------------------------------
            ptr = start->next;
            start->next = NULL;
            start = ptr;
            start->prev = NULL;
        }

        void deleteMiddle()
        {
            //-------------------------------------------Deletion in middle-------------------------------------------
            int index, i=0;
            cout<<"Enter the index at which the element has to be deleted : ";
            cin>>index;
            ptr = start;
            if(index>0)
            {
                while(ptr!=NULL && i!=index-1)
                {
                    ptr = ptr->next;
                    i += 1;
                }
            }
            if(i==index-1)
            {
                Node<temp> *newnode;
                newnode = ptr->next;
                ptr->next = newnode->next;
                newnode->next->prev = ptr;
                newnode->next = NULL;
                newnode->prev = NULL;
            }
            else
            {
                cout<<"Invalid Index"<<endl;
            }
        }

        void deleteEnd()
        {
            //-------------------------------------------Deletion in End-------------------------------------------
            ptr = start;
            while(ptr->next->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            end->prev = NULL;
            end = ptr;
        }

        void search()
        {
            //-------------------------------------------Searching-------------------------------------------
            cout<<"Enter the element to be searched : ";
            temp t;
            cin>>t;
            ptr = start;
            bool flag = false;
            while(ptr!=NULL)
            {
                if(ptr->data==t)
                {
                    flag = true;
                    break;
                }
                ptr = ptr->next;
            }
            if(flag)
            {
                cout<<"The element is found."<<endl;
            }
            else
            {
                cout<<"The element is not found."<<endl;
            }
        }
};

void printOptions()
{
    cout<<"The avalible options are : "<<endl;
    cout<<"1) Insert a node in the middle"<<endl;
    cout<<"2) Insert a node in the front"<<endl;
    cout<<"3) Insert a node in the end"<<endl;
    cout<<"4) Delete a node in the middle"<<endl;
    cout<<"5) Delete a node in the front"<<endl;
    cout<<"6) Delete a node in the end"<<endl;
    cout<<"7) Print the nodes."<<endl;
    cout<<"8) Print the nodes in reverse order."<<endl;
    cout<<"9) Search for an element in the list."<<endl;
    cout<<"10) Exit"<<endl;
}


int main()
{
    Linkedlist<int> list;
    int cho;
    do
    {
        printOptions();
        cout<<"Enter your option : ";
        cin>>cho;
        switch(cho)
        {
            case 1 :
                list.insertMiddle();
                break;
            case 2 :
                list.insertFront();
                break;
            case 3 :
                list.insertEnd();
                break;
            case 4 :
                list.deleteMiddle();
                break;
            case 5 :
                list.deleteFront();
                break;
            case 6 :
                list.deleteEnd();
                break;
            case 7 :
                list.printList();
                break;
            case 8 :
                list.printReverse();
                break;
            case 9 :
                list.search();
                break;
            case 10 :
                cout<<"End of program."<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    } while (cho!=10);
}