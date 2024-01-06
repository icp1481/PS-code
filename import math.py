import math

n = int(input())
m = int(input())
s = 0
m2 = math.ceil(math.sqrt(n))

for i in range(m2, int(math.sqrt(m)) + 1):
    s += i * i

if s > 0:
    print(s)
    print(m2 * m2)
else:
    print(-1)