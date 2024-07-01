class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        string ans;

        for(int i = 0; i < n ; i++){
            //If star occur , dont push it and pop previous charecter
            if(s[i] == '*'){
                st.pop();
            }
            //otherwise pop the previous charecter
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
