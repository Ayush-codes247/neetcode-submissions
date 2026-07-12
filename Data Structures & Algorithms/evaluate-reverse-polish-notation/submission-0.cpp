class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                string s = tokens[i];
                if(s == "+"){
                    st.push(op2 + op1);
                }else if (s == "-"){
                    st.push(op2 - op1);
                }else if(s == "*"){
                    st.push(op2 * op1);
                }else{
                    st.push(op2/op1);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
