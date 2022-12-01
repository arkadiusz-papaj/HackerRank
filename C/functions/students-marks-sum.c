//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  //index 0,2,4 -> boy
  //index 1,3,5 -> girl
  //offset depends on gender
  enum Offset {BOYS = 0, GIRLS = 1};
  unsigned long sum_of_gender_marks = 0;
  
  for (int i = ((gender == 'b') ? BOYS : GIRLS); i < number_of_students; i += 2){
      sum_of_gender_marks += marks[i];
  }
  
  return sum_of_gender_marks;
}