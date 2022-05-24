import matplotlib.pyplot as plt
import random

def randcolor():
    return "#"+''.join([random.choice('ABCDEF0123456789') for i in range(6)])

#region input
input_filename = "test1"
coordinates = open(input_filename + ".txt",'r')
coor = []
lines = coordinates.readlines()
for line in lines:
    coor.append(tuple(map(float,line.split())))
n=coor.pop(0)[0]
n=int(n+.5)

exemplars = []
exem = open(input_filename + '_output.txt','r')
line = exem.readline()
exemplars = list(map(int,line.split()))
#endregion

colordict = {}

for exemplar in set(exemplars):
    colordict[exemplar]=randcolor()
for i in range(n):
    if i==exemplars[i]:
        plt.plot([coor[i][0]],[coor[i][1]],color = colordict[exemplars[i]], marker = 'D')
    else:
        plt.plot([coor[i][0]],[coor[i][1]],color = colordict[exemplars[i]], marker = 'o')
        plt.plot([coor[i][0],coor[exemplars[i]][0]],[coor[i][1],coor[exemplars[i]][1]],color = 'black')

plt.show()
