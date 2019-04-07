#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class TreeNode {
  public:
  int avg;
  int top, left, bottom, right;
  TreeNode* leftTop, *rightTop, *rightBottom, *leftBottom;
  TreeNode(int t, int l, int b, int r, int a): top(t), left(l), bottom(b), right(r), avg(a) {
    leftTop = rightTop = rightBottom = leftBottom = NULL;
  }
};

TreeNode* buildTreeSub(Mat& im, int t, int l, int b, int r, double stddevThres) {
  static int count = 0;
  if(t > b || l > r) return NULL;
  
  Scalar mean, stddev;
  Mat roi = im(Rect(Point(l, t), Point(r + 1, b + 1)));
  meanStdDev(roi, mean, stddev);
  
  int color = round(mean[0]);
  TreeNode* root = new TreeNode(t, l, b, r, color);
  if(stddev[0] <= stddevThres) return root;
  
  int verMid = (t + b) / 2, horMid = (l + r) / 2;
  root -> leftTop     = buildTreeSub(im, t, l, verMid, horMid, stddevThres);
  root -> rightTop    = buildTreeSub(im, t, horMid + 1, verMid, r, stddevThres);
  root -> leftBottom  = buildTreeSub(im, verMid + 1, l, b, horMid, stddevThres);
  root -> rightBottom = buildTreeSub(im, verMid + 1, horMid + 1,  b, r, stddevThres);
  return root;
}

TreeNode* buildTree(Mat& im, double stddevThres) {
  return buildTreeSub(im, 0, 0, im.rows - 1, im.cols - 1, stddevThres);
}

void recoverSub(TreeNode* root, Mat& rst) {
  if(!root) return;
  if(!root -> leftTop) {
    Rect roi(Point(root -> left, root -> top), Point(root -> right + 1, root -> bottom + 1));
    rectangle(rst, roi, Scalar(root -> avg), FILLED);
    return;
  }
  recoverSub(root -> leftTop, rst);
  recoverSub(root -> leftBottom, rst);
  recoverSub(root -> rightTop, rst);
  recoverSub(root -> rightBottom, rst);
}

Mat recover(TreeNode* root) {
  int rows = root -> bottom + 1;
  int cols = root -> right + 1;
  Mat rst(rows, cols, CV_8UC1, Scalar(0));
  recoverSub(root, rst);
  return rst;
}

int main() {
  Mat image;
  image = imread("pond.JPG");
  resize(image, image, Size(616, 408));
  imshow("origin", image);

  Mat bgr[3];
  split(image, bgr);

  double stddevThres = 20;
  TreeNode* b = buildTree(bgr[0], stddevThres);
  TreeNode* g = buildTree(bgr[1], stddevThres);
  TreeNode* r = buildTree(bgr[2], stddevThres);

  vector<Mat> ch;
  ch.push_back(recover(b));
  ch.push_back(recover(g));
  ch.push_back(recover(r));

  Mat compressed;
  merge(ch, compressed);
  imshow("compressed", compressed);
  imshow("diff", abs(compressed - image));
  waitKey(0);
  return 0;
}

