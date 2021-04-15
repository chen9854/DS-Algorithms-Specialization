#include <iostream>
#include <vector>
int get_change(int m) {
  //write your code here
  if(m < 0){
    return 0;
  }
  
  int n = 0;
  while(m >= 10){
    m -= 10;
    n++;
  }
  while(m >= 5){
    m -= 5;
    n++;
  }
  while(m >= 1){
    m -= 1;
    n++;
  }
  
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
