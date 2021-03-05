
// Import Statements.
import java.util.*;

// Node Class to represent each vertex of a graph.
class Node
{
    private String name;
    private HashMap<Node, Integer> adjascMap;

    Node(String name)
    {
        // Initializes the instances of the node class.
        this.name = name;
        adjascMap = new HashMap<Node, Integer>();
    }

    String getName()
    {
        // Returns the name of the node.
        return(this.name);
    }

    HashMap<Node, Integer> getAdjascentMap()
    {
        // Returns a list of all the adjascent vertices to the present vertex.
        return(this.adjascMap);
    }

    void addAdjascentNode(Node nodeB, int w)
    {
        // Adds a vertex as adjascent to this current vertex.
        String othName = nodeB.getName();
        boolean flag = false;
        for(Map.Entry<Node, Integer> itr : this.adjascMap.entrySet())
        {
            if(othName.equals(itr.getKey().getName()))
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            this.adjascMap.put(nodeB, w);
        }
    }
}

// A Graph class that represents a graph or a collection of vertices that are linked with each other in numerous ways.
class Graph
{
    private String name;
    private ArrayList<Node> vertices;

    Graph(String name)
    {
        // Initializes the instance of the graph class.
        this.name = name;
        vertices = new ArrayList<Node>();
    }

    String getName()
    {
        // Returns the name of the graph.
        return(this.name);
    }

    ArrayList<Node> getVertices()
    {
        // Returns all the vertices of the graph.
        return(this.vertices);
    }

    boolean checkVertices(String nameToSearch)
    {
        // It checks if a vertex with the provided name exists in the graph or not.
        Iterator<Node> itr = vertices.iterator();
        String itrName;
        while(itr.hasNext())
        {
            itrName = itr.next().getName();
            if(itrName.equals(nameToSearch))
            {
                return(true);
            }
        }
        return(false);
    }

    Node getNode(String nameToSearch)
    {
        // Returns the node with the provided name if present in the graph.
        Iterator<Node> itr = vertices.iterator();
        String itrName;
        Node curNode;
        while(itr.hasNext())
        {
            curNode = itr.next();
            itrName = curNode.getName();
            if(itrName.equals(nameToSearch))
            {
                return(curNode);
            }
        }
        return(null);
    }

    void getInputByEdges(Scanner sc)
    {
        // It take input in the form of edges for the graph.
        System.out.println("Enter the number of edges : ");
        int numEdges = Integer.parseInt(sc.nextLine());
        if(numEdges > 0)
        {
            System.out.println("Enter 1 if the edges are uni-directional.\nEnter 2 if the edges are bidirectional.");
            System.out.print("Enter your choice :   ");
            int cho = Integer.parseInt(sc.nextLine());
            if(cho == 1 || cho == 2)
            {
                if(cho == 1)
                {
                    System.out.println("The format for entering the edges is : Source-Vertex    Destination-Vertex    Weight");
                }
                else if(cho == 2)
                {
                    System.out.println("The format for entering the edges is : Vertex-1    Vertex-2    Weight");
                }
                System.out.println("Enter the edges one by one : ");
                String str[];
                int weight;
                Node nodeA, nodeB;
                for(int i=0;i<numEdges;i++)
                {
                    str = new String[3];
                    str = sc.nextLine().split(" ");
                    weight = Integer.parseInt(str[2]);
                    if(checkVertices(str[0]) == false)
                    {
                        nodeA = new Node(str[0]);
                        this.vertices.add(nodeA);
                    }
                    else
                    {
                        nodeA = this.getNode(str[0]);
                    }
                    if(checkVertices(str[1]) == false)
                    {
                        nodeB = new Node(str[1]);
                        this.vertices.add(nodeB);
                    }
                    else
                    {
                        nodeB = this.getNode(str[1]);
                    }
                    nodeA.addAdjascentNode(nodeB, weight);
                    if(cho == 2)
                    {
                        // If the edges are stated to be bidirectional.
                        nodeB.addAdjascentNode(nodeA, weight);
                    }
                }
            }
            else
            {
                // Invalid choice is entered for the type of edges.
                System.out.println("Invalid Input.");
                sc.close();
                System.exit(0);
            }
        }
    }

    void getInputByVertices(Scanner sc)
    {
        // To get the input in the form of vertices and their adjascent vertices to form the graph.
        System.out.println("Enter the number of vertices : ");
        int numVertices = Integer.parseInt(sc.nextLine());
        String nameA;
        String str[];
        int numAdj, i, j, w;
        Node nodeA, nodeB;
        for(i=0;i<numVertices;i++)
        {
            System.out.println("Enter the name of the vertex : ");
            nameA = sc.nextLine();
            if(this.checkVertices(nameA) == true)
            {
                nodeA = this.getNode(nameA);
            }
            else
            {
                nodeA = new Node(nameA);
                this.vertices.add(nodeA);
            }
            System.out.println("Enter the number of adjascent vertices : ");
            numAdj = Integer.parseInt(sc.nextLine());
            if(numAdj > 0)
            {
                System.out.println("The format for the input is :   Destination-Vertex    Weight");
                System.out.println("Enter all the edges leading fron the vertex '" + nameA + "' : ");
                for(j=0;j<numAdj;j++)
                {
                    // For each adjascent vertex do the following.
                    str = sc.nextLine().split(" ");
                    w = Integer.parseInt(str[1]);
                    if(checkVertices(str[0]) == false)
                    {
                        nodeB = new Node(str[0]);
                        this.vertices.add(nodeB);
                    }
                    else
                    {
                        nodeB = this.getNode(str[0]);
                    }
                    nodeA.addAdjascentNode(nodeB, w);
                    // For the case of bidirectional edges we have to state it twice one from source to destination and vice versa in this form of representation.
                }
            }
        }
    }
}

// A class to maipulate the above classes and implement the dijkstra algorithm.
public class Dijkstra
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name of the graph : ");
        Graph graph = new Graph(sc.nextLine());
        int cho;
        System.out.println("Enter 1 to make the graph by specfying the details of the edges.\nEnter 2 to make the graph by specfying the details of vertices.");
        System.out.print("Enter your choice :   ");
        cho = Integer.parseInt(sc.nextLine());
        switch(cho)
        {
            case 1 :
                graph.getInputByEdges(sc);
                break;
            case 2 :
                graph.getInputByVertices(sc);
                break;
            default :
                System.out.println("Invalid Input.");
                sc.close();
                System.exit(0);
        }
        if(graph.getVertices().size() > 0)
        {
            // If the graph entered is not an emptyof null graph.
            System.out.println("Enter the name of the source vertex : ");
            String src = sc.nextLine();
            if(graph.checkVertices(src) == true)
            {
                // If the entered source node name is present in the graph.
                HashMap<Node, Integer> distance = new HashMap<Node, Integer>();
                // Distance data structure holds the shortest distance of the node from the source node.
                HashMap<Node, ArrayList<Node>> path = new HashMap<Node, ArrayList<Node>>();
                // Path data structure holds the entire path from the source node till that node for the most optimal path.
                Iterator<Node> itr1 = graph.getVertices().iterator();
                Iterator<Node> itr2;
                final int inf = (int)Double.POSITIVE_INFINITY;
                Node curNode;
                while(itr1.hasNext())
                {
                    // To perform default initialization for the path and distance data structures.
                    curNode = itr1.next();
                    distance.put(curNode, inf);
                    path.put(curNode, new ArrayList<Node>());
                }
                ArrayList<Node> notVisited = new ArrayList<Node>(graph.getVertices());
                // notVisited holds a list of all the vertices that have not yet been visited.
                Node nodeVisit = graph.getNode(src);
                int curDist = 0, w = 0, minDist;
                distance.put(nodeVisit, curDist);
                // To finish visiting the source node.
                ArrayList<Node> curPath;
                while(notVisited.size() > 0)
                {
                    // Until we have not yet visited all the nodes.
                    notVisited.remove(nodeVisit);
                    curDist = distance.get(nodeVisit);
                    for(Map.Entry<Node, Integer> entry : nodeVisit.getAdjascentMap().entrySet())
                    {
                        // To check every node that is adjscent to the currently visiting node.
                        w = entry.getValue();
                        curNode = entry.getKey();
                        if(distance.get(curNode) > (w + curDist) && notVisited.contains(curNode))
                        {
                            // If there is a shorter path to reach here from the source node.
                            distance.put(curNode, w+curDist);
                            path.remove(curNode);
                            curPath = new ArrayList<Node>(path.get(nodeVisit));
                            curPath.add(nodeVisit);
                            path.put(curNode, curPath);
                            // Modify the path and the distance data structures based on the shorter path found.
                        }
                    }
                    curPath = new ArrayList<Node>(path.get(nodeVisit));
                    curPath.add(nodeVisit);
                    path.put(nodeVisit, curPath);
                    // Adds the currently visiting node to its path thereby completing its path.
                    minDist = inf;
                    nodeVisit = null;
                    for(Map.Entry<Node, Integer> entry : distance.entrySet())
                    {
                        if(entry.getValue() < minDist && notVisited.contains(entry.getKey()))
                        {
                            // To find a node that has not yet been visited and has minimum weight.
                            minDist = entry.getValue();
                            nodeVisit = entry.getKey();
                        }
                    }
                    // It finds the node that dhould be visited next based on the weights.
                }
                // To print the results of the algorithm to the console.
                System.out.println("The vertices of the graph '" + graph.getName() + "'  and their shortest distances from the source vertex '" + src + "' are : ");
                itr1 = graph.getVertices().iterator();
                while(itr1.hasNext())
                {
                    // Prints the details of every node, namely its shortest distance and the path followed from the source node.
                    curNode = itr1.next();
                    System.out.println("Node : " + curNode.getName());
                    System.out.println("Distance from source : " + distance.get(curNode));
                    curPath = new ArrayList<Node>(path.get(curNode));
                    if(curPath.size() == 0 || distance.get(curNode) == inf)
                    {
                        System.out.println("The node is not reachable from the source.");
                        // If the node cannot be reached from the entered source.
                    }
                    else
                    {
                        // If the current node can be reached from the source and we have found an optimal path.
                        System.out.print("Path from source :    ");
                        itr2 = curPath.iterator();
                        while(itr2.hasNext())
                        {
                            System.out.print(itr2.next().getName());
                            if(itr2.hasNext())
                            {
                                System.out.print(" -> ");
                            }
                        }
                        System.out.println();
                        // Prints the optimal path of the current node from the source node.
                    }
                    System.out.println("---------------------------------------------------------------------------------");
                }
            }
            else
            {
                // If the entered name for the source node is invalid or dosent exist in the entered graph.
                System.out.println("Invalid Source Vertex.");
                sc.close();
                System.exit(0);
            }
        }
        else
        {
            // If the entered graph has no vertices.
            System.out.println("The entered graph is a null graph.");
        }
        System.out.println("End of Program.");
        System.out.println("---------------------------------------------------------------------------------");
        // Closing the scanner class object.
        sc.close();
        // Program has ended.
    }
}