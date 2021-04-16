#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <map>
using std::vector;

struct Segment {
  long long start, end;
};

vector<long long> optimal_points(vector<Segment> &segments) {

  vector<long long> points;
  //write your code here

  while(!segments.empty()){
    std::map<long long, long long> seg_map;
    for (size_t i = 0; i < segments.size(); ++i){
      for (int j = segments[i].start; j <= segments[i].end; ++j) {
        seg_map[j] += 1;
      }      
    }  

    int s1 = -1;
    long long s2 = -1;
    for(auto it = seg_map.begin(); it != seg_map.end(); it++){
      if(it->second >= s2){  
        s1 = it->first;      
        s2 = it->second;
      }
    }
    points.push_back(s1);  
    // for(int i = segments.size()-1; i >= 0; --i){
      // if(s1 >= segments[i].start && s1 <= segments[i].end){
        // segments.erase(segments.begin()+i);
      // }
    // }
    for(auto it = segments.end()-1; it >= segments.begin(); --it){      
      if (s1 >= it->start && s1 <= it->end){
        segments.erase(it);
      }
    }    
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<long long> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
