#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }

    return sum % 10;
}

std::vector<uint64_t> pisano(uint64_t m)
{
    std::vector<uint64_t> res;
    if(m == 1){
        res.push_back(0);
        res.push_back(1);
    }
    else{
        res.push_back(0);
        res.push_back(1);     
        for(uint64_t i = 2; i < m * m - 1; i++)
        {
            uint64_t curr = (res[i-1] + res[i-2]) % m;
            if(curr==1 && res[i-1]==0){
                res.pop_back();
                break;
            }
            res.push_back(curr);
        } 
    }
    return res;
}


uint64_t get_fibonacci_partial_sum_solution(uint64_t from, uint64_t to) {
    std::vector<uint64_t> pisano_vector = pisano(10);
    uint64_t p_size = pisano_vector.size();    
    uint64_t from_rem = from%p_size;
    uint64_t to_rem = to%p_size;
    uint64_t range_div = ((to-from)/p_size) % 10;
    uint64_t sum1 = 0;
    uint64_t sum = 0; 
    for(uint64_t i = 0; i < p_size; ++i) {
        sum1 += pisano_vector[i];        
    }
    if(from_rem <= to_rem){
        for(int i = from_rem; i < to_rem+1; i++){
            sum += pisano_vector[i];
        }
    }
    else{
        for(int i = to_rem+1; i < from_rem; i++){
            sum += pisano_vector[i];
        }
        sum = sum1 - sum;
    }
    sum += sum1*range_div;
    return sum%10;
}

int main() {
    uint64_t from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_solution(from, to) << '\n';
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
