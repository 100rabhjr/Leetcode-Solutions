class Solution {
public:
int merge(vector<int>& nums,int st,int mid,int end){
     int count = 0;
        int right = mid + 1;
    
    for (int i = st; i <= mid; i++) {
        while (right <= end && (long long)nums[i] > 2LL * nums[right]) {
            right++;
        }
        count += (right - (mid + 1));
    }
    vector<int> temp;
    int i = st, j = mid+1;
    while(i <= mid && j <= end){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i++]);
        }else {
            temp.push_back(nums[j++]); 
        }
    }
    while(i <= mid){
        temp.push_back(nums[i++]);
    }
    while(j <= end){
        temp.push_back(nums[j++]);
    }
    for(int idx = 0;idx < temp.size();idx++){
        nums[idx+st] = temp[idx];
    }
    return count;
}
int mergeSort(vector<int>& nums,int st,int end){
    if(st < end){
    int mid = st + (end -st)/2;
   int lftInv = mergeSort(nums,st,mid);
   int rgtInv = mergeSort(nums,mid+1,end);
    int invCount = merge(nums,st,mid,end);
    return lftInv+rgtInv+invCount;
    }
    return 0;
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};