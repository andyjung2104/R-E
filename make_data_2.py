import random, math

n=50
file = open('ising_test_2.txt','w')
file.write(str(n)+"\n")
coor1 = [(random.random()/math.sqrt(2),random.random()/math.sqrt(2)) for i in range(n)]
coor2 = [(random.random()/math.sqrt(2),random.random()/math.sqrt(2)) for i in range(n)]

for i in range(n):
    for j in range(n):
        ll=((coor1[i][0]-coor2[j][0])**2+(coor1[i][1]-coor2[j][1])**2)**.5
        file.write(f"{ll} ")
    file.write("\n")
file.close()