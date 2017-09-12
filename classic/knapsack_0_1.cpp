#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> item;
/*					
                     +----------------------------------------------------+
                     | dp[weight - items[i].weight][i-1] + items[i].price |
 dp[weight][i] = max |                                                    |
                     | items[weight][i-1])                                |
                     +----------------------------------------------------+
*/

int bag(vector<item> &items, int capacity) {
	int len = items.size();
	vector<int> dp(capacity + 1, 0);
	for(int i = 0; i<len; ++i){
		for(int j = capacity; j >= 0; --j) {
			if(items[i].first <= j) {
				dp[j] = max(dp[j], dp[j - items[i].first] + items[i].second);
			}
		}
	}
	return dp[capacity];
}

int main() {
	vector<item> items;
	for(int i = 0; i < 3; ++i) {
		int weight = rand() % 10 + 1;
		int price = rand() % 10;
		items.push_back(item(weight, price));
		cout << "item: " << i << " weight: " << weight << " price: " << price << endl;
	}
	int capacity = 5; 
	cout << "capacity: " << capacity << endl;
	cout << "max price: " << bag(items, capacity) << endl;
}
