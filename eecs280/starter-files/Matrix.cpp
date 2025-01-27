// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Matrix.h"

using namespace std;

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
    // TODO Replace with your implementation!
    assert(width > 0 && width <= MAX_MATRIX_WIDTH);
    assert(height > 0 && height <= MAX_MATRIX_HEIGHT);
    mat->height = height;
    mat->width = width;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//           WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
    // TODO Replace with your implementation!
    os << mat->width << ' ' << mat->height << endl;
    for (int i = 0; i < mat->height; ++i) {
        for (int j = 0; j < mat->width; ++j) {
            os << mat->data[i * mat->width + j] << ' ';
        }
        os << endl;
    }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
    // TODO Replace with your implementation!
    return mat->width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
    // TODO Replace with your implementation!
    return mat->height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
    // TODO Replace with your implementation!
    return (ptr - mat->data) / mat->width;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
    // TODO Replace with your implementation!
    return (ptr - mat->data) % mat->width;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
    // TODO Replace with your implementation!
    assert(row >= 0 && row < mat->height);
    assert(column >= 0 && column < mat->width);
    return mat->data + row * mat->width + column;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
    // TODO Replace with your implementation!
    assert(row >= 0 && row < mat->height);
    assert(column >= 0 && column < mat->width);
    return mat->data + row * mat->width + column;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
    // TODO Replace with your implementation!
    for (int i = 0; i < mat->height; ++i) {
        for (int j = 0; j < mat->width; ++j) {
            mat->data[i * mat->width + j] = value;
        }
    }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
    // TODO Replace with your implementation!
    for (int i = 0; i < mat->width; ++i) {
        mat->data[i] = value;
        mat->data[mat->width * mat->height - i - 1] = value;
    }
    for (int i = 0; i < mat->height; ++i) {
        mat->data[i * mat->width] = value;
        mat->data[(i + 1) * mat->width - 1] = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
    // TODO Replace with your implementation!
    int result = mat->data[0];
    for (int i = 0; i < mat->width * mat->height; ++i) {
        if (result < mat->data[i]) {
            result = mat->data[i];
        }
    }
    return result;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    // TODO Replace with your implementation!
    assert(row >= 0 && row < mat->height);
    assert(column_start >= 0 && column_end <= mat->width && column_start < column_end);
    int result = column_start;
    for (int i = column_start; i < column_end; ++i) {
        if (mat->data[row * mat->width + i] < mat->data[row * mat->width + result]) {
            result = i;
        }
    }
    return result;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    // TODO Replace with your implementation!
    assert(row >= 0 && row < mat->height);
    assert(column_start >= 0 && column_end <= mat->width && column_start < column_end);
    int result = mat->data[row * mat->width + column_start];
    for (int i = column_start; i < column_end; ++i) {
        if (mat->data[row * mat->width + i] < result) {
            result = mat->data[row * mat->width + i];
        }
    }
    return result;
}
