class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need;
        int distChar = 0;
        for(int i = 0; i < t.length(); i++){
            char c = t[i];
            if(need[c] == 0){
                distChar++;
            }
            need[c]++;
        }
        int left = 0, right = 0;
        map<char, int> window;
        int formed = 0;
        pair<int, int> ans;
        int a = INT_MAX;
        while(left <= right && right < s.length()){
            char c = s[right];
            window[c]++;
            if(window[c] == need[c]){
                formed++;
            }
            while(left <= right && formed == distChar){
                if(formed == distChar){
                    if(a > right - left + 1){
                        ans.first = left;
                        ans.second = right;
                        a = right - left + 1;
                    }
                }
                //Shrink
                char x = s[left];
                if(window[x] == need[x]){
                    formed--;
                }
                window[x]--;
                left++;
            }
            right++;
        }
        if(a == INT_MAX){
            return "";
        }else{
            return s.substr(ans.first, ans.second - ans.first + 1);
        }
    }
};
