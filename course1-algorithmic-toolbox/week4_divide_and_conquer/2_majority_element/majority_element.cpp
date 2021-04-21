#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int64_t get_majority_element(vector<int64_t> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid = (int) (left + right)/2;
  int64_t left_majority = get_majority_element(a, left, mid);
  int64_t right_majority = get_majority_element(a, mid, right);
  if(left_majority  == right_majority){
    return left_majority;
  }
  else{
    int left_count = 0;    
    if(left_majority != -1){
      for(int i = left; i < right; ++i){
        if(a[i] == left_majority){
          left_count++;
        }
      }
    }

    int right_count = 0;
    if(right_majority != -1){
      for(int i = left; i < right; ++i){
        if(a[i] == right_majority){
          right_count++;
        }
      }
    }

    if(left_count > (int) (right-left)/2){
      return left_majority;
    }
    else if(right_count > (int) (right-left)/2){
      return right_majority;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int64_t> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
