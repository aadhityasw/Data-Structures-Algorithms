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
            if(r>=0 && r<size && arr[r]<arr[i])
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

        void insertNode(temp data)
        {
            arr[size] = data;
            size++;
            build_Min_Heap();
        }

        int searchNode(temp data)
        {
            int i;
            for(i=0;i<size;i++)
            {
                if(data==arr[i])
                {
                    return(i);
                }
            }
            return(-1);
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

        temp minNode()
        {
            return(arr[0]);
        }

        void printHeap()
        {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<"\t";
            }
        }
};

void printOptions()
{
    cout<<"The avalible options are : "<<endl;
    cout<<"1) Insert a node into the heap."<<endl;
    cout<<"2) Delete the min node from the heap."<<endl;
    cout<<"3) Search for an element in the heap."<<endl;
    cout<<"4) View the min node from the heap."<<endl;
    cout<<"5) Print the heap's array."<<endl;
    cout<<"6) Exit"<<endl;
}

int main()
{
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t\tWelcome\n";
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    typedef int temp;       // Change your datatype here.
    BinaryMinHeap<temp> heap;
    int cho=0;
    temp no;
    do
    {
        printOptions();
        cout<<"Enter your option : ";
        cin>>cho;
        switch(cho)
        {
            case 1 :
                cout<<"Enter the element to be inserted : ";
                cin>>no;
                heap.insertNode(no);
                break;
            case 2 :
                if(heap.size>0)
                {
                    no = heap.deleteMinNode();
                    cout<<"The top of the node is : "<<no<<" and it has been removed from the heap."<<endl;
                }
                else
                {
                    cout<<"The Heap is empty."<<endl;
                }
                break;
            case 3 :
                cout<<"Enter the element to be searched : ";
                cin>>no;
                int res;
                res = heap.searchNode(no);
                if(res>=0)
                {
                    cout<<"The element is present in the index "<<res<<" in the heap's array."<<endl;
                }
                else
                {
                    cout<<"The element is not present in the heap."<<endl;
                }
                break;
            case 4 :
                no = heap.minNode();
                cout<<"The node with the minimum value in the heap is : "<<no<<endl;
                break;
            case 5 :
                cout<<"The elements of the heap are : ";
                heap.printHeap();
                cout<<endl;
                break;
            case 6 :
                cout<<"End of program."<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
        }
        cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    }while(cho!=6);
}