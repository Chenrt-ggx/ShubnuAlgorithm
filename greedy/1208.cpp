#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int size, total;
    std::cin >> size >> total;
    std::vector<std::pair<int, int>> items(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> items[i].first >> items[i].second;
    }
    std::sort(items.begin(), items.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return lhs.first < rhs.first;
    });
    int result = 0;
    for (std::pair<int, int> &i : items) {
        if (size >= i.second) {
            result += i.second * i.first;
            size -= i.second;
        } else if (size) {
            result += size * i.first;
            size = 0;
        }
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
