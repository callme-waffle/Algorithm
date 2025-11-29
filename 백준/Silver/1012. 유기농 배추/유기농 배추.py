
board = []

def dfs(x, y):
  global board
  board[x][y] = 0

  poss = [[0, 1], [0, -1], [1, 0], [-1, 0]]
  cx = 0
  cy = 0

  q = [[x, y]]
  while len(q) > 0:
    v = q.pop()
    board[v[0]][v[1]] = 0

    for d in poss:
      cx = v[0] + d[0]
      cy = v[1] + d[1]

      if not (
        cx >= 0 and cx < len(board) and
        cy >= 0 and cy < len(board[cx])
      ):
        continue
      
      if board[cx][cy] == 1:
        q.append([cx, cy])

for _ in range(0, int(input())):
  m, n, k = [int(x) for x in input().split()]
  board = [[0 for _ in range(0, n)] for _ in range(0, m)]
  inputs = []
  for __ in range(0, k):
    x, y = [int(x) for x in input().split()]
    inputs.append([x, y])
    board[x][y] = 1

  c = 0
  for iv in inputs:
    if (board[iv[0]][iv[1]] == 1):
      c += 1
      dfs(iv[0], iv[1])

  print(c)