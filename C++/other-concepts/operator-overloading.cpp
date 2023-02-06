#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
class Matrix
{
public:
   void populate(std::istream & input, unsigned no_of_rows, unsigned no_of_columns) {
      data.reserve(no_of_rows);
      for (auto row = unsigned{0}; row < no_of_rows; row++) {
         auto elements_in_row = std::vector<T>{};
         elements_in_row.reserve(no_of_columns);
         std::copy_n(std::istream_iterator<T>(input),
                     no_of_columns,
                     std::back_inserter(elements_in_row));

         data.push_back(std::move(elements_in_row));
      }
   };

   Matrix& operator+(Matrix const& rhs) {
      std::transform(this->data.begin(),
                     this->data.end(),
                     rhs.data.begin(),
                     this->data.begin(), 
                     [](auto& row1, auto& row2) {
                        std::transform(row1.begin(),
                                       row1.end(),
                                       row2.begin(),
                                       row1.begin(),
                                       std::plus<>{});
                        return row1;});
      return *this;
      };

   friend std::ostream& operator<<(std::ostream & os, Matrix const& matrix) {
      std::for_each(matrix.data.begin(), matrix.data.end(), [&os](auto row){
         std::copy(row.begin(), row.end(), std::ostream_iterator<T>(os, " "));
         os << '\n';
      });
      return os;
   };

private:
   std::vector<std::vector<T>> data;
};

int main ()
{
   auto no_of_rows = unsigned{};
   auto no_of_columns = unsigned{};
   auto no_of_tests = unsigned{};
   std::cin >> no_of_tests;

   for (auto test = unsigned{0}; test < no_of_tests; test++) {
      auto first_matrix = Matrix<unsigned>{};
      auto second_matrix = Matrix<unsigned>{};
      auto result = Matrix<unsigned>{};

      std::cin >> no_of_rows >> no_of_columns;

      first_matrix.populate(std::cin, no_of_rows, no_of_columns);
      second_matrix.populate(std::cin, no_of_rows, no_of_columns);

      result = first_matrix + second_matrix;
      std::cout << result;
   }  
   return 0;
}