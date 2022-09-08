#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    typedef std::priority_queue<int, std::vector<int>, std::greater<>> heap;
    std::unordered_map<int, heap> map;
    std::sort(buf.begin(), buf.end());
    for (int i : buf) {
        if (map.find(i) == map.end()) {
            map[i] = std::priority_queue<int, std::vector<int>, std::greater<>>();
        }
        if (map.find(i - 1) == map.end() || map[i - 1].empty()) {
            map[i].push(1);
        } else {
            map[i].push(map[i - 1].top() + 1);
            map[i - 1].pop();
        }
    }
    std::cout << std::accumulate(map.begin(), map.end(), INT32_MAX, [](int lhs, std::pair<const int, heap> &rhs) {
        return rhs.second.empty() ? lhs : std::min(lhs, rhs.second.top());
    });
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
