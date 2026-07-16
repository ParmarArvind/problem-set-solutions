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


// class Solution {
// public:
//     int myAtoi(string s) {
//         long long result = 0;
//         bool flag = 0;     // number started
//         bool signSeen = 0; // sign seen
//         int sign = 1;      // default positive

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == ' ' && flag == 0 && signSeen == 0) continue;

//             if (flag == 0 && signSeen == 0 && (s[i] == '-' || s[i] == '+')) {
//                 signSeen = 1;
//                 if (s[i] == '-') sign = -1;
//                 continue;
//             }

//             int value = s[i] - '0';
//             if (value >= 0 && value < 10) {
//                 flag = 1;
//                 result = result * 10 + value;

//                 // Check bounds with sign applied
//                 if (sign * result < INT_MIN) return INT_MIN;
//                 if (sign * result > INT_MAX) return INT_MAX;
//             } else {
//                 break;
//             }
//         }

//         return (int)(sign * result);
//     }
// };