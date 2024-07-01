class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st; // To store the index of ele
        vector<int> result(n);

        for(int i = n - 1 ; i >= 0 ; i--){

            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                //if curr ele is greater than pop it
                st.pop();
            }

            if(st.empty()){
                //No greater element so --> zero days
                result[i] = 0;
            }
            else{
                //otherwise top index - curr index
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};
