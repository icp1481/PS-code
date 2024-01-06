def fin(file) :
    t = file.readline().strip() # 양쪽 끝에 있는 공백과 개행 문자 제거
    print(t)
    t1, t2 = map(int, t.split())
    return t1, t2

n = int(input())

ta = []
for i in range(n) :
    t1, t2 = fin()
    ta.append((t1, t2))

a = sorted(ta, key=lambda x: x[0])

ti = 0
for ai, bi in a :
    ti = max(ti, ai) + bi

print(ti)