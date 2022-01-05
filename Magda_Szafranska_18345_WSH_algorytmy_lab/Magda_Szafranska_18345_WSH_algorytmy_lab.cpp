// Autor: Magda Szafrañska, nr indeksu WSH: 18345
// Informatyka NST, rok 2, sem. 3
// Algorytmy, laboratoria nr 1

#include <iostream>
#include <windows.h>        // to the GetTickCount() function

using namespace std;

// Prototypes of functions (declarations)
double** CreateTab(int rowCount, int colCount);
void RandomTab(int rowCount, int colCount, double** tab);
void PrintTab(int rowCount, int colCount, double** tab);
void DeleteTab(int rowCount, int colCount, double** tab);
void AddTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3);
void SubtractTab(int rowCount, int colCount, double** tab1, double** tab2, double** tab3);
void CopyTab(int rowCount, int colCount, double** tab1, double** tab2);
void TransTab(int rowCount, int colCount, double** tab, double** temp_tab);
void MulTab(int rowCount, int colCount, int colCount2, double** tab1, double** tab2, double** tab3);    // colCount2 to liczba kolumn wynikowej
void ExecutionTimeByGetTickCount64(int startTime, int stopTime);

int main()
{
    int rowCount = 5;
    int colCount = 4;
    int colCount2 = 3;          // another dimension to multiple arrays

    // for measuring the execution time
    int executableTime;         // the difference between start and stop time by GetTickCount64() function
    int startT1, stopT1;        // start and stop measures by GetTickCount64() function

    double** tab1 = CreateTab(rowCount, colCount);
    double** tab2 = CreateTab(rowCount, colCount);
    double** tab3 = CreateTab(rowCount, colCount);              // to keep the result of operations
    double** tab4 = CreateTab(rowCount, colCount);              // to copy here another values of an array
    double** transTab = CreateTab(colCount, rowCount);          // to transposition an array
    double** tab5 = CreateTab(colCount, colCount2);             // to multiplication for the second array
    double** tabMultiplication = CreateTab(rowCount, colCount2);// to keep the result of multiplication two arrays

    cout << "Matrix 1" << endl;
    // start to measure the time
    startT1 = (int)GetTickCount64();
    RandomTab(rowCount, colCount, tab1);
    PrintTab(rowCount, colCount, tab1);
    // stop to measure the time
    stopT1 = (int)GetTickCount64();
    ExecutionTimeByGetTickCount64(startT1, stopT1);

    cout << endl << "Matrix 5 to multiplication" << endl;
    RandomTab(colCount, colCount2, tab5);
    PrintTab(colCount, colCount2, tab5);

    cout << endl << "Multiplication of matrix 1 and 5" << endl;
    // start to measure the time
    startT1 = (int)GetTickCount64();
    MulTab(rowCount, colCount, colCount2, tab1, tab5, tabMultiplication);
    PrintTab(rowCount, colCount2, tabMultiplication);
    // stop to measure the time
    stopT1 = (int)GetTickCount64();
    ExecutionTimeByGetTickCount64(startT1, stopT1);

    // Transposition of matrix 1 with result in transTab
    cout << endl << "Transposition of matrix 1" << endl;
    // start to measure the time
    startT1 = (int)GetTickCount64();
    TransTab(rowCount, colCount, tab1, transTab);
    PrintTab(colCount, rowCount, transTab);
    // stop to measure the time
    stopT1 = (int)GetTickCount64();
    ExecutionTimeByGetTickCount64(startT1, stopT1);

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
    DeleteTab(colCount, rowCount, transTab);
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
void TransTab(int rowCount, int colCount, double** tab, double** temp_tab)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            temp_tab[j][i] = tab[i][j];
        }
    }
}
void MulTab(int RowCount, int ColCount, int ColCount2, double** Tab, double** Tab2, double** Tab3)
{
    for (int i = 0; i < RowCount; ++i)
    {
        for (int j = 0; j < ColCount2; ++j)
        {
            double sum = 0;
            for (int k = 0; k < ColCount; ++k)
            {
                sum += Tab[i][k] * Tab2[k][j];
            }
            Tab3[i][j] = sum;
        }
    }
}
void ExecutionTimeByGetTickCount64(int startTime, int stopTime)
{
    int executableTime = stopTime - startTime;

    // changing colour in the console window for better clarity of the code
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

    cout << endl << "Execution time with GetTickCount64() function: " << executableTime << " miliseconds." << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}