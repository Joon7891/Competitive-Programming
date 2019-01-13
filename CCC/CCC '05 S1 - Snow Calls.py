keys_map = {
  'A':'2',
  'B':'2',
  'C':'2',
  'D':'3',
  'E':'3',
  'F':'3',
  'G':'4',
  'H':'4',
  'I':'4',
  'J':'5',
  'K':'5',
  'L':'5',
  'M':'6',
  'N':'6',
  'O':'6',
  'P':'7',
  'Q':'7',
  'R':'7',
  'S':'7',
  'T':'8',
  'U':'8',
  'V':'8',
  'W':'9',
  'X':'9',
  'Y':'9',
  'Z':'9',
}

n = int(input())
for i in range(n):
  sentence = input().replace('-', '').replace('-', '')
  sent_char = [char for char in sentence]
  final = str()
  for i in range(10):
    if sent_char[i] in keys_map.keys():
      final += keys_map[sent_char[i]]
    else:
      final += sent_char[i]

  print(final[0:3] + "-" + final[3:6] + "-" + final[6:10])
