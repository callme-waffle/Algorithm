cnt = int(input())

values = set([ input() for i in range(0, cnt) ])
sorted_values = sorted(
  values,
  key=lambda value: (len(value), value)
)

for v in sorted_values:
  print(v)