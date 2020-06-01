
def getaddr(x, y):
    address = 0
    printstr = '{'
    if(x > 38 or y > 8):
        return 0

    if(x <= 29 and y <= 5): # page 0
        address = y*0x1E #base address of Y
        address += x
        printstr += str(hex(address)) + ', ' + '0}, '
        

    else:
        if(x<=29 and y>=6): #page 1
            address = (y-6)*0x1E
            address += x
            printstr += str(hex(address)) + ', ' + '1}, '

        
        else:           # page 1
            address = y*9
            address += 0x5A
            address += (x-30)
            printstr += str(hex(address)) + ', ' + '1}, '

    print(printstr, end = ' ')
    return address

print("byte addrmap[9][39] = {", end = '')
for i in range(9):
    print("{", end = '')
    for j in range(39):
        #print(hex(getaddr(j, i)), end = '')
        getaddr(j, i)   
    print("}, \\", end = '')
    print('\n', end = '')

print("};", end = '')
