#include <string>
#include <iostream>

void solve() {
    int sub;
    std::string str;
    std::cin >> str >> sub;
    int count = (int) str.length() - sub;
    for (int i = 0; i < sub; ++i) {
        for (int j = 0; j < str.length() - 1; ++j) {
            if (str[j] > str[j + 1]) {
                str.erase(str.begin() + j);
                break;
            }
        }
    }
    std::string result = str.substr(0, count);
    if (result.find_first_not_of('0') == std::string::npos) {
        std::cout << "0";
    } else {
        std::cout << result.substr(result.find_first_not_of('0'));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
