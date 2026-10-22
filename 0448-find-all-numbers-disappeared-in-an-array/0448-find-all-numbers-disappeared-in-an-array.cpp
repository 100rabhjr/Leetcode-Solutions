class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans;
       vector<int> arr(n+1,0);
       for(int i = 0;i < n;i++){
        arr[nums[i]]++;
       } 
       for(int i = 1;i <= n;i++){
        if(arr[i] == 0){
            ans.push_back(i);
        }
       }
       return ans;
    }
};