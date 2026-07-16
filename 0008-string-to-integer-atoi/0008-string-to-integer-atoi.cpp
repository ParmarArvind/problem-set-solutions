class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' ') i++;
        bool isPositive=true;
        int j=i;
        long long num=0L;
        while(i<n)
        {

            if(i==j && s[i]=='-') isPositive=false;
            else if(i==j && s[i]=='+') isPositive=true;
            else if(s[i]>='0' && s[i]<='9') {
                num=num*10+s[i]-'0';
            }
            else break;
            i++;
            if(num>pow(2,31)) break;

        }
        if(!isPositive) num=-num;

        if(num < -1*pow(2,31)) return -1*pow(2,31);
        if(num > pow(2,31)-1) return pow(2,31)-1;

        return num;

    }
};