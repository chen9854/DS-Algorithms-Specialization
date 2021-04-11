#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
    }
    return current % m;
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

uint64_t get_fibonacci_huge_efficient(uint64_t n, uint64_t m) {
    if(m == 0){
        return 0;
    }
    else if(m == 1){
        return 1;
    }
    std::vector<uint64_t> vector_pisano = pisano(m);
    uint64_t m_pisano = n%(vector_pisano.size());
    return vector_pisano[m_pisano];
}


int main() {
    uint64_t n, m;
    std::cin >> n >> m;
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_efficient(n, m) << '\n';    
}
