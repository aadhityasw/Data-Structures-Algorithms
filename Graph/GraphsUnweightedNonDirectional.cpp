// NonDirectional Unweighted Graph
#include<iostream>
using namespace std;

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
                cout<<(i+1)<<") Enter the name of the nodes in edge : ";
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
                            nodeList[j].insertAdjascentNode(s1);
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
                        nodeList[n].insertAdjascentNode(s1);
                        n++;
                    }
                }
            }
        }

        void getInputByAdjacency()
        {
            int numNodes, numAdj, pos, j;
            cout<<"Enter the total number of nodes in the graph : ";
            cin>>numNodes;
            tempName s1, s2;
            bool flag;
            for(int i=0;i<numNodes;i++)
            {
                cout<<(i+1)<<") Enter the name of the node : ";
                cin>>s1;
                flag = true;
                pos = 0;
                for(j=0;j<n;j++)
                {
                    if(nodeList[j].name == s1)
                    {
                        pos = j;
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    Node<tempName> new_node;
                    new_node.name = s1;
                    nodeList[n] = new_node;
                    pos = n;
                    n++;
                }
                cout<<"Enter the number of adjascent nodes to "<<s1<<" : ";
                cin>>numAdj;
                cout<<"Enter the adjascent nodes one by one : "<<endl;
                for(j=0;j<numAdj;j++)
                {
                    cin>>s2;
                    if(s2!=s1)
                    {
                        nodeList[pos].insertAdjascentNode(s2);
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
    int cho;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Welcome"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Make a choice : "<<endl;;
    cout<<"Enter 1 to insert by edges. \nEnter 2 to insert by adjascency list."<<endl;
    cout<<"Enter your choice : ";
    cin>>cho;
    
    switch(cho)
    {
        case 1 :
            graph.getInputByEdges();
            break;
        case 2 :
            graph.getInputByAdjacency();
            break;
    }

    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
    graph.printGraph();
    cout<<"-------------------------------------------------------------------------------------------------"<<endl;
}