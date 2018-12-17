#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept> 

using namespace std;

class Matrix {
private:
	vector<vector<int>> matrix;
	int columns = 0, rows = 0;
public:
	Matrix() {
	}
	Matrix(int num_rows, int num_cols) {
		if (num_rows < 0 or num_cols < 0) {
			throw out_of_range("");
		}
		columns = num_cols;
		rows = num_rows;
		vector<vector<int>> A(rows, vector<int>(columns));
		matrix = A;
	}
	void Reset(int num_rows, int num_cols) {
		Matrix(num_rows, num_cols);
	}
	int At(int row, int column) const {
		if (row >= 0 && row < rows
			&& column >= 0 && column < columns) {
			return matrix[row][column];
		} else {
			throw out_of_range("");

		}
	}
	int& At(int row, int column) {
		if (row >= 0 && row < rows
			&& column >= 0 && column < columns) {
			return matrix[row][column];
		} else {
			throw out_of_range("");
		}
	}
	int GetNumRows() const {
		return rows;
	}
	int GetNumColumns() const {
		return columns;
	}
};

ostream& operator <<(ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int i = 0; i < matrix.GetNumRows(); ++i) {
    	for (int j = 0; j < matrix.GetNumColumns(); ++j) {
    		stream << matrix.At(i, j);
    		if (j != matrix.GetNumColumns() - 1) {
    			stream << " ";
    		}
    	}
    	stream << endl;
    }
    return stream;
}

istream& operator >>(istream& stream, Matrix& matrix) {
	int rows = 0, columns = 0;
    stream >> rows >> columns;
    matrix = Matrix(rows, columns);
    for (int i = 0; i < matrix.GetNumRows(); ++i) {
    	for (int j = 0; j < matrix.GetNumColumns(); ++j) {
    		stream >> matrix.At(i, j);
    	}
    }
    return stream;
}

bool operator ==(const Matrix& left, const Matrix& right) {
	if (left.GetNumRows() == right.GetNumRows() && left.GetNumColumns() == right.GetNumColumns()) {
		for (int i = 0; i < left.GetNumRows(); ++i) {
			for (int j = 0; i < left.GetNumColumns(); ++j) {
				if (left.At(i, j) != right.At(i, j)) {
					return false;
				}
			}
		}
		return true;
	} else {
		return false;
	}
}

Matrix operator +(const Matrix& left, const Matrix& right) {
	if (left.GetNumRows() == right.GetNumRows() && left.GetNumColumns() == right.GetNumColumns()) {
		Matrix the_sum = left;
		for (int i = 0; i < the_sum.GetNumRows(); ++i) {
			for (int j = 0; j < the_sum.GetNumColumns(); ++j) {
				the_sum.At(i, j) += right.At(i, j);
			}
		}
		return the_sum;
	} else {
		throw invalid_argument("");
	}
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}