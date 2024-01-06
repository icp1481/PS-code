import random

X = [(1, 2, 3, 4, 5), (2, 3, 4, 5, 6), (3, 4, 5, 6, 7), (4, 5, 6, 7, 8), (5, 6, 7, 8, 9), (13, 14, 15, 16, 17), (7, 8,
9, 10, 18), (8, 9, 10, 18, 19), (9, 10, 18, 19, 20), (10, 18, 19, 20, 21), (11, 12, 15, 23, 24), (12, 15, 23,
24, 29), (15, 23, 24, 29, 30), (14, 15, 16, 17, 22), (15, 16, 17, 22, 25), (23, 24, 29, 30, 30), (17, 22, 25,
26, 27), (22, 25, 26, 27, 28), (19, 20, 21, 22, 25), (20, 21, 22, 25, 26), (21, 22, 25, 26, 27), (22, 25, 26,
27, 28), (25, 26, 27, 28, 29), (24, 29, 30, 30, 30), (29, 30, 30, 30, 30), (26, 27, 28, 29, 30), (27, 28, 29,
30, 30), (28, 29, 30, 30, 30), (29, 30, 30, 30, 30), (30, 30, 30, 30, 30)]

n = [0] * 31
n[30] = 0

p = [0.1536, 0.3456, 0.3456, 0.1296, 0.0256]
Fp = [0] * 5

Fp[0] = p[0]
for i in range(1, 5) :
    Fp[i] = Fp[i - 1] + p[i]

print(Fp)
num = input("test number?: ")
if num == 'a' :
    n[29] = 1    
    for i in range(28, -1, -1) :
        s = 0
        for j in range(5) :
            s += n[X[i][j]] * p[j]
        s += 1
        n[i] = s
    for i in range(31) :
        print(f"{i}: {n[i]}")   

elif num == 'b' :
    N = 100000
    for st in range(30) :
        for tc in range(N) :
            po = st
            cnt = 0
            while po < 30 :
                ran = random.random()
                if ran < Fp[0] :
                    t = 0
                elif ran < Fp[1] :
                    t = 1
                elif ran < Fp[2] :
                    t = 2
                elif ran < Fp[3] :
                    t = 3
                else :
                    t = 4
                po = X[po][t]
                cnt += 1
            n[st] += cnt
        n[st] /= N
    print(f"N: {N}")
    for i in range(31) :
        print(f"{i}: {n[i]}")   
elif num == 'c' :
    XC = [0] * 11
    XC[0] = 1
    for i in range(1, 11) :
        for j in range(1, min(i, 5) + 1) :
            if i - j == 5 :
                continue
            XC[i] += XC[i - j] * p[j - 1]
    pp = [0] * 4
    pp[0] = XC[5] * XC[3]
    pp[1] = XC[5] * (1 - XC[3])
    pp[2] = XC[10]
    pp[3] = 1 - pp[0] - pp[1] - pp[2]
    for i in range(4) :
        print(f"p{i+1}: {pp[i]}")

elif num == 'd' :
    N = 100000
    vis = [0] * 31
    pp = [0] * 4
    for tc in range(1, N + 1) :
        po = 0
        while po < 30 :
            ran = random.random()
            vis[po] = tc
            if ran < Fp[0] :
                t = 0
            elif ran < Fp[1] :
                t = 1
            elif ran < Fp[2] :
                t = 2
            elif ran < Fp[3] :
                t = 3
            else :
                t = 4
            po = X[po][t]
        if vis[5] == tc and vis[15] == tc :
            ty = 0
        elif vis[5] == tc :
            ty = 1
        elif vis[10] == tc:
            ty = 2
        else :
            ty = 3
        pp[ty] += 1
    print(f"N: {N}")
    for i in range(4) :
        print(f"p{i+1}: {pp[i] / N}")

