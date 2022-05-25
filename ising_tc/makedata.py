import random, math
n=200
for tc in range(1, 101):
    file = open(f'ising_tc_{n}_{tc}.txt','w')
    file.write(str(n)+"\n")
    coor1 = [(random.random()/math.sqrt(2),random.random()/math.sqrt(2)) for i in range(n)]
    coor2 = [(random.random()/math.sqrt(2),random.random()/math.sqrt(2)) for i in range(n)]
    for i in range(n):
        for j in range(n):
            ll=((coor1[i][0]-coor2[j][0])**2+(coor1[i][1]-coor2[j][1])**2)**.5
            file.write(f"{ll} ")
        file.write("\n")
    file.close()