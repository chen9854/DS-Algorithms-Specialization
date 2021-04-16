#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n <= 2){
    summands.push_back(n);
    return summands;
  }
  else{
    summands.push_back(1);
    n--;
  }

  while(n > 0){
    if(n < 2*summands.back()+3){
      summands.push_back(n);
      n = 0;
    }
    else{
      summands.push_back(summands.back()+1);
      n -= summands.back();
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
