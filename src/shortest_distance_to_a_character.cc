#include "code_utils.h"

vector<int> shortestToChar(string S, char C) {
    vector<int> res;
    res.reserve(S.size());
    int i = 0;
    int len = S.size();
    for (auto & ch : S) {
        if (ch != C) {
            ++i;
            continue;
        }
        while (i >= 0) {
            res.push_back(i--);
        }
        i = 0;
    }
    while(i) {
        res.push_back(i--);
    }
    print_array(res);
    vector<int> next_res;
    i = 0;
    for (int j = S.size() - 1; j >= 0; --j) {
        auto ch = S[j];
        if (ch != C) {
            ++i;
            continue;
        }
        while (i >=0) {
             next_res.push_back(i--);
        }
        i = 0;
    }
    while(i) {
        next_res.push_back(i--);
    }
    print_array(next_res);
    for (int i = 0; i < next_res.size();++i) {
        res[i] = std::min(res[i], next_res[len - i - 1]);
    }
    return res;
}
int main() {
    //auto res = shortestToChar("loveleetcode", 'e');
    auto res = shortestToChar("aaba", 'b');
    print_array(res);
    return 0;
}