#include <vector>
#include <numeric>
#include <iostream>

bool check(std::vector<int> &buf, int limit, int count) {
    int sum = 0;
    for (int i : buf) {
        if (limit < i) return false;
        if (sum + i > limit) --count, sum = i;
        else sum += i;
    }
    return count > 0;
}

void solve() {
    int total, count;
    std::cin >> total >> count;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    int left = -1 + std::accumulate(buf.begin(), buf.end(), 0, [](int x, int y) {
        return std::max(x, y);
    }), right = std::accumulate(buf.begin(), buf.end(), 0, [](int x, int y) {
        return x + y;
    });
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(buf, mid, count)) right = mid;
        else left = mid;
    }
    std::cout << right;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
