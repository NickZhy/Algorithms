#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, char> cell;

map<char, map<char, bool> > priority = {
	{'+', {{'+', true }, {'-', true }, {'*', false}, {'/', false}, {'%', false}, {'^', false}, {'!', false}, {'N', false}, {'P', false}, {'(', false}}}, 
	{'-', {{'+', true }, {'-', true }, {'*', false}, {'/', false}, {'%', false}, {'^', false}, {'!', false}, {'N', false}, {'P', false}, {'(', false}}},
	{'/', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', false}, {'!', false}, {'N', false}, {'P', false}, {'(', false}}},
	{'%', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', false}, {'!', false}, {'N', false}, {'P', false}, {'(', false}}},
	{'^', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', true }, {'!', false}, {'N', false}, {'P', false}, {'(', false}}},
	{'!', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', true }, {'!', true }, {'N', false}, {'P', false}, {'(', false}}},
	{'N', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', true }, {'!', true }, {'N', false}, {'P', false}, {'(', false}}},
	{'P', {{'+', true }, {'-', true }, {'*', true }, {'/', true }, {'%', true }, {'^', true }, {'!', true }, {'N', false}, {'P', false}, {'(', false}}},
	{'(', {{'+', false}, {'-', false}, {'*', false}, {'/', false}, {'%', false}, {'^', false}, {'!', false}, {'N', false}, {'P', false}, {'(', false}}},
};

bool isOp(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch =='%' || ch == '^' || ch == '!' || ch == '(' || ch == ')';
}

bool isNum(char ch) {
	return '0' <= ch && ch <= '9';
}

int readNum(string& str, int& idx) {
	int num = 0;
	while(idx < str.size() && isNum(str[idx])) {
		num *= 10;
		num += str[idx++] - '0';
	}
	return num;
}

void pushStk(vector<cell>& stk, int num, char op) {
	if(op == ' ') 
		stk.push_back(cell(num, ' '));
	else
		stk.push_back(cell(0, op));
}

vector<cell> reversePolish(string str) {
	int len = str.size();
	if(!len) return vector<cell>(); 
	vector<cell> stk;
	vector<char> opStk;
	int idx = 0;
	bool isLastOp = true; // record whether the last readed symbol is operation. So we can find minus and nagetive.
	while(idx < len) {
		if(isNum(str[idx])) {
			stk.push_back(cell(readNum(str, idx), ' '));
			isLastOp = false;
		} else if(isOp(str[idx])) {
			char op = str[idx++];
			if(isLastOp && (op == '+' || op == '-')) {
				op = (op == '+'? 'P': 'N');
			}
			if(op == ')') {
				while(opStk.size() && opStk.back() != '(' ) {
					pushStk(stk, 0, opStk.back());
					opStk.pop_back();
				}
				if(opStk.size()) opStk.pop_back();
			} else {
				while(opStk.size() && priority[opStk.back()][op]) {
					pushStk(stk, 0, opStk.back());
					opStk.pop_back();
				}
				opStk.push_back(op);
			  isLastOp = true;
			}
		}
	}
	while(opStk.size()) {
		pushStk(stk, 0, opStk.back());
		opStk.pop_back();
	}
	return stk;
}

void printStack(vector<cell> stk) {
	for(cell c: stk) {
		if(c.second == ' ')
			cout << c.first << " ";
		else
			cout << c.second << " ";
	}
	cout << endl;
}

int main() {
	vector<cell> rp =  reversePolish("(1)-(2%5)");
	printStack(rp);
	return 0;
}
