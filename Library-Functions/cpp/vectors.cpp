#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Vectors
{
    public :
    Vectors()
    {
        vector<T> vec(100);
    }
    void resizeVector(int n)
    {
        vec.resize(n);
        cout<<"Vector has been resized. The new size is :- "<<vec.size()<<endl;
    }
    void detailsVector()
    {
        cout<<"The size of vector is :- "<<vec.size()<<endl;
        cout<<"The capacity of vector is :- "<<vec.capacity()<<endl;
        cout<<"The maximum number of elements that the vector can hold is :- "<<vec.max_size()<<endl;
    }
    void traverseVector()
    {
        vector<T> :: iterator i;
        vector<T> :: reverse_iterator j;

        for(i=vec.begin();i!=vec.end();i++)
        {
            cout<<*i<<"\t";
        }
        cout<<endl;

        //cbegin and cend creates a constant iterator that can only be used to read values and not for modifying the values.
        for(i=vec.cbegin();i!=vec.cend();i++)
        {
            cout<<*i<<"\t";
        }
        cout<<endl;

        for(j=vec.rbegin();j!=vec.rend();j++)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;

        for(j=vec.crbegin();j!=vec.crend();j++)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;
    }
    void elementAccessVector(int n)
    {
        cout<<"The element at the position is :- "<<vec[n]<<" "<<vec.at(n)<<" ";
        vector<T> :: iterator i;
        int j=0;
        for(i=vec.begin();j<n;i++)
        {
            j++;
        }
        cout<<*i;
        cout<<endl;

        T *pos = vec.data();
        cout<<"The first element is :- "<<vec.front()<<" "<<*pos<<endl;
        cout<<"The last element is :- "<<vec.back()<<endl;
    }
    void modifiersVector()
    {
        cout<<"Enter the number of elements to be entered :- ";
        int n,in;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>in;
            vec.push_back(in);
        }
        cout<<"The last element has been removed";
        vec.pop_back();
        
    }
}