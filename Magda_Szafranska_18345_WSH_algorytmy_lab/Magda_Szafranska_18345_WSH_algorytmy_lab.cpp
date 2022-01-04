// Autor: Magda Szafrañska, nr indeksu WSH: 18345
// Informatyka NST, rok 2, sem. 3
// Algorytmy, laboratoria nr 1

#include <iostream>

using namespace std;

double** CreateTab(int rowCount, int colCount);
void RandomTab(int rowCount, int colCount, double** tab);
void PrintTab(int rowCount, int colCount, double** tab);
void DeleteTab(int rowCount, int colCount, double** tab);

int main()
{
    int rowCount = 5;
    int colCount = 4;
    double** tab1 = CreateTab(rowCount, colCount);
    RandomTab(rowCount, colCount, tab1);
    PrintTab(rowCount, colCount, tab1);

    // deleting created matrix
    DeleteTab(rowCount, colCount, tab1);
}

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