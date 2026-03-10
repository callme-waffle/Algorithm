import math

def isCirContain(c, x, y):
  return math.sqrt(math.pow(c[0] - x, 2) + math.pow(c[1] - y, 2)) < c[2]


for _ in range(0, int(input())):
  x1, y1, x2, y2 = [int(x) for x in input().split()]

  clist = []
  for _c in range(0, int(input())):
    cx, cy, cr = [int(x) for x in input().split()]
    clist.append((cx, cy, cr))

  clist.sort(key=lambda x: x[2])

  stack_1 = []
  stack_2 = []
  for c in clist:
    if isCirContain(c, x1, y1):
      stack_1.append(c)

    if isCirContain(c, x2, y2):
      stack_2.append(c)
    
  p1 = len(stack_1)
  p2 = len(stack_2)

  for _ in range(0, max(p1, p2)):
    if p1 == 0 or p2 == 0:
      break
    
    if stack_1[p1-1] == stack_2[p2-1]:
      del stack_1[p1-1]
      del stack_2[p2-1]
      p1 -= 1
      p2 -= 1

  print(p2+p1)