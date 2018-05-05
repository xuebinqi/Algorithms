/*
Strassen Algorithm Implementation in C++
Coded By: QiXuebin in May 5 2018 .
--------------------------------------------
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

int strassen(int **, int **, int **, int); // Multiplies Two Matrices recrusively.

int add(int **, int **, int **, int); // Adds two Matrices, and places the result in another Matrix

int sub(int **, int **, int **, int); // Subtracts two Matrices , and places  the result in another Matrix

int multi(int **, int **, int **, int); // Multiplies two matrices in conventional way.

void fillMatrix(int **, int **, int); // Fills Matrices with random numbers.

void printMatrix(int **, int); // prints the Matrix content.


int main() {
	int matrixSize = 0; // the size of the Matrix
	int **matrixA;
	int **matrixB;
	int **matrixC;

	// Compute the time consumed by normal method
	clock_t startTimeForNormalMultipilication;
	clock_t endTimeForNormalMultipilication;

	// Compute the time consumed by Strssen method
	clock_t startTimeForStrassen;
	clock_t endTimeForStrassen;

	srand(time(0)); //set seed for rand number

	cout << endl << setw(60) << "Strassen Algorithm Implementation in C++ "
		<< endl << endl << setw(50) << "By QiXuebin"
		<< endl << setw(50) << "May 5 2018";

	cout << "\nPlease Enter your Matrix Size(must be in a power of two(eg:32,64,512,..): ";
	cin >> matrixSize;

	matrixA = new int *[matrixSize];
	matrixB = new int *[matrixSize];
	matrixC = new int *[matrixSize];

	for (int i = 0; i < matrixSize; ++i) {
		matrixA[i] = new int[matrixSize];
		matrixB[i] = new int[matrixSize];
		matrixC[i] = new int[matrixSize];
	}

	fillMatrix(matrixA, matrixB, matrixSize);

	//*******************conventional multiplication test********************
	cout << "Phase I started:  " << (startTimeForNormalMultipilication = clock());
	multi(matrixA, matrixB, matrixC, matrixSize);
	cout << "\nPhase I ended: " << (endTimeForNormalMultipilication = clock());
	cout << "\nMatrix Result... \n";
	printMatrix(matrixC, matrixSize);

	//*******************Strassen multiplication test************************
	cout << "Phase I started:  " << (startTimeForStrassen = clock());
	strassen(matrixA, matrixB, matrixC, matrixSize);
	cout << "\nPhase I ended: " << (endTimeForStrassen = clock());
	cout << "\nMatrix Result... \n";
	printMatrix(matrixC, matrixSize);

	// ********************compare the result******************************
	cout << "Matrix size " << matrixSize;
	cout << "\nNormal mode " << (endTimeForNormalMultipilication - startTimeForNormalMultipilication)
		<< " Clocks.." << (endTimeForNormalMultipilication - startTimeForNormalMultipilication) / CLOCKS_PER_SEC << " Sec";
	cout << "\nStrassen mode " << (endTimeForStrassen - startTimeForStrassen)
		<< " Clocks.." << (endTimeForStrassen - startTimeForStrassen) / CLOCKS_PER_SEC << " Sec\n";


	system("Pause");
	return 0;
}

void fillMatrix(int **matrixA, int **matrixB, int matrixSize) {
	for (int row = 0; row < matrixSize; ++row) {
		for (int column = 0; column < matrixSize; ++column) {
			matrixB[row][column] = rand() % 3;
			matrixA[row][column] = matrixB[row][column];
		}
	}
}

void printMatrix(int **matrix, int matrixSize) {
	cout << endl;
	for (int row = 0; row < matrixSize; ++row) {
		for (int column = 0; column < matrixSize; ++column) {
			cout << matrix[row][column] << "\t";

			if ((column + 1) % ((matrixSize)) == 0)
				cout << endl;
		}

	}
	cout << endl;
}

int add(int **matrixA, int **matrixB, int **matrixResult, int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	return 0;
}

int sub(int **matrixA, int **matrixB, int **matrixResult, int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			matrixResult[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	return 0;
}

int multi(int **matrixA, int **matrixB, int **matrixResult, int matrixSize) {
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixSize; j++) {
			matrixResult[i][j] = 0;

			for (int k = 0; k < matrixSize; ++k) {
				matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	return 0;
}

int strassen(int **matrixA, int **matrixB, int **matrixC, int matrixSize) {
	int halfSize = matrixSize / 2;
	int newSize = matrixSize / 2;
	if (matrixSize <= 2) {
		multi(matrixA, matrixB, matrixC, matrixSize);
	}
	else {
		int** A11, ** A12, ** A21, ** A22;

		int** B11, ** B12, ** B21, ** B22;

		int** C11, ** C12, ** C21, ** C22;

		int **P1, **P2, **P3, **P4, **P5, **P6, **P7;

		int** AResult;
		int** BResult;

		A11 = new int *[newSize];
		A12 = new int *[newSize];
		A21 = new int *[newSize];
		A22 = new int *[newSize];

		B11 = new int *[newSize];
		B12 = new int *[newSize];
		B21 = new int *[newSize];
		B22 = new int *[newSize];

		C11 = new int *[newSize];
		C12 = new int *[newSize];
		C21 = new int *[newSize];
		C22 = new int *[newSize];

		P1 = new int *[newSize];
		P2 = new int *[newSize];
		P3 = new int *[newSize];
		P4 = new int *[newSize];
		P5 = new int *[newSize];
		P6 = new int *[newSize];
		P7 = new int *[newSize];

		AResult = new int *[newSize];
		BResult = new int *[newSize];

		for (int i = 0; i < newSize; i++) {
			A11[i] = new int[newSize];
			A12[i] = new int[newSize];
			A21[i] = new int[newSize];
			A22[i] = new int[newSize];

			B11[i] = new int[newSize];
			B12[i] = new int[newSize];
			B21[i] = new int[newSize];
			B22[i] = new int[newSize];

			C11[i] = new int[newSize];
			C12[i] = new int[newSize];
			C21[i] = new int[newSize];
			C22[i] = new int[newSize];

			P1[i] = new int[newSize];
			P2[i] = new int[newSize];
			P3[i] = new int[newSize];
			P4[i] = new int[newSize];
			P5[i] = new int[newSize];
			P6[i] = new int[newSize];
			P7[i] = new int[newSize];

			AResult[i] = new int[newSize];
			BResult[i] = new int[newSize];
		}

		//splitting input Matrixes, into 4 submatrices each.
		for (int i = 0; i < halfSize; ++i) {
			for (int j = 0; j < halfSize; ++j) {
				A11[i][j] = matrixA[i][j];
				A12[i][j] = matrixA[i][j + halfSize];
				A21[i][j] = matrixA[i + halfSize][j];
				A22[i][j] = matrixA[i + halfSize][j + halfSize];

				B11[i][j] = matrixB[i][j];
				B12[i][j] = matrixB[i][j + halfSize];
				B21[i][j] = matrixB[i + halfSize][j];
				B22[i][j] = matrixB[i + halfSize][j + halfSize];
			}
		}

		// calculate P1..P7 matrices.

		// P1 = A11 * (B12 - B22)
		sub(B12, B22, BResult, halfSize);
		strassen(A11, BResult, P1, halfSize);

		// P2 = (A11 + A12) * B22;
		add(A11, A12, AResult, halfSize);
		strassen(AResult, B22, P2, halfSize);

		// P3 = (A21 + A22) * B11
		add(A21, A22, AResult, halfSize);
		strassen(AResult, B11, P3, halfSize);

		// P4 = A22 * ( B21 - B11)
		sub(B21, B11, BResult, halfSize);
		strassen(A22, BResult, P4, halfSize);

		// P5 = (A11 + A22) * (B11 + B22)
		add(A11, A22, AResult, halfSize);
		add(B11, B22, BResult, halfSize);
		strassen(AResult, BResult, P5, halfSize);

		// P6 = (A12 - A22) * (B21 + B22)
		sub(A12, A22, AResult, halfSize);
		add(B21, B22, BResult, halfSize);
		strassen(AResult, BResult, P6, halfSize);

		// P7 = (A11 - A21) * (B11 + B12)
		sub(A21, A11, AResult, halfSize);
		add(B11, B12, BResult, halfSize);
		strassen(AResult, BResult, P7, halfSize);

		// C11 = P5 + P4 - P2 + P6
		add(P5, P4, AResult, halfSize);
		sub(P6, P2, BResult, halfSize);
		add(AResult, BResult, C11, halfSize);

		// C12 = P1 + P2
		add(P1, P2, C12, halfSize);

		// C21 = P3 + P4
		add(P3, P4, C21, halfSize);

		// C22 = P5 + P1 - P3 + P7
		add(P5, P1, AResult, halfSize);
		sub(P7, P3, BResult, halfSize);
		add(AResult, BResult, C22, halfSize);

		// put C11, C12, C21, C22 together and make a unit matrix 
		for (int i = 0; i < halfSize; ++i) {
			for (int j = 0; j < halfSize; ++j) {
				matrixC[i][j] = C11[i][j];
				matrixC[i][j + halfSize] = C12[i][j];
				matrixC[i + halfSize][j] = C21[i][j];
				matrixC[i + halfSize][j + halfSize] = C22[i][j];
			}
		}

		// dont forget to free the space we alocated for matrices
		for (int i = 0; i < halfSize; ++i) {
			delete[]A11[i];
			delete[]A12[i];
			delete[]A21[i];
			delete[]A22[i];

			delete[]B11[i];
			delete[]B12[i];
			delete[]B21[i];
			delete[]B22[i];

			delete[]C11[i];
			delete[]C12[i];
			delete[]C21[i];
			delete[]C22[i];

			delete[]P1[i];
			delete[]P2[i];
			delete[]P3[i];
			delete[]P4[i];
			delete[]P5[i];
			delete[]P6[i];
			delete[]P7[i];

			delete[]AResult[i];
			delete[]BResult[i];
		}

		delete[]A11;
		delete[]A12;
		delete[]A21;
		delete[]A22;

		delete[]B11;
		delete[]B12;
		delete[]B21;
		delete[]B22;

		delete[]C11;
		delete[]C12;
		delete[]C21;
		delete[]C22;

		delete[]P1;
		delete[]P2;
		delete[]P3;
		delete[]P4;
		delete[]P5;
		delete[]P6;
		delete[]P7;

		delete[]AResult;
		delete[]BResult;
	}

	return 0;
}
