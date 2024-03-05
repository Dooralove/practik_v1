#include <stdio.h>
#define INF 99999
#define V 5

// Function to print the solution matrix
void printSolution(int dist[][V]);

// Implementation of the Floyd-Warshall algorithm
void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    // Initialize the distance matrix with the input graph
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update the shortest distances using all vertices as intermediate nodes
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the final solution matrix
    printSolution(dist);
}

// Function to print the solution matrix
void printSolution(int dist[][V])
{
    printf("Following matrix shows the shortest distances"
           " between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {
        {0, 1, 4, INF, INF},
        {INF, 0, 2, 4, INF},
        {INF, INF, 0, INF, 3},
        {INF, INF, INF, 0, INF},
        {INF, INF, INF, 2, 0}
    };

    // Call the Floyd-Warshall algorithm
    floydWarshall(graph);
    return 0;
}
////qq/////q//