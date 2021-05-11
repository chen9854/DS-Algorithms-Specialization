#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int value[10001][31];
  int n = w.size();
  for(int j = 0; j <= n; ++j){
    value[0][j] = 0;
  }
  for(int v = 0; v <= W; ++v){
    value[v][0] = 0;
  }
  for(int i = 1; i <= n; ++i){
    for(int v = 1; v <= W; ++v){
      value[v][i] = value[v][i-1];
      if(w[i-1] <= v){
        int val = value[v-w[i-1]][i-1] + w[i-1];
        if(value[v][i] < val){
          value[v][i] = val;
        }
      }
    }

  }
  return value[W][n];
  // int current_weight = 0;
  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  // return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
