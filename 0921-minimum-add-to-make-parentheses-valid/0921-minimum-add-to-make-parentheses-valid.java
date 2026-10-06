class Solution {
    public int minAddToMakeValid(String s) {
        int open=0;
        int close=0;
        int i=0;
        int result=0;
        while(i<s.length())
        {
            if(s.charAt(i)=='(') {
                result +=close;
                close=0;
                open++;
            }
            else{
                if(open>0) open--;
                else close++;
            }
            i++;
        }
        result+= open +close;
        return result;
    }
}