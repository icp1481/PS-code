#a = list(map(int,input().split()))

#print(a)


a = [5, 6, 7, 8, 9]


for i in range(len(a)) :
    for j in range(len(a)) :
        for k in range(len(a)) :
            #if i == j or i == k or j == k: # this is not 3 types of card
            #    continue
            print(i, j, k)