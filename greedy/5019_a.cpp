#include <vector>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    int result = buf[0];
    for (int i = 1; i < total; ++i) {
        if (buf[i] > buf[i - 1]) {
            result += buf[i] - buf[i - 1];
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
