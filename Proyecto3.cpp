#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

void Swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void SelectionSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n ; ++i)
	{
		for (int j = i; j < n ; ++j)
		{
			if (arr[j] < arr[i])
			{
				Swap(arr,i,j);
			}
		}
	}
}
void SelectionSortR(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 0; i < n ; ++i)
	{
		for (int j = i; j < n ; ++j)
		{
			if (arr[j] > arr[i])
			{
				Swap(arr,i,j);
			}
		}
	}
}
void BubbleSort(vector<int>& arr)
{
	int n = arr.size();
	for(int i = 0; i < n -1 ; ++i)
	{
		bool swapped = false;
		for(int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
			}
		}
		if (!swapped)
            break;
	}
}
void BubbleSortR(vector<int>& arr)
{
	int n = arr.size();
	for(int i = 0; i < n -1 ; ++i)
	{
		bool swapped = false;
		for(int j = 0; j < n - 1 - i; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
			}
		}
		if (!swapped)
            break;
	}
}
void InsertionSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i)
	{
       int key = arr[i];
       int j = i - 1;
       while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void InsertionSortR(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; ++i)
	{
       int key = arr[i];
       int j = i - 1;
       while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void ShellSort(vector<int>& arr)
{
	int n = arr.size();
	int intervalo = 1;
	
    while (intervalo < n / 3) {
        intervalo = 3 * intervalo + 1;
    }

    while (intervalo > 0) {
        for (int i = intervalo; i < n; ++i)
		{
            int temp = arr[i];
            int j = i;
            
            while (j >= intervalo && arr[j - intervalo] > temp)
			{
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }
            arr[j] = temp;
        }
        intervalo /= 3;
    }
}
void ShellSortR(vector<int>& arr)
{
	int n = arr.size();
	int intervalo = 1;
	
    while (intervalo < n / 3) {
        intervalo = 3 * intervalo + 1;
    }

    while (intervalo > 0) {
        for (int i = intervalo; i < n; ++i)
		{
            int temp = arr[i];
            int j = i;
            
            while (j >= intervalo && arr[j - intervalo] < temp)
			{
                arr[j] = arr[j - intervalo];
                j -= intervalo;
            }
            arr[j] = temp;
        }
        intervalo /= 3;
    }
}
void Merge(vector<int>& arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
    int n2 = right - middle;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; ++i)
	{
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j)
	{
        R[j] = arr[middle + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
	{
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
	{
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void MergeSort(vector<int>& arr, int left, int right)
{
	if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(arr, left, middle);

        MergeSort(arr, middle + 1, right);

        Merge(arr, left, middle, right);
    }
}
void MergeR(vector<int>& arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
    int n2 = right - middle;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; ++i)
	{
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j)
	{
        R[j] = arr[middle + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1)
	{
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
	{
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void MergeSortR(vector<int>& arr, int left, int right)
{
	if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSortR(arr, left, middle);

        MergeSortR(arr, middle + 1, right);

        MergeR(arr, left, middle, right);
    }
}
int Partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot)
		{
            ++i;
            Swap(arr, i, j);
        }
    }
    Swap(arr, i + 1, high);
    return i + 1;
}
void QuickSort(vector<int>& arr, int low, int high)
{
	if (low < high) {
        int partitionIndex = Partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}
int PartitionR(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; ++j) {
        if (arr[j] >= pivot)
		{
            ++i;
            Swap(arr, i, j);
        }
    }
    Swap(arr, i + 1, high);
    return i + 1;
}
void QuickSortR(vector<int>& arr, int low, int high)
{
	if (low < high) {
        int partitionIndex = PartitionR(arr, low, high);
        QuickSortR(arr, low, partitionIndex - 1);
        QuickSortR(arr, partitionIndex + 1, high);
    }
}
void heapify(vector<int>& arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void HeapSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i)
	{
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i)
	{
        Swap(arr,arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void heapifyR(vector<int>& arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (left < n && arr[left] < arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] < arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void HeapSortR(vector<int>& arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; --i)
	{
        heapifyR(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i)
	{
        Swap(arr,arr[0], arr[i]);
        heapifyR(arr, i, 0);
    }
}
double getResultFromAlg(vector<int>& arr,int option) {
	high_resolution_clock::time_point start =  high_resolution_clock::now();
	switch(option)
	{
		case 0: SelectionSort(arr);
				break;
		case 1: BubbleSort(arr);
				break;
		case 2: InsertionSort(arr);
				break;
		case 3: ShellSort(arr);
				break;
		case 4: MergeSort(arr, 0, arr.size()-1);
				break;
		case 5: QuickSort(arr, 0, arr.size()-1);
				break;
		case 6: HeapSort(arr);
				break;
		case 7: SelectionSortR(arr);
				break;
		case 8: BubbleSortR(arr);
				break;
		case 9: InsertionSortR(arr);
				break;
		case 10: ShellSortR(arr);
				break;
		case 11: MergeSortR(arr, 0, arr.size()-1);
				break;
		case 12: QuickSortR(arr, 0, arr.size()-1);
				break;
		case 13: HeapSortR(arr);
				break;		
	}
	high_resolution_clock::time_point end =  high_resolution_clock::now();
	return duration_cast<duration<double>>(end - start).count();
}

void SortExecution(vector<int>& arr)
{
	vector<int> arr1,arr2,arr3,arr4,arr5,arr6;
	arr1.assign(arr.begin(), arr.end());
	arr2.assign(arr.begin(), arr.end());
	arr3.assign(arr.begin(), arr.end());
	arr4.assign(arr.begin(), arr.end());
	arr5.assign(arr.begin(), arr.end());
	arr6.assign(arr.begin(), arr.end());
	
	unordered_map<string, double> results;
	
	results["HeapSort"] = getResultFromAlg(arr6,6);
	results["QuickSort"] = getResultFromAlg(arr5,5);
	results["MergeSort"] = getResultFromAlg(arr4,4);
	results["ShellSort"] = getResultFromAlg(arr3,3);
	results["InsertionSort"] = getResultFromAlg(arr2,2);
	results["BubbleSort"] = getResultFromAlg(arr1,1);
	results["SeleciontSort"] = getResultFromAlg(arr,0);
	
	int id = 1;
	double min = 0;
	string ganador;
	for (const auto& pair : results)
	{
		if(min>pair.second||min==0)
		{
			min = pair.second;
			ganador = pair.first;
		}
		const string& key = pair.first;
		double value = pair.second;
		cout << id << ". " << key << ", " << fixed << value << setprecision(5)
		<< endl;
		id++;
	}
	cout<<ganador<<" es el ganador con "<<min<< " segundos"<<endl;
}
void SortExecutionR(vector<int>& arr)
{
	vector<int> arr1,arr2,arr3,arr4,arr5,arr6;
	arr1.assign(arr.begin(), arr.end());
	arr2.assign(arr.begin(), arr.end());
	arr3.assign(arr.begin(), arr.end());
	arr4.assign(arr.begin(), arr.end());
	arr5.assign(arr.begin(), arr.end());
	arr6.assign(arr.begin(), arr.end());
	
	unordered_map<string, double> results;
	
	results["HeapSort"] = getResultFromAlg(arr6,13);
	results["QuickSort"] = getResultFromAlg(arr5,12);
	results["MergeSort"] = getResultFromAlg(arr4,11);
	results["ShellSort"] = getResultFromAlg(arr3,10);
	results["InsertionSort"] = getResultFromAlg(arr2,9);
	results["BubbleSort"] = getResultFromAlg(arr1,8);
	results["SeleciontSort"] = getResultFromAlg(arr,7);
	
	int id = 1;
	double min = 0;
	string ganador;
	for (const auto& pair : results)
	{
		if(min>pair.second||min==0)
		{
			min = pair.second;
			ganador = pair.first;
		}
		const string& key = pair.first;
		double value = pair.second;
		cout << id << ". " << key << ", " << fixed << value << setprecision(5)
		<< endl;
		id++;
	}
	cout<<ganador<<" es el ganador con "<<min<< " segundos"<<endl;
}
void SortGeneration(vector<int>& arrA, vector<int>& arrD, vector<int>& arrR, vector<int>& arrSinDuplicado, int amount)
{
	int random_value;
	for (int i = 0; i < amount ; ++i)
	{
		arrA.push_back(i+1);
		arrD.push_back(amount-i);
		arrSinDuplicado.push_back(i+1);
		if ( i == 0 )
		{
			random_value = 1 + rand() % (amount);
			arrR.push_back(random_value);
		}
		else
		{
			random_value = 1 + rand() % (amount);
			arrR.push_back(random_value);
		}
	}
	for (int i = amount - 1; i > 0; --i)
	{
        int j = rand() % (i + 1);
        swap(arrSinDuplicado[i], arrSinDuplicado[j]);
    }
}

int main(int argc, char* argv[]) {
	
	vector<int> arrRandom, arrSorted, arrReverse, arrOrdenR; //Tablero
	vector<int> arrRandom1, arrSorted1, arrReverse1, arrOrdenR1; //Camino
	vector<int> arrRandom2, arrSorted2, arrReverse2, arrOrdenR2; //Objeto
	int menu;
	
	int Tablero = 30000;//90000 + rand() % 10001;
	int Camino = 20000;//50000 + rand() % 20001;
	int Objeto = 7500 + rand() % 7501;
	cout << "Generando set de datos: " << endl;
	
	SortGeneration(arrSorted, arrReverse, arrRandom, arrOrdenR, Tablero);
	SortGeneration(arrSorted1, arrReverse1, arrRandom1, arrOrdenR1, Camino);
	SortGeneration(arrSorted2, arrReverse2, arrRandom2, arrOrdenR2, Objeto);
    
    cout << "Carreras de algoritmos" << endl;
    cout << "1. Ascendente." << endl << "2. Descendente." << endl;
    cin >> menu;
    cout << "Opcion elgida: " << menu << endl;
    
    switch(menu)
    {
    	case 1: cout << "\nCarrera por el Tablero: Modo Ordenado" << endl;
				SortExecution(arrSorted);
				cout << "\nCarrera por el Tablero: Modo Invertido" << endl;
				SortExecution(arrReverse);
				cout << "\nCarrera por el Tablero: Modo Aleatorio con duplicado" << endl;
				SortExecution(arrRandom);
				cout << "\nCarrera por el Tablero: Modo Aleatorio sin duplicado" << endl;
				SortExecution(arrOrdenR);
				
				cout << "\nCarrera por el Camino: Modo Ordenado" << endl;
				SortExecution(arrSorted1);
				cout << "\nCarrera por el Camino: Modo Invertido" << endl;
				SortExecution(arrReverse1);
				cout << "\nCarrera por el Camino: Modo Aleatorio con duplicado" << endl;
				SortExecution(arrRandom1);
				cout << "\nCarrera por el Camino: Modo Aleatorio sin duplicado" << endl;
				SortExecution(arrOrdenR1);
				
				cout << "\nCarrera por los Objetos: Modo Ordenado" << endl;
				SortExecution(arrSorted2);
				cout << "\nCarrera por los Objetos: Modo Invertido" << endl;
				SortExecution(arrReverse2);
				cout << "\nCarrera por los Objetos: Modo Aleatorio con duplicado" << endl;
				SortExecution(arrRandom2);
				cout << "\nCarrera por los Objetos: Modo Aleatorio sin duplicado" << endl;
				SortExecution(arrOrdenR2);
    			break;
    	case 2:	cout << "\nCarrera por el Tablero: Modo Ordenado" << endl;
				SortExecutionR(arrSorted);
				cout << "\nCarrera por el Tablero: Modo Invertido" << endl;
				SortExecutionR(arrReverse);
				cout << "\nCarrera por el Tablero: Modo Aleatorio con duplicado" << endl;
				SortExecutionR(arrRandom);
				cout << "\nCarrera por el Tablero: Modo Aleatorio sin duplicado" << endl;
				SortExecutionR(arrOrdenR);
				
				cout << "\nCarrera por el Camino: Modo Ordenado" << endl;
				SortExecutionR(arrSorted1);
				cout << "\nCarrera por el Camino: Modo Invertido" << endl;
				SortExecutionR(arrReverse1);
				cout << "\nCarrera por el Camino: Modo Aleatorio con duplicado" << endl;
				SortExecutionR(arrRandom1);
				cout << "\nCarrera por el Camino: Modo Aleatorio sin duplicado" << endl;
				SortExecutionR(arrOrdenR1);
				
				cout << "\nCarrera por los Objetos: Modo Ordenado" << endl;
				SortExecutionR(arrSorted2);
				cout << "\nCarrera por los Objetos: Modo Invertido" << endl;
				SortExecutionR(arrReverse2);
				cout << "\nCarrera por los Objetos: Modo Aleatorio con duplicado" << endl;
				SortExecutionR(arrRandom2);
				cout << "\nCarrera por los Objetos: Modo Aleatorio sin duplicado" << endl;
				SortExecutionR(arrOrdenR2);
    			break;
	}
	
	return 0;
}
