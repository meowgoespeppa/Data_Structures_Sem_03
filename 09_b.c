/*

  LAB PROGRAM 9b

  Write a program to check whether given graph is
  connected or not using DFS method

*/

#include <stdio.h>

void dfs(int n, int a[20][20], int u, int visited[]) {
  visited[u] = 1;

  for (int v = 0; v < n; v++) {
    if (a[u][v] == 1 && visited[v] == 0) {
      dfs(n, a, v, visited);
    }
  }
}

int main() {
  int n, a[20][20], visited[20] = {0};

  printf("Enter number of nodes: ");
  scanf("%d", &n);

  printf("Enter adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  /* Start DFS from vertex 0 */
  dfs(n, a, 0, visited);

  /* Check connectivity */
  for (int i = 0; i < n; i++) {
    if (visited[i] == 0) {
      printf("Graph is not connected\n");
      return 0;
    }
  }

  printf("Graph is connected\n");
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
  Graph is connected

*/
