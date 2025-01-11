#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFSUtil(int vertex, int* visited, struct Graph* graph) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        if (!visited[temp->vertex])
            DFSUtil(temp->vertex, visited, graph);
        temp = temp->next;
    }
}

void DFS(struct Graph* graph) {
    int* visited = calloc(graph->numVertices, sizeof(int));
    int i;
    
    for (i = 0; i < graph->numVertices; i++)
        if (!visited[i])
            DFSUtil(i, visited, graph);
    free(visited);
}

void BFS(struct Graph* graph, int startVertex) {
    int* visited = calloc(graph->numVertices, sizeof(int));
    int queue[graph->numVertices], front = 0, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currVertex = queue[front++];
        printf("%d ", currVertex);

        struct Node* temp = graph->adjLists[currVertex];
        while (temp) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    
    free(visited);
}

int main() {
    struct Graph* graph = createGraph(5);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    
    printf("DFS: ");
    DFS(graph);
    
    printf("\nBFS: ");
    BFS(graph, 0);

    return 0;
}

