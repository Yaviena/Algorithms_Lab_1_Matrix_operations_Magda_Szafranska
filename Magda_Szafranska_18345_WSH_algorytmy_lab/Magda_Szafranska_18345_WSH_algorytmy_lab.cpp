// Autor: Magda Szafrañska, nr indeksu WSH: 18345
// Informatyka NST, rok 2, sem. 3
// Algorytmy, laboratoria nr 1

#include <iostream>

using namespace std;

// Prototypes of functions (declarations)
double** CreateTab(int rowCount, int colCount);
void RandomTab(int rowCount, int colCount, double** tab);
void PrintTab(int rowCount, int colCount, double** tab);
void DeleteTab(int rowCount, int colCount, double** tab);
void AddTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3);
void SubtractTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3);
void CopyTab(int rowCount, int colCount, double** tab1, double** tab2);

int main()
{
    int rowCount = 5;
    int colCount = 4;

    double** tab1 = CreateTab(rowCount, colCount);
    double** tab2 = CreateTab(rowCount, colCount);
    double** tab3 = CreateTab(rowCount, colCount);      // to keep the result of operations
    double** tab4 = CreateTab(rowCount, colCount);      // to copy here another values of an array

    cout << "Matrix 1" << endl;
    RandomTab(rowCount, colCount, tab1);
    PrintTab(rowCount, colCount, tab1);

    cout << endl << "Copied matrix 1 to empty matrix" << endl;
    CopyTab(rowCount, colCount, tab1, tab4);
    PrintTab(rowCount, colCount, tab4);

    cout << endl << "Matrix 2" << endl;
    RandomTab(rowCount, colCount, tab2);
    PrintTab(rowCount, colCount, tab2);

    cout << endl << "Addition matrix 1 and 2" << endl;
    AddTab(rowCount, colCount, tab1, tab2, tab3);
    PrintTab(rowCount, colCount, tab3);

    cout << endl << "Subtraction matrix 1 and 2" << endl;
    SubtractTab(rowCount, colCount, tab1, tab2, tab3);
    PrintTab(rowCount, colCount, tab3);

    // deleting all created arrays
    DeleteTab(rowCount, colCount, tab1);
    DeleteTab(rowCount, colCount, tab2);
    DeleteTab(rowCount, colCount, tab3);
    DeleteTab(rowCount, colCount, tab4);
}

// Definitions of the functions (the bodies of the functions)
double** CreateTab(int rowCount, int colCount)
{
    double** tab = new double* [rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        tab[i] = new double[colCount];
    }
    return tab;
}
void RandomTab(int rowCount, int colCount, double** tab)
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            tab[i][j] = (rand() % 101) / 100.0;
        }
    }
}
void PrintTab(int rowCount, int colCount, double** tab)
{
    for (int i = 0; i < rowCount; ++i)
    {
        printf("%.2f", tab[i][0]);
        for (int j = 1; j < colCount; j++)
        {
            printf(", %.2f", tab[i][j]);
        }
        printf("\n");
    }
}
void DeleteTab(int rowCount, int colCount, double** tab)
{
    for (int i = 0; i < rowCount; i++)
        delete[] tab[i];

    delete[] tab;
}
void AddTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3)
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            tab3[i][j] = tab1[i][j] + tab2[i][j];
        }
    }
}
void SubtractTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3)
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            tab3[i][j] = tab1[i][j] - tab2[i][j];
        }
    }
}
void CopyTab(int rowCount, int colCount, double** tab1, double** tab2)
{
    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            tab2[i][j] = tab1[i][j];
        }
    }
}