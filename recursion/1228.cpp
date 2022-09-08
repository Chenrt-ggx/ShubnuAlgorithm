#include <iostream>

void dfs(int x, int y, int sx, int sy, int size) {
    if (size == 1) return;
    int buf = size >> 1;
    if (x <= buf) {
        if (y <= buf) {
            std::cout << buf + 1 + sx << ' ' << buf + 1 + sy << " 1" << std::endl;
            dfs(x, y, sx, sy, buf);
            dfs(buf, 1, sx, sy + buf, buf);
            dfs(1, buf, sx + buf, sy, buf);
            dfs(1, 1, sx + buf, sy + buf, buf);
        } else {
            std::cout << buf + 1 + sx << ' ' << buf + sy << " 2" << std::endl;
            dfs(buf, buf, sx, sy, buf);
            dfs(x, y - buf, sx, sy + buf, buf);
            dfs(1, buf, sx + buf, sy, buf);
            dfs(1, 1, sx + buf, sy + buf, buf);
        }
    } else {
        if (y <= buf) {
            std::cout << buf + sx << ' ' << buf + 1 + sy << " 3" << std::endl;
            dfs(buf, buf, sx, sy, buf);
            dfs(buf, 1, sx, sy + buf, buf);
            dfs(x - buf, y, sx + buf, sy, buf);
            dfs(1, 1, sx + buf, sy + buf, buf);
        } else {
            std::cout << buf + sx << ' ' << buf + sy << " 4" << std::endl;
            dfs(buf, buf, sx, sy, buf);
            dfs(buf, 1, sx, sy + buf, buf);
            dfs(1, buf, sx + buf, sy, buf);
            dfs(x - buf, y - buf, sx + buf, sy + buf, buf);
        }
    }
}

void solve() {
    int total, x, y;
    std::cin >> total >> x >> y;
    dfs(x, y, 0, 0, 1 << total);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
