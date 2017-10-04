#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

string cutZero(string a) {
	int i = 0;
	while(a[i] == '0' && i < a.size())
		++i;
	if(i == a.size())
		return "0";
	return a.substr(i);
}

string negtive(string a) {
	if(a[0] == '-')
		return a.substr(1);
	return "-" + a;
}

string addPositive(string a, string b) {
	string str = "";
	int more = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;
	while(i >= 0 || j >= 0) {
		int aDigit = i >= 0 ? a[i--] - '0': 0;
		int bDigit = j >= 0 ? b[j--] - '0': 0;

		str.push_back((aDigit + bDigit + more)%10 + '0');
		more = (aDigit + bDigit + more)/10;
	}
	if(more != 0)
		str.push_back(more+'0');
	reverse(str.begin(), str.end());
	return str;
}

string subPosOF(string& a, string& b) {
	string str = "";
	int more = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;
	while(i >= 0 || j >= 0) {
		int aDigit = i >= 0 ? a[i--] - '0': 0;
		int bDigit = j >= 0 ? b[j--] - '0': 0;

		int tmp = aDigit - bDigit - more;
		if(tmp < 0) {
			tmp += 10;
			more = 1;
		} else {
			more = 0;
		}
		str.push_back(tmp + '0');
	}
	if(more != 0)
		str.push_back('9');
	reverse(str.begin(), str.end());
	return cutZero(str);
}

string subPositive(string a, string b) {
	a = cutZero(a);
	b = cutZero(b);
	if(a.size() > b.size())
		return subPosOF(a, b);
	if(a.size() == b.size()) {
		if(a.compare(b) >= 0)
			return subPosOF(a, b);
		return "-" + subPosOF(b, a);
	}
	return "-" + subPosOF(b, a);
}

string sub(string a, string b) {
	if(a[0] == '-' && b[0] == '-')
		return sub(b.substr(1), a.substr(1));
	if(a[0] == '-')
		return negtive(addPositive(a.substr(1), b));
	if(b[0] == '-')
		return addPositive(a, b.substr(1));
	return subPositive(a, b);
}

string add(string a, string b) {
	if(a[0] == '-' && b[0] == '-')
		return "-" + addPositive(a.substr(1), b.substr(1));
	if(a[0] == '-')
		return subPositive(b, a.substr(1));
	if(b[0] == '-')
		return subPositive(a, b.substr(1));
	return addPositive(a, b);
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 1000; ++i) {
		int a = rand()%100000;
		int b = rand()%100000;
		if (rand()%100 > 50)
			a = -a;
		if (rand()%100 > 50)
			b = -b;
		string c = to_string(a + b);
		string d = to_string(a - b);
		
		string aStr = to_string(a);
		string bStr = to_string(b);
		if(c.compare(add(aStr, bStr)) != 0) {
			cout << "error add:" << a << " + " << b << " = " << add(aStr, bStr) << " not " << c << endl;
			break;
		}
		if(d.compare(sub(aStr, bStr)) != 0) {
			cout << "error sub:" << a << " - " << b << " = " << sub(aStr, bStr) << " not " << d << endl;
			break;
		}
	}
	return 0;
}
