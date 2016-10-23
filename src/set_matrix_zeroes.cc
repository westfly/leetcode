#include "code_utils.h"

// 用空间记录0的i,j位置
// 后面这种方法是将j,i的位置投影到横纵坐标上，因为坐标做了投影
// 所以0需要做特殊处理
void setZeroes(vector<vector<int> > &matrix)
{
    bool bColZero = false, bRowZero = false;

    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return;
    }

    // Mark bColZero true when col[0] contains zero.
    for (size_t row = 0; row < matrix.size(); ++row)
    {
        if (!matrix[row][0]) bColZero = true;
    }

    // Mark bRowZero true when row[0] contains zero.
    for (size_t col = 0; col < matrix[0].size(); ++col)
    {
        if (!matrix[0][col]) bRowZero = true;
    }

    // Map zero points to row[0] and col[0].
    for (size_t row = 1; row < matrix.size(); ++row)
    {
        for (size_t col = 1; col < matrix[row].size(); ++col)
        {
            if (!matrix[row][col])
            {
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }

    // Set zero according to row[0] and col[0].
    for (size_t row = 1; row < matrix.size(); ++row)
    {
        for (size_t col = 1; col < matrix[row].size(); ++col)
        {
           if (!matrix[row][0] || !matrix[0][col])
           {
               matrix[row][col] = 0;
           }
        }
    }

    // Process col[0].
    if (bColZero)
    {
        for (size_t row = 0; row < matrix.size(); ++row)
        {
            matrix[row][0] = 0;
        }
    }

    // Process row[0].
    if (bRowZero)
    {
        for (size_t col = 0; col < matrix[0].size(); ++col)
        {
            matrix[0][col] = 0;
        }
    }
}
int main(int argc, char* argv[]) {

	return 0;
}

