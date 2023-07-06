def eh_primo(n):
  return n > 1 and len(list(filter(lambda i: n%i == 0, range(2, n)))) == 0

def obter_primos(l: list):
  return list(filter(lambda i: eh_primo(i), l))

print(*obter_primos(list(map(int, input().split()))));