#coding=windows-1251
def gold(n, M, z):
    dp = [0] * (M + 1)
    
    for zs in z:
        for w in range(M, zs - 1, -1):
            dp[w] = max(dp[w], dp[w - zs] + zs)
    
    return dp[M]


n1, M1 = 5, 15
z1 = [3, 8, 1, 2, 5]
n2, M2 = 5, 19
z2 = [10, 10, 7, 7, 4]
print(gold(n1, M1, z1))  
print(gold(n2, M2, z2))  
