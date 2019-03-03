class Route:
    def __init__(self, id, round):
        self.id = id
        self.round = round

def solve():
    n = int(input())

    total = []
    routes = []

    for _ in range(n):
        line = [int(x) for x in input().split()]
        routes.append(Route(line[0], line[2:]))
        total.extend(line[2:])

    bucket = []
    m = min(total)
    for i in range(n):
        if m in routes[i].round:
            bucket.append(routes[i].id)
    
    bucket.sort()

    return m, bucket

for _ in range(10):
    a, b = solve()
    ans = str(a) + ' ' + str(b).replace('[', '{').replace(']', '}').replace(' ', '')
    print(ans)