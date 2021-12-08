#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char chars[4] = {'a', 'c', 'g', 'o'};

    int n;
    std::cin >> n;
    int count = 0;

    for (auto i = 0; i < n * 8; i++) {
        char c;
        std::cin >> c;
        if (c == '1') count++;
    }

    if (n * 3 > count || n * 6 < count) {
        std::cout << "NIE" << std::endl;
        return 0;
    }

    int rest = count - n * 3;
    std::vector<int> nums(n, 0);

    for (auto i = 0; i < n; i++) {
        if (rest == 0) break;
        int addition = std::min(3, rest);
        rest -= addition;
        nums[i] += addition;
    }

    for (auto i = 0; i < n; i++) std::cout << chars[nums[i]];
    std::cout << std::endl;

    return 0;
}
