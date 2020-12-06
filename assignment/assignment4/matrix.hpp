#ifndef MATRIX
#define MATRIX
#include <iostream>
using namespace std;

class Matrix
{
private:
    int row;
    int col;
    float *entry;
    int * refcount;
public:
    Matrix() {row = 1; col = 1; *entry = 1.0;}
    Matrix(int r, int c);
    Matrix(int r, int c, float *e, int * rv);
    Matrix(const Matrix &mat) {row = mat.row; col = mat.col; entry = mat.entry;}
    ~Matrix() {release();}
    static inline int CV_XADD(int* addr, int delta){int tmp = * addr; * addr += delta; return tmp;}
    static inline void matmul_n(size_t r1, size_t c, size_t c2, float * m1, float * m2, float * result);

    Matrix &operator = (const Matrix & mat);
    Matrix &operator + (const Matrix & mat);
    Matrix &operator - (const Matrix & mat);
    Matrix &operator * (const Matrix & mat);

    int GetRow() {return row;}
    int GetCol() {return col;}
    void release();
    friend std::ostream & operator <<(std::ostream &os, const Matrix & other);
    friend Matrix operator *(double real, const Matrix & mat);
    friend Matrix operator *(const Matrix & mat,double real);
};
#endif