/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 1) {
            return points.size();
        }

        int max = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            map<double, int> count;
            int vertLine = 0;
            int samePos = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].y != points[j].y) {
                    double q = double(points[i].x-points[j].x)/double(points[i].y-points[j].y);
                    ++count[q];
                } else if (points[i].x != points[j].x) {
                    ++vertLine;
                } else {
                    ++samePos;
                }
            }

            for(auto x = count.begin(); x != count.end(); ++x) {
                if (x->second + samePos + 1 > max) {
                    max = x->second + samePos + 1;
                }
            }
            if (vertLine + samePos + 1 > max) {
                max = vertLine + samePos + 1;
            }
        }
        return max;
    }
};
