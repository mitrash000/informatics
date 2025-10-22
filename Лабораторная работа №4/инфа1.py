t = int(input())
A=[int(s) for s in input().split()]
B=[int(s) for s in input().split()]
count_A = sum(1 for x in A if x > t)
count_B = sum(1 for x in B if x > t)
if count_A >= count_B:
    print("Массив A:", A)
    print("Массив B:", B)
else:
    print("Массив B:", B)
    print("Массив A:", A)

