#include <iostream>

void dfs(int n) {
    bool first = true;
    for (int i = 16; i >= 0; --i) {
        if (n & (1 << i)) {
            if (first) first = false;
            else std::cout << "+";
            if (i == 0) {
                std::cout << "2(0)";
            } else if (i == 1) {
                std::cout << "2";
            } else {
                std::cout << "2(";
                dfs(i);
                std::cout << ")";
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    dfs(n);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
