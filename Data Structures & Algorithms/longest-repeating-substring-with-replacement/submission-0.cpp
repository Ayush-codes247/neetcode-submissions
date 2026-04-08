class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0; int j = 0;
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;
        while(j < s.length()){
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);
            if(j-i+1 - maxFreq > k){
                freq[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};
