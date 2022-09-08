#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total, query;
    std::cin >> total >> query;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    for (int i = 0, value; i < query; ++i) {
        std::cin >> value;
        auto it = std::lower_bound(buf.begin(), buf.end(), value);
        std::cout << (*it == value ? it - buf.begin() + 1 : -1) << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
