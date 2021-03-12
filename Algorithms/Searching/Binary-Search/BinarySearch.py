# Binary Search
def bina(l,low,high,a) :
    mid=(low+high)//2
    if low>high :
        return False
    elif a<l[mid] :
        return(bina(l,low,mid-1,a))
    elif a>l[mid] :
        return(bina(l,low+1,high,a))
    elif a==l[mid] :
        return True
n=int(input())
l=[]
for i in range(n) :
    l.append(int(input()))
l.sort()
b=int(input())
print(bina(l,0,len(l)-1,b))
