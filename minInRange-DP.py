def preprocess(nums):
    n = len(nums)
    dp = [[0]*n for _ in range(n)]
    for i in range(n):
        dp[i][i] = nums[i]
        for j in range(i+1,n):
            dp[i][j] = min(dp[i][j-1],nums[j])
        return dp
def query(nums,i,j):
    dp = preprocess(nums)
    return dp[i][j]