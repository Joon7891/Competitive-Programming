co = (24 * 60 * 60) / (((24 * 60 + 37) * 60) + 22.663)

for i in range(10):
  d, h, m = map(int, input().split())

  #Mars Seconds
  total = ((d * 24 + h) * 60 + m + 37 + 22.63 / 60) * 60 * co

  days = total // (24 * 60 * 60)
  total -= days * (24 * 60 * 60)

  hours = total // (60 * 60)
  total -= hours * (60 * 60)

  minutes = total // (60)

  days, hours, minutes = int(days), int(hours), int(minutes)

  if hours < 10:
    hours = '0' + str(hours)
  
  if minutes < 10:
    minutes = '0' + str(minutes)

  print('Day ' + str(days) + ', ' + str(hours) + ':' + str(minutes))
