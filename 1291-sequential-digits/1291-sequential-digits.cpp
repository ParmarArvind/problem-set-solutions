class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int start = 12;
        int curr = 12;
        int digits = 2;
        int nextDigit = 3;
        int num = 10;
        int decade = 10;

         vector<int> result;
         if(low>123456789) return result;

        while (curr < low) {
            curr = (curr - num) * 10;
            curr += nextDigit;
            nextDigit++;
            num += decade;
            
            if (nextDigit == 10) {
                start *= 10;
                digits++;
                start += digits;
                if(curr >= low) result.push_back(curr);
                curr = start;

                decade *= 10;
                num = decade;
                nextDigit = digits + 1;
            }
        }

       

        while (curr <= high) {
            result.push_back(curr);
            if(curr==123456789) break;
            curr = (curr - num) * 10;
            curr += nextDigit;
            nextDigit++;
            num += decade;
            if (nextDigit == 10) {
                if(curr>high) return result;
                result.push_back(curr);
                
                start *= 10;
                digits++;
                start += digits;
                curr = start;

                decade *= 10;
                num = decade;
                nextDigit = digits + 1;
                
            }
        }

        return result;
    }
};