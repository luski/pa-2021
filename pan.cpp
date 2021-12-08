#include <iostream>
#include <vector>
#include <algorithm>

struct item_t {
    int size;
    int count;
    int order;

    item_t(int s, int c, int o): size(s), count(c), order(o) {}
};

bool sortfn(const item_t &a,
            const item_t &b) {
    return a.order > b.order;
}


void solve() {
    int n;
    uint8_t c;
    bool isInWhole = false;
    int currSize = 0;
    int infected = 0;

    std::cin >> n;
    std::vector<item_t> wholes;
    wholes.reserve(n);
    std::string test;
    bool singular = true;

    for (int i = 0; i < n; i++) {
        std::cin >> c;

        if (i == 0) {
            isInWhole = c == '0';
            if (!isInWhole) singular = false;
        }

        if (c == '0' && isInWhole) {
            currSize++;
        } else if (c == '0' && !isInWhole) {
            currSize = 1;
            isInWhole = true;
        } else if (c == '1' && isInWhole) {
            wholes.emplace_back(currSize, singular ? 1 : 2, singular ? currSize * 2 : currSize);
            singular = false;
            isInWhole = false;
            infected++;
        } else if (c == '1' && !isInWhole) {
            infected++;
        }
    }

    if (isInWhole) {
        wholes.emplace_back(currSize, 1, currSize * 2);
    }

    std::sort(wholes.begin(), wholes.end(), sortfn);

    int t = 0;

    for (const auto &whole: wholes) {
        if (whole.count == 2) {
            if (whole.size - t * 2 > 2) {
                infected += t * 2 + 1;
                t += 2;
            } else if (whole.size - t * 2 > 0) {
                infected += whole.size - 1;
                t += 1;
            } else {
                infected += whole.size;
            }
        } else {
            if (whole.size > t) {
                infected += t;
                t += 1;
            } else {
                infected += whole.size;
            }
        }
    }

    std::cout << infected << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}