class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i = 0;i < n;i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                int prevDay = s.top();
                s.pop();
                ans[prevDay] = i - prevDay;
            }
            s.push(i);
        }
        return ans;
    }
};