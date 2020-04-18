class Solution {
public:
    string getNext(string a){
        reverse(a.begin(), a.end());
        a += " ";
        int i;
        bool exit = false;
        for (i = 0; i < a.length() - 1 && !exit; i++){
            exit = true;
            
            if (a[i] == 'b' && a[i + 1] == 'a') a[i] = 'c';
            else if (a[i] == 'a' && a[i + 1] == 'b') a[i] = 'c';
            else if (a[i] == 'a' && a[i + 1] == 'c') a[i] = 'b';
            else if (a[i + 1] == ' ') a[i]++;
            else exit = false;
        }
        
        if (a[a.size() - 2] > 'c') return "";
        
        for (int j = i - 2; j >= 0; j--){
            if (a[j + 1] == 'b' || a[j + 1] == 'c') a[j] = 'a';
            else a[j] = 'b';
        }
                
        a = a.substr(0, a.length() - 1);
        reverse(a.begin(), a.end());
        return a;
    }
    
    string getHappyString(int n, int k) {
        vector<string> happy;
        
        string initial = "";
        for (int i = 0; i < n; i++){
            if (i % 2 == 0) initial += 'a';
            else initial += 'b';
        }
        
        happy.push_back(initial);
        
        while (happy.size() < k){
            string next = getNext(happy[happy.size() - 1]);
            happy.push_back(next);
            
            if (next == "") return "";
        }
        
        return happy[k - 1];
    }
};