#include <iostream>
#include <vector>
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum += current;
    }

    return sum%10;
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

int fibonacci_sum_solution(uint64_t n) {
    if (n <= 1)
        return n;
    std::vector<uint64_t> pisano_vector = pisano(10);
    uint64_t p_size = pisano_vector.size();
    uint64_t div = (n+1) / p_size; 
    uint64_t rem = (n+1) % p_size; 
    uint64_t sum1 = 0; 
    uint64_t sum = 0; 

    for(uint64_t i = 0; i < p_size; ++i) {
        sum1 += pisano_vector[i];        
    }
    for(uint64_t i = 0; i < rem; ++i){
        sum += pisano_vector[i];
    }
    sum += sum1*div;

    return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum_solution(n);
}
