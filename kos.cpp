#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<uint8_t> points;
    points.reserve(n);

    for (auto i = 0; i < n; i++) {
        int pts;
        std::cin >> pts;
        points.push_back(pts);
    }

    std::sort(points.begin(), points.end());
    auto iter = std::upper_bound(points.begin(), points.end(), points[n - k] - 1);
    std::cout << (int) (points.end() - iter) << std::endl;
    return 0;
}
