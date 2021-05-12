#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int value[102][102][102]{0};
  int na = a.size();
  int nb = b.size();
  int nc = c.size();
  for(int i = 1; i <= na; ++i){
    for(int j = 1; j <= nb; ++j){
      for(int k = 1; k <= nc; ++k){
        int val = std::max(value[i][j][k-1], std::max(value[i-1][j][k], value[i][j-1][k]));
        value[i][j][k] = val;
        if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
          value[i][j][k] = value[i-1][j-1][k-1]+1;
        }
      }
    }
  }
  return value[na][nb][nc];  
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
