def is_not_in(x, L):
  return len(list(filter(lambda i: i == x, L))) == 0

def diff_sym(A: list, B: list):
  return (list(filter(lambda i: is_not_in(i, B), A)) + list(filter(lambda i: is_not_in(i, A), B)))

print(
  *diff_sym(list(map(int, input().split())), list(map(int, input().split())))
) def troca(i, p, q):
  if(i == p): return q + p
  else: return i