#include "code_utils.h"
auto gucciGang = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
#pragma GCC optimise ("Ofast")
class Solution {
public:
  bool detectCapitalUse(string word) {
    int upCaseCount = 0;
    for (int i = 0; i < word.size(); ++i) {
        auto ch = word[i];
        if (ch >= 'A' && ch <= 'Z') {
            ++upCaseCount;
		}
    }
	if (upCaseCount == 0 || upCaseCount == word.size()) {
		return true;
	}
	if (upCaseCount == 1 && word[0] <= 'Z') {
		return true;
	}
    return false;
  }
};

int main() {
   return 0;
}
