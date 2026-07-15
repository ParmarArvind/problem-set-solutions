class StockSpanner {
public:
    vector<int> arr;
    int i;
    stack<int> st;

    StockSpanner() {
        i = 0;
    }

    int next(int price) {

        while (!st.empty() && arr[st.top()] <= price)
            st.pop();

        int ans;

        if (st.empty()) ans = i + 1;
        else  ans = i - st.top();

        arr.push_back(price);
        st.push(i);
        i++;

        return ans;
    }
};