#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "visualize.hpp"
using namespace std;

const int START_POS = 4;
const int MIN_DIST = 2;
const char* LC = "\u256D";
const char* RC = "\u256E";
const char* HB = "\u2500";
const char* LB = "\u23A0";
const char* RB = "\u239D";
const char* CS = "\u2534";

//Default color, green :)
Color BinTreeNode::color() {
  return Color::GRN;
}
// Default style, bold :)
Style BinTreeNode::style() {
  return Style::BOLD;
}

void BinTreeNode::prepare(BinTreeNode* root) {
  if(!root) return;
  BinTreeNode *l = root -> lCh(), *r = root -> rCh();
  prepare(l);
  prepare(r);
  int infoWid = root -> info().size();
  if(!l && !r) {
    root -> width = infoWid;
  } else if(!l) {
    root -> width = max(r -> width, infoWid);
  } else if(!r){
    root -> width = max(l -> width, infoWid);
  } else {
    root -> width = max(l -> width + r -> width + MIN_DIST, infoWid);
  }
}

BinTreeNode::~BinTreeNode() {}

class triplet {
  public:
  int offset, level;
  BinTreeNode* node;
  triplet(int off, int lev, BinTreeNode* n) {
    offset = off;
    level = lev;
    node = n;
  }
};

// fxxk unicode 
void fillTo(string& buff, int& startPos, int endPos, const char* ch) {
  while(startPos < endPos) {
    buff += ch;
    ++startPos;
  }
}

void addStyle(string& buf, Color color, Style style) {
  int c = int(color);
  int s = int(style);
  if(c != 0)
    buf += "\033[" + to_string(c) + "m";
  if(s != 0)
    buf += "\033[" + to_string(s) + "m";
}

void rmStyle(string& buf) {
  buf += "\033[0m";
}

void showBinTree(BinTreeNode* root, Color color, Style style) {
  if(!root) return;
  BinTreeNode::prepare(root);

  queue<triplet> q;
  q.push(triplet(START_POS, 0, root));

  string buff1 = "", buff2 = "";
  int pos1 = 0, pos2 = 0, currLevel = 0;
  while(q.size()) {
    triplet tp = q.front(); q.pop();

    // print the result of last level
    if(tp.level > currLevel) {
      cout << buff1 << endl << buff2 << endl;
      buff1.clear();  buff2.clear();
      pos1 = pos2 = 0;
      ++currLevel;
    }

    BinTreeNode* curr = tp.node;
    string info = curr -> info();

    //draw the node
    int printPos = tp.offset + (curr -> width - info.size()) / 2;
    fillTo(buff1, pos1, printPos, " ");
    addStyle(buff1, curr -> color(), curr -> style());
    buff1 += info;
    rmStyle(buff1);
    pos1 += info.size();

    //draw the edge
    BinTreeNode *l = curr -> lCh(), *r = curr -> rCh();
    if(!l && !r) continue;
    int currWidth = curr -> width;
    int mPos = tp.offset + (currWidth - 1) / 2;
    if(l && r) {
      int lWidth = l -> width, rWidth = r -> width;
      int lPos = tp.offset + (lWidth - 1) / 2;
      int rPos = tp.offset + currWidth - 1 - rWidth / 2;

      fillTo(buff2, pos2, lPos, " ");
      // draw double sided edge
      addStyle(buff2, color, style);
      buff2 += LC;  ++pos2;
      fillTo(buff2, pos2, mPos, HB); 
      buff2 += CS;  ++pos2;
      fillTo(buff2, pos2, rPos, HB);  
      buff2 += RC;  ++pos2;
      rmStyle(buff2);

      q.push(triplet(tp.offset, tp.level + 1, l));
      q.push(triplet(tp.offset + currWidth - rWidth, tp.level + 1, r));
    } else if(l) {
      int lWidth = l -> width;
      fillTo(buff2, pos2, mPos, " "); 
      //draw left edge
      addStyle(buff2, color, style);
      buff2 += LB;  
      rmStyle(buff2);
      
      ++pos2;
      q.push(triplet(tp.offset + (currWidth - lWidth + 1) / 2, tp.level + 1, l));
    } else {
      int rWidth = r -> width;
      fillTo(buff2, pos2, mPos, " "); 
      //draw right edge
      addStyle(buff2, color, style);
      buff2 += RB;
      rmStyle(buff2);
      ++pos2;
      q.push(triplet(tp.offset + (currWidth - rWidth + 1) / 2, tp.level + 1, r));
    }
  }
  // print the last level
  cout << buff1 << endl << buff2 << endl;
}
