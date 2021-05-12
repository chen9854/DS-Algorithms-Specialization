#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<long long> &a, vector<long long> &b) {
  //write your code here
  int value[102][102]{0};
  int na = a.size();
  int nb = b.size();
  for(int i = 1; i <= na; ++i){
    for(int j = 1; j <= nb; ++j){
      int val = std::max(value[i-1][j], value[i][j-1]);
      value[i][j] = val;
      if(a[i-1]==b[j-1]){
        value[i][j] = value[i-1][j-1] + 1;
      }
    }
  }
  return value[na][nb];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long long> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
