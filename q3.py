def is_pal(s):
    if(len(s) <= 1): 
      return True

    if(s[0] == s[-1]): 
      return is_pal(s[1:-1])
    else: 
      return False

def comp_str(posIn, n, w):
  if(posIn == len(w) - n + 1):
    return 'nao'
  else:
    if(len(list(filter(lambda i: is_pal(w[posIn: i]), range(posIn + n, len(w))))) > 0):
      return 'sim'
    else: return comp_str(posIn + 1, n, w)

print(comp_str(0, int(input()), input()))
