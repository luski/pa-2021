#include <iostream>
#include <array>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<uint8_t> visited(n, 0);
    std::vector<int> queue;
    queue.reserve(n);

    int idx;
    int count = 0;
    int size = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> idx;
        if (count == k) {
            continue;
        }
        if (visited[idx]) {
            queue.push_back(i);
        } else {
            visited[idx] = 1;
            count++;
        }
        size++;
    }

    if (count < k) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long result = 0;
    for (int i: queue) {
        result += (size-- - i - 1);
    }
    std::cout << result << std::endl;

    return 0;
}
