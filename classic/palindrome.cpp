#include <iostream>
#include <vector>

// 1. Add redundant characters. aaa -> "$#a#a#a#^", tmpStr[2 * i + 2] = str[i].
// 2. Compute the longest palindrome substring centering at each i.
// 3. Find the center and length of the longest palindrome substring.
// 3. Map to the original string, return the result, startPos = (mIdx - maxLen) / 2; Len = maxPd.
using namespace std;
string LongestPalindromeSubstring(const string& s) {
	int len = s.size();
	if(!len) return "";
	
	int tLen = 2 * len + 3;
	string str(tLen, '#');
	str[0] = '$';
	str[tLen - 1] = '^';
	
	vector<int> pd(tLen, 0);
	for(int i = 0; i < len; ++i)
		str[i * 2 + 2] = s[i];

	int mIdx = -1, maxLen = -1;
	int idx = 0, mx = 0;
	for(int i = 1; i < tLen; ++i) {
		pd[i] = i < mx? min(pd[2 * idx - i], mx - i): 0;
		while(str[i + pd[i] + 1] == str[i - pd[i] - 1]) ++pd[i];
		if(i + pd[i] > mx) {
			mx = i + pd[i];
			idx = i;
		}
		if(pd[i] > maxLen) {
			mIdx = i;
			maxLen = pd[i];
		}
	}
	
	return s.substr((mIdx - maxLen) / 2, maxLen);
}


int main() {
	cout << LongestPalindromeSubstring("abba") << endl;
}
