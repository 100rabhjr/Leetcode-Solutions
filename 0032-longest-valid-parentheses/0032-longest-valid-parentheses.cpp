class Solution {
public:
    int longestValidParentheses(string s) {
     stack<char> st;
    stack<int> prev_counts;
    int count = 0;
    int max_count = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
            prev_counts.push(count); 
            count = 0;               
        }
        else if(s[i] == ')' && st.empty()) {
            count = 0;
        }
        else if(s[i] == ')' && !st.empty()) {
            count += 2 + prev_counts.top(); 
            prev_counts.pop();
            max_count = max(count, max_count);
            st.pop();
        }
    }
    return max_count;
    }
};