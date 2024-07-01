class Solution {
public:
    string simplifyPath(string path) {
        string token ;
        stringstream ss(path);
        string result = "";
        stack<string> st;

        while(getline(ss,token,'/')){

            //Nothing to do --> Move forward
            if(token == ""  || token == ".") continue;

            //If .. --> pop it else push
            if(token != ".."){
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        if(st.empty())
            return "/";

        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};
