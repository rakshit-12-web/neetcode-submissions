class Solution {
public:
    int evalRPN(vector<string>& t) {

        stack<int> st;

        for(int i=0;i<t.size();i++){

            if(t[i]=="+"||t[i]=="-"||t[i]=="*"||t[i]=="/"){

                int val1=st.top();
                st.pop();

                int val2=st.top();
                st.pop();

                int result=0;

                if(t[i]=="+")
                    result=val2+val1;
                else if(t[i]=="-")
                    result=val2-val1;
                else if(t[i]=="*")
                    result=val2*val1;
                else
                    result=val2/val1;

                st.push(result);
            }
            else{
                st.push(stoi(t[i]));
            }
        }

        return st.top();
    }
};