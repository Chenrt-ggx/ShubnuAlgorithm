#include <vector>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> dp(total + 1, 1);
    for (int i = 2; i <= total; ++i) {
        for (int j = 1; j <= i >> 1; ++j) {
            dp[i] += dp[j];
        }
    }
    std::cout << dp[total];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
