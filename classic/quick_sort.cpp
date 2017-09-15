#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

void quickSort(vector<int> &nums, int start, int end) {
	if(start + 1 >= end) {
		return;
	}
	int tmp = nums[start];
	int idx = start;
	for(int j = idx + 1; j < end; ++j) {
		if(nums[j] < tmp) {
			swap(nums[++idx], nums[j]);
		}
	}
	swap(nums[start], nums[idx]);	
	quickSort(nums, start, idx);
	quickSort(nums, idx+1, end);
}

int main() {
	srand(time(NULL));
	vector<int> nums;
	for(int i = 0; i < 1000000; ++i)
		nums.push_back(rand()%1000);

	vector<int> t_nums = nums;

	quickSort(nums, 0, nums.size());
	sort(t_nums.begin(), t_nums.end());

	for(int i = 0; i < nums.size(); ++i) {
		if (t_nums[i] != nums[i]) {
			cout << "Check Failed!" << endl;
			break;
		}
	}
	return 0;
}
