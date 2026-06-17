#coding=windows-1251
def gold(M, z):
    z.sort(reverse=True) 
    aii_w = 0
    
    for w in z:
        if aii_w + w <= M:
            aii_w += w
    return aii_w


M1 = 15
z1 = [3, 8, 1, 2, 5]
M2 = 19
z2 = [10, 10, 7, 7, 4]
print(gold(M1, z1))  
print(gold(M2, z2))  
