#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

char** dekart(char a[], char b[], char c[], int sizeOfArray_a, int sizeOfArray_b, int sizeOfArray_c) {
	int sizeOfArray = sizeOfArray_a * sizeOfArray_b * sizeOfArray_c;
	char** result = new char* [sizeOfArray];
	for (int i = 0; i < sizeOfArray_a; i++)
	{
		for (int j = 0; j < sizeOfArray_b; j++)
		{
			for (int k = 0; k < sizeOfArray_c; k++)
			{
				result[i * sizeOfArray_b + j] = new char[3];
				result[i * sizeOfArray_b + j][0] = a[i];
				result[i * sizeOfArray_b + j][1] = b[j];
				result[i * sizeOfArray_b + j][2] = c[k];
				result[i * sizeOfArray_b + j + sizeOfArray / 2] = new char[3];
				result[i * sizeOfArray_b + j + sizeOfArray / 2][0] = a[i];
				result[i * sizeOfArray_b + j + sizeOfArray / 2][1] = b[j];
				result[i * sizeOfArray_b + j + sizeOfArray / 2][2] = c[k - 1];
			}

		}
	}
	return result;
}

void univers(char a[], char b[], char universum[], int sizeOfArray_a_2, int sizeOfArray_b_2, int sizeOFArray_universum) {
	int key_a = 0;
	int key_b = 0;

	char* bit_a = new char[sizeOFArray_universum];
	char* bit_b = new char[sizeOFArray_universum];

	char* bit_negation = new char[sizeOFArray_universum];
	char* bit_conjunction = new char[sizeOFArray_universum];
	char* bit_disjunction = new char[sizeOFArray_universum];
	//char* bit_unknown = new char[sizeOFArray_universum];
	char* bit_strict_disjunction = new char[sizeOFArray_universum];

	for (int i = 0; i <= sizeOFArray_universum; i++)
	{
		bit_a[i] = '0';
		bit_b[i] = '0';
	}
	for (int i = 0; i <= sizeOfArray_a_2; i++)
	{
		for (int j = 0; j <= sizeOFArray_universum; j++)
		{
			if (a[i] == universum[j])
			{
				bit_a[j] = '1';
				break;
			}
		}
	}
	for (int i = 0; i <= sizeOfArray_b_2; i++)
	{
		for (int j = 0; j <= sizeOFArray_universum; j++)
		{
			if (b[i] == universum[j])
			{
				bit_b[j] = '1';
				break;
			}
		}
	}
	//-------NOT(Negation)(-)-------
	cout << "NOT(Negation)(-): " << endl;
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_a[i] == '0')
		{
			bit_negation[i] = '1';
		}
		else
		{
			bit_negation[i] = '0';
		}
	}
	cout << "Result:";
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_negation[i] == '1')
		{
			cout << " " << universum[i];
		}
		else
		{
			cout << " " << "-";
		}
	}
	cout << endl;
	//-------AND(Conjunction)(∧)-------
	cout << "AND(Conjunction)(∧): " << endl;
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_a[i] == bit_b[i] && bit_a[i] == '1')
		{
			bit_conjunction[i] = '1';
		}
		else {
			bit_conjunction[i] = '0';
		}
	}
	cout << "Result:";
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_conjunction[i] == '1')
		{
			cout << " " << universum[i];
		}
		else
		{
			cout << " " << "-";
		}
	}
	cout << endl;
	//-------OR(Disjunction)(∨)-------
	cout << "OR(Disjunction)(∨): " << endl;
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_a[i] == bit_b[i] && bit_a[i] == '0') {
			bit_disjunction[i] = '0';
		}
		else {
			bit_disjunction[i] = '1';
		}
	}
	cout << "Result:";
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_disjunction[i] == '1')
		{
			cout << " " << universum[i];
		}
		else
		{
			cout << " " << "-";
		}
	}
	cout << endl;

	//-------Unknown(???)(\)-------
	//cout << "Unknown(???)(\): " << endl;
	//for (int i = 0; i <= sizeOFArray_universum; i++) {
	//	if ()
	//	{
	//		bit_unknown[i] = '1';
	//	}
	//	else
	//	{
	//		bit_unknown[i] = '0';
	//	}
	//}
	//cout << "Result:";
	//for (int i = 0; i <= sizeOFArray_universum; i++) {
	//	if (bit_unknown[i] == '1')
	//	{
	//		cout << " " << universum[i];
	//	}
	//	else
	//	{
	//		cout << " " << "-";
	//	}
	//}
	//cout << endl;


	//-------XOR(Strict Disjunction)(⊕)-------
	cout << "XOR(Strict Disjunction)(⊕): " << endl;
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_a[i] != bit_b[i])
		{
			bit_strict_disjunction[i] = '1';
		}
		else
		{
			bit_strict_disjunction[i] = '0';
		}
	}
	cout << "Result:";
	for (int i = 0; i <= sizeOFArray_universum; i++) {
		if (bit_strict_disjunction[i] == '1')
		{
			cout << " " << universum[i];
		}
		else
		{
			cout << " " << "-";
		}
	}
	cout << endl;
}

int main()
{
	char A[3] = { 'a', 'b', 'c' };
	char B[3] = { 'x', 'y', 'z' };
	char C[2] = { '0', '1' };

	cout << "Array A: ";
	cout << "{" << A[0] << " " << A[1] << " " << A[2] << "}" << endl;
	cout << "Array B: ";
	cout << "{" << B[0] << " " << B[1] << " " << B[2] << "}" << endl;
	cout << "Array C: ";
	cout << "{" << C[0] << " " << C[1] << "}" << endl << endl;

	int sizeOfArray_a = sizeof(A) / sizeof(A[0]);
	int sizeOfArray_b = sizeof(B) / sizeof(B[0]);
	int sizeOfArray_c = sizeof(C) / sizeof(C[0]);

	cout << "Results of Dekart {BxBxC}: " << endl;

	char** result;
	result = dekart(B, B, C, sizeOfArray_b, sizeOfArray_b, sizeOfArray_c);

	for (int i = 0; i < sizeOfArray_b * sizeOfArray_b * sizeOfArray_c; i++)
	{
		cout << "(" << result[i][0] << " " << result[i][1] << " " << result[i][2] << ")" << endl;
	}
	cout << endl;



	int n = 0;
	cout << "Enter Universum Number: ";
	cin >> n;
	char* universum = new char[n];
	for (int i = 0; i < n; i++)
	{
		universum[i] = i + 1 + '0';
	}
	cout << "Array[universum]:";
	for (int i = 0; i < n; i++)
	{
		cout << " " << universum[i];
	}
	int sizeOFArray_universum = sizeof(universum) / sizeof(universum[0]);
	cout << endl;
	int n_a = 0;
	cout << "Enter [A] Number: ";
	cin >> n_a;
	char* a_array = new char[n_a];
	for (int i = 0; i < n_a; i++)
	{
		cout << "a[" << i << "]: ";
		cin >> a_array[i];
	}
	int sizeOFArray_a_2 = sizeof(a_array) / sizeof(a_array[0]);
	sort(a_array, a_array + n_a);
	cout << "Array[a]:";
	for (int i = 0; i < n_a; i++)
	{
		cout << " " << a_array[i];
	}
	cout << endl;
	int n_b = 0;
	cout << "Enter [B] Number: ";
	cin >> n_b;
	char* b_array = new char[n_b];
	for (int i = 0; i < n_b; i++)
	{
		cout << "b[" << i << "]: ";
		cin >> b_array[i];
	}
	int sizeOFArray_b_2 = sizeof(b_array) / sizeof(b_array[0]);
	sort(b_array, b_array + n_b);
	cout << "Array[b]:";
	for (int i = 0; i < n_b; i++)
	{
		cout << " " << b_array[i];
	}
	cout << endl;

	univers(a_array, b_array, universum, sizeOFArray_a_2, sizeOFArray_b_2, sizeOFArray_universum);
}