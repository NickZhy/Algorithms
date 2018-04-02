#ifndef VISUALIZE_HPP
#define VISUALIZE_HPP

class BinTreeNode {
  private:
  int width; // used to compute the position of each node
  static void prepare(BinTreeNode*);
  public:
  friend void showBinTree(BinTreeNode*);
  virtual BinTreeNode* lCh() = 0;
  virtual BinTreeNode* rCh() = 0;
  virtual std::string info() const = 0;
};

#endif
