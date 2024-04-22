class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int ans=-1,mn=INT_MAX,one=0;
        for(int i=0;i<n;i++){
            one=0;
            for(int j=0;j<m;j++){
                if(a[i][j])one++;
            }
            if(one<mn){
                mn=one;
                ans=i+1;
            }
        }
        return ans;
    }
};
