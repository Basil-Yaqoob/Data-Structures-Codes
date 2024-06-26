#include <iostream>
#include <string>

using namespace std;
class Qnode
{
public:
    int data;
    int distance;

    Qnode(int d, int dis)
    {
        data = d;
        distance = dis;
    }

    Qnode()
    {
        data = 0;
        distance = 0;
    }
};

class PriorityQ
{
public:
    Qnode *arr;
    int size;
    int current_size;

    PriorityQ(int s)
    {
        size = s;
        arr = new Qnode[size];
        current_size = 0;
    }

    void Insert(int value, int dis)
    {

        arr[current_size].data = value;
        arr[current_size].distance = dis;
        MinHeapify(current_size);
        current_size++;
    }

    void MinHeapify(int child)
    {
        if (child <= 0)
            return;

        int parent = (child - 1) / 2;
        if (arr[child].distance < arr[parent].distance)
        {
            swap(arr[child], arr[parent]);
            MinHeapify(parent);
        }
        else
        {
            return;
        }
    }

    void Dequeue()
    {

        arr[0] = arr[current_size - 1];
        current_size--;
        int i = 0;
        while (i <= current_size)
        {
            int leftchild = 2 * i + 1;
            int rightchild = 2 * i + 2;
            int smallest = i;

            if (leftchild <= current_size && arr[leftchild].distance < arr[i].distance)
                smallest = leftchild;
            if (rightchild <= current_size && arr[rightchild].distance < arr[i].distance)
                smallest = rightchild;

            if (i != smallest)
            {

                swap(arr[i], arr[smallest]);
                i = smallest;
            }
            else
            {
                return;
            }
        }
    }
    int Front()
    {
        return arr[0].data;
    }

    bool isEmpty()
    {
        if (current_size == 0)
            return true;
        else
            return false;
    }

    void display()
    {
        for (int i = 0; i < current_size; i++)
        {
            cout << arr[i].data << "," << arr[i].distance << "  ";
        }
    }
};

class node
{
public:
    int data;
    int weight;
    node *next;

    node()
    {
        data = 0;
        weight = 0;
        next = NULL;
    }

    node(int d, int w)
    {
        data = d;
        weight = w;
        next = 0;
    }
};

class Graph
{
public:
    int vertices;
    node **adjList;

    Graph(int v)
    {
        vertices = v;
        adjList = new node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = NULL;
        }
    }

    void AddEdge(int a, int b, int w, bool directed)
    {

        node *newnode = new node(b, w);
        if (adjList[a] == 0)
            adjList[a] = newnode;
        else
        {
            newnode->next = adjList[a];
            adjList[a] = newnode;
        }

        if (!directed)
        {
            node *newnode2 = new node(a, w);
            if (adjList[b] == 0)
                adjList[b] = newnode2;
            else
            {
                newnode2->next = adjList[b];
                adjList[b] = newnode2;
            }
        }
    }

    void Display()
    {

        for (int i = 0; i < vertices; i++)
        {
            cout << "link[" << i << "] ---> ";
            node *temp = adjList[i];

            do
            {
                if (temp == 0)
                {
                    cout << "NULL";
                    break;
                }
                else
                {

                    cout << "(" << temp->data << "," << temp->weight << ") --->";
                }
                temp = temp->next;
            } while (temp != 0);

            cout << endl;
        }
    }

    void DijkstraAlgoShortestPath(int s_vertex)
    {

        int *distance = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            distance[i] = 100000;
        }

        bool *visited = new bool[vertices]{false};
        PriorityQ pq(vertices);
        pq.Insert(s_vertex, 0);
        distance[s_vertex] = 0;
        // visited[s_vertex] = true;

        while (!pq.isEmpty())
        {

            int curr = pq.Front(); // front return data part
            // cout << "\ncurr: " << curr << endl;
            pq.Dequeue();
            visited[curr] = true;
            node *temp = adjList[curr];

            while (temp != 0)
            {
                // cout << temp->data << " " << visited[temp->data] << endl;

                if (!visited[temp->data] && distance[curr] + temp->weight < distance[temp->data])
                {
                    // cout << "here;";
                    distance[temp->data] = distance[curr] + temp->weight;
                    pq.Insert(temp->data, distance[temp->data]);
                }

                temp = temp->next;
            }
        }

        for (int i = 0; i < vertices; i++)
        {
            cout << distance[i] << " ";
        }
    }
};

int main()
{
    int v, to = 0, src, w;
    cout << "Enter no of vertices: ";
    cin >> v;
    Graph g(v);

    /*  0 1 4
        1 3 3
        2 3 4
        2 0 5
        4 0 3
        4 1 2
        4 2 1
        4 3 1


        1 2 2
        1 3 4
        2 4 7
        2 3 1
        4 6 1
        6 5 5
        4 5 2
        5 3 3

*/
    while (to != -1)
    {
        cout << "Enter src :";
        cin >> src;
        cout << "Enter To: ";
        cin >> to;
        cout << "Enter Weights: ";
        cin >> w;
        g.AddEdge(src, to, w, false);
        cout << endl;
    }

    g.Display();
    cout << endl;
    g.DijkstraAlgoShortestPath(1);
}
