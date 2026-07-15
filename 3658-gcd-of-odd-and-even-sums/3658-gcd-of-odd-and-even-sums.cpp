class Solution {
public:
    int GCD(int a,int b)
    {
        if(a==0) return b;
        return GCD(b%a,a);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int evenSum=n*(n+1);
        return GCD(evenSum%oddSum,oddSum );
    }
};