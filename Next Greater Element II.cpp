class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> NGE(n);
        stack<int> st;

        vector<int> circular(2*n);
        for(int i = 0; i < n ;i++){
            circular[i] = nums[i];
            circular[i+n] = nums[i];
        }
        // Or we can use Hypothetical extended using (i%n)

        for(int i = 2*n - 1; i >=0 ; i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                if(st.empty())
                    NGE[i] = -1;
                else 
                    NGE[i] = st.top(); 
            }
            st.push(nums[i%n]);
        }
        return NGE;
    }
};
