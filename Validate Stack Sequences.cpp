class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        int n = pushed.size(); //both array has same length
        int i = 0 , j = 0;
        stack<int> st;

        while( i < n && j < n ){
            //Push each pushed ele into the stack
            st.push(pushed[i]);

            //if the popped ele equals to top then pop it until j < n
            while(!st.empty() && j < n && popped[j] == st.top()){
                st.pop();
                j++;
            }
            i++;
        }
        //if each ele is popped out --> empty ( sequence is True )
        return st.empty();
    }
};
