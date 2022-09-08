#include <string>
#include <vector>
#include <iostream>

void solve() {
    int sub;
    std::string str;
    std::cin >> str >> sub;
    int count = (int) str.length() - sub;
    std::vector<int> prev(str.length()), next(str.length());
    for (int i = 0; i < str.length() - 1; ++i) {
        prev[i + 1] = i;
        next[i] = i + 1;
    }
    int start = 0;
    prev[0] = next[str.length() - 1] = -1;
    for (int i = start + 1; i != -1; i = next[i]) {
        int cur = prev[i];
        while (cur != -1 && str[i] < str[cur]) {
            cur = prev[cur];
            if (--sub == 0) break;
        }
        if (cur == -1) start = i, prev[i] = -1;
        else next[cur] = i, prev[i] = cur;
        if (sub == 0) break;
    }
    std::string result;
    for (int i = start; i != -1; i = next[i]) {
        result += str[i];
    }
    result = result.substr(0, count);
    if (result.find_first_not_of('0') == std::string::npos) {
        std::cout << "0";
    } else {
        std::cout << result.substr(result.find_first_not_of('0'));
    }
    std::cout << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
