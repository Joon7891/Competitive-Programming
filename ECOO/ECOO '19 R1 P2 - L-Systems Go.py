import sys
input = sys.stdin.readline

def solve():
    r, t, a = map(str, input().split())
    r = int(r)
    t = int(t)

    switches = {}
    for i in range(r):
        c, s = input().split()
        switches[c] = s

    freq = {}

    for char in a:
        if not char in freq.keys():
            freq[char] = 1
        else:
            freq[char] += 1

    first = a[0]
    last = a[len(a) - 1]

    for i in range(t):
        first = switches[first][0]
        last = switches[last]
        length = len(last)
        last = last[length - 1]

        new_freq = {}
        for aa in freq.keys():
            for char in switches[aa]:
                if not char in new_freq.keys():
                    new_freq[char] = freq[aa]
                else:
                    new_freq[char] += freq[aa]
    
        freq = new_freq

    ans_length = 0
    for char in freq.keys():
        ans_length += freq[char]

    ans = first + last
    return "{0} {1}".format(ans, ans_length)

for _ in range(10):
    print(solve())
    sys.stdout.flush()