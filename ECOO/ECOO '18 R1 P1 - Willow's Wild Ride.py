def execute(t, n, boxes):
    daysLeft = 0
    
    for i in range(n):
        if boxes[i] == 'B':
            daysLeft += t

        if daysLeft > 0:
            daysLeft -= 1    

    print(max(0, daysLeft))

for i in range(10):
    t, n = map(int, input().split())
    boxes = []
    for i in range(0, n):
        boxes.append(input())
    execute(t, n, boxes)
