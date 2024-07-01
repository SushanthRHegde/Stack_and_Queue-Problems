class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        vector<int> ans;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push(asteroids[i]);
            } 
            else {
                // pop the ele until top ele > curr ele
                while(!st.empty()  && st.top() > 0 &&
                       st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop(); // Both asteroids are destroyed ( equal) --> again pop
                } else if (st.empty() || st.top() < 0) {
                    //if first is -ve 
                    st.push(asteroids[i]);
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
