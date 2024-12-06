//THIS WHOLE FILE IS NEW
#pragma once
#pragma once

#include "Particle.h"
#include "Matrices.h"

namespace Matrices
{
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