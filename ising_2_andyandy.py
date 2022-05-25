import math

#region readinput
filename = "ising_test_2"
inputfile = open(filename+".txt",'r')
lines = inputfile.readlines()
n=int(lines[0])
w=[]
for i in range(1,1+n):
    w.append(list(map(float,lines[i].split())))
w=[[-u for u in w[i]] for i in range(n)]
inputfile.close()