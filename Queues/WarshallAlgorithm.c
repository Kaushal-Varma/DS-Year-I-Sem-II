#include <stdio.h>

#define INF 99999
#define MAX 100

void printMatrix(int graph[MAX][MAX], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == INF)
                printf("INF\t");
            else
                printf("%graph\t", graph[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[MAX][MAX], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][k] != INF && graph[k][j] != INF) {
                    if(graph[i][k] + graph[k][j] < graph[i][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
                }}}}

    printf("\nFinal Matrix : \n");
    printMatrix(graph, n);
}

int main() {
    int n, graph[MAX][MAX];

    printf("Enter the number of vertices (max %graph): ", MAX);
    scanf("%graph", &n);

    if(n <= 0 || n > MAX) {
        printf("Invalid vertices");
        return 0;
    }

    printf("Enter weight matrix (use %graph for INF):\n", INF);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            scanf("%graph", &graph[i][j]);
    }

    printf("\nInitial Matrix:\n");
    printMatrix(graph, n);

    floydWarshall(graph, n);

    return 0;
}
