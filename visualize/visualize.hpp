#ifndef VISUALIZE_HPP
#define VISUALIZE_HPP

enum class Color: int {
  DFT = 0,
  BLK = 30, 
  RED = 31,
  GRN = 32,
  YEL = 33,
  BLU = 34,
  MAG = 35,
  CYN = 36,
  WHT = 37,
  
  BGBLK = 40, 
  BGRED = 41,
  BGGRN = 42,
  BGYEL = 43,
  BGBLU = 44,
  BGMAG = 45,
  BGCYN = 46,
  BGWHT = 47
};

enum class Style: int {
  DFT  = 0,
  BOLD = 1,
  UNDL = 4,
};

class BinTreeNode;

void showBinTree(BinTreeNode*, Color c = Color::YEL, Style s = Style::BOLD);

class BinTreeNode {
  private:
  int width; // used to compute the position of each node
  static void prepare(BinTreeNode*);
  public:
  friend void showBinTree(BinTreeNode*, Color, Style);
  virtual BinTreeNode* lCh() = 0;
  virtual BinTreeNode* rCh() = 0;
  virtual std::string info() const = 0;
  virtual Color color();
  virtual Style style();
};

#endif
