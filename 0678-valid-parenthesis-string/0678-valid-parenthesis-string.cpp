class Solution {
public:
    bool checkValidString(string s) {
        int op = 0;
        int cl = 0;
        for(char ch : s){
            if(ch == '('){
                op++;cl++;
            }
            else if(ch == ')'){
                op = max(0,op-1);
                cl--;
            }
            else {
                op = max(0,op-1);
                cl++;
            }
            if(cl < 0){
                return false;
            }
        }
        return op == 0;
    }
};