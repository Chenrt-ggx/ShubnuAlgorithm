#include <vector>
#include <iostream>
#include <functional>

int search(std::vector<int> &buf, int sub, int l, int r) {
    if (l > r) return 0;
    int val = INT32_MAX, pos = -1;
    for (int i = l; i <= r; ++i) {
        if (buf[i] < val) {
            val = buf[i];
            pos = i;
        }
    }
    int left = search(buf, val, l, pos - 1);
    int right = search(buf, val, pos + 1, r);
    return val - sub + left + right;
}

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    std::cout << search(buf, 0, 0, total - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
