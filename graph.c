#include <stdio.h>

#define V 6

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

/* Adjacency Matrix */
int graph[V][V] = {
    {0, 1, 1, 0, 0, 0},  // A
    {1, 0, 0, 1, 1, 0},  // B
    {1, 0, 0, 0, 0, 1},  // C
    {0, 1, 0, 0, 0, 0},  // D
    {0, 1, 0, 0, 0, 1},  // E
    {0, 0, 1, 0, 1, 0}   // F
};

/* Adjacency List */
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

Node *adjList[V];

/* Create a new node */
Node* createNode(int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

/* Add edge */
void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

/* Display adjacency matrix */
void displayMatrix() {
    printf("\nAdjacency Matrix:\n\n");

    printf("  ");
    for (int i = 0; i < V; i++)
        printf("%c ", vertices[i]);

    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%c ", vertices[i]);

        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);

        printf("\n");
    }
}

/* Display adjacency list */
void displayList() {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < V; i++) {
        printf("%c -> ", vertices[i]);

        Node *temp = adjList[i];

        while (temp != NULL) {
            printf("%c -> ", vertices[temp->vertex]);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

/* BFS using adjacency matrix */
void BFS(int start) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS starting from A: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%c ", vertices[current]);

        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

/* DFS */
void DFSUtil(int vertex, int visited[]) {
    visited[vertex] = 1;

    printf("%c ", vertices[vertex]);

    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && visited[i] == 0) {
            DFSUtil(i, visited);
        }
    }
}

void DFS(int start) {
    int visited[V] = {0};

    printf("\nDFS starting from A: ");
    DFSUtil(start, visited);
    printf("\n");
}

/* Search using adjacency matrix */
void searchMatrix(char target) {
    int operations = 0;

    printf("\nSearching %c using Adjacency Matrix:\n", target);

    for (int i = 0; i < V; i++) {
        operations++;

        if (vertices[i] == target) {
            printf("Vertex %c found.\n", target);
            printf("Operations required = %d\n", operations);
            return;
        }
    }

    printf("Vertex not found.\n");
}

/* Search using adjacency list */
void searchList(char target) {
    int operations = 0;

    printf("\nSearching %c using Adjacency List:\n", target);

    for (int i = 0; i < V; i++) {
        operations++;

        if (vertices[i] == target) {
            printf("Vertex %c found.\n", target);
            printf("Operations required = %d\n", operations);
            return;
        }
    }

    printf("Vertex not found.\n");
}

int main() {

    /* Create adjacency list */
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;

    addEdge(0, 1); // A-B
    addEdge(0, 2); // A-C
    addEdge(1, 3); // B-D
    addEdge(1, 4); // B-E
    addEdge(2, 5); // C-F
    addEdge(4, 5); // E-F

    /* Part A */
    displayMatrix();
    displayList();

    BFS(0);
    DFS(0);

    /* Part B */
    searchMatrix('F');
    searchList('F');

    return 0;
}
