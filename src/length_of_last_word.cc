

#include "code_utils.h"


int lengthOfLastWord(string s) {
    int count = 0;
    for (int i = s.size() - 1; i >=0; --i) {
        if (isspace(s[i])) {
            if (count) 
                break;
            else
                count++;
        }
    }
    return count;
}
int main(int argc, char* argv[]) {



}