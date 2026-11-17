class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>m;
         for (int i = 0; i < s.size(); i++) {
        m[s[i]] = i; 
    }
    
    unordered_set<char> visited; 
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (visited.count(s[i])) continue; 
        while (!ans.empty() && ans.back() > s[i] && i < m[ans.back()]) {
            visited.erase(ans.back());
            ans.pop_back();
        }
        
        ans.push_back(s[i]);
        visited.insert(s[i]);
    }
    
    return ans;
    }
};