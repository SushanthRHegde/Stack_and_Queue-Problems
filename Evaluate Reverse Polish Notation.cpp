class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            //if the string is operator --> pop two ele do operation and put it in stack
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if (token == "+") {
                    st.push(num1 + num2);
                } else if (token == "-") {
                    st.push(num1 - num2);
                } else if (token == "*") {
                    st.push(num1 * num2);
                } else if (token == "/") {
                    st.push(num1 / num2);
                }
            }
            //If the string is number --> put it into stack  
            else {
                //stoi() --? convert string to integer value
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
