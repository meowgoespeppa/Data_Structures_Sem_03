/*

  LAB PROGRAM 9a

  Write a program to traverse a graph using BFS method

*/

#include <stdio.h>

void bfs(int n, int a[20][20], int src) {
  int visited[20] = {0};
  int q[20];
  int f = 0, r = 0;
  int u, v;

  q[r] = src;
  visited[src] = 1;

  printf("BFS Traversal: ");

  while (f <= r) {
    u = q[f++];
    printf("%d ", u);

    for (v = 0; v < n; v++) {
      if (a[u][v] == 1 && visited[v] == 0) {
        visited[v] = 1;
        q[++r] = v;
      }
    }
  }
}

int main() {
  int n, a[20][20], src;

  printf("Enter number of nodes: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter source vertex: ");
  scanf("%d", &src);

  bfs(n, a, src);

  return 0;
}

/*

  OUTPUT

  Enter number of nodes: 4
  Enter adjacency matrix:
  0 1 1 0
  1 0 0 1
  1 0 0 1
  0 1 1 0
  Enter source vertex: 0
  BFS Traversal: 0 1 2 3

*/
