words = input().split()
final = str()
n = len(words)

for i in range(n):
  if i == n - 1:
    final += words[i] + '.'
  else:
    if words[i + 1][0].upper() == words[i + 1][0]:
      final += words[i] + '. '
    else:
      final += words[i] + ' '

print(final)