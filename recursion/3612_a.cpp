#include <string>
#include <iostream>

char dfs(std::string &str, long long bound, long long index) {
    if (index <= str.length()) {
        return str[index - 1];
    } else if (index <= bound / 2) {
        return dfs(str, bound / 2, index);
    } else {
        long long next = index - bound / 2 - 1;
        return dfs(str, bound / 2, next ? next : bound / 2);
    }
}

void solve() {
    std::string str;
    long long index;
    std::cin >> str >> index;
    auto bound = (long long) str.length();
    while (bound < index) bound <<= 1;
    std::cout << dfs(str, bound, index);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
