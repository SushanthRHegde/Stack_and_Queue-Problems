class Solution {
public:
    string reverseParentheses(string s) {
        //for keeping last skip length
        stack<int> lastLength;
        int n = s.size();
        string res = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                lastLength.push(res.length());
            }
            else if(s[i] == ')'){
                //revesring the string 
                int l = lastLength.top(); lastLength.pop();
                reverse(res.begin()+l,res.end());
            }
            else res.push_back(s[i]);
        }
        return res;
    }
}; 
