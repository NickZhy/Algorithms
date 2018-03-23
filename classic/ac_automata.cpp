#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
  public:
  bool hasWord;
  string wd;
  Node* child[256];
  Node* fail;
  Node(const string& w): child(), fail(NULL), hasWord(false), wd(w) {}
  ~Node() {
    for(Node* p: child)
      delete p;
  }
};

void addStr(Node* root, string& str) {
  string wd = "";
  for(char ch: str) {
    wd += ch;
    if(!root -> child[ch])
      root -> child[ch] = new Node(wd);
    root = root -> child[ch];
  }
  root -> hasWord = true;
}

void buildFail(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(q.size()) {
    Node* curr = q.front(); 
    q.pop();
    for(int ch = 0; ch < 256; ++ch) {
      Node* c = curr -> child[ch];
      if(!c) continue;
      q.push(c);
      Node* tmp = curr -> fail;
      while(tmp && !tmp -> child[ch])
        tmp = tmp -> fail;
      if(!tmp) {
        c -> fail = root;
      } else {
        c -> fail = tmp -> child[ch];
      }
    }
  }
  root -> fail = root;
}

void traverse(Node* root) {
  if(!root) return;
  cout << "+-----------node info-----------" << endl;
  cout << "| word: " << root -> wd << endl;
  cout << "| fail pointer: " << (root -> fail? root -> fail -> wd : "NULL") << endl;
  cout << "| has word: " << root -> hasWord << endl;
  cout << "+-------------------------------" << endl;
  for(Node* c: root -> child)
    traverse(c);
}

void findPattern(Node* root, const string& input) {
  Node* curr = root;
  int i = 0;
  while(i < input.size()) {
    char ch = input[i];
    if(curr -> child[ch]) {
      curr = curr -> child[ch];
      if(curr -> hasWord) {
        string& wd = curr -> wd;
        cout << "match string: \"" << wd << "\" at postion: " << (i + 1 - wd.size()) << endl;
      }
      ++i;
    } else {
      cout << "+----------match info-----------" << endl;
      cout << "| match failed at position: " << i << endl;
      cout << "| already matched: " << curr -> wd << endl;
      cout << "| can reuse: " << curr -> fail -> wd << endl;
      cout << "+-------------------------------" << endl;
      curr = curr -> fail;
      if(curr == root)
        ++i;
    }
  }
}

int main() {
  vector<string> words = {"banana", "apple", "yellow", "wash", "water", "abababa", "application", "apply"};
  string test = "abababababababbbbab";
  Node* root = new Node("");
  for(string& wd: words)
    addStr(root, wd);
  buildFail(root);
  traverse(root);
  findPattern(root, test);
  delete root;
  return 0;
}
