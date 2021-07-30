#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::pair;
using std::stack;

void dfs(vector<vector<int>> &adj, vector<bool>& visited, stack<int>& st, bool & res) {
  int top = st.top();
  int m = adj[top].size();
  for (int i = 0; i < m; ++i) {
    if (visited[adj[top][i]]) {
      // std::cout<< adj[top][i] << std::endl;
      res = true;
      return;
    } else {
      st.push(adj[top][i]);
      visited[adj[top][i]] = true;
      dfs(adj, visited, st, res); 
    }
  }
  visited[st.top()] = false;
  st.pop();
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here 
  bool res = false;
  int n = adj.size();
  
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      stack<int> st;
      st.push(i);
      visited[i] = true;
      dfs(adj, visited, st, res);
      if (res) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
