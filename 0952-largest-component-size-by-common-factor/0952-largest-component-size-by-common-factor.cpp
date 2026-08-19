class Solution {
public:

    int largestComponentSize(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> parent;
        unordered_map<int, int> sz;

        // Initially every number is its own parent
        for (int num : nums) {
            parent[num] = num;
            sz[num] = 1;
        }

        // Find with Path Compression
        function<int(int)> find = [&](int x) {

            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        };

        // Union by Size
        auto unite = [&](int u, int v) {

            u = find(u);
            v = find(v);

            if (u == v)
                return;

            if (sz[u] < sz[v])
                swap(u, v);

            parent[v] = u;
            sz[u] += sz[v];
        };

        // factor -> first number having this factor
        unordered_map<int, int> factorOwner;

        // Build connected components
        for (int num : nums) {
            for (int i = 2; i * i <= num; i++) {

                if (num % i == 0) {

                    // Factor i
                    if (factorOwner.count(i)) {
                        unite(num, factorOwner[i]);
                    } else {
                        factorOwner[i] = num;
                    }

                    // Factor num / i
                    int other = num / i;
                    if (other != i) {
                        if (factorOwner.count(other)) {
                            unite(num, factorOwner[other]);
                        } else {

                            factorOwner[other] = num;
                        }
                    }
                }
            }

            // num itself can be a prime factor
            if (num > 1) {
                if (factorOwner.count(num)) {
                    unite(num, factorOwner[num]);
                } else {
                    factorOwner[num] = num;
                }
            }
        }

        // Find largest component
        int ans = 0;
        for (auto& it : sz) {
            int x = it.first;
            if (find(x) == x) {
                ans = max(ans, sz[x]);
            }
        }

        return ans;
    }
};