#include <iostream>
#include <vector>
#include <algorithm>

uint64_t MaxPairwiseProduct(const std::vector<uint64_t>& numbers) {
    uint64_t max_product = 0;
    int n = numbers.size();

    // for (int first = 0; first < n; ++first) {
    //     for (int second = first + 1; second < n; ++second) {
    //         max_product = std::max(max_product,
    //             numbers[first] * numbers[second]);
    //     }
    // }
    std::vector<uint64_t> nums = numbers;
    std::sort(nums.begin(), nums.end());
    max_product = nums[n-2] * nums[n-1];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<uint64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
