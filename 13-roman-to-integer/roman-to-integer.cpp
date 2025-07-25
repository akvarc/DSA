class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int>mp{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int j = 0; j<s.size();j++){
            if(mp[s[j]]<mp[s[j+1]]){
                ans=ans-mp[s[j]];
            }
            else{
                ans=ans+mp[s[j]];
            }
        }
        return ans;
    }
};