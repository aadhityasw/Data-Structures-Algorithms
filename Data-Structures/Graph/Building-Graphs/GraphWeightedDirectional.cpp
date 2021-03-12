// Directional Weighted Graph
#include<iostream>
using namespace std;

template<class tempName>
class Node
{
    public :
        tempName name;
        tempName *adj;
        int *weights;
        int n;
        Node()
        {
            adj = new tempName[20];
            weights = new int[20];
            n=0;
        }

        void insertAdjascentNode(tempName ins_node, int ins_weight)
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
                weights[n] = ins_weight;
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
            int numEdges, weight;
            cout<<"Enter the number of edges in the graph : ";
            cin>>numEdges;
            tempName s1;
            tempName s2;
            bool f1, f2;
            for(int i=0;i<numEdges;i++)
            {
                cout<<(i+1)<<") Enter the name of the source, destination nodes in edge and its weight : ";
                cin>>s1>>s2>>weight;
                f1 = false;
                f2 = false;
                if(s1!=s2)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(!(f1) && nodeList[j].name==s1)
                        {
                            nodeList[j].insertAdjascentNode(s2, weight);
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
                        nodeList[n].insertAdjascentNode(s2, weight);
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
                        cout<<"("<<nodeList[i].adj[j]<<", "<<nodeList[i].weights[j]<<"), ";
                    }
                    else
                    {
                        cout<<"("<<nodeList[i].adj[j]<<", "<<nodeList[i].weights[j]<<")";
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
}