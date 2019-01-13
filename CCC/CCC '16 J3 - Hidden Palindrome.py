def is_palindrome(word):
  n = len(word)

  for i in range(n // 2):
    if word[i] != word[n - i - 1]:
      return False

  return True

word = input()
longest = str()
n = len(word)

for i in range(n):
  for j in range(1, n - i + 1):
    if is_palindrome(word[i:i + j + 1]) and len(word[i:i + j + 1]) > len(longest):
      longest = word[i:i + j + 1]

print(len(longest))