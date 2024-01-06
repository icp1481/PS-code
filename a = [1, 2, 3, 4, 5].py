a = [0] * 42 # check the count each number when we divided by 42

inp = [42,
84,
252,
420,
840,
126,
42,
84,
420,
126]
 

ans = 0
for i in inp :
    num = i % 42
    a[num] = a[num] + 1 # counting
    if i == a[num] :
        ans = ans + 1


print(ans)
