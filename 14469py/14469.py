def fin(file) :
    t = file.readline().strip() # 양쪽 끝에 있는 공백과 개행 문자 제거
    t1, t2 = map(int, t.split())
    return t1, t2

with open("cowqueue.in", "r") as infile:

    n = int(infile.readline().strip()) 

    ta = []
    for i in range(n) :
        t1, t2 = fin(infile)
        ta.append((t1, t2))

    a = sorted(ta, key=lambda x: x[0])

ti = 0
for ai, bi in a :
    ti = max(ti, ai) + bi

with open('cowqueue.out', 'w') as file:
    file.write(str(ti))