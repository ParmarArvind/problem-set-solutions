//  (tc= n*logk  ,sc= k)
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int time=0;
        priority_queue<pair<int,int> ,
                        vector<pair<int,int>>, 
                        greater<pair<int,int>>>pq;
        int n=arrival.size();
        set<int>st;
        for(int i=0;i<k;i++) st.insert(i);

        vector<int>usedCount(k,0);
        for(int i=0;i<n;i++)
        {
            time=arrival[i];
            while(!pq.empty() && time>= pq.top().first)
            {
                st.insert(pq.top().second);
                pq.pop();
            }

            // for(int j=i;j<i+k;j++)
            // {
            //     if(st.size()==0) break;

            //     if(st.find((j+k)%k)!=st.end()){
            //         pq.push({time+load[i] , (j+k)%k});
            //         st.erase((j+k)%k);
            //         usedCount[(j+k)%k]++;
            //         break;
            //     }
                
            // }

            int target=i%k;

            auto it=st.lower_bound(target);

            if(it==st.end()) {
                it=st.begin();
            }
            if(st.empty()) continue;

            int server=*it;
            usedCount[server]++;
            pq.push({time + load[i] ,server});
            st.erase(it);
        }

        int maxCount=*max_element(usedCount.begin(),usedCount.end());
        vector<int>result;
        for(int i=0;i<k;i++){
            if(maxCount==usedCount[i]) result.push_back(i);
        }

        return result;
    }
};