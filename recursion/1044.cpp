#include <vector>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> dp(total + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= total; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - j - 1];
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
