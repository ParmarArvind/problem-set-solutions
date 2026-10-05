class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int>score;
        score.push(0);
        int i=0;
 
        while(i<s.size())
        {
            if(s[i]=='(') {
                score.push(0);
            }
            else {
                int top=score.top();
                score.pop();

                int value;
                if(top==0){
                    value= 1;
                }else{
                     value= 2*top;
                }

                score.top() += value;
            }

            i++;
        }

        return score.top();
    }
};