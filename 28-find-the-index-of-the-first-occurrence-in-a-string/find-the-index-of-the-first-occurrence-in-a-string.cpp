class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();

        if(n>m) return -1;

        for(int i=0;i<m;i++)
        {
            if(needle[0]==haystack[i])
            {
                int x=i+1;
                int y=1;
                while(y<n)
                {
                    if(needle[y]!=haystack[x])  break;
                    x++;
                    y++;
                }
                if(y==n) return i;
            }
        }
        return -1;
    }
};