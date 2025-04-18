def is_leap(year):
    leap = False
    
    # Write your logic here
    is_divisible = lambda year, divisor : divisor != 0 and (year % divisor) == 0
    
    if is_divisible(year, 4) and not is_divisible(year, 100) or is_divisible(year, 400):
        leap = True
        
    return leap

year = int(input())
print(is_leap(year))