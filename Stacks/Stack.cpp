#include <iostream>
using namespace std;

template<class temp>
class Stack
{
    public :
        int size, top;
        temp *arr;
        Stack(int s)
        {
            size = s;
            top = -1;
            arr = new temp[size];
        }
        void push()
        {
            temp ele;
            cout<<"Enter the element to be inserted : ";
            cin>>ele;
            if(top==size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else
            {
                arr[++top] = ele;
            }
        }
        void pop()
        {
            if(top==-1)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                temp ele;
                ele = arr[top--];
                cout<<"The deleted element is : "<<ele<<endl;
            }
        }
        void traverse()
        {
            int i;
            cout<<"The elements in the stack are : "<<endl;
            for(i=top;i>=0;i--)
            {
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
};

int main()
{
    cout<<"-----------Welcome to Stacks----------"<<endl;
    bool flag = true;
    int size, cho;
    cout<<"Enter the size of the stack : ";
    cin>>size;
    cout<<"Choose the data type of the stack : \n1)Integer.\n2)Double.\n3)String.\nEnter your choice : ";
    cin>>cho;
    Stack<int> st(size);
    if(cho==1)
    {
        Stack<int> st(size);
    }
    else if(cho==2)
    {
        Stack<double> st(size);
    }
    else if(cho==3)
    {
        Stack<string> st(size);
    }
    
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
            default:
                cout<<"Enter a valid choice."<<endl;
                break;
        }
    }while(flag);
    cout<<"-----------End of Program----------"<<endl;
}