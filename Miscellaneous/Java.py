k, l = 0, 0

def get():
  for i in range(l - 3):
    if k[i:i+4] == 'java':
      return i
  
  return l

k = input()
l = len(k)
print(get())