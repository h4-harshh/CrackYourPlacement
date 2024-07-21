class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();

        if(t.length()>n) return "";

        unordered_map<char,int>mp;

        for(auto &x:t){
            mp[x]++;
        }

        int countRequired=t.length();
        int minWindow=INT_MAX;
        int start_i=0;

        int i=0,j=0;
        while(j<n)
        {
            char ch=s[j];

            if(mp[ch]>0) countRequired--;

            mp[ch]--;

            while(countRequired==0)
            {
                int currWindow=j-i+1;

                if(currWindow<minWindow)
                {
                    minWindow=currWindow;
                    start_i=i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0)
                {
                    countRequired++;
                }

                i++;
            }

            j++;
        }

        return minWindow==INT_MAX?"":s.substr(start_i,minWindow);
    }
};