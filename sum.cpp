#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int>::iterator iit;
typedef std::vector<long long>::iterator llit;

bool query(long long element, iit sortedBegin, iit sortedEnd, llit sumsBegin, llit sumsEnd) {
    if (sortedBegin == sortedEnd) return true;
    auto it = std::lower_bound(sortedBegin, sortedEnd, element);
    if (it == sortedBegin) return false;
    if (it == sortedEnd) return true;

    auto index = *it == element ? it - sortedBegin : it - sortedBegin - 1;
    auto nextElement = *std::next(sumsBegin, index);
    return query(nextElement, std::next(sortedBegin, index + 1), sortedEnd, std::next(sumsBegin, index + 1), sumsEnd);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> elements(n);
    std::vector<int> sorted(n);
    std::vector<long long> sums(n);

    for (auto i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        elements[i] = k;
        sorted[i] = k;
    }

    std::sort(sorted.begin(), sorted.end());

    long long sum = 0;
    for (auto i = 0; i < n; i++) {
        sum += sorted[i];
        sums[i] = sum;
    }

    for (auto element: elements) {
        std::cout << (query(element, sorted.begin(), sorted.end(), sums.begin(), sums.end()) ? 'T' : 'N');
    }
    std::cout << std::endl;

    return 0;
}
