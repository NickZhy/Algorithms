#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>


using namespace std;

void sortFlag(vector<int> &flags) {
	int i,j,k;
	i = j = k = 0;
	while(k < flags.size()) {
		if(flags[k] == 1) {
			swap(flags[k], flags[j++]);
		} else if(flags[k] == 0) {
			swap(flags[k], flags[j]);
			swap(flags[j++], flags[i++]);
		}
		++k;
	}
}

int main() {
	srand(time(NULL));
	
	vector<int> nums;
	for(int i = 0; i < 100; ++i)
		nums.push_back(rand()%3);
	sortFlag(nums);
	for(int i = 0; i < nums.size(); ++i) 
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
