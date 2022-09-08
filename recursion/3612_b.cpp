#include <string>
#include <iostream>

void solve() {
    std::string str;
    long long index;
    std::cin >> str >> index;
    auto bound = (long long) str.length();
    while (bound < index) bound <<= 1;
    while (bound != str.length()) {
        bound >>= 1;
        if (index > bound) {
            if (index != bound + 1) index -= bound + 1;
            else index = bound;
        }
    }
    std::cout << str[index - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
