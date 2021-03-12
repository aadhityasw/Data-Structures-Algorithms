#include<iostream>
using namespace std;

template<class temp>
class Queue
{
    public :
        int size, front, rear;
        temp *arr;
        Queue(int s)
        {
            size = s;
            front = 0;
            rear = -1;
            arr = new temp[size];
        }
        void enqueue()
        {
            temp ele;
            cout<<"Enter the element to be entered : ";
            cin>>ele;
            if(rear == size-1)
            {
                cout<<"Overflow"<<endl;
            }
            else
            {
                arr[++rear] = ele;
            }
        }
        void dequeue()
        {
            if(rear == -1 || front == rear+1)
            {
                cout<<"Underfow"<<endl;
            }
            else
            {
                temp ele;
                ele = arr[front++];
                cout<<"The removed element is : "<<ele<<endl;
            }
        }
        void traverse()
        {
            cout<<"The traversal of the queue is : ";
            int i;
            for(i=front;i<=rear;i++)
            {
                cout<<arr[i]<<'\t';
            }
            cout<<endl;
        }
};

int main()
{
    cout<<"-----------Welcome to Queues----------"<<endl;
    bool flag = true;
    int size, cho;
    cout<<"Enter the size of the queue : ";
    cin>>size;
    Queue<int> queue(size);
    
    do
    {
        cout<<"Options avalible are : \n1)Push an element into queue.\n2)Pop an element from a queue.\n3)Print all the elements in the queue.\n4)Exit."<<endl;
        cout<<"Enter your choice : ";
        cin>>cho;
        switch (cho)
        {
            case 1 :
                queue.enqueue();
                break;
            case 2 :
                queue.dequeue();
                break;
            case 3 :
                queue.traverse();
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