#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::stack;
using std::cin;
using std::cout;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if (n < 1) return result;
    stack<int> st;
    int cur = 0;
    while (cur > -1 || !st.empty()) {
      while(cur > -1){
        st.push(cur);
        cur = left[cur];
      }
      cur = st.top();
      st.pop();
      result.push_back(key[cur]);
      cur = right[cur];
    }
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if (n < 1) return result;
    stack<int> st;
    int cur = 0;
    st.push(0);
    while (!st.empty()) {
      cur = st.top();
      st.pop();      
      result.push_back(key[cur]);
      if (right[cur] > -1)
        st.push(right[cur]);      
      if (left[cur] > -1)
        st.push(left[cur]);
    }
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    if (n < 1) return result;
    stack<int> st;
    int cur = 0;
    while (cur > -1 || !st.empty()) {
      while (cur > -1) {
        if (right[cur] > -1) 
          st.push(right[cur]);
        st.push(cur);
        cur = left[cur];
      }
      cur = st.top();
      st.pop();
      if (right[cur] > -1 && !st.empty() && st.top() == right[cur]) {
        st.pop();
        st.push(cur);
        cur = right[cur];
      } else {
        result.push_back(key[cur]);
        cur = -1;
      } 
    }
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

