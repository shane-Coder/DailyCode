class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char ch : expression) {
            if (ch == ',' || ch == '(')
                continue;  

            if (ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|') {
                st.push(ch);
            }
            else if (ch == ')') {
                bool flag = false, seek = false;
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') flag = true;
                    if (val == 'f') seek = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(flag ? 'f' : 't');
                } else if (op == '&') {
                    st.push(seek ? 'f' : 't');
                } else {
                    st.push(flag ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};