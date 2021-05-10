#include <iostream>
#include <map>
#include <set>
#include <limits>
int get_change(int m) {
  //write your code here
  std::map<int,int> min_num_coins;
  std::set<int> coins = {1,3,4};
  min_num_coins[0] = 0;
  for(int im = 1; im <= m; ++im)  {
    min_num_coins[im] = std::numeric_limits<int>::max();
    for(int c : coins){
      if(im >= c){
        int num_coins = min_num_coins[im - c] + 1;
        if(num_coins < min_num_coins[im]){
          min_num_coins[im] = num_coins;
        }
      }
    }
  }

  return min_num_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
