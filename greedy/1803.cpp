#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total;
    std::cin >> total;
    std::vector<std::pair<int, int>> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i].first >> buf[i].second;
    }
    std::sort(buf.begin(), buf.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.second < rhs.second;
    });
    int count = 0;
    for (int index = 0, now = 0; index < total; ++index) {
        if (now <= buf[index].first) {
            now = buf[index].second;
            ++count;
        }
    }
    std::cout << count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
