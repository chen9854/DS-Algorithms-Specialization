#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

string InverseBWT(const string& bwt) {
  string text = "";

  // write your code here
  int n = bwt.size();
  unordered_map<char, int> map;
  map['$'] = 0;
  map['A'] = 1;
  map['C'] = 2;
  map['G'] = 3;
  map['T'] = 4;
  int nc = 5;
  vector<int> count(nc + 1, 0);
  for (int i = 0; i < n; ++i) {
    count[map[bwt[i]] + 1]++;
  }
  for (int i = 1; i <= nc; ++i) {
    count[i] += count[i - 1];
  }

  unordered_map<char, int> first;
  first['$'] = 0;
  first['A'] = 0;
  first['C'] = 0;
  first['G'] = 0;
  first['T'] = 0;  

  vector<int> last_to_first(n, 0);
  for (int i = 0; i < n; ++i) {
    char c = bwt[i];    
    last_to_first[i] = count[map[c]] + first[c];
    first[c]++;        
  }

  int i = 0;  
  while (text.size() < n - 1) {
    char c = bwt[i];
    text.push_back(c);
    i = last_to_first[i];
  }
  reverse(text.begin(), text.end());
  text += '$';
  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
