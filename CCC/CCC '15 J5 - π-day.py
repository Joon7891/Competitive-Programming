memo = {}

def get(n, k, m):
    array_tuple = str(n) + " " + str(k) + " " + str(m)
    if array_tuple in memo.keys():
        return memo[array_tuple]
    
    if n == k:
        total = 1
    elif k == 1:
        total = 1
    else:
        total = 0

        for i in range(m, (n // k) + 1):
            total += get(n - i, k - 1, i)    

    memo[array_tuple] = total
    return memo[array_tuple]


n = int(input())
k = int(input())

print(get(n, k, 1))
