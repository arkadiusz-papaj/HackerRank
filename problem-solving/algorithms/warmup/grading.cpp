#include <vector>
#include <algorithm>

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

[[nodiscard]] auto gradingStudents(std::vector<int> grades) noexcept -> std::vector<int> {
    std::for_each(grades.begin(), grades.end(), [](auto & grade){
        if ((grade >= 38) && (grade % 5 > 2)) {
            grade = int{(grade / 5) + 1} * 5;
        }
    });

    return grades;
}