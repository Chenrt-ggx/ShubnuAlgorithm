#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

void solve() {
    int total, size;
    std::cin >> total >> size;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    static int max_len, min_len;
    min_len = 0, max_len = std::accumulate(buf.begin(), buf.end(), 0, [](int x, int y) {
        return std::max(x, y);
    });
    for (static int mid; max_len - min_len > 1;) {
        mid = (max_len + min_len) >> 1;
        long long sum = std::accumulate(buf.begin(), buf.end(), 0l, [](long long x, int y) {
            return y > mid ? x + y - mid : x;
        });
        if (sum < size) max_len = mid;
        else min_len = mid;
    }
    std::cout << min_len;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
