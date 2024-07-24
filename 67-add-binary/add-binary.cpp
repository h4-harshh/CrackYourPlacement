class Solution {
public:
    string addBinary(string a, string b) {
        
        string result="";

        int carry=0;
        int n=a.length();
        int m=b.length();
        int i=n-1;
        int j=m-1;

        while(i>=0 || j>=0 || carry!=0)
        {
            int X=0;
            if(i>=0 && a[i]=='1') X=1;

            int Y=0;
            if(j>=0 && b[j]=='1') Y=1;

            result= to_string((X+Y+carry)%2)+result;
            carry=(X+Y+carry)/2;
            i--;
            j--;
        }
        return result;
    }
};