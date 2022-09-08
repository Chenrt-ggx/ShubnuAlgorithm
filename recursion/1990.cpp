#include <vector>
#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    std::vector<int> f(total + 1, 1);
    std::vector<int> g(total + 1, 0);
    const int mask = 10000;
    for (int i = 2; i <= total; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 1]) % mask;
        g[i] = (f[i - 2] + g[i - 1]) % mask;
    }
    std::cout << f[total];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
