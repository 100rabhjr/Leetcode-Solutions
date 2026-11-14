class Solution {
public:
    string removeDuplicates(string s, int k) {
          stack<pair<char,int>> st;
        string r;
        for(int i = 0;i < s.size();i++){
            if(st.empty()){
                st.push({s[i],1});
            }else if(st.top().first == s[i]){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }else{
                st.push({s[i],1});
            }
        }
        while(!st.empty()){
            int count = st.top().second;
            char ch = st.top().first;
            while(count != 0){
          r.push_back(ch);
          count--;
          }
          st.pop();
        }
        reverse(r.begin(),r.end());
        return r;
    }
};