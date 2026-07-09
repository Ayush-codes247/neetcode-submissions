class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0;
        vector<int> ans;
        for(i = 0; i < nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() < i - k + 1){
                dq.pop_front();
            }
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
