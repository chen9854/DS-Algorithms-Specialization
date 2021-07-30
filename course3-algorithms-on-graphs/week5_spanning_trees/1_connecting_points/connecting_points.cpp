#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
using std::vector;
using std::priority_queue;
using std::pair;

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  const int n = x.size();
  vector<bool> mstSet(n, false);
  priority_queue<pair<double, int>, vector<pair<double, int>>, std::greater<pair<double, int>>> pq;
  vector<double> cost(n, 10000);
  
  cost[0] = 0;

  for (int i = 0; i < n; ++i) {
    pq.push({cost[i], i});
  }
  for (int count = 0; count < n - 1; ++count) {
    int v = pq.top().second;
    while (mstSet[v]) {
      pq.pop();
      v = pq.top().second;
    }
    mstSet[v] = true;
    for (int z = 0; z < n; ++z) {
      if (!mstSet[z]) {
        double dist = std::sqrt((x[z] - x[v]) * (x[z] - x[v]) + (y[z] - y[v]) * (y[z] - y[v]));
        if (cost[z] > dist) {
          cost[z] = dist;
          pq.push({dist, z});
        }
      }
    }
    
  }
  for (int i = 0; i < n; ++i) {
    result += cost[i];
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
