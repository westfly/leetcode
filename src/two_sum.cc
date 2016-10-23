#include "code_utils.h"


/*暴力方法超时*/
vector<int> two_sum_force(vector<int> &numbers, int target)
{
	vector<int> index;
	for(int i = 0; i < numbers.size(); ++i) {
		for(int j = i + 1; j < numbers.size(); ++j) {
			if (numbers[i] + numbers[j] == target) {
				index.push_back(i + 1);
				index.push_back(j + 1);
			}
		}
	}
	return index;
}
#include <unordered_map>
vector<int> two_sum_hash(vector<int> &numbers, int target)
{
    vector<int> index;
	std::unordered_map<int, int> hashmap;
	for(int i = 0; i < numbers.size(); ++i) {
		int curr = numbers[i];
		if (hashmap.find(curr) == hashmap.end())
		{
			hashmap[target - curr] = i + 1;
			continue;
		}
		index.push_back(hashmap[curr]);
		index.push_back(i + 1);
	}
	return index;
}
vector<int> two_sum_sort(vector<int> &numbers, int target) {
	vector<int> index;
	sort(numbers.begin(), numbers.end());
	int begin = 0;
	int end = number.size();
	while (begin < end) {
		int sum = numbers[begin] + numbers[end - 1];
		if (sum < target) {
			++begin;
		} else if (sum > target) {
			--end;
		} else {
			index.push(begin);
		}
	}
	return index;
}
vector<int> twoSum(vector<int> &numbers, int target)
{


}

int main(int argc, char* argv[]) {

	return 0;
}
