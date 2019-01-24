import math

yearHeader = input()
teamName = {}
totalHit = {}
a = {}
b = {}
c = {}
d = {}
e = {}
totalTotal = 0
aTotal = 0
bTotal = 0
cTotal = 0
dTotal = 0
eTotal = 0

def slugging(newA, newB, newC, newD, newE):
    sa = round(((newA + 2 * newB + 3 * newC + 4 * newD) / newE) * 1000)/ 1000

    sa = str(sa)
    sa = sa.replace('0', '', 1)
    if len(sa) is 3:
        sa = sa + '0'

    return sa

def batting(e, newTotal):
    ba = round((newTotal / e) * 1000) / 1000
    ba = str(ba)
    ba = ba.replace('0', '', 1)
    if len(ba) is 3:
        ba = ba + '0'

    return ba

for i in range(0, 10):
    currentLine = input().split(' ')
    teamName[i], b[i], c[i], d[i], e[i], totalHit[i] = currentLine[0], int(currentLine[5]), int(currentLine[6]), int(currentLine[7]), int(currentLine[2]), int(currentLine[4])
    a[i] = totalHit[i] - b[i] - c[i] - d[i]
    totalTotal += totalHit[i]
    aTotal += a[i]
    bTotal += b[i]
    cTotal += c[i]
    dTotal += d[i]
    eTotal += e[i]

print(yearHeader)
print('====================')
for i in range(0, 10):
    print(teamName[i] + ":", batting(e[i], totalHit[i]), slugging(a[i], b[i], c[i], d[i], e[i]))

print('====================')
print('Big 10 Av:', batting(eTotal, totalTotal), slugging(aTotal, bTotal, cTotal, dTotal, eTotal))