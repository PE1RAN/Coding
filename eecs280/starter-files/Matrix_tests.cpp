// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.
TEST(test_1) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 1, 1);
    Matrix_fill_border(mat, 1);
    Matrix* tam = new Matrix;
    Matrix_init(tam, 1, 1);
    Matrix_fill(tam, 1);
    ASSERT_TRUE(Matrix_equal(mat, tam));
    delete mat;
    delete tam;
}

TEST(test_2) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 2, 2);
    Matrix_fill_border(mat, 1);
    Matrix* tam = new Matrix;
    Matrix_init(tam, 2, 2);
    Matrix_fill(tam, 1);
    ASSERT_TRUE(Matrix_equal(mat, tam));
    delete mat;
    delete tam;
}

TEST(test_3) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill_border(mat, 1);
    *Matrix_at(mat, 1, 1) = 1;
    Matrix* tam = new Matrix;
    Matrix_init(tam, 3, 3);
    Matrix_fill(tam, 1);
    ASSERT_TRUE(Matrix_equal(mat, tam));
    delete mat;
    delete tam;
}

TEST(test_4) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 7);
    ASSERT_EQUAL(Matrix_height(mat), 7);
    ASSERT_EQUAL(Matrix_width(mat), 5);
    delete mat;
}

TEST(test_5) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 9, 6);
    Matrix_fill(mat, 5);
    ASSERT_EQUAL(Matrix_row(mat, Matrix_at(mat, 2, 3)), 2);
    ASSERT_EQUAL(Matrix_column(mat, Matrix_at(mat, 2, 3)), 3);
    delete mat;
}

TEST(test_6) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 5);
    ASSERT_EQUAL(Matrix_max(mat), 5);
    *Matrix_at(mat, 2, 2) = 114514;
    ASSERT_EQUAL(Matrix_max(mat), 114514);
    delete mat;
}

TEST(test_7) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 5);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 4), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 4), 5);
    *Matrix_at(mat, 2, 4) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 4), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 4), 5);
    *Matrix_at(mat, 2, 2) = 1;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 4), 2);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 4), 1);
    *Matrix_at(mat, 2, 1) = 0;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 1, 4), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 1, 4), 0);
    delete mat;
}

TEST(test_8) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 5, 3);
    Matrix_fill(mat, 5);
    *Matrix_at(mat, 2, 4) = 1;
    *Matrix_at(mat, 2, 2) = 1;
    *Matrix_at(mat, 2, 1) = 0;
    ostringstream s;
    Matrix_print(mat, s);
    ostringstream correct;
    correct << "5 3\n"
            << "5 5 5 5 5 \n"
            << "5 5 5 5 5 \n"
            << "5 0 1 5 1 \n";
    ASSERT_EQUAL(s.str(), correct.str());
    delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
