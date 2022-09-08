#include <iostream>
#include <unordered_map>

void dfs(int now, std::unordered_map<int, int> &mem) {
    int ans = 1;
    for (int i = 1; i <= now >> 1; ++i) {
        if (mem.find(i) == mem.end()) dfs(i, mem);
        ans += mem.at(i);
    }
    mem[now] = ans;
}

void solve() {
    int total;
    std::unordered_map<int, int> mem;
    std::cin >> total;
    mem[1] = 1;
    dfs(total, mem);
    std::cout << mem[total];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
