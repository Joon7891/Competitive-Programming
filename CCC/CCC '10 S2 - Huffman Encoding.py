n = int(input())
sets = {}
for i in range(n):
    letter, key = map(str, input().split())
    sets[key] = letter

k = input()
final = str()
while len(k) > 0:
    for i in range(1, len(k) + 1):
        if k[0:i] in sets.keys():
            final += sets[k[0:i]]
            k = k[i:]

print(final)
