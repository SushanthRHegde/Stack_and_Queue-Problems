class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        int number = 0 , result = 0 , sign = 1;

        for(int i = 0 ; i < n ; i++){
            //If it is digit --> make number
            if(isdigit(s[i])){
                number = (number * 10) + ( s[i] - '0' );
            }
            // + --> add to result , num as 0 & sign as 1 (+ve)
            else if(s[i] == '+'){
                result += (number * sign);
                number = 0;
                sign = 1;

            }
            // - --> add to result , num as 0 & sign as -1 (-ve)
            else if( s[i] == '-' ) {
                result += (number * sign);
                number = 0;
                sign = -1;
            }
            // ( --> push result and sign to stack , make res , num as 0 and sign as 1
            else if ( s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            // ) --> add the result , multiply by last_sign & add last_res
            else if( s[i] == ')'){
                result += (number * sign );
                number = 0;
                int last_sign = st.top(); st.pop();
                int last_res = st.top(); st.pop();
                result *= last_sign ;
                result += last_res ;
            }
        }
        // Left out numbers are added into the result
        result += ( number * sign );
        return result;
    }
};
