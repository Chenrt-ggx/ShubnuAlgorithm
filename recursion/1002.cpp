#include <vector>
#include <iostream>

void solve() {
    int sx, sy, hx, hy;
    std::cin >> sx >> sy >> hx >> hy;
    std::vector<std::vector<long long>> dp(sx + 1, std::vector<long long>(sy + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= sx; ++i) {
        for (int j = 0; j <= sy; ++j) {
            int gx = abs(i - hx), gy = abs(j - hy);
            if (gx + gy && (std::max(gx, gy) != 2 || std::min(gx, gy) != 1)) {
                if (i) dp[i][j] += dp[i - 1][j];
                if (j) dp[i][j] += dp[i][j - 1];
            }
        }
    }
    std::cout << dp[sx][sy];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
