//THIS WHOLE FILE IS NEW
#pragma once
#pragma once

#include "Particle.h"
#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix()
	{
		cout << "this isnt supposed to show up. Defalt Matrix constrcutor called" << endl;
	}
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;
		a.resize(rows);
		for (int i = 0; i < rows; i++)
		{
			a.at(i).resize(cols);
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				a.at(i).at(j) = 0.0;
			}
		}
		//ALSO WORKS: a = vector<vector<double>>(rows, vector<double>(cols,0);
		//this is a really dense version of the for loops above, it does the same thing.
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if ((a.getRows() != b.getRows()) || (a.getCols() != b.getCols()))
		{
			throw runtime_error("Error: dimensions must agree");
		}
		else
		{
			Matrix c(a.getRows(), a.getCols());
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					c(i, j) = a(i, j) + b(i, j);
				}
			}
			return c;
		}
	}

///Matrix multiply.  See description.
///usage:  c = a * b;
	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		//ermm what the scallop
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}
		else
		{
			Matrix c(a.getRows(), b.getCols());
			for (int k = 0; k < b.getCols(); k++)
			{
				for (int i = 0; i < a.getRows(); i++)
				{
					for (int j = 0; j < a.getCols(); j++)
					{
						c(i, k) += a(i, j) * b(j, k);
					}
				}
			}
			return c;
		}
	}

///Matrix comparison.  See description.
///usage:  a == b
	bool operator==(const Matrix& a, const Matrix& b)
	{
		if ((a.getRows() != b.getRows()) || (a.getCols() != b.getCols()))
		{
			return false;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) < 0.001)
					{

					}
					else
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		if ((a.getRows() != b.getRows()) || (a.getCols() != b.getCols()))
		{
			return true;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) > 0.001)
					{

					}
					else
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				os << setw(10) << a(i, j) << ' ';
			}
			os << '\n' << '\n';
		}
		return os;
	}
};

	

///2D rotation matrix
	///usage:  A = R * A rotates A theta radians counter-clockwise
	///Call the parent constructor to create a 2x2 matrix
	///Then assign each element as follows:
	/*
	cos(theta)  -sin(theta)
	sin(theta)   cos(theta)
	*/
	///theta represents the angle of rotation in radians, counter-clockwise
	RotationMatrix::RotationMatrix(double theta) :Matrix(2, 2)
	{
		//DONE
		a.at(0).at(0) = cos(theta);
		a.at(0).at(1) = -sin(theta);
		a.at(1).at(0) = sin(theta);
		a.at(1).at(1) = cos(theta);
	}

///2D scaling matrix
///usage:  A = S * A expands or contracts A by the specified scaling factor


	///Call the parent constructor to create a 2x2 matrix
	///Then assign each element as follows:
	/*
	scale   0
	0       scale
	*/
	///scale represents the size multiplier
	ScalingMatrix::ScalingMatrix(double scale) :Matrix(2, 2)
	{
		//DONE
		a.at(0).at(0) = scale;
		a.at(0).at(1) = 0;
		a.at(1).at(0) = 0;
		a.at(1).at(1) = scale;
	}


///2D Translation matrix
///usage:  A = T + A will shift all coordinates of A by (xShift, yShift)


	///Call the parent constructor to create a 2xn matrix
	///Then assign each element as follows:
	/*
	xShift  xShift  xShift  ...
	yShift  yShift  yShift  ...
	*/
	///paramaters are xShift, yShift, and nCols
	///nCols represents the number of columns in the matrix
	///where each column contains one (x,y) coordinate pair
	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) :Matrix(2, nCols)
	{
		//DONE
		for (int j = 0; j < nCols; j++)
		{
			a.at(0).at(j) = xShift;
			a.at(1).at(j) = yShift;
		}
	}
