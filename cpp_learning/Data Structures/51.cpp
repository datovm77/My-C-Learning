#include <iostream>
using namespace std;

const int SRC_ROWS = 2;
const int SRC_COLS = 3;
const int DST_ROWS = 3;
const int DST_COLS = 2;

void rotateLeft90(int *src, int *dst)
{
    for (int row = 0; row < DST_ROWS; row++) {
        for (int col = 0; col < DST_COLS; col++) {
            int srcIndex = col * SRC_COLS + (SRC_COLS - 1 - row);
            int dstIndex = row * DST_COLS + col;
            *(dst + dstIndex) = *(src + srcIndex);
        }
    }
}

void printMatrix(int *mat, int rows, int cols)
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << *(mat + row * cols + col) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int srcMatrix[SRC_ROWS][SRC_COLS];
        int rotatedMatrix[DST_ROWS][DST_COLS];

        for (int i = 0; i < SRC_ROWS; i++) {
            for (int j = 0; j < SRC_COLS; j++) {
                cin >> srcMatrix[i][j];
            }
        }

        int *srcPtr = *srcMatrix;
        int *rotatedPtr = *rotatedMatrix;

        rotateLeft90(srcPtr, rotatedPtr);
        printMatrix(rotatedPtr, DST_ROWS, DST_COLS);
    }

    return 0;
}
