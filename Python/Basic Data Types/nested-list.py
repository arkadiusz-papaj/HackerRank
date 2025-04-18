if __name__ == '__main__':
    students_list = [[input(), float(input())] for _ in range(int(input()))]
    second_lowest_score = sorted({score for _, score in students_list})[1]
    students_with_second_lowest_score = sorted([name for name, score in students_list if (score == second_lowest_score)])
    
    print(*students_with_second_lowest_score, sep='\n')
