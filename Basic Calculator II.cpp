class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int number = 0;
        char op = '+';
        
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            //If its digit --> make number 
            if (isdigit(ch)) {
                number = (number * 10) + (ch - '0');
            }
            
            // If the character is an operator or the last character in the string
            if ((!isdigit(ch) && !isspace(ch)) || i == n - 1) {
                if (op == '+') {
                    st.push(number);
                } else if (op == '-') {
                    st.push(-number);
                } else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * number);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / number);
                }
                op = ch;
                number = 0;
            }
        }
        
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

