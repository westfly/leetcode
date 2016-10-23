/**********************************************************************************
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".
**********************************************************************************/
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
string addBinary(const string& a, const string& b) {
	int aLen = a.size();
	int bLen = b.size();
	std::string result;
	int carrier = 0;
	while (aLen || bLen) {
		int aValue = 0;
		int bValue = 0;
		if (aLen) {
			aValue = a[--aLen] - '0';
		}
		if (bLen) {
			bValue = b[--bLen] - '0';
		}
		int sum = aValue + bValue + carrier;
		carrier = sum/2;
		result.push_back(sum%2 + '0');
	}
	if (carrier)
	{
		result.push_back('1');
	}
	std::reverse(result.begin(), result.end());
	return result;
}


int main(int argc, char **argv) {
	std::string a("1");
	string b("111");
	
	printf("%s\n", addBinary(a, b).c_str());
}
