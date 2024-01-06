m = int(input())
n = int(input())

sum = 0
first = 0
i = 1
while i * i <= n :
    if i * i >= m :
        if first == 0:
            first = i * i
        sum += i * i
    i += 1

if sum == 0 :
    print(-1)
else :
    print(sum)
    print(first)