def execute():
  w_t, w_a, w_p, w_q = map(int, input().split())
  n = int(input())

  count = 0
  for i in range(n):
    t, a, p, q = map(int, input().split())
    total = t * w_t + a * w_a + p * w_p + q * w_q

    if total >= 5000:
      count += 1
  
  return count

for i in range(10):
  print(execute())
