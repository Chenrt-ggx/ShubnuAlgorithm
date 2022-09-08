#include <vector>
#include <iostream>

void solve() {
    int total, limit;
    std::cin >> total >> limit;
    std::vector<int> buf(total);
    for (int i = 0; i < total; ++i) {
        std::cin >> buf[i];
    }
    long long result = 0;
    for (int i = 1; i < total; ++i) {
        if (buf[i - 1] + buf[i] > limit) {
            int gap = buf[i - 1] + buf[i] - limit;
            if (gap <= buf[i]) buf[i] -= gap;
            else buf[i - 1] -= gap - buf[i], buf[i] = 0;
            result += gap;
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
