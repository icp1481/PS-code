def fin(file) :
    t = file.readline().strip() # 양쪽 끝에 있는 공백과 개행 문자 제거
    print(t)
    t1, t2 = map(int, t.split())
    return t1, t2

def f(p1, p2, q1, q2) :
    if p2 + q2 <= q1 :
        return 0, p2 + q2
    else :
        return p2 + q2 - q1, q1

with open("mixmilk.in", "r") as input_file:
    a1, a2 = fin(input_file)
    b1, b2 = fin(input_file)
    c1, c2 = fin(input_file)

for i in range(33) :
    a2, b2 = f(a1, a2, b1, b2)
    b2, c2 = f(b1, b2, c1, c2)
    c2, a2 = f(c1, c2, a1, a2)
a2, b2 = f(a1, a2, b1, b2)

with open('mixmilk.out', 'w') as file:
    # 파일에 쓰기
    file.write(str(a2) + "\n")
    file.write(str(b2) + "\n")
    file.write(str(c2) + "\n")