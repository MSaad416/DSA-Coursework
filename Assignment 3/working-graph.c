#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define N 7

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];

    int * visited; // visited nodes;
};

// Data structure to store adjacency list nodes of the graph
struct Node
{
    int dest;
    struct Node* next;
};

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->visited = malloc(N * sizeof(int));


    // initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    // add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // get the source and destination vertex
        int src = edges[i].src;
        int dest = edges[i].dest;

        // allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;

        // point new node to the current head
        newNode->next = graph->head[src];

        // point head pointer to the new node
        graph->head[src] = newNode;

        graph->visited = 0;

    }



    return graph;
}

//
//void DFSUtil(struct Graph *g, int v, int *visited) {
//    visited[v] = 1;
//}
//
//int Mothvex() {
//    int * visited = malloc(N * sizeof(int));
//    for(int i =0; i< N; i++){
//        visited[i] = 0;
//    }
//
//    int v = 0;
//
//    for (int i =0; i < N; i++) {
//        if (visited[i] == 0) {
//            DFSUtil(i, visited);
//            v = i;
//        }
//    }
//
//    // reset values to 0
//    for(int i =0; i< N; i++){
//        visited[i] = 0;
//    }
//    DFSUtil(v, visited);
//    for (int i = 0; i < N; i++) {
//        if (visited[i] == 0) {
//            return -1;
//        }
//    }
//    return v;
//
//}



// Function to print adjacency list representation of a graph
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // print current vertex and all its neighbors
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

// Directed graph implementation in C
int main(void)
{
    // input array containing edges of the graph (as per the above diagram)
    // (x, y) pair in the array represents an edge from x to y
//    struct Edge edges[] =
//            {
//                    {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
//            };
    struct Edge edges[] =
            {
                    {0, 1}, {0,2}, {1,3}, {4,1}, {5,2}, {5,6}, {6,4}, {6,0}
            };




    // calculate the total number of edges
    int n = sizeof(edges)/sizeof(edges[0]);

    // construct a graph from the given edges
    struct Graph *graph = createGraph(edges, n);

    // Function to print adjacency list representation of a graph
    printGraph(graph);

    return 0;
}

to find a mother vertex in the graph. If the mother vertex of the graph does not exist, output -1. If there are multiple mother vertex, output all of them. A mother vertex in a graph G = (V, E) is a vertex v such that all other vertices in G can be reached by a path from v.