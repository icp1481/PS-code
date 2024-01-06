def findDiscardSum(originalRows, tiles):
    s = 0
    ch = 0
    a = [0] * 5
    a1 = [0] * 5
    a2 = [0] * 5

    # Split the input 4-digit integer into individual digits and store them in an array
    ta = int(originalRows)
    for i in range(3, -1, -1):
        a[i] = ta % 10
        ta //= 10

    # Divide each digit into tens and units and store them
    for i in range(4):
        a1[i] = 0
        a2[i] = a[i]

    j = 0
    s = 0
    # Iterate through the tiles
    for po in range(0, len(tiles), 3):
        t1 = int(tiles[po])
        t2 = int(tiles[po + 1])
        #print(t1, t2)
        fi = 0
        # Check for a double in the current state
        for i in range(4):
            if a1[i] == a2[i]:
                fi = 1
                break
        ch = 0
        num = 0
        if fi == 1:  # If there is a double
            if a2[i] == t1:
                a1[i] = t1
                a2[i] = t2
                j = i
                ch = 1
            elif a2[i] == t2:
                a1[i] = t2
                a2[i] = t1
                j = i
                ch = 1
        else:
            # Iterate through the rows to find a suitable placement
            for x in range(1, 5):
                i = (j + x) % 4
                if a2[i] == t1:
                    a1[i] = t1
                    a2[i] = t2
                    j = i
                    ch = 1
                    break
                elif a2[i] == t2:
                    a1[i] = t2
                    a2[i] = t1
                    j = i
                    ch = 1
                    break

        # If no suitable placement is found, add the numbers to the sum
        if ch == 0:
            s += t1 + t2

    return s


print(findDiscardSum(5179, "14 92 71 51 42 19 18 28 89 29 96 46 13 57 78 27"))
print(findDiscardSum(4287, "69 36 21 93 94 35 83 62 88 97 18 72 42 73 75 31 28 52 66 87"))
print(findDiscardSum(1745, "21 37 92 42 93 96 19 72 78 18 71 36 56 85 99 97 31 98 23"))
print(findDiscardSum(6655, "23 55 55 45 94 99 12 99 89 32 77 65 58 57 66 27 16 76"))
print(findDiscardSum(3333, "43 35 55 34 37 53 23 49 13 22 98 12 33 11 53 79 57 39 77 43 72 22 12 48 17 15 75"))
print(findDiscardSum(5923, "56 27 73 34 99 45 32 19 64 57 18"))
print(findDiscardSum(4687, "81 72 15 89 36 21 13 67 42 93 48 83 45 47 52 94 62"))
print(findDiscardSum(1932, "94 81 13 43 21 31 89 69 18 28 86 88 29 89 92"))
print(findDiscardSum(1957, "32 69 87 73 31 88 62"))
print(findDiscardSum(1542, "24 44 39 32 92 63 47 76 37 78 38"))
