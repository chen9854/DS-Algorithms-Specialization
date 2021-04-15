#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int num = 0;
    if(tank > dist){
        return 0;
    }
    int s0 = 0;
    stops.push_back(dist);
    for(int i = 0; i < stops.size()-1; ++i){
        if(stops[i+1]-stops[i] > tank || stops[i]-s0 > tank){
            num = -1;
        }
        else{
            if(tank >= stops[i]-s0 && tank < stops[i+1]-s0){
                s0 = stops[i];
                num++;
            } 
        }
    }
    return num;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
