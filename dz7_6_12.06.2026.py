#coding=windows-1251

def fast_pow(a, n):
    result = 1
    while n > 0:
        if n % 2 == 1:
            result = (result * a)
        a = (a * a)
        n //= 2
    return result

a, n = 2,10
a2, n2 = 5,2
print(fast_pow(a, n))
print(fast_pow(a2, n2))