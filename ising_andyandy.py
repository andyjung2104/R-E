import math,random

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

T=10**-2

A=[[0]*n for i in range(n)]
R=[[0]*n for i in range(n)]

iter = 5000
#naive
for it in range(iter):
    for k in range(n):
        tmp=sum(math.exp((R[k][b]+w[k][b]/2)/T) for b in range(n))
        for a in range(n):
            A[k][a]=w[k][a]/2 - T*math.log(tmp-math.exp((R[k][a]+w[k][a]/2)/T))

    for a in range(n):
        tmp = sum([math.exp((A[j][a]+w[j][a]/2)/T) for j in range(n)])
        for k in range(n):
            R[k][a]=w[k][a]/2 - T*math.log(tmp-math.exp((A[k][a]+w[k][a]/2)/T))



output = []
for i in range(n):
    for j in range(n):
        if R[i][j]+A[i][j]>0:
            output.append((i,j))
#disable for large n
for i in range(n):
    for j in range(n):
        if (i,j) in output:
            print(1,end=" ")
        else:
            print(0,end=" ")
    print()
op_file = open(filename+"_output.txt",'w')
for op in output:
    op_file.write(f"{op[0]} {op[1]}\n")
op_file.close()