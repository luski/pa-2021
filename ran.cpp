#include <iostream>
#include <vector>

long long query(int w, const std::vector<std::pair<int, int>> &ranges) {
    int n = (int) ranges.size();
    auto idxSm = ranges[w / 2].first;
    auto idxGt = ranges[w / 2].second;

    if (idxGt - idxSm <= w - 1) {
        auto maxMargin = w - 1 - (idxGt - idxSm);
        auto lMargin = std::min(maxMargin, idxSm - 1);
        auto minL = idxSm - lMargin;
        auto maxL = idxSm;
        auto minR = minL + w - 1;
        auto maxR = std::min(n, idxSm + w - 1);
        return 1 + std::min(maxL - minL, maxR - minR);
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> idx(n + 1);
    std::vector<std::pair<int, int>> ranges;
    ranges.reserve(n);

    for (int i = 1; i <= n; i++) {
        int k;
        std::cin >> k;
        idx[k] = i;
    }

    for (int i = n; i > 0; i--) {
        if (i == n) {
            ranges.emplace_back(idx[i], idx[i]);
        } else {
            ranges.emplace_back(std::min(idx[i], ranges.rbegin()->first),
                                std::max(idx[i], ranges.rbegin()->second));
        }
    }
    long long result = 0;

    for (int i = 1; i <= n; i++) {
        result += query(i, ranges);
    }

    std::cout << 2 * n + 1 << " " << result << std::endl;

    return 0;
}
