from math import gcd, floor

a = int(input())
b = int(input())

new_gcd = gcd(a, b)

if a % b != 0:
    a = a / new_gcd
    b = b / new_gcd
    
    quo = int(a // b)
    rem = int(a % b)
    
    if quo == 0:
        print('{0}/{1}'.format(rem, int(b)))
    else:
        print('{0} {1}/{2}'.format(quo, rem, int(b)))
else:
    print(new_gcd)