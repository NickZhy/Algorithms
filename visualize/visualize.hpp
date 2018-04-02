#ifndef VISUALIZE_HPP
#define VISUALIZE_HPP

class BinTreeNode {
  private:
  int width;
  friend void prepare(BinTreeNode*);
  friend void showBinTree(BinTreeNode*);
  public:
  virtual BinTreeNode* lCh() = 0;
  virtual BinTreeNode* rCh() = 0;
  virtual std::string info() const = 0;
};

#endif
