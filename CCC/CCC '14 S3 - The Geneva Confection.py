def execute():
  n = int(input())
  carts = []
  branch = []
  needed_cart = 1
  for i in range(n):
    carts.append(int(input()))

  for i in range(n - 1, -1, -1):
    new_cart = carts[i]
    branch.append(new_cart)

    while len(branch) > 0 and branch[len(branch) - 1] == needed_cart:
      branch.pop()
      needed_cart += 1
  
  if len(branch) == 0:
    return 'Y'
  else:
    return 'N'


t = int(input())
for i in range(t):
    print(execute())