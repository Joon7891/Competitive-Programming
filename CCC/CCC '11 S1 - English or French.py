n = int(input())

french_count = 0
english_count = 0

for _ in range(n):
    line = input()

    for char in line:
        if char == 't' or char == 'T':
            english_count += 1
        elif char == 's' or char == 'S':
            french_count += 1

if english_count > french_count:
    print("English")
else:
    print("French")
