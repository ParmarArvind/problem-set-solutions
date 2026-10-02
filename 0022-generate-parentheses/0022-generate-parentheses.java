class Solution {
    public Boolean valid(StringBuilder st ,int n)
    {
        int i=0;
        
        int open=0;
      
        while(i<n){
            if(open<0) return false;

            if(st.charAt(i)=='(') open++;
            else open--;
            i++;
        }
        return open==0 ? true :false;
    }
    public void solve(int n, StringBuilder st ,  List<String> result)
    {
        
        if(st.length() == 2*n){
            if(valid(st,2*n)) result.add(st.toString());
            return ;
        }

        st.append('(');
        solve(n ,st, result);
        st.deleteCharAt(st.length()-1);


        st.append(')');
        solve(n ,st, result);
        st.deleteCharAt(st.length()-1);
    }

    public List<String> generateParenthesis(int n) {

        List<String> result=new ArrayList<>();
        StringBuilder st=new StringBuilder("");
        solve(n,st,result);
        return result;

    }
}