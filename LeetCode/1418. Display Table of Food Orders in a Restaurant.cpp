class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, map<string, int>> tables;
        vector<string> items;
        set<string> itemSet;
        
        vector<int> tableVector;
        set<int> tableSet;
        
        for (vector<string> order : orders){
            tables[order[1]][order[2]]++;
            if (itemSet.find(order[2]) == itemSet.end()) {
                itemSet.insert(order[2]);
                items.push_back(order[2]);
            }
            
            if (tableSet.find(stoi(order[1])) == tableSet.end()){
                tableSet.insert(stoi(order[1]));
                tableVector.push_back(stoi(order[1]));
            }
        }
        
        sort(items.begin(), items.end());
        sort(tableVector.begin(), tableVector.end());
        
        vector<vector<string>> ans;
        
        vector<string> header;
        header.push_back("Table");
        for (string i : items) header.push_back(i);
        ans.push_back(header);
        
        for (int table : tableVector){
            vector<string> result;
            result.push_back(to_string(table));
            
            for (string i : items) result.push_back(to_string(tables[to_string(table)][i]));
            
            ans.push_back(result);
        }
        
        return ans;
    }
};