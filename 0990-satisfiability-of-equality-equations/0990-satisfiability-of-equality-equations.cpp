class Solution {
public:
    vector<int>parent;
    vector<int> rank;
     int find(int x)
    {
        if(x==parent[x]) return x;
        return find(parent[x]);
    }
    void Union(int i ,int j)
    {
        int parent_i=find(i);
        int parent_j=find(j);
        if(parent_i == parent_j) return ;
        if(rank[parent_i] < rank[parent_j]) 
        {
            parent[parent_i] =parent_j;
        }
        else if(parent_i >parent_j)
        {
            parent[parent_j]= parent_i;
        }
        else {
            parent[parent_i]=parent_j;
            rank[parent_j]++;
        }
        
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        
        for(auto &s:equations)
        {
            if(s[1]== '=')
            {
                int x=find(s[0]-'a');
                int y=find(s[3]-'a');

                if(x==y) continue;
                parent[x]=parent[y];
                Union(x,y);
            }
        }

        for(auto &s:equations)
        {
            if(s[1]== '!')
            {
                int x=find(s[0]-'a');
                int y=find(s[3]-'a');

                if(x==y) return false;
            }
        }

    return true;

        
    }
};

// class Solution {
// public:
//     vector<int>parent;
//     vector<int>rank;
//     int find(int x){
//         if(parent[x]==x)return x;
//         //then find  x ke parent ka parent 
//         return parent[x]=find(parent[x]);
//     }
//     void Union(int x,int y)
//     {
//         int x_parent=find(x);
//         int y_parent=find(y);
//         if(x_parent == y_parent) return ;
//     // jiski rank jayda hai use parent bana do 
//         if(rank[y_parent] >rank[x_parent]) 
//         {
//             parent[x_parent] =y_parent;
//         }
//         else if(rank[y_parent] < rank[x_parent])
//         {
//             parent[y_parent] =x_parent;
//         }
//         else{ // same rank hai toh kisi ko bhi parent bna do or uski rank +1 kar do
//             parent[y_parent] =x_parent;
//             rank[x_parent]++;
//         }
//     }
//     bool equationsPossible(vector<string>& equations) {
//         parent.resize(26);
//         rank.resize(26);
//         for(int i=0;i<26;i++)
//         {
//             parent[i]=i;
//             rank[i]=0;
//         }
//         sort(equations.begin(), equations.end(), [](const string &a, const string &b)
//         {
//             // a == b comes first
//             bool isEqualA = (a[1] == '=');
//             bool isEqualB = (b[1] == '=');

//             if (isEqualA != isEqualB)
//                 return isEqualA > isEqualB;  // "==" first

//             return a < b; // fallback lexicographic
//         });

//         for(int i=0;i<equations.size();i++)
//         {
//             int x=equations[i][0] -'a';
//             int y=equations[i][3] -'a';
//             int x_parent =find(x);
//             int y_parent=find(y);

//             if(equations[i][1]=='=')
//             {
//                 if(x_parent != y_parent) Union(x,y);
//             }
//             else
//             {
//                 if(x_parent == y_parent ) return false;                
//             }
//         }
//         return true;
//     }
// };