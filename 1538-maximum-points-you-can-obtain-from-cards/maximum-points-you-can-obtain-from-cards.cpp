class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int left_sum=0;
        int right_sum=0;
        int max_score=0;

        int right_index=n-1;

        for(int i=0;i<k;i++) left_sum+=cardPoints[i];

        if(n==k) return left_sum;

        // cout<<left_sum;
        max_score=left_sum;

        for(int i=k-1;i>=0;i--)
        {
            left_sum-=cardPoints[i];

            right_sum+=cardPoints[right_index];
            right_index--;

            max_score=max(max_score,(left_sum+right_sum));
        }

        return max_score;
    }
};