new_word = input()
while new_word != 'X':
    while True:
        if 'ANA' in new_word or 'BAS' in new_word:
            new_word = new_word.replace('ANA', 'A')
            new_word = new_word.replace('BAS', 'A')
        else:
            break
    
    if new_word == 'A':
        print('YES')
    else:
        print('NO')
    
    new_word = input()
