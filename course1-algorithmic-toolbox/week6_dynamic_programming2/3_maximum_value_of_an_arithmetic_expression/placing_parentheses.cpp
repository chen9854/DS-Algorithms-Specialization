#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  vector<char> op;
  vector<int> d;
  for(auto c : exp){
    if(c=='*' || c=='+' || c=='-'){
      op.push_back(c);
    }
    else{
      int temp = c-'0';
      d.push_back(temp);
    }
  }
  int n = d.size();
  long long m[16][16]{0}, M[16][16]{0};
  for(int i = 1; i <= n; ++i){
    m[i][i] = d[i-1];
    M[i][i] = d[i-1];
  }
  for(int s = 1; s <= n-1; ++s){
    for(int i = 1; i <= n-s; ++i){
      int j = i + s;
      m[i][j] = INT8_MAX;
      M[i][j] = INT8_MIN;
      for(int k = i; k < j; ++k){
        long long a = eval(M[i][k], M[k+1][j], op[k-1]);
        long long b = eval(M[i][k], m[k+1][j], op[k-1]);
        long long c = eval(m[i][k], M[k+1][j], op[k-1]);
        long long d = eval(m[i][k], m[k+1][j], op[k-1]);
        m[i][j] = std::min(m[i][j], std::min(std::min(a,b), std::min(c,d)));
        M[i][j] = std::max(M[i][j], std::max(std::max(a,b), std::max(c,d)));
      }
    }
  }
  return M[1][n];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
