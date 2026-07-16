class Solution {
public:
    int num(char c)
    {
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
    return 1000;
    }
    int romanToInt(string s) 
    {
        int ans=0;
        int i=0;
       while(i<s.size()-1)
       {
        if(num(s[i])<num(s[i+1]))
            ans-=num(s[i]);
        else
            ans += num(s[i]);

        i++;
       }
        ans += num(s[s.size()-1]);

    return ans;


    }
};