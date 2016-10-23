

#include <string>
#include <stdio.h>
using namespace std;

string get_next_string(const string& str)
{
	string next;
	char ch= str[0];
	int count = 0;
	char buf[128];
	for(int i = 0; i <= str.size(); ++i) {
		if (ch != str[i]) {
			int len = snprintf(buf, sizeof(buf), "%d%c", count, ch);
			next.append(buf, len);
			ch = str[i];
			count = 1;
		} else {
			++count;
		}
	}
	return next;
}
string countAndSay(int n) {
	string ret = "1";
	for(int i  = 1 ; i < n; ++i) {
		printf("i = %d\t%s\n", i, ret.c_str());
		ret = get_next_string(ret);

	}
	return ret;
}
int main(int argc, char **argv) {
	countAndSay(10);
	return 0;
}



