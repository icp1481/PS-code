n = 10
c = [0] * 42
ans = 0

for i in range(n):
    a = int(input())
    c[a % 42] += 1

for i in range(42):
    if c[i] > 0 :
        ans += 1

print(ans)
