#include <vector>
#include <iostream>
#include <algorithm>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    std::sort(buf.begin(), buf.end());
    long long result = buf.back() * buf.back();
    for (int i = 0, l = 0, r = (int) buf.size() - 1; i < total - 1; ++i) {
        result += (buf[l] - buf[r]) * (buf[l] - buf[r]);
        if (i & 1) ++l;
        else --r;
    }
    std::cout << result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
