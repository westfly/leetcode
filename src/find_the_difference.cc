#include "code_utils.h"

char find_the_difference(const string& s, const string& t) {
    int stat_map[256]= {0};
    for (int i = 0; i < s.size(); ++i) {
        stat_map[s[i]]++;
        
    }
    for (int i = 0; i < t.size(); ++i) {
        stat_map[t[i]]--;
    }
    for (int i = 0; i < sizeof(stat_map)/sizeof(int); ++i) {
        if (stat_map[i] != 0) {
            return i;
        }
    }
    return '\0';

}

char findTheDifference(string s, string t) {
    return find_the_difference(s, t);
}
int main(int argc, char **argv) {
    char ch = findTheDifference(argv[1], argv[2]);
    printf("diff is \%d\t%c\n", ch, ch);
    return 0;
}
