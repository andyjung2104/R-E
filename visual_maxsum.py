import matplotlib.pyplot as plt
import random

def randcolor():
    return "#"+''.join([random.choice('ABCDEF0123456789') for i in range(6)])

#region input
input_filename = "maxsumtest1"
coordinates = open(input_filename + ".txt",'r')
coor = []
lines = coordinates.readlines()
coordinates.close()
for line in lines:
    coor.append(tuple(map(float,line.split())))
n=coor.pop(0)[0]
n=int(n+.5)
#endregion


#region girlboy
n//=2
girl = [coor[i] for i in range(n)]
boy = [coor[i] for i in range(n,2*n)]
#endregion
for i in range(n):
    plt.plot([girl[i][0]],[girl[i][1]],color = 'red', marker = '.')
    plt.plot([boy[i][0]],[boy[i][1]],color = 'blue', marker = '.')


op = open(input_filename + '_output.txt','r')
lines = op.readlines()
for line in lines:
    i,j=map(int,line.split())
    plt.plot([girl[i][0],boy[j][0]],[girl[i][1],boy[j][1]], color = 'black')
op.close()

plt.show()
