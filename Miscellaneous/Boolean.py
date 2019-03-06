line = input().split()
counter = 0
for word in line:
    if word == 'not':
        counter += 1

if line[len(line) - 1] == 'True':
    if counter % 2 == 0:
        print('True')
    else:
        print('False')
else:
    if counter % 2 == 0:
        print('False')
    else:
        print('True')