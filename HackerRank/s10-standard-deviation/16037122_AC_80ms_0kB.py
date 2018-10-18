import statistics as st

def main():
    n = int(input())
    x = list(map(int, input().split()))
    
    print("%.1f"%st.pstdev(x))
main()