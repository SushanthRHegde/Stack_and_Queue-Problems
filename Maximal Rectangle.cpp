#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int histogram(vector<int>& arr) {
        int n = arr.size();
        vector<int> PSE(n);  // Previous Smaller Element
        vector<int> NSE(n);  // Next Smaller Element
        stack<int> st;

        // Calculate Previous Smaller Element (PSE) for each element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            PSE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear the stack for reuse
        while (!st.empty()) st.pop();


        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate the maximum area using heights and widths
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = NSE[i] - PSE[i] - 1;
            maxi = max(maxi, arr[i] * width);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> preSum(n, 0);

        int maxArea = 0;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j] == '1'){
                    preSum[j] ++;
                }
                else preSum[j] = 0;
            }
            maxArea = max(maxArea, histogram(preSum));

        }

        return maxArea;
    }
};
