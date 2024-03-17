def climbStairs(n):
        ways = [0] * (n+1)
        ways[0] = 1
        ways[1] = 1
        for i in range(2, n+1):
            ways[i] = ways[i-1] + ways[i-2]
        print(ways)
        return ways[n]

print(climbStairs(2))



def climbStairs(n):
    if n == 0 or n == 1:
        return 1

    dp = [0] * (n+1)
    dp[0] = dp[1] = 1
        
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    
    print(dp)
    return dp[n]

print(climbStairs(2))