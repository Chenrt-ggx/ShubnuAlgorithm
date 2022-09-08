#include <vector>
#include <numeric>
#include <iostream>

bool check(std::vector<int> &buf, int gap, int count) {
    for (int i : buf) {
        count -= i / gap;
    }
    return count <= 0;
}

void solve() {
    int total, count;
    std::cin >> total >> count;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    int left = 0, right = std::accumulate(buf.begin(), buf.end(), 0, [](int l, int r) {
        return std::max(l, r);
    });
    while (right - left > 1) {
        int mid = (left + right) >> 1;
        if (check(buf, mid, count)) left = mid;
        else right = mid;
    }
    std::cout << left;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
