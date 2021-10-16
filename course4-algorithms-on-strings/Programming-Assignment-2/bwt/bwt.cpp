#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
  string result = "";

  // write your code here
  vector<string> matrix;
  for (int i = 0; i < text.size(); ++i) {    
    matrix.push_back(text.substr(i) + text.substr(0, i));
  }
  sort(matrix.begin(), matrix.end());
  int m = matrix.size(), n = matrix[0].size();
  for (int i = 0; i < m; ++i) {    
    result.push_back(matrix[i][n - 1]);
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  cout << BWT(text) << endl;
  return 0;
}