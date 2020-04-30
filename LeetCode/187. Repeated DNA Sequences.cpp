class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<char, int> charToBit;
        charToBit['A'] = 0b00;
        charToBit['C'] = 0b01;
        charToBit['G'] = 0b10;
        charToBit['T'] = 0b11;
        
        map<int, char> bitToChar;
        bitToChar[0b00] = 'A';
        bitToChar[0b01] = 'C';
        bitToChar[0b10] = 'G';
        bitToChar[0b11] = 'T';
                
        int cur = 0;
        vector<int> seen;
        map<int, int> freq;
        for (int i = 0; i < s.length(); i++){
            cur = ((cur << 2) | charToBit[s[i]]);
            
            if (i >= 9){
                cur &= 0b11111111111111111111;
                                
                if (freq[cur] == 0) seen.push_back(cur);
                freq[cur]++;                
            }
        }
        
        vector<string> ans;
        for (int x : seen){
            if (freq[x] >= 2){
                string dna = "";
                for (int i = 0; i < 10; i++){
                    int bit = (x >> (2 * i)) & 0b11;
                    dna = bitToChar[bit] + dna;
                }
                
                ans.push_back(dna);
            }
        }
        return ans;
                
    }
};