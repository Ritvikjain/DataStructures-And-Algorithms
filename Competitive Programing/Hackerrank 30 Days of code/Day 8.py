# Enter your code here. Read input from STDIN. Print output to STDOUT
d={}
l=[]
n=int(input())
for i in range(n):
    str=input()
    str1,str2=str.split(" ")
    d[str1]=str2
    l.append(str1)
for i in range(n):
    str=input()
    if str in d:
        print(str+"="+d[str])
    else:
        print("Not found")
