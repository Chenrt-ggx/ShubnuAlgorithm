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
    for (int i = 0, lt = 0, le = 0; i < total; ++i) {
        while (lt < total && buf[lt] - buf[i] < sub) ++lt;
        while (le < total && buf[le] - buf[i] <= sub) ++le;
        if (buf[lt] - buf[i] == sub && buf[le - 1] - buf[i] == sub) {
            result += le - lt;
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
