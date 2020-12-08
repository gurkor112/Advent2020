

def bagCount(dic, key):
    value = dic[key]
    size = len(value)
    toReturn = 0
    for i in range(0, size, 2):
        toReturn += int(str(value[i]))
        toReturn += int(str(value[i])) * bagCount(dic, value[i + 1])
    return toReturn



f = open("input7")

line = f.readline()

toHandle = {}

while line:
    words = line.split(' ')
    pos = 4
    index = str(words[0]) + str(words[1])

    amount = len(words) - 4
    toInsert = []
    if words[pos] != "no":

        while amount > 0:
            toInsert.append(words[pos])
            pos += 1
            toInsert.append(str(words[pos]) + str(words[pos + 1]))
            pos += 3
            amount -= 4
        toHandle[index] = toInsert
        line = f.readline()
    else:
        toHandle[index] = []
        line = f.readline()

moved = 1
a = 0
keys = toHandle.keys()
'''
while moved != 0:
    print(str(a))
    moved = 0
    for key in keys:
        value = toHandle[key]
        if not "shinygold" in value:
            i = 0
            for word in value:
                if i%2 ==1:
                    searchList = toHandle[word]
                    if "shinygold" in searchList:
                        toHandle[key][i] = "shinygold"    
                        moved = 1
                i = i+ 1
    a += 1
toPrint = 0
for key in keys:
    value = toHandle[key]
    if "shinygold" in value:
        toPrint += 1

print(toPrint)
'''

print(str(bagCount(toHandle, "shinygold")))






