#include <string.h>
#include <stdio.h>

class EightQueen
{
public:
    EightQueen()
    {
        memset(chessboard_, 0, sizeof(chessboard_));
    }

    void result()
    {
        resolve(0);
    }

private:
    void resolve(int row)
    {
        if (row == 8)
        {
            print();
        }
        else
        {
            for (int j = 0; j < 8; ++j)
            {
                chessboard_[row][j] = 1;
                if (check(row, j))
                {
                    resolve(row + 1);
                }
                chessboard_[row][j] = 0;
            }
        }
    }

    bool check(int row, int column)
    {
        if (row == 0)
        {
            return true;
        }
        for (int i = 0; i < row; ++i)
        {
            if (chessboard_[i][column] == 1)
            {
                return false;
            }
        }
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (chessboard_[i][j] == 1)
            {
                return false;
            }
        }
        for (int i = row - 1, j = column + 1; i >= 0 && j < 8; --i, ++j)
        {
            if (chessboard_[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }

    void print()
    {
        static int count = 0;
        printf("The %d solution:\n", ++count);
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                printf("%2d ", chessboard_[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int chessboard_[8][8];
};

int main(int argc, char const *argv[])
{
    EightQueen obj;
    obj.result();
    return 0;
}
