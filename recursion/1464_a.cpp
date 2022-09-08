#include <vector>
#include <iostream>

int dfs(int a, int b, int c, std::vector<std::vector<std::vector<int>>> &mem) {
    if (mem[a][b][c]) {
        return mem[a][b][c];
    } else if (a == 0 || b == 0 || c == 0) {
        return mem[a][b][c] = 1;
    } else if (a < b && b < c) {
        return mem[a][b][c] = dfs(a, b, c - 1, mem) + dfs(a, b - 1, c - 1, mem)
                              - dfs(a, b - 1, c, mem);
    } else {
        return mem[a][b][c] = dfs(a - 1, b, c, mem) + dfs(a - 1, b - 1, c, mem)
                              + dfs(a - 1, b, c - 1, mem) - dfs(a - 1, b - 1, c - 1, mem);
    }
}

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
        std::vector<std::vector<std::vector<int>>> mem(a + 1, std::vector<std::vector<int>>(
                b + 1, std::vector<int>(c + 1, 0)));
        std::cout << dfs(a, b, c, mem) << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
