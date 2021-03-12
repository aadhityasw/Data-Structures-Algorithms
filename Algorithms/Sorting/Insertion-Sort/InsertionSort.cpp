#include<iostream>
using namespace std;

template<class temp>
class InsertionSort
{
    public :
        temp *arr;
        int n;

        InsertionSort(int size)
        {
            arr = new temp[size];
            n = size;
        }

        void insertionSort()
        {
            int i, j, k;
            temp t;
            for(i=1;i<n;i++)
            {
                for(j=0;j<i;j++)
                {
                    if(arr[j]>arr[i])
                    {
                        break;
                    }
                }
                t = arr[i];
                for(k=i;k>j;k--)
                {
                    arr[k] = arr[k-1];
                }
                arr[j] = t;
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

    InsertionSort<int> ob(n);

    cout<<"Enter the elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ob.arr[i];
    }

    ob.insertionSort();
    ob.printArray();
}