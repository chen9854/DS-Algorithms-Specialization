#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void inoder(const vector<Node>& tree, vector<int> &result) {
    int n = tree.size();
    if (n < 2) return;
    stack<int> st;
    int cur = 0;
    while (cur > -1 || !st.empty()) {
      while(cur > -1){
        st.push(cur);
        cur = tree[cur].left;
      }
      cur = st.top();
      st.pop();
      result.push_back(tree[cur].key);
      cur = tree[cur].right;
    }
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  vector<int> result;
  inoder(tree, result);
  if (result.size() < 2) return true;
  int max_num = INT_MIN;
  for (size_t i = 1; i < result.size(); ++i) {
    max_num = std::max(result[i-1], max_num);
    if (result[i] < max_num)
      return false;
  }
  return true;
};

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
