#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::set;

long long distance(vector<vector<int> > &adj, vector<vector<long long> > &cost, int s, int t) {
  //write your code here
  int n = adj.size();
  vector<long long> dist(n, LLONG_MAX);
  vector<long long> prev(n, -1);
  set<int> known;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<pair<long long, int>>> pq;  

  dist[s] = 0;
  known.insert(s);
  for (int i = 0; i < adj.size(); ++i) {
    pq.push({dist[i], i});    
  }

  int last = s;
  while (last != t && !pq.empty()) {
    int v_next = pq.top().second;
    // while (known.find(v_next) != known.end()  && !pq.empty()) {
      // v_next = pq.top().second;
    pq.pop();

      for (int i = 0; i < adj[v_next].size(); ++i) {
        if (dist[v_next] + cost[v_next][i] < dist[adj[v_next][i]]) {
          dist[adj[v_next][i]] = dist[v_next] + cost[v_next][i];
          prev[adj[v_next][i]] = v_next;
          pq.push({dist[adj[v_next][i]], adj[v_next][i]});
        }
      }
  

    last = v_next;
    known.insert(v_next);
  }

  return dist[t] == LLONG_MAX ? -1 : dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<long long> > cost(n, vector<long long>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
