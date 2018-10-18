def main():
    inps = list(map(int, input().rstrip().split()))
    n,k,total = inps[0], inps[1],0
    l = list(map(int, input().rstrip().split()))

    for i in range(len(l)-1, 0, -1):
        if(l[len(l)-1] != l[i-1]):
            total = i
            break 
    if total >= k:
        total = -1
    print(total)

main()
