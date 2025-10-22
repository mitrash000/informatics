a = input().split()
A = set(a)

b = input().split()
B = set(b)

count_A = len(A)
count_B = len(B)

if count_A >= count_B:
    print(*A)
else:
    print(*B)