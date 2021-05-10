#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>
#include <set>
using std::vector;
// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while (n >= 1) {
//     sequence.push_back(n);
//     if (n % 3 == 0) {
//       n /= 3;
//     } else if (n % 2 == 0) {
//       n /= 2;
//     } else {
//       n = n - 1;
//     }
//   }
//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }
vector<int> optimal_sequence(int n) {
  std::map<int,int> min_num_opts;
  std::vector<int> prev;
  std::vector<int> sequence;
  // std::set<int> coins = {1,3,4};
  min_num_opts[0] = -1;
  prev.push_back(0);
  for(int im = 1; im <= n; ++im)  {
    min_num_opts[im] = std::numeric_limits<int>::max();
    prev.push_back(0);
    std::set<int> coins = {im-1, im/2, im/3};
    if(im % 3 == 0){
      int num_coins = min_num_opts[im/3] + 1;
      if(num_coins < min_num_opts[im]){
        min_num_opts[im] = num_coins;
        prev[im] = im/3;
      }
    }
    if(im % 2 == 0){
      int num_coins = min_num_opts[im/2] + 1;
      if(num_coins < min_num_opts[im]){
        min_num_opts[im] = num_coins;
        prev[im] = im/2;
      }
    }
    int num_coins = min_num_opts[im-1] + 1;
    if(num_coins < min_num_opts[im]){
      min_num_opts[im] = num_coins;
      prev[im] = im-1;
    }  
  }
  int p = n;
  while(p > 0){
    sequence.push_back(p);
    p = prev[p];
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
