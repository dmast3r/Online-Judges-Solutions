from math import floor, log2 as log
x = int(input())
print("TAK") if x == 2 ** int(floor(log(x))) else print("NIE")
