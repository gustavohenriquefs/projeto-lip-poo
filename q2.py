def troca(i, p, q):
  if(i == p): return q + p
  else: return i

def perc(l:list, p, q):
  return list(map(lambda i: troca(i, p, q), l))

print(*perc(list(map(lambda i: int(i), input().split())), int(input()), int(input())))