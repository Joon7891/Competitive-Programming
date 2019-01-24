words = ["ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"]
memo = {}

def combinations(testWord):
    if testWord in memo:
        return memo[testWord]
    
    newCount = 0

    if len(testWord) is 0:
        return 1

    for newWord in words:
        if testWord.startswith(newWord):
            newCount += combinations(testWord.replace(newWord, "", 1))

    memo[testWord] = newCount
    return newCount

for i in range(10):
    print(combinations(input()))