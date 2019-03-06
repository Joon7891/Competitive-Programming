size = int(input())

currentList = []
for i in range(size):
    currentList.append(int(input()))

currentList.sort()
listSize = len(currentList)
for i in range(listSize):
    print(currentList[i])