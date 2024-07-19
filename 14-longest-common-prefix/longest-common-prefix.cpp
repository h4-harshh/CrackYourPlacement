class Solution {
public:

    int solve(string word1,string word2)
    {
        int count=0;
        int k=word1.length();
        int l=word2.length();
        int i=0;
        int j=0;
        while(i<k && j<l)
        {
            if(word1[i]!=word2[j]) break;
            i++;
            j++;
            count++;
        }
        return count;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int lcp=strs[0].size();

        for(int i=1;i<strs.size();i++)
        {
            int curr_cmn=solve(strs[0],strs[i]);
            lcp=min(lcp,curr_cmn);
        }
        string word=strs[0];
        return word.substr(0,lcp);
    }
};