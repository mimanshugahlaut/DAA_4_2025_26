class Solution {
public:
    bool isPallindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int start,string s,vector<string> &current,vector<vector<string>> &result){
        if(start==s.length()){
            result.push_back(current);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPallindrome(s,start,i)){
                current.push_back(s.substr(start,i-start+1));
                solve(i+1,s,current,result);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        solve(0,s,current,result);
        return result;
    }
};
