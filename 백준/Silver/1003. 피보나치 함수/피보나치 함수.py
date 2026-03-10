zc = 0
oc = 0

sp = {
   0: (1, 0, 0),
   1: (0, 1, 1)
}

def fibonacci(n):
  global sp
  global zc
  global oc

  if (n in sp):
     return sp[n]

  if n == 0:
      zc += 1
      return sp[n]
  if n == 1:
      oc += 1
      return sp[n]
  
  fv2 = fibonacci(n-2)
  fv1 = fibonacci(n-1)

  sp[n] = (fv2[0] + fv1[0], fv2[1] + fv1[1], fv2[2] + fv1[2])
  return sp[n]

inputs = []
for i in range(0, int(input())): 
  inputs.append(int(input()))

fibonacci(max(inputs)+1)

for i in inputs:
  print("%d %d" % (sp[i][0], sp[i][1]))
  