#include<iostream>
using namespace std;

template<class temp>
class BubbleSort
{
    public :
        temp *arr;
        int n;

        BubbleSort(int size)
        {
            arr = new temp[size];
            n = size;
        }

        void bubbleSort()
        {
            int i, j;
            temp t;
            for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-i-1;j++)
                {
                    if(arr[j]>arr[j+1])
                    {
                        t = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = t;
                    }
                }
            }
        }

        void printArray()
        {
            cout<<"The array is : ";
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
};

int main()
{
    int n, i;
    cout<<"Enter the number of elements to be entered : ";
    cin>>n;

    BubbleSort<int> ob(n);

    cout<<"Enter the elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ob.arr[i];
    }

    ob.bubbleSort();
    ob.printArray();
}