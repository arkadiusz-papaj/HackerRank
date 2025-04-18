if __name__ == '__main__':
    N = int(input())
    list_to_modify = []
    actions = {
        "insert" : lambda lst, position, value : lst.insert(position, value),
        "print"  : lambda lst                  : print(lst),
        "remove" : lambda lst, value           : lst.remove(value),
        "append" : lambda lst, value           : lst.append(value),
        "sort"   : lambda lst                  : lst.sort(),
        "pop"    : lambda lst                  : lst.pop(),
        "reverse": lambda lst                  : lst.reverse()
    }
    
    for _ in range(N):
        command, *args = input().split()
        actions[command](list_to_modify, *map(int, args))