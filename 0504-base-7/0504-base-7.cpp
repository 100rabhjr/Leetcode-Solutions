class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }
        bool isNegative = num < 0;
        num = abs(num);
        string s="";
        while(num != 0){
            s += to_string(num%7);
            num=num/7;
        }
        if(isNegative){
            s += "-";
        }
        reverse(s.begin(),s.end());
        return s;
    }
};