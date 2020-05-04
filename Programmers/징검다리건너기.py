def check(stones,t,k):
    cnt = 0
    for stone in stones:
        if stone-k<=0:
            cnt+=1
        else:
            cnt=0
        if cnt>=t:
            return False
    return True
def solution(stones, k):
    i=200000001
    j=0
    for stone in stones:
        i = min(stone,i)
        j = max(stone,j)
    
    while i<=j:
        m = int((i+j)/2)
        if check(stones,k,m):
            i=m+1
        else:
            j=m-1
    return i