a = input()

ch = 1
for i in range(0, len(a) - 1) :
    j = len(a) - i - 1 
    if a[i] != a[j] :
        ch = 0
        break

if ch : 
    print(1)
else :
    print(0)