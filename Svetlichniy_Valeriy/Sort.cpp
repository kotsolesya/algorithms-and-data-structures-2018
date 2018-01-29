#include "Windows.h"
#include "iostream"
#include "iomanip"
#include "time.h"

#define N 100000

using namespace std;

//COLOR

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

// BUBLE 

void bubbleSort(int* arrayPtr, int length_array)
{
	int temp = 0;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) 
	
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
			{
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false;
			}
	}
}

// INSERT

void insertionSort(int *arrayPtr, int length)
{
	int temp,
		item;

	for (int counter = 1; counter < length; counter++)
	{
		temp = arrayPtr[counter];
		item = counter - 1;

		while (item >= 0 && arrayPtr[item] > temp)
		{
			arrayPtr[item + 1] = arrayPtr[item];
			arrayPtr[item] = temp;
			item--;
		}
	}
}

//SELECT

void selectSort(int *num, int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min])
			{
				min = j;
			}
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}


//SHELL

void shellSort(int v[], int n)
{
	int gap;
	int i, j, temp;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

//QUICK

void quicksort(int *mas, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2];
	do
	{
		while (mas[f]<mid) f++;
		while (mas[l]>mid) l--;
		if (f <= l)
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f<l);
	if (first<l) quicksort(mas, first, l);
	if (f<last) quicksort(mas, f, last);
}

//MAIN

int main()
{
	setlocale(LC_ALL, "Russian");
	SetColor(10, 0);
	int q;
	cout << "Выберите номер условия : " << endl << endl;
	cout << "1) Алгоритмы сортировки на 100 элементов." << endl;
	cout << "2) Алгоритмы сортировки на 1000 элементов." << endl;
	cout << "3) Алгоритмы сортировки на 10000 элементов." << endl;
	cout << "4) Алгоритмы сортировки на 100000 элементов." << endl;
	cout << endl;
	SetColor(12, 0);
	cout << "Введите номер условия : ";
	cin >> q;
	cout << endl;
	switch (q)
	{
	default:
		case 1 :
		{
			//BUBLE_1
			SetColor(14, 0);

			srand(time(NULL));
			cout << "Тип сортировки Buble на 100 элементов.";
			int size_array1;
			size_array1 = 100;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start1 = clock();

			int *sorted_array1 = new int[size_array1];
			for (int counter = 0; counter < size_array1; counter++)
			{
				sorted_array1[counter] = rand() % 10;
				cout << setw(2) << sorted_array1[counter];
			}

			cout << endl << endl;

			bubbleSort(sorted_array1, size_array1);

			for (int counter = 0; counter < size_array1; counter++)
			{
				cout << setw(2) << sorted_array1[counter];
			}
			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish1 = clock();

			cout << "Программа работает : " << ((double)(finish1 - start1)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//INSERT_1
			SetColor(14, 0);

			srand(time(NULL));
			int size_array2;
			cout << "Тип сортировки Insert на 100 элементов.";
			size_array2 = 100;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start2 = clock();

			int *sorted_array2 = new int[size_array2];

			for (int counter = 0; counter < size_array2; counter++)
			{
				sorted_array2[counter] = rand() % 10;
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			insertionSort(sorted_array2, size_array2);

			for (int counter = 0; counter < size_array2; counter++)
			{
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			delete[] sorted_array2;

			SetColor(12, 0);

			clock_t finish2 = clock();

			cout << "Программа работает : " << ((double)(finish2 - start2)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SELECT_1
			SetColor(14, 0);

			int size_array3;
			srand(time(NULL));
			cout << "Тип сортировки Select на 100 элементов." << endl << endl;
			size_array3 = 100;


			int *sorted_array3 = new int[size_array3];

			SetColor(10, 0);

			clock_t start3 = clock();

			for (int i = 0; i < size_array3; i++)
			{
				sorted_array3[i] = rand() % 10;
			}

			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			selectSort(sorted_array3, size_array3);
			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish3 = clock();

			cout << "Программа работает : " << ((double)(finish3 - start3)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SHELL_1
			SetColor(14, 0);

			int i, size_array4;
			srand(time(NULL));
			cout << "Тип сортировки Shell на 100 элементов." << endl << endl;
			size_array4 = 100;

			int *sorted_array4 = new int[size_array4];

			SetColor(10, 0);

			clock_t start4 = clock();

			for (i = 0; i < size_array4; i++)
			{
				sorted_array4[i] = rand() % 10;
			}

			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			shellSort(sorted_array4, size_array4);
			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish4 = clock();

			cout << "Программа работает : " << ((double)(finish4 - start4)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//QUICK_1
			SetColor(14, 0);

			srand(time(NULL));
			SetColor(14, 0);
			cout << "Тип сортировки Quick на 100 элементов." << endl << endl;
			const int n = 100;
			int first, last;
			int *A = new int[n];

			SetColor(10, 0);

			clock_t start = clock();

			for (int i = 0; i<n; i++)
			{
				A[i] = rand() % 10;
				cout << A[i] << " ";
			}

			first = 0;
			last = n - 1;
			quicksort(A, first, last);
			cout << endl << endl;
			for (int i = 0; i<n; i++) cout << A[i] << " ";

			SetColor(12, 0);

			cout << endl << endl;

			delete[]A;

			clock_t finish = clock();

			cout << "Программа работает : " << ((double)(finish - start)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;


			SetColor(7, 0);
			
			system("pause");
		}
		break;

		case 2 :
		{
			//BUBLE_2
			SetColor(14, 0);

			srand(time(NULL));
			cout << "Тип сортировки Buble на 1000 элементов.";
			int size_array1;
			size_array1 = 1000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start1 = clock();

			int *sorted_array1 = new int[size_array1];
			for (int counter = 0; counter < size_array1; counter++)
			{
				sorted_array1[counter] = rand() % 10;
				cout << setw(2) << sorted_array1[counter];
			}

			cout << endl << endl;

			bubbleSort(sorted_array1, size_array1);

			for (int counter = 0; counter < size_array1; counter++)
			{
				cout << setw(2) << sorted_array1[counter];
			}
			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish1 = clock();

			cout << "Программа работает : " << ((double)(finish1 - start1)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//INSERT_2
			SetColor(14, 0);

			srand(time(NULL));
			int size_array2;
			cout << "Тип сортировки Insert на 1000 элементов.";
			size_array2 = 1000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start2 = clock();

			int *sorted_array2 = new int[size_array2];

			for (int counter = 0; counter < size_array2; counter++)
			{
				sorted_array2[counter] = rand() % 10;
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			insertionSort(sorted_array2, size_array2);

			for (int counter = 0; counter < size_array2; counter++)
			{
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			delete[] sorted_array2;

			SetColor(12, 0);

			clock_t finish2 = clock();

			cout << "Программа работает : " << ((double)(finish2 - start2)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SELECT_2
			SetColor(14, 0);

			int size_array3;
			srand(time(NULL));
			cout << "Тип сортировки Select на 1000 элементов." << endl << endl;
			size_array3 = 1000;

			int *sorted_array3 = new int[size_array3];

			SetColor(10, 0);

			clock_t start3 = clock();

			for (int i = 0; i < size_array3; i++)
			{
				sorted_array3[i] = rand() % 10;
			}

			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			selectSort(sorted_array3, size_array3);
			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish3 = clock();

			cout << "Программа работает : " << ((double)(finish3 - start3)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SHELL_2
			SetColor(14, 0);

			int i, size_array4;
			srand(time(NULL));
			cout << "Тип сортировки Shell на 1000 элементов." << endl << endl;
			size_array4 = 1000;

			int *sorted_array4 = new int[size_array4];

			SetColor(10, 0);

			clock_t start4 = clock();

			for (i = 0; i < size_array4; i++)
			{
				sorted_array4[i] = rand() % 10;
			}

			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			shellSort(sorted_array4, size_array4);
			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish4 = clock();

			cout << "Программа работает : " << ((double)(finish4 - start4)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//QUICK_2
			SetColor(14, 0);

			srand(time(NULL));
			SetColor(14, 0);
			cout << "Тип сортировки Quick на 1000 элементов." << endl << endl;
			const int n = 1000;
			int first, last;
			int *A = new int[n];

			SetColor(10, 0);

			clock_t start = clock();

			for (int i = 0; i<n; i++)
			{
				A[i] = rand() % 10;
				cout << A[i] << " ";
			}

			first = 0;
			last = n - 1;
			quicksort(A, first, last);
			cout << endl << endl;
			for (int i = 0; i<n; i++) cout << A[i] << " ";

			SetColor(12, 0);

			cout << endl << endl;

			delete[]A;

			clock_t finish = clock();

			cout << "Программа работает : " << ((double)(finish - start)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			SetColor(7, 0);

			system("pause");
		}
		break;

		case 3 :
		{
			//BUBLE_3
			SetColor(14, 0);

			srand(time(NULL));
			cout << "Тип сортировки Buble на 10000 элементов.";
			int size_array1;
			size_array1 = 10000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start1 = clock();

			int *sorted_array1 = new int[size_array1];
			for (int counter = 0; counter < size_array1; counter++)
			{
				sorted_array1[counter] = rand() % 10;
				cout << setw(2) << sorted_array1[counter];
			}

			cout << endl << endl;

			bubbleSort(sorted_array1, size_array1);

			for (int counter = 0; counter < size_array1; counter++)
			{
				cout << setw(2) << sorted_array1[counter];
			}
			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish1 = clock();

			cout << "Программа работает : " << ((double)(finish1 - start1)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//INSERT_3
			SetColor(14, 0);

			srand(time(NULL));
			int size_array2;
			cout << "Тип сортировки Insert на 10000 элементов.";
			size_array2 = 10000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start2 = clock();

			int *sorted_array2 = new int[size_array2];

			for (int counter = 0; counter < size_array2; counter++)
			{
				sorted_array2[counter] = rand() % 10;
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			insertionSort(sorted_array2, size_array2);

			for (int counter = 0; counter < size_array2; counter++)
			{
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			delete[] sorted_array2;

			SetColor(12, 0);

			clock_t finish2 = clock();

			cout << "Программа работает : " << ((double)(finish2 - start2)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SELECT_3
			SetColor(14, 0);

			int size_array3;
			srand(time(NULL));
			cout << "Тип сортировки Select на 10000 элементов." << endl << endl;
			size_array3 = 10000;

			int *sorted_array3 = new int[size_array3];

			SetColor(10, 0);

			clock_t start3 = clock();

			for (int i = 0; i < size_array3; i++)
			{
				sorted_array3[i] = rand() % 10;
			}

			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			selectSort(sorted_array3, size_array3);
			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish3 = clock();

			cout << "Программа работает : " << ((double)(finish3 - start3)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SHELL_3
			SetColor(14, 0);

			int i, size_array4;
			srand(time(NULL));
			cout << "Тип сортировки Shell на 10000 элементов." << endl << endl;
			size_array4 = 10000;

			int *sorted_array4 = new int[size_array4];

			SetColor(10, 0);

			clock_t start4 = clock();

			for (i = 0; i < size_array4; i++)
			{
				sorted_array4[i] = rand() % 10;
			}

			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			shellSort(sorted_array4, size_array4);
			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish4 = clock();

			cout << "Программа работает : " << ((double)(finish4 - start4)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//QUICK_3
			SetColor(14, 0);

			srand(time(NULL));
			SetColor(14, 0);
			cout << "Тип сортировки Quick на 10000 элементов." << endl << endl;
			const int n = 10000;
			int first, last;
			int *A = new int[n];

			SetColor(10, 0);

			clock_t start = clock();

			for (int i = 0; i<n; i++)
			{
				A[i] = rand() % 10;
				cout << A[i] << " ";
			}

			first = 0;
			last = n - 1;
			quicksort(A, first, last);
			cout << endl << endl;
			for (int i = 0; i<n; i++) cout << A[i] << " ";

			SetColor(12, 0);

			cout << endl << endl;

			delete[]A;

			clock_t finish = clock();

			cout << "Программа работает : " << ((double)(finish - start)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			SetColor(7, 0);

			system("pause");
		}
		break;

		case 4 :
		{
			//BUBLE_4
			SetColor(14, 0);

			srand(time(NULL));
			cout << "Тип сортировки Buble на 100000 элементов.";
			int size_array1;
			size_array1 = 100000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start1 = clock();

			int *sorted_array1 = new int[size_array1];
			for (int counter = 0; counter < size_array1; counter++)
			{
				sorted_array1[counter] = rand() % 10;
				cout << setw(2) << sorted_array1[counter];
			}

			cout << endl << endl;

			bubbleSort(sorted_array1, size_array1);

			for (int counter = 0; counter < size_array1; counter++)
			{
				cout << setw(2) << sorted_array1[counter];
			}
			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish1 = clock();

			cout << "Программа работает : " << ((double)(finish1 - start1)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//INSERT_4
			SetColor(14, 0);

			srand(time(NULL));
			int size_array2;
			cout << "Тип сортировки Insert на 100000 элементов.";
			size_array2 = 100000;
			cout << endl << endl;

			SetColor(10, 0);

			clock_t start2 = clock();

			int *sorted_array2 = new int[size_array2];

			for (int counter = 0; counter < size_array2; counter++)
			{
				sorted_array2[counter] = rand() % 10;
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			insertionSort(sorted_array2, size_array2);

			for (int counter = 0; counter < size_array2; counter++)
			{
				cout << setw(2) << sorted_array2[counter];
			}

			cout << endl << endl;

			delete[] sorted_array2;

			SetColor(12, 0);

			clock_t finish2 = clock();

			cout << "Программа работает : " << ((double)(finish2 - start2)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SELECT_4
			SetColor(14, 0);

			int size_array3;
			srand(time(NULL));
			cout << "Тип сортировки Select на 100000 элементов." << endl << endl;
			size_array3 = 100000;

			int *sorted_array3 = new int[size_array3];

			SetColor(10, 0);

			clock_t start3 = clock();

			for (long int i = 0; i < size_array3; i++)
			{
				sorted_array3[i] = rand() % 10;
			}

			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			selectSort(sorted_array3, size_array3);
			for (int i = 0; i < size_array3; i++)
			{
				cout << sorted_array3[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish3 = clock();

			cout << "Программа работает : " << ((double)(finish3 - start3)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//SHELL_4
			SetColor(14, 0);

			int i, size_array4;
			srand(time(NULL));
			cout << "Тип сортировки Shell на 100000 элементов." << endl << endl;
			size_array4 = 100000;

			int *sorted_array4 = new int[size_array4];

			SetColor(10, 0);

			clock_t start4 = clock();

			for (i = 0; i < size_array4; i++)
			{
				sorted_array4[i] = rand() % 10;
			}

			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			shellSort(sorted_array4, size_array4);
			for (i = 0; i < size_array4; i++)
			{
				cout << sorted_array4[i] << " ";
			}

			cout << endl << endl;

			SetColor(12, 0);

			clock_t finish4 = clock();

			cout << "Программа работает : " << ((double)(finish4 - start4)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			//QUICK_4
			SetColor(14, 0);

			srand(time(NULL));
			SetColor(14, 0);
			cout << "Тип сортировки Quick на 100000 элементов." << endl << endl;
			const int n = 100000;
			int first, last;
			int *A = new int[n];

			SetColor(10, 0);

			clock_t start = clock();

			for (int i = 0; i<n; i++)
			{
				A[i] = rand() % 10;
				cout << A[i] << " ";
			}

			first = 0;
			last = n - 1;
			quicksort(A, first, last);
			cout << endl << endl;
			for (int i = 0; i<n; i++) cout << A[i] << " ";

			SetColor(12, 0);

			cout << endl << endl;

			delete[]A;

			clock_t finish = clock();

			cout << "Программа работает : " << ((double)(finish - start)) / CLOCKS_PER_SEC << " секунд." << endl;
			cout << endl;

			SetColor(7, 0);

			system("pause");
		}
		break;
	}
}