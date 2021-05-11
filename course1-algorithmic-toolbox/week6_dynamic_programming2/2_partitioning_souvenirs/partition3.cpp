#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int sum_A = std::accumulate(A.begin(), A.end(), 0);

  if(sum_A % 3 || A.size() < 3){
    return 0;
  }
  int W = sum_A / 3;
  int value1[401][51];
  int n = A.size(); //column: item #
  for(int j = 0; j <= n; ++j){
    value1[0][j] = 0;
  }
  for(int v = 0; v <= 2*W; ++v){
    value1[v][0] = 0;
  }
  for(int i = 1; i <= n; ++i){
    for(int v = 1; v <= 2*W; ++v){
      value1[v][i] = value1[v][i-1];
      if(A[i-1] <= v){
        int val = value1[v-A[i-1]][i-1] + A[i-1];
        if(value1[v][i] < val){
          value1[v][i] = val;
        }
      }
    }
  }
  int val1 = value1[W][n];
  int val2 = value1[2*W][n];
  return val1==W && val2==2*W;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
