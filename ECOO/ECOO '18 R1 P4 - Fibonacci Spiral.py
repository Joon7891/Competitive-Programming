storedSeq = {}

def fib(n):
    if n in storedSeq: 
        return storedSeq[n]
    elif n is 1 or n is 2:
        return 1
    else:
        newFib = fib(n - 1) + fib(n - 2)
        storedSeq[n] = newFib
        return newFib

def insideRect(rectX, rectY, rectWidth, rectHeight, x, y):
    if x >= rectX and x <= (rectX + rectWidth) and y >= rectY and y <= (rectY + rectHeight):
        return True
    else:
        return False

def buildRect(currentX, currentY, currentWidth, currentHeight, addFib, direction):
    if direction is 0:
        return (currentX - addFib), currentY, currentWidth + addFib, currentHeight
    elif direction is 1:
        return currentX, currentY, currentWidth, currentHeight + addFib
    elif direction is 2:
        return currentX, currentY, currentWidth + addFib, currentHeight
    else:
        return currentX, currentY - addFib, currentWidth, currentHeight + addFib

def execute(Px, Py):
    direction = -1
    x, y, width, height = 0, -1, 1, 1
    n  = 1
    inside = False
    while not inside:
        if not insideRect(x, y, width, height, Px, Py):
            direction = (direction + 1) % 4
            n += 1
            x, y, width, height = buildRect(x, y, width, height, fib(n), direction)
        else:
            inside = True

    return n

for i in range(10):
    x, y = map(int, input().split())
    print(execute(x, y))