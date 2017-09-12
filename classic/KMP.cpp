#include <iostream>
#include <string>
#include <vector>

using namespace std;

void buildTable(string& word, vector<int>& table) {
	int len = word.size();
	table = vector<int>(len, 0);
	int pos = 1, preSuffMax = 0;
	while(pos < len) {
		while(preSuffMax > 0 && word[pos] != word[preSuffMax]) {
			preSuffMax = table[preSuffMax - 1];
		}
		if(word[pos] == word[preSuffMax]) {
			++preSuffMax;
		}
		table[pos++] = preSuffMax;
	}
}

int match(string& str, string& word) {
	vector<int> table;
	buildTable(word, table);

	int pos = 0, offset = 0;
	while(pos + offset < str.size()) {
		if(str[pos + offset] == word[offset]) {
			++offset;
			if(offset == word.size())
				return pos;
		} else {
			if(offset > 0) {
				pos = pos + offset - table[offset - 1];
				offset = table[offset - 1];
			} else {
				++pos;
			}
		}
	}
	return -1;
}

int main() {
	string str = "ababad";
	string word = "ababad";
	cout << match(str, word) << endl;
	return 0;
}
