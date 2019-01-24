def build_fail_output(fails):
    output = 'FAIL: '
    len_fails = len(fails)
    for i in range(len_fails):
        output += str(fails[i]) + (',' if i != len_fails - 1 else '')

    return output

def execute(even_increase, odd_decrease, zero_set, prevals, postvals):
    correct_prevals = []
    for preval in prevals:
        correct_preval = str()
        for char in preval:
            new_char = 0
            char_int = int(char)
            if char_int == 0:
                new_char = zero_set
            elif char_int % 2 == 0:
                new_char = char_int + even_increase
            else:
                new_char = max(char_int - odd_decrease, 0)

            correct_preval += str(new_char)
        correct_prevals.append(correct_preval)

    fails = []
    for i in range(len(correct_prevals)):
        if correct_prevals[i] != postvals[i]:
            fails.append(i+1)

    fails.sort()
    return 'MATCH' if len(fails) == 0 else build_fail_output(fails)
  
for i in range(10):
  fl = input().split()
  n = int(fl[0])
  even_increase = int(fl[1])
  odd_decrease = int(fl[2])
  zero_set = int(fl[3])
  prevals = []
  postvals = []

  readpost = False
  while True:
      line = input()

      if line == 'A':
          readpost =  True
          continue

      if line == '*':
          break

      if not readpost:
          prevals.append(line)
      else:
          postvals.append(line)
      
  print(execute(even_increase, odd_decrease, zero_set, prevals, postvals))
