#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int cho, ele;
    stack<int> st;
    bool flag = true;
    do
    {
        cout<<"Options avalible are : \n1)Push an element into stack.\n2)Pop an element from a stack.\n3)Exit."<<endl;
        cout<<"Enter your choice : ";
        cin>>cho;
        switch (cho)
        {
            case 1 :
                cout<<"Enter the element to be inserted : ";
                cin>>ele;
                st.push(ele);
                break;
            case 2 :
                st.pop();
                cout<<"The element has been deleted from the stack : "<<endl;
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