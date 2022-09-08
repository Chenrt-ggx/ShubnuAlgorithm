#include <vector>
#include <iostream>

void solve() {
    int a, b, c;
    while (true) {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        std::cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if (a <= 0 || b <= 0 || c <= 0) a = b = c = 0;
        if (a > 20 || b > 20 || c > 20) a = b = c = 20;
        std::vector<std::vector<std::vector<int>>> dp(a + 1, std::vector<std::vector<int>>(
                b + 1, std::vector<int>(c + 1, 1)));
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                for (int k = 1; k <= c; ++k) {
                    if (i < j && j < k) {
                        dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k]
                                      + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
                    }
                }
            }
        }
        std::cout << dp[a][b][c] << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
