#include <iostream>

void dfs(int level, int size) {
    if (size == 1) {
        if (level == 0) std::cout << " /\\ ";
        else std::cout << "/__\\";
    } else {
        int buf = 1 << (size - 1);
        if (level < buf) {
            for (int i = 0; i < buf; ++i) std::cout << ' ';
            dfs(level, size - 1);
            for (int i = 0; i < buf; ++i) std::cout << ' ';
        } else {
            dfs(level - buf, size - 1);
            dfs(level - buf, size - 1);
        }
    }
}

void solve() {
    int total;
    std::cin >> total;
    for (int i = 0; i < 1 << total; ++i) {
        dfs(i, total);
        std::cout << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
