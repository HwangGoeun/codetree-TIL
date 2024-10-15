#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES   1000
#define MAX_EDGES   10000

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int n, m;
int count = 0;

void dfs(int v, int n) {
    visited[v] = 1;

    for(int j = 0; j < n; j++) {
        if(graph[v][j] == 1 && visited[j] == 0) {
            count += 1;
            dfs(j, n);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    int x, y;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }

    dfs(0, n);
    printf("%d", count);

    return 0;
}