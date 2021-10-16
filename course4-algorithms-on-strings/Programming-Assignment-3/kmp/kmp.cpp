#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::string;
using std::vector;


vector<int> compute_prefix(const string str) {
  int n = str.size();
  vector<int> s(n, 0);
  int border = 0;
  for (int i = 1; i < n; ++i) {
    while (border > 0 && str[i] != str[border]) {
      border = s[border - 1];
    }
    if (str[i] == str[border]) {
      border++;
    } else {
      border = 0;
    }
    s[i] = border;
  }
  return s;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  // Implement this function yourself
  string str = pattern + '$' + text;
  vector<int> s = compute_prefix(str);
  for (int i = pattern.size() + 1; i < str.size(); ++i) {
    if (s[i] == pattern.size()) {
      result.push_back(i - 2 * pattern.size());
    }
  }
  return result;
}


int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
