#include<iostream>
using namespace std;

template<class temp>
class Node
{
    public :
        temp data;
        Node<temp> *next;
};

template<class temp>
class Stack
{
    public :
        Node<temp> *start, *node;
        Stack()
        {
            start = new Node<temp>();
            node = new Node<temp>();
            start->next = NULL;
        }

        void push()
        {
            temp ele;
            cout<<"Enter the element to be inserted : ";
            cin>>ele;
            node = new Node<temp>();
            node->data = ele;
            node->next = start;
            start = node;
        }

        void pop()
        {
            if(start == NULL)
            {
                cout<<"The Stack is empty."<<endl;
            }
            else
            {
                temp ele;
                ele = start->data;
                start = start->next;
                cout<<"The taken element is : "<<ele<<endl; 
            }
            
        }

        void traverse()
        {
            node = new Node<temp>();
            node = start;
            cout<<"The traversal of the stack is : ";
            while(node->next!=NULL)
            {
                cout<<node->data<<"\t";
                node = node->next;
            }
            cout<<endl;
        }
};

int main()
{
    cout<<"-----------Welcome to Stacks----------"<<endl;
    bool flag = true;
    int cho;
    Stack<int> st;
    do
    {
        cout<<"Options avalible are : \n1)Push an element into stack.\n2)Pop an element from a stack.\n3)Print all the elements in the stack.\n4)Exit."<<endl;
        cout<<"Enter your choice : ";
        cin>>cho;
        switch (cho)
        {
            case 1 :
                st.push();
                break;
            case 2 :
                st.pop();
                break;
            case 3 :
                st.traverse();
                break;
            case 4 :
                flag = false;
                break;
            default:
                cout<<"Enter a valid choice."<<endl;
                break;
        }
        cout<<"-------------------------------"<<endl;
    }while(flag);
    cout<<"-----------End of Program----------"<<endl;
}