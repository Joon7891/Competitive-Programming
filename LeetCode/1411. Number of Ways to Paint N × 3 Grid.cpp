class Solution {
public:
    // Red = 1, Yellow = 2, Green = 3
    struct State{
        int a, b, c;
        State(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
    };
    
    const int MOD = 1000000007;
    void addMod(int &a, int b){
        a = (a + b) % MOD;
    }
    
    bool valid(State a, State b){
        return a.a != b.a && a.b != b.b && a.c != b.c;
    }
    
    int numOfWays(int n) {
        const int MOD = 1000000007;
        
        int dp[5005][12];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 12; i++){
            dp[1][i] = 1;
        }
        
        vector<State> states;
        states.push_back(State(1, 2, 1));
        states.push_back(State(2, 1, 2));
        states.push_back(State(3, 1, 2));
        states.push_back(State(1, 2, 3));
        states.push_back(State(2, 1, 3));
        states.push_back(State(3, 1, 3));
        states.push_back(State(1, 3, 1));
        states.push_back(State(2, 3, 1));
        states.push_back(State(3, 2, 1));
        states.push_back(State(1, 3, 2));
        states.push_back(State(2, 3, 2));
        states.push_back(State(3, 2, 3));

        for (int i = 2; i <= n; i++){
            for (int j = 0; j < states.size(); j++){
                for (int k = 0; k < states.size(); k++){
                    if (valid(states[j], states[k])){
                        addMod(dp[i][j], dp[i - 1][k]);
                    }
                }
            }
        }
        
        int total = 0;
        for (int i = 0; i < states.size(); i++){
            total = (total + dp[n][i]) % MOD;
        }
        
        return total;
    }
};