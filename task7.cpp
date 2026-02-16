#include <iostream>
using namespace std;

int main() 
{
	int rows, columns;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    
    int** matrix = new int*[rows];

    
    for(int i = 0; i < rows; i++) 
	{
        matrix[i] = new int[columns];
    }

    
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < rows; i++) 
	{
        for(int j = 0; j < columns; j++) 
		{
            cin >> matrix[i][j];
        }
    }

    
    cout << "\nMatrix is:\n";
    for(int i = 0; i < rows; i++) 
	{
        for(int j = 0; j < columns; j++) 
		{
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    for(int i = 0; i < rows; i++) 
	{
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}

