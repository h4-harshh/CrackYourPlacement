class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result="";
        
        while(columnNumber)
        {
            columnNumber--;

            int remainder=columnNumber%26;

            char ch=remainder+'A';
            result=ch+result;

            columnNumber/=26;
        }

        return result;
    }
};