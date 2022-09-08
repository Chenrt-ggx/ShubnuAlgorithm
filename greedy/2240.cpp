#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total, size;
    std::cin >> total >> size;
    std::vector<std::pair<int, int>> items(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> items[i].first >> items[i].second;
    }
    std::sort(items.begin(), items.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
        return 1.0 * lhs.second / lhs.first > 1.0 * rhs.second / rhs.first;
    });
    double result = 0;
    for (std::pair<int, int> &i : items) {
        if (size >= i.first) {
            result += i.second;
            size -= i.first;
        } else if (size) {
            result += 1.0 * size / i.first * i.second;
            size = 0;
        }
    }
    printf("%.2lf", result);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
