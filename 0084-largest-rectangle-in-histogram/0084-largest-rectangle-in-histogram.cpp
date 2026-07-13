class Solution {
public:
    void findNSL(vector<int>&height ,vector<int>&NSL)
    {
        stack<int>st;
        int n=height.size();
        for(int i=0;i<n;i++)
        {
            if(st.empty()) {
                NSL[i]=-1;
            }
            else{
                while(!st.empty() && height[st.top()] >= height[i]) st.pop();

                if(st.empty()) NSL[i]=-1;
                else NSL[i]=st.top();
            }
            st.push(i);
        }

    }
    void findNSR(vector<int>&height ,vector<int>&NSR)
    {
        stack<int>st;
        int n=height.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty()) {
                NSR[i]=n;
            }
            else{
                while(!st.empty() && height[st.top()] >= height[i]) st.pop();

                if(st.empty()) NSR[i]=n;
                else NSR[i]=st.top();
            }
            st.push(i);
        }

    }
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
        vector<int>NSL(n);
        vector<int>NSR(n);

        findNSL(height,NSL);
        findNSR(height,NSR);

        int result=0;
        for(int i=0;i<n;i++)
        {
            int width=NSR[i]-NSL[i]-1;
            int area=width*height[i];
            result=max(area,result);
        }

        return result;


    }
};