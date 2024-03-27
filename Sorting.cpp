//Merge Sort
#include <iostream>
using namespace std;
void merge(int *a,int lb,int mid,int ub) {
    int*b = new int[ub+1];
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    if (i > mid) {
        while (j <= ub) {
            b[k++] = a[j++];
        }
    }
    else {
        while (i <= mid) {
            b[k++] = a[i++];
        }
    }
    for (int i = lb; i < ub+1; i++) {
        a[i] = b[i];
    }
}
void mergeSort(int* a, int lb, int ub) {
    if (lb < ub) {
        int mid = (ub + lb) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
int main()
{
    int a[] = { 5,4,3,9,7,8,0,6,1,2 };
    mergeSort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
}
 //Binary Search
#include<iostream>
using namespace std;
int BinarySearch(int* a, int si, int ei, int key) {
    if (si >= ei) {
        
        return -1;
    }
    else {
        int mid = (ei + si) / 2;

        if (a[mid] == key) {
            
            return mid;
        }

        if (a[mid] > key) {
            
           return BinarySearch(a, si, mid - 1, key);
        }
        else {
          
            return BinarySearch(a, mid + 1, ei, key);
        }
    }
}
int main() {
    int a[] = { 0,1,2,3,4,5,6,7,8,9 };
    int key = 9; 
    int result = BinarySearch(a, 0, 10, key);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}

//Interpolation search
#include<iostream>
using namespace std;
int InterPolationSearch(int* a, int lb, int ub,int key) {
	if (lb >= ub) {
		return -1;
	}
	else {
		int pos = lb + (((ub - lb) / (a[ub] - a[lb])) * (key - a[lb]));
		if (a[pos] == key) {
			return pos;
		}
		if (a[pos] > key) {
			return InterPolationSearch(a, lb, pos - 1, key);
		}
		else {
			return InterPolationSearch(a, pos+1, ub, key);
		}
	}
}
int main() {
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	int key = 9;
	int result = InterPolationSearch(a, 0, 10, key);

	if (result != -1) {
		cout << "Element found at index " << result << endl;
	}
	else {
		cout << "Element not found" << endl;
	}

	return 0;
}
 //QuickSort
#include<iostream>
using namespace std;
int partition(int* a, int lb, int ub) {
	int pivot = a[lb];
	int start = lb;
	int end = ub;
	while (start < end) {
		while (a[start] <= a[pivot]) {
			start++;
		}
		while (a[end] > a[pivot]) {
			end--;
		}
		if (start < end) {
			swap(a[start], a[end]);
		}
	}
	swap(a[pivot], a[end]);
	return end;
}
void QuickSort(int* a, int lb, int ub) {
	if (lb < ub) {
		int loc = partition(a, lb, ub);
		QuickSort(a, lb, loc - 1);
		QuickSort(a, loc+1, ub);
	}
}
int main()
{
	int a[] = { 5,4,3,9,7,8,0,6,1,2 };
	QuickSort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
//Radix Sort                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
#include<iostream>
using namespace std;
int GetMax(int* a, int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
void CountSort(int* a, int n,int pos) {
	int* b = new int[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; i++)
		++count[((a[i] / pos) % 10)];
	for (int i = 1; i <= 9; i++)
		count[i] = count[i] + count[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--count[((a[i] / pos) % 10)]] = a[i];
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void RadixSort(int* a, int n) {
	int max = GetMax(a, n);
	for (int pos = 1; max / pos > 0; pos *= 10)
		CountSort(a, n, pos);
}
int main()
{
	int* a = new int[10] { 5, 4, 3, 9, 7, 8, 0, 6, 1, 2 };
	RadixSort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}