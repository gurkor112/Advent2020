



f = open("input1", "r")

a = []
for x in f:
    a.append(x)

l = len(a)

for i in range(l -1 ):
    for y in range(l - 1):
        for x in range(l - 1):
            b = int(a[i]) + int(a[y]) + int(a[x])
            if b == 2020:
                print(str(int(a[i]) * int(a[y]) * int(a[x])))

