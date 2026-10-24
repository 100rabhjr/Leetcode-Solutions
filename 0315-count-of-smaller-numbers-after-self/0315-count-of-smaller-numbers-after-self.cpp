class Solution {
public:
void merge(vector<int>& nums, int st, int mid, int end, vector<int>& ans, vector<int>& index) {
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) {
        if (nums[index[i]] <= nums[index[j]]) {
            ans[index[i]] += (j - (mid + 1));
            temp.push_back(index[i]);
            i++;
        } else {
            temp.push_back(index[j]);
            j++;
        }
    }
    
    while (i <= mid) {
        ans[index[i]] += (end - mid);
        temp.push_back(index[i]);
        i++;
    }
    
    while (j <= end) {
        temp.push_back(index[j]);
        j++;
    }
    
    for (int idx = 0; idx < temp.size(); idx++) {
        index[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int>& nums, int st, int end, vector<int>& ans, vector<int>& index) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(nums, st, mid, ans, index);
        mergeSort(nums, mid + 1, end, ans, index);
        merge(nums, st, mid, end, ans, index);
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);  
    vector<int> index(n); 
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    mergeSort(nums, 0, n - 1, ans, index);
    return ans;
}
};