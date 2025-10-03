class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;++i)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<m;++j)
                {
                    grid[i][j]^=1;
                }
            }
        }
        int ans=(1<<(m-1))*n;
        for(int j=1;j<m;++j)
        {
            int cnt=0;
            for(int i=0;i<n;++i)
            {
                if(grid[i][j])
                {
                    ++cnt;
                }
            }
            cnt=max(cnt,n-cnt);
            ans+=(1<<(m-j-1))*cnt;
            // if(2*cnt<n)
            // {
            //     for(int i=0;i<n;++i)
            //     {
            //         grid[i][j]^=1;
            //     }
            // }
        }
        return ans;
    }
};
