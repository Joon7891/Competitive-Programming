class Solution {
public:
    struct Node{
        int i, j, val;
        
        Node(int i, int j, int val){
            this->i = i;
            this->j = j;
            this->val = val;
        }
        
        bool operator<(const Node next){
            if (next.i + next.j == i + j) return next.i > i;
            return next.i + next.j < i + j;
        }
    };
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<Node> toSort;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < nums[i].size(); j++){
                toSort.push_back(Node(i, j, nums[i][j]));
            }
        }
        
        sort(toSort.rbegin(), toSort.rend());
        
        vector<int> ans;
        for (int i = 0; i < toSort.size(); i++) ans.push_back(toSort[i].val);
        
        return ans;
    }
};