def valid(a):
    a = str(a)
    
    num = set()
    for char in a:
        num.add(char)
    
    return len(a) == len(num)

n = int(input())
n += 1

while True:
    if valid(n):
        print(n)
        break
    else:
        n += 1
