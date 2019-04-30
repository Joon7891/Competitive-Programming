def solve():
  n = int(input())

  total = set()
  for i in range(n):
    email = input()

    at = 0
    for i in range(len(email)):
      if email[i] == '@':
        at = i
      
    new = str()
    plus_flag = False
    for i in range(len(email)):
      if email[i] == '+':
        plus_flag = True
      elif i < at and email[i] != '.' and not plus_flag:
        new += email[i].lower()
      elif i >= at:
        new += email[i].lower()

    total.add(new)

  return len(total)  
  
for _ in range(10):
  print(solve())