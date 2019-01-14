from math import floor

def color(r, g, b):
  return floor(r ** 0.5), floor(g ** 0.5), floor(b ** 0.5)

r1, g1, b1 = map(int, input().split())
r2, g2, b2 = map(int, input().split())

if color(r1, g1, b1) == color(r2, g2, b2):
  print('Dull')
else:
  print('Colourful')
