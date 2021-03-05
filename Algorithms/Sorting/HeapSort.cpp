#include<iostream>
using namespace std;

template <class temp>
class BinaryMinHeap
{
    public :
        temp *arr;
        int size;

        BinaryMinHeap()
        {
            arr = new temp[100];
            size = 0;
        }

        int leftNode(int i)
        {
            if(2*i < size)
            {
                return(2*i);
            }
            else
            {
                return(-1);
            }
        }

        int rightNode(int i)
        {
            if(2*i+1 < size)
            {
                return(2*i+1);
            }
            else
            {
                return(-1);
            }
        }

        int parentNode(int i)
        {
            if(i/2 > 0)
            {
                return((int)(i/2));
            }
            else
            {
                return(-1);
            }
        }

        void min_Heapify(int i)
        {
            int l, r, smallest;
            l = leftNode(i);
            r = rightNode(i);
            
            smallest = i;
            if(l>=0 && l<size && arr[l]<arr[i])
            {
                smallest = l;
            }
            if(r>=0 && r<size && arr[r]<arr[smallest])
            {
                smallest = r;
            }
            if(smallest != i)
            {
                temp t;
                t = arr[i];
                arr[i] = arr[smallest];
                arr[smallest] = t;
                min_Heapify(smallest);
            }
        }

        void build_Min_Heap()
        {
            // Bottom up Approach or Re-hepification upward.
            int i, n;
            n = (int)(size/2);
            for(i=n;i>=0;i--)
            {
                min_Heapify(i);
            }
        }

        temp deleteMinNode()
        {
            // Top Down Approach or Re-hepification downward.
            temp no = arr[0];
            arr[0] = arr[size-1];
            arr[size-1] = 0;
            size--;
            min_Heapify(0);
            return(no);
        }
};

int main()
{
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\tWelcome\n";
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    typedef int temp;       // Change your datatype here.
    BinaryMinHeap<temp> heap;
    int cho=0;
    temp no;
    
    int leng;
    cout<<"Enter the number of elements to be sorted : ";
    cin>>leng;

    cout<<"Enter the elements to be sorted :"<<endl;
    for(int i=0;i<leng;i++)
    {
        cin>>no;
        heap.arr[heap.size] = no;
        heap.size++;
        heap.build_Min_Heap();
    }

    temp arr2[leng];
    int i=0;
    while(heap.size>0)
    {
        arr2[i] = heap.deleteMinNode();
        i++;
    }

    cout<<"The sorted order is :- ";
    for(i=0;i<leng;i++)
    {
        cout<<arr2[i]<<'\t';
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
}