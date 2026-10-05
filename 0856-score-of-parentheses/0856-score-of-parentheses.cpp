class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);

        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }
      
        else {
    int x = st.top();
    st.pop();

    int score;

    if (x == 0) {
        score = 1;
    } else {
        score = 2 * x;
    }

    int parent = st.top();
    parent = parent + score;

    st.pop();
    st.push(parent);
}
        }
return st.top();

    }
};