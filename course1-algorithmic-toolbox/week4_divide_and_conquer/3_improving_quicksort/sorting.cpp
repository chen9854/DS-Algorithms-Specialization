#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// int partition2(vector<int> &a, int l, int r) {
//   int x = a[l];
//   int j = l;
//   for (int i = l + 1; i <= r; i++) {
//     if (a[i] <= x) {
//       j++;
//       swap(a[i], a[j]);
//     }
//   }
//   swap(a[l], a[j]);
//   return j;
// }

vector<int> partition3(vector<int> &a, int l, int r) {
  vector<int> result;
  int x = a[l];
  int j = l + 1;
  int k = l + 1;

  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      swap(a[i], a[j]);
      j++;
    }
    else if(a[i] == x){
      swap(a[i], a[j]);
      swap(a[j], a[k]);
      j++; 
      k++;
    }
  }
  int m = std::min(k-l, j-k);
  for(int i = l; i < l+m; ++i){
    swap(a[i], a[j-i+l-1]);
  }
  result.push_back(j-k+l);
  result.push_back(j-1);
  return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m;
  m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
