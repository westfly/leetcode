#include <stdio.h>
#include "code_utils.h"

bool is_anagram(const string& s, const string& t) {
  if (s.size() != t.size())
  {
    return false;
  }
  char char_map[256] = {0};
  for (int i = 0; i < t.size(); ++i) {
    char_map[s[i]]++;
    char_map[t[i]]--;
  }
  for (int i = 0; i < t.size(); ++i) {
    if (char_map[t[i]] != 0) {
      return false;
    }
  }
  return true;
}
bool isAnagram(string s, string t) {
  return is_anagram(s, t);
}

int main(int argc, char* argv[])
{
    bool anagram = isAnagram("abc", "cba");
    printf("%d\n", anagram);
    return 0;
}

