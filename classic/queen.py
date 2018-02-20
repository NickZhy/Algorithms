from itertools import permutations as perm

queen = lambda n: sum([not any(any(x + y == m + n or x - y == m - n or y == n  for m, n in enumerate(p[:x])) for x, y in enumerate(p)) for p in perm(range(n))])
print queen(10)
