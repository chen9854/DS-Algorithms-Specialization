#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;

  // write your code here
  std::map<double, double, std::greater<double>> vpw;
  for(int i = 0; i < values.size(); i++){
    double temp = values[i]/weights[i];
    vpw[temp] = weights[i];
  }
  for(auto it : vpw){
    if(capacity > it.second){
      value += it.first * it.second;
      capacity -= it.second;
    }
    else{
      value += capacity * it.first;
      capacity = 0;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
