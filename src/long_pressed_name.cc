#include "code_utils.h"
bool isLongPressedName(string name, string typed) {
    if (typed.size() < name.size()) {
        return false;
    }
    int nlen = name.size();
    int tlen = typed.size();
    int i = 0, j = 0;
    while (i < nlen) {
        while (j <  tlen && name[i] != typed[j]) {
            ++j;
        }
        if (name[i] == typed[j]) {
            ++i,j++;
            continue;
        }
        return false;
    }
    return true;
}
int main() {

}