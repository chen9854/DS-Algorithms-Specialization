#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_euclidGCD(int a, int b) {
  if(b == 0){
    return a;
  }
  int aPrime = a % b;
  return gcd_euclidGCD(b, aPrime);
}

long long lcm_efficient(int a, int b) {  
  if(a==0 || b==0){
    return 0;
  }
  else{
    long long gcd = gcd_euclidGCD(a, b);
    return gcd * (a/gcd) * (b/gcd);
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_efficient(a, b) << std::endl;
  return 0;
}
