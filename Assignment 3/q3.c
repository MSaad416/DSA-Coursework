// q3.c - Assignment 03 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>

// upper bound limit for vertices
#define MAX_VERTICES 100

// defining directed graph structure
typedef struct Graph
{
    // adjacency list
    struct Node* adjList[MAX_VERTICES];

    // boolean array to track visited vertices
    int visited[MAX_VERTICES];

    // number of vertices
    int numVertices;
} Graph;

// defining node in adjacency list
typedef struct Node
{
    int vertex;
    // pointer to next node
    struct Node* next;
} Node;


// creating nodes in adjacency list
Node* createNode(int v)
{
    // allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // initializing values
    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

// function to create a graph
Graph* createGraph(int numVertices)
{
    // allocate memory for graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    // set number of vertices
    graph->numVertices = numVertices;

    // initialize vertices as not visited
    for (int i = 0; i < numVertices; i++)
        graph->visited[i] = 0;

    // initialize entire adjacency lists as empty
    for (int i = 0; i < numVertices; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// adds edge to graph
void addEdge(Graph* graph, int src, int dest)
{

    // create a new node
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// function for a DFS traversal
// helper function to Mothvex()
void DFS(Graph* graph, int vertex)
{
    // set node as visited
    graph->visited[vertex] = 1;

    // recursively visit all visitable vertices
    Node* temp = graph->adjList[vertex];
    while (temp != NULL)
    {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0)
            DFS(graph, adjVertex);
        temp = temp->next;
    }
}

// function to find a mother vertex in the graph
void Mothvex(Graph* graph)
{
    // last recent vertex
    int recentVertex;

    // DFS traversal on vertices
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->visited[i] == 0)
        {
            DFS(graph, i);
            recentVertex = i;
        }
    }

    // initialize all vertices as not visited
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;

    // DFS traversal to all reachable vertices
    DFS(graph, recentVertex);

    // check if all vertices are visited
    int motherVertex = recentVertex;
    for (int i = 0; i < graph->numVertices; i++)
    {
        // mother vertex does not exist
        if (graph->visited[i] == 0) {
            motherVertex = -1;
            break;
        }

    }

    // printing the mother vertex
    if (motherVertex != -1)
        printf("Mother vertex: %d\n", motherVertex);
    else
        printf("Mother vertex does not exist\n");
}


int main()
{
    // initializing graph with 7 vertices
    Graph* graph = createGraph(7);

    // adding edges to the graph
    // creating the example graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 4);
    addEdge(graph, 6, 0);

    // function to find mother vertex in the graph
    Mothvex(graph);

    return 0;
}
