#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int dist[200][200];
  int n = str1.size();
  int m = str2.size();
  for(int i = 0; i <= n; ++i){
    dist[i][0] = i;
  }
  for(int j = 0; j <= m; ++j){
    dist[0][j] = j;
  }  
  for(int j = 1; j <= m; ++j){
    for(int i = 1; i <= n; ++i){
      int ins = dist[i][j-1] + 1;
      int del = dist[i-1][j] + 1;
      int mat = dist[i-1][j-1];
      int mis = dist[i-1][j-1] + 1;
      int min_di = std::min(del, ins);
      if(str1[i-1] == str2[j-1]){
        dist[i][j] = std::min(mat, min_di);
      }
      else{
        dist[i][j] = std::min(mis, min_di);
      }
    }
  }
  return dist[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
