//method -3 
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0 ;
        int left=0 ,right=0;
        
        reverse(s.begin(),s.end());
        while(i<n)
        {
            while(i<n && s[i]!=' ')
            {
                s[right]=s[i];
                right++;
                i++;
            }
            if(left<right)
            {
                s[right]=' ';
                right++;
                reverse(s.begin()+left,s.begin()+right-1);
                left=right;
            }
            i++;
        }
        s=s.substr(0,right-1);
        return s;
    }
};


// // method -2
// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream  ss(s);

//         string result="";
//         string token="";

//         while(ss >> token){
//             result = token+ ' '+ result;
//         }

//         return result.substr(0,result.size()-1);// remove the last sapce
        
        
//     }
// };

// // method -1
// class Solution {
// public:
//     string reverseWords(string s) {
//         string ans;
//         int i = s.size() - 1;

//         while (i >= 0) {
//            //skip space in front off string
//             while (i >= 0 && s[i] == ' ') i--;
            
//             if (i < 0) break; 

//             string sub;
//             while (i >= 0 && s[i] != ' ') {
//                 sub.push_back(s[i]);
//                 i--;
//             }

//             reverse(sub.begin(), sub.end());
//             if (!ans.empty()) ans.push_back(' '); // Avoid adding leading space
//             ans.append(sub);
//         }

//         return ans;
//     }
// };
