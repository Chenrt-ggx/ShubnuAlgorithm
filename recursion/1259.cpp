#include <iostream>

void solve() {
    int total;
    std::cin >> total;
    for (int i = total; i > 3; --i) {
        for (int j = 0; j < i; ++j) std::cout << "o";
        for (int j = 0; j < i; ++j) std::cout << "*";
        std::cout << "--";
        for (int j = 0; j < total - i; ++j) std::cout << "o*";
        std::cout << std::endl;
        for (int j = 0; j < i - 1; ++j) std::cout << "o";
        std::cout << "--";
        for (int j = 0; j < i - 1; ++j) std::cout << "*";
        for (int j = 0; j < total - i + 1; ++j) std::cout << "o*";
        std::cout << std::endl;
    }
    const char *buf[] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
    for (const char *i : buf) {
        std::cout << i;
        for (int j = 0; j < total - 4; ++j) std::cout << "o*";
        std::cout << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
