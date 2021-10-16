#include <string>
#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;
  // write your code here
  edges root;
  root[patterns[0][0]] = 1;
  t.push_back(root);
  for (auto pattern : patterns) {
    int curr = 0;
    for (auto c : pattern) {
      if (curr < t.size() && t[curr].count(c)) {
        curr = t[curr][c];
      } else {
        edges node;
        t.push_back(node);
        t[curr][c] = t.size();
        curr = t.size();
      }
    } 
  }

  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}