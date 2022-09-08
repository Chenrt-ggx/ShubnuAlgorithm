#include <vector>
#include <iostream>

void solve() {
    int total, size;
    std::cin >> total >> size;
    std::vector<int> dp(size + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < total; ++i) {
        int weight;
        std::cin >> weight;
        for (int j = size; j >= weight; --j) {
            dp[j] = dp[j] + dp[j - weight];
        }
    }
    std::cout << dp[size];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
