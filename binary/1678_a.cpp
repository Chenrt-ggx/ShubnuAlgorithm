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
    std::sort(buf.begin(), buf.end());
    long long result = 0;
    for (int i = 0, value; i < query; ++i) {
        std::cin >> value;
        auto upper = std::lower_bound(buf.begin(), buf.end(), value);
        if (upper == buf.begin()) {
            result += buf.front() - value;
        } else if (upper == buf.end()) {
            result += value - buf.back();
        } else {
            result += std::min(*upper - value, value - *(upper - 1));
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
