#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total, sub;
    std::cin >> total >> sub;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    std::sort(buf.begin(), buf.end());
    long long result = 0;
    for (int i = 0; i < total; ++i) {
        auto lower = std::lower_bound(buf.begin(), buf.end(), buf[i] - sub);
        auto upper = std::upper_bound(buf.begin(), buf.end(), buf[i] - sub);
        result += upper - lower;
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}