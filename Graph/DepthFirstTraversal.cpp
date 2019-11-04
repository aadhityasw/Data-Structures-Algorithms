// Depth First Traversal of a Directional Unweighted Graph
#include<iostream>
using namespace std;

template<class temp>
class Stack
{
    public :
        int size, top;
        temp *arr;
        Stack()
        {
            size = 50;
            top = -1;
            arr = new temp[size];
        }

        void push(temp ele)
        {
            arr[++top] = ele;
        }

        temp pop()
        {
            temp ele;
            ele = arr[top--];
            return(ele);
        }
        
        bool isEmpty()
        {
            if(top==-1)
            {
                return(true);
            }
            return(false);
        }
};


template<class tempName>
class Node
{
    public :
        tempName name;
        tempName *adj;
        int n;
        Node()
        {
            adj = new tempName[20];
            n=0;
        }

        void insertAdjascentNode(tempName ins_node)
        {
            bool flag = true;
            for(int i=0;i<n;i++)
            {
                if(adj[i] == ins_node)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                adj[n] = ins_node;
                n++;
            }
        }
};


template<class tempName>
class Graph
{
    public :
        tempName name;
        Node<tempName> *nodeList;
        int n;
        Graph()
        {
            nodeList = new Node<tempName>[20];
            n=0;
        }

        void getInputByEdges()
        {
            int numEdges;
            cout<<"Enter the number of edges in the graph : ";
            cin>>numEdges;
            tempName s1;
            tempName s2;
            bool f1, f2;
            for(int i=0;i<numEdges;i++)
            {
                cout<<(i+1)<<") Enter the name of the source and destination nodes in edge : ";
                cin>>s1>>s2;
                f1 = false;
                f2 = false;
                if(s1!=s2)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(!(f1) && nodeList[j].name==s1)
                        {
                            nodeList[j].insertAdjascentNode(s2);
                            f1 = true;
                        }
                        if(!(f2) && nodeList[j].name==s2)
                        {
                            f2 = true;
                        }
                    }
                    if(f1 == false)
                    {
                        Node<tempName> new_node;
                        new_node.name = s1;
                        nodeList[n] = new_node;
                        nodeList[n].insertAdjascentNode(s2);
                        n++;
                    }
                    if(f2 == false)
                    {
                        Node<tempName> new_node;
                        new_node.name = s2;
                        nodeList[n] = new_node;
                        n++;
                    }
                }
            }
        }

        void printGraph()
        {
            cout<<"Graph : "<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<nodeList[i].name<<" : ";
                for(int j=0;j<nodeList[i].n;j++)
                {
                    if(j < nodeList[i].n-1)
                    {
                        cout<<nodeList[i].adj[j]<<", ";
                    }
                    else
                    {
                        cout<<nodeList[i].adj[j];
                    }
                }
                cout<<endl;
            }
        }
};

int main()
{
    typedef int tempName;
    Graph<tempName> graph;

    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Welcome"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    
    graph.getInputByEdges();

    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    graph.printGraph();
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;

    tempName src;
    cout<<"Enter the source node : ";
    cin>>src;

    Stack<tempName> stack;
    stack.push(src);
    tempName ele;

    tempName* visited = new tempName[20];
    int i, j, n = 0, pos;
    bool flag1, flag2;

    cout<<"The Depth First Traversal of the graph from "<<src<<" is : ";
    while(!stack.isEmpty())
    {
        ele = stack.pop();
        flag1 = true;
        for(i=0;i<n;i++)
        {
            if(visited[i] == ele)
            {
                flag1 = false;
                break;
            }
        }
        if(flag1 == true)
        {
            cout<<ele<<"    ";
            pos = 0;
            visited[n] = ele;
            n++;
            for(i=0;i<graph.n;i++)
            {
                if(graph.nodeList[i].name == ele)
                {
                    pos = i;
                    break;
                }
            }
            for(i=0;i<graph.nodeList[pos].n;i++)
            {
                flag2 = true;
                for(j=0;j<n;j++)
                {
                    if(visited[j] == graph.nodeList[pos].adj[i])
                    {
                        flag2 = false;
                        break;
                    }
                }
                if(flag2 == true)
                {
                    stack.push(graph.nodeList[pos].adj[i]);
                }
            }
        }
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
}