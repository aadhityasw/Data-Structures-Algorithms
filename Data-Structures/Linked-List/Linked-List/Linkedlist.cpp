#include<iostream>
using namespace std;

template<class temp>
class Node
{
    //-------------------------------------------Creation of Node-------------------------------------------
    public :
        temp data;
        Node *next;
};

template<class temp>
class Linkedlist
{
    public :
        Node<temp> *start, *ptr;

        Linkedlist()
        {
            start = NULL;
        }

        void insertFront()
        {
            //-------------------------------------------Insertion in Front-------------------------------------------
            Node<temp> *newnode = new Node<temp>();
            cout<<"Enter the element : ";
            cin>>newnode->data;
            newnode->next = NULL;
            if(start == NULL)
            {
                start = newnode;
            }
            else
            {
                newnode->next = start;
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
            if(start == NULL)
            {
                start = newnode;
            }
            else
            {
                ptr = start;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
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
                start = newnode;
            }
            else
            {
                cout<<"Enter the index at which the element has to be inserted : ";
                cin>>index;
                while(ptr->next!=NULL and flag==false)
                {
                    if(i==index)
                    {
                        flag = true;
                        break;
                    }
                    ptr = ptr->next;
                    i++;
                }
                if(flag==true)
                {
                    cout<<"Enter the element : ";
                    cin>>newnode->data;
                    newnode->next = ptr->next;
                    ptr->next = newnode;
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

        void deleteFront()
        {
            //-------------------------------------------Deletion in Front-------------------------------------------
            ptr = start->next;
            start->next = NULL;
            start = ptr;
        }

        void deleteMiddle()
        {
            //-------------------------------------------Deletion in middle-------------------------------------------
            int index, i=0;
            cout<<"Enter the index at which the element has to be deleted : ";
            cin>>index;
            ptr = start;
            while(ptr!=NULL && i!=index)
            {
                ptr = ptr->next;
                i += 1;
            }
            if(i==index)
            {
                Node<temp> *newnode;
                newnode = ptr->next;
                ptr->next = newnode->next;
                newnode->next = NULL;
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
    cout<<"8) Search for an element in the list."<<endl;
    cout<<"9) Exit"<<endl;
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
                list.search();
                break;
            case 9 :
                cout<<"End of program."<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    } while (cho!=9);
}