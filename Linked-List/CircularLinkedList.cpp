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
                start->next = start;
            }
            else
            {
                Node<temp> *end;
                end = start;
                while(end->next!=start)
                {
                    end = end->next;
                }
                newnode->next = start;
                start = newnode;
                end->next = start;
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
                while(ptr->next!=start)
                {
                    ptr = ptr->next;
                }
                newnode->next = start;
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
                while(ptr->next!=start and flag==false)
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
            if(ptr!=NULL)
            {
                do
                {
                    cout<<ptr->data<<'\t';
                    ptr = ptr->next;
                }while(ptr!=start);
            }
            else
            {
                cout<<"Invalid Input";
            }
            
            cout<<endl;
        }

        void deleteFront()
        {
            //-------------------------------------------Deletion in Front-------------------------------------------
            Node<temp> *end;
            end = start;
            while(end->next!=start)
            {
                end = end->next;
            }
            ptr = start->next;
            start->next = NULL;
            start = ptr;
            end->next = start;
        }

        void deleteEnd()
        {
            //-------------------------------------------Deletion in End-------------------------------------------
            ptr = start;
            while(ptr->next->next!=start)
            {
                ptr = ptr->next;
            }
            ptr->next->next = NULL;
            ptr->next = start;
        }

        void search()
        {
            //-------------------------------------------Searching-------------------------------------------
            cout<<"Enter the element to be searched : ";
            temp t;
            cin>>t;
            ptr = start;
            bool flag = false;
            do
            {
                if(ptr->data==t)
                {
                    flag = true;
                    break;
                }
                ptr = ptr->next;
            }while(ptr!=start);
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
    cout<<"4) Delete a node in the front"<<endl;
    cout<<"5) Delete a node in the end"<<endl;
    cout<<"6) Print the nodes."<<endl;
    cout<<"7) Search for an element in the list."<<endl;
    cout<<"8) Exit"<<endl;
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
                list.deleteFront();
                break;
            case 5 :
                list.deleteEnd();
                break;
            case 6 :
                list.printList();
                break;
            case 7 :
                list.search();
                break;
            case 8 :
                cout<<"End of program."<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    } while (cho!=8);
}