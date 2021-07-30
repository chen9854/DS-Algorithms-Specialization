#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > &adj, vector<bool> &visited, int v) {
  visited[v] = true;
  for (int j = 0; j < adj[v].size(); ++j) {
    if (!visited[adj[v][j]]) {
      explore(adj, visited, adj[v][j]);
    }
  }
}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  const int n = adj.size();
  vector<bool> visited = vector<bool>(n, false);
  explore(adj, visited, x);

  return visited[y];
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
