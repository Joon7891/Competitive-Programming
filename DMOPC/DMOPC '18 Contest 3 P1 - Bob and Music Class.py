hash_map = {
  'A':0,
  'A#':1,
  'B':2,
  'C':3,
  'C#':4,
  'D':5,
  'D#':6,
  'E':7,
  'F':8,
  'F#':9,
  'G':10,
  'G#':11,
}

def get_interval(a, b):
  d = (hash_map[b] - hash_map[a] + 12) % 12
  return d

k1 = raw_input()
first = k1
k2 = raw_input()
k3 = raw_input()
d1 = get_interval(k1, k2)
d2 = get_interval(k2, k3)

cycles = 0
if not ((d1 == 4 and d2 == 3) or (d1 == 3 and d2 == 4) or (d1 == 4 and d2 == 4) or (d1 == 3 and d2 == 3)):
  first = k2
  d1 = get_interval(k2, k3)
  d2 = get_interval(k3, k1)
  cycles = 1

if not ((d1 == 4 and d2 == 3) or (d1 == 3 and d2 == 4) or (d1 == 4 and d2 == 4) or (d1 == 3 and d2 == 3)):
  first = k3
  d1 = get_interval(k3, k1)
  d2 = get_interval(k1, k2)
  cycles = 2

print(first)

if d1 == 4 and d2 == 3:
  print('major')
elif d1 == 3 and d2 == 4:
  print('minor')
elif d1 == 4 and d2 == 4:
  print('augmented')
elif d1 == 3 and d2 == 3:
  print('diminished')

if cycles == 0:
  print('root position')
elif cycles == 2:
  print('first inversion')
else:
  print('second inversion')