path_dir = ''
loc_name = ''
pairs = []

start_dir = input()
while loc_name != 'SCHOOL':
  loc_name = input()
  if not loc_name == 'SCHOOL':

    path_dir = input()

  pairs.append([path_dir, loc_name])

n = len(pairs)
for i in range(len(pairs) - 1):
  cache = pairs[n - 2 - i]

  if cache[0] == 'R':
    print('Turn LEFT onto {} street.'.format(cache[1]))
  else:
    print('Turn RIGHT onto {} street.'.format(cache[1]))

if start_dir == 'R':
    print('Turn LEFT into your HOME.')
else:
    print('Turn RIGHT into your HOME.')
