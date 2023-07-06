def is_in_rct(rct, point):
  if(point[0] >= rct[0] and point[1] >= rct[1] and point[0] <= rct[0] + rct[2] and point[1] <= rct[1] + rct[3]): return "sim"
  else: return "não"

print(is_in_rct(
  tuple(map(int, input().split())),
  tuple(map(int, input().split()))
))