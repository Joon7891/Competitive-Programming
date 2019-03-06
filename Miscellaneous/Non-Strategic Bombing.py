def area(x1, y1, x2, y2, x3, y3): 
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1)  + x3 * (y1 - y2)) / 2.0) 
  
def solve(x1, y1, x2, y2, x3, y3, x, y): 
    total = area (x1, y1, x2, y2, x3, y3) 
    a1 = area (x, y, x2, y2, x3, y3) 
    a2 = area (x1, y1, x, y, x3, y3) 
    a3 = area (x1, y1, x2, y2, x, y) 
    
    if total == (a1 + a2 + a3):
        return True
    
    return False

n, m = map(int, input().split())

points = []
for i in range(n): 
    points.append([int(x) for x in input().split()])

for i in range(m):
    counter = 0
    a = [int(x) for x in input().split()]

    for point in points:

        if solve(a[0], a[1], a[2], a[3], a[4], a[5], point[0], point[1]):
            counter += 1

    print(counter)