def main():
    s = input()
    sdist = list(set(s))
    l = len(sdist)
    if(l % 2 == 0):
        print("CHAT WITH HER!")
    else:
        print("IGNORE HIM!")
main()
