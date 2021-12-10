#include <iostream>
#include <set>
#include <array>
#include <vector>
#include <queue>

bool contains(const std::array<int, 3> &value, const std::set<std::array<int, 3>> &cache) {
    return cache.find(value) != cache.end();
}

typedef std::array<int, 3> Node;
typedef std::pair<std::array<int, 3>, int> FifoEl;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::set<std::array<int, 3>> cache;
    int resultCount = 0;

    int aStart, bStart, cStart, a, b, c;
    std::cin >> a >> b >> c >> aStart >> bStart >> cStart;
    std::array<int, 3> sizes{a, b, c};


    std::vector<int> result(c + 1, -1);
    std::queue<FifoEl> fifo;
    fifo.emplace(std::make_pair<Node, int>({aStart, bStart, cStart}, 0));
    cache.insert({aStart, bStart, cStart});

    bool stopped = false;
    while (!fifo.empty()) {
        const auto &element = fifo.front();

        for (auto v: element.first) {
            if (result[v] == -1) {
                result[v] = element.second;
                if (++resultCount == c + 1) {
                    stopped = true;
                    break;
                }
            }
        }
        if (stopped) break;


        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    if (element.first[i] > 0 && element.first[j] < sizes[j]) {
                        const Node &prevNode = element.first;
                        Node n = prevNode;
                        n[i] = std::max(0, prevNode[i] - (sizes[j] - prevNode[j]));
                        n[j] = std::min(sizes[j], prevNode[j] + prevNode[i]);

                        if (!contains(n, cache)) {
                            cache.insert(n);
                            fifo.push({n, element.second + 1});
                        }
                    }
                }
            }
        }


        fifo.pop();
    }

    for (auto i: result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
