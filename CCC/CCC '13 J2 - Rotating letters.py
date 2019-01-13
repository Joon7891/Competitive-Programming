letters = ['I', 'O', 'S', 'H', 'Z', 'X', 'N']

def can_rotate(word):
    for char in word:
        if not char in letters:
            return False


    return True

word = input()

if can_rotate(word):
    print('YES')
else:
    print('NO')
