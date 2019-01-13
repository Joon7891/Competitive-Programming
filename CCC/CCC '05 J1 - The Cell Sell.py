day = int(input())
even = int(input())
end = int(input())

plan_a = round(max(0, day - 100) * 0.25 + even * 0.15 + end * 0.2, 2)
plan_b = round(max(0, day - 250) * 0.45 + even * 0.35 + end * 0.25, 2)

print('Plan A costs {:2}'.format(plan_a))
print('Plan B costs {:2}'.format(plan_b))

if plan_a < plan_b:
  print('Plan A is cheapest.')
elif plan_b < plan_a:
    print('Plan B is cheapest.')
else:
  print('Plan A and B are the same price.')