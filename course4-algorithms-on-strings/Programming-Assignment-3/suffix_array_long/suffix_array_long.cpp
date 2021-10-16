#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::map;
vector<int> sort_characters(const string& S) {
  int n = S.size();
  map<char, int> m;
  m['$'] = 0, m['A'] = 1, m['C'] = 2, m['G'] = 3, m['T'] = 4;
  int nc = 5;
  vector<int> order(n, 0);
  vector<int> count(nc, 0);
  for (int i = 0; i < n; ++i) {
    count[m[S[i]]]++;
  }
  for (int i = 1; i < nc; ++i) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    char c = S[i];
    count[m[c]]--;
    order[count[m[c]]] = i;
  }
  return order;
}

vector<int> compute_char_cls(const string& S, const vector<int>& order) {
  int n = S.size();
  vector<int> cls(n, 0);
  for (int i = 1; i < n; ++i) {
    if (S[order[i]] != S[order[i - 1]]) {
      cls[order[i]] = cls[order[i - 1]] + 1;
    } else {
      cls[order[i]]  = cls[order[i - 1]];
    }
  }
  return cls;
}

vector<int> sort_doubled(const string& S, int L, const vector<int>& order, const vector<int> cls) {
  int n = S.size();
  vector<int> count(n, 0), newOrder(n, 0);
  for (int i = 0; i < n; ++i) {
    count[cls[i]]++;
  }
  for (int i = 1; i < n; ++i) {
    count[i] += count[i - 1];
  }
  for (int i = n - 1; i >= 0 ; --i) {
    int start = (order[i] - L + n) % n;
    int cl = cls[start];
    count[cl]--;
    newOrder[count[cl]] = start;
  }
  return newOrder;
}

vector<int> update_cls(const vector<int>& new_order, vector<int>& cls, const int L) {
  int n = new_order.size();
  vector<int> new_cls(n, 0);
  for (int i = 1; i < n; ++i) {
    int cur = new_order[i], prev = new_order[i - 1];
    int mid = cur + L, midPrev = (prev + L) % n;
    if (cls[cur] != cls[prev] || cls[mid] != cls[midPrev]) {
      new_cls[cur] = new_cls[prev] + 1;
    } else {
      new_cls[cur] = new_cls[prev];
    }
  }
  return new_cls;
}
// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
vector<int> BuildSuffixArray(const string& text) {
  // vector<int> result;
  // Implement this function yourself
  vector<int> order = sort_characters(text);
  vector<int> cls = compute_char_cls(text, order);
  int L = 1;
  while (L < text.size()) {
    order = sort_doubled(text, L, order, cls);
    cls = update_cls(order, cls, L);
    L *= 2;
  }

  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
