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
using namespace std;
//https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
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
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
double getResultFromAlg(vector<int>& arr,int option) {
	time_t start, end;
	double time_taken;
	time(&start);
	ios_base::sync_with_stdio(false);
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
		case 5:	QuickSort(arr, 0, arr.size()-1);
				break;
		case 6: HeapSort(arr);
				break;
	}
	time(&end);
	time_taken = double(end - start);
	return time_taken;
}
int main(int argc, char* argv[]) {
	
	vector<int> arr, arrSorted, arrReverse;
	int random_value;
	int amount = 100000;
	cout << "Generando set de datos: " << endl;
	for (int i = 0; i < amount ; ++i)
	{
		arrSorted.push_back(i+1);
		arrReverse.push_back(amount-i);
		if ( i == 0 )
		{
			random_value = 1 + rand() % (amount);
			arr.push_back(random_value);
		}
		else
		{
			random_value = 1 + rand() % (amount);
			arr.push_back(random_value);
		}
	}
	vector<int> arr1,arr2,arr3,arr4,arr5,arr6;
	arr1.assign(arr.begin(), arr.end());
	arr2.assign(arr.begin(), arr.end());
	arr3.assign(arr.begin(), arr.end());
	arr4.assign(arr.begin(), arr.end());
	arr5.assign(arr.begin(), arr.end());
	arr6.assign(arr.begin(), arr.end());
	
	unordered_map<string, double> results;
	//results["HeapSort"] = getResultFromAlg(arrReverse,6);
	results["QuickSort"] = getResultFromAlg(arrReverse,5);
	//results["MergeSort"] = getResultFromAlg(arr4,4);
	//results["ShellSort"] = getResultFromAlg(arr3,3);
	//results["InsertionSort"] = getResultFromAlg(arr2,2);
	//results["BubbleSort"] = getResultFromAlg(arr1,1);
	//results["SeleciontSort"] = getResultFromAlg(arr,0);
	
	
	int id = 1;
	for (const auto& pair : results)
	{
		const string& key = pair.first;
		double value = pair.second;
		cout << id << ". " << key << ", " << fixed << value << setprecision(5)
		<< endl;
		id++;
	}
return 0;
}
