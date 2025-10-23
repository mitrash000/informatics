A = set([1, 2, 3, 4, 5])

B = set([10, 20, 30])

count_A = len(A)
count_B = len(B)

if count_A >= count_B:
    print(*A)
else:
    print(*B)