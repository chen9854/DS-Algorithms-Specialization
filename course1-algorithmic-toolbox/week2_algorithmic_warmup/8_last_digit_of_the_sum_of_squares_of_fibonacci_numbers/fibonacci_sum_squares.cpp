#include <iostream>
#include <vector>
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current * current;
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


uint64_t fibonacci_sum_squares_solution(uint64_t n) {
    if (n <= 1)
        return n;
    int num1 = 10+get_fibonacci_partial_sum_solution(n+1, n+1);
    int num2 = get_fibonacci_partial_sum_solution(n-1, n-1);
    return abs((num1*num1-num1*num2))%10;
}

int main() {
    uint64_t n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_solution(n);    
    // std::cout << fibonacci_sum_squares_naive(n);
}
