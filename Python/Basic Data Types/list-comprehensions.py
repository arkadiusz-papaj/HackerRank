if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    
    permutations = [[xx, yy, zz] for xx in range(x+1) for yy in range(y+1) for zz in range(z+1) if xx+yy+zz != n]
    
    print(permutations)