#include <string>
#include <iostream>

std::string dfs() {
    char next;
    int digit;
    std::string result, buffer;
    while (std::cin >> next) {
        if (next == '[') {
            std::cin >> digit;
            buffer = dfs();
            for (int i = 0; i < digit; ++i)
                result += buffer;
        } else if (next == ']') {
            return result;
        } else {
            result += next;
        }
    }
    return result;
}

void solve() {
    std::cout << dfs();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
