class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> rst;
        for(int i = 0; i < nums.size(); ++i) {
            if(dq.size() && dq.front() <= i - k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) rst.push_back(nums[dq.front()]);
        }
        return rst;
    }
};