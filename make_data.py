import random

n=5000
file = open('okok.txt','w')
file.write(str(n)+"\n")
for i in range(n):
    r1=random.uniform(0,1000)
    r2=random.uniform(0,1000)
    file.write(f"{r1} {r2}\n")
file.close()
