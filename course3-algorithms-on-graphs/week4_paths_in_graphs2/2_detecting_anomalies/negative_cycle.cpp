#include <iostream>
#include <vector>
#include <climits>
#include <set>
using std::vector;
using std::set;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int n = adj.size();
  int res = 0;
  int s = 0;
  set<int> visited;
  for (int s = 0; s < n; ++s) {
    vector<int> dist(n, 10^9);
    vector<int> prev(n, -1);  
    if (visited.find(s) != visited.end()) {
      continue;
    }
    dist[s] = 0;
    int count = n;

    while (count > 0) {
      count--;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
          if (dist[i] + cost[i][j] < dist[adj[i][j]]) {
            dist[adj[i][j]] = dist[i] + cost[i][j];
            prev[adj[i][j]] = i;
            visited.insert(adj[i][j]);
            if (count == 1) {
              res = 1;
              break;
            }
          }
        }
      }
    }
    if (res == 1) {
      break;
    }
}
  return res;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
