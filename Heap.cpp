//#include <iostream>
//using namespace std;
//class Heap {
//public:
//    int* arr;
//    static int size;
//    Heap(int size) {
//        arr = new int[size];
//    }
//    void Insert(int data) {
//        arr[size] = data;
//        int index = size;
//        while (index > 1 && arr[index / 2] < arr[index]) {
//            swap(arr[index / 2], arr[index]);
//            index = index / 2;
//        }
//        size++;
//    }
//    void Print() {
//        for (int i = 1; i < size; i++) {
//            cout << arr[i] << "\t";
//        }
//        cout << endl;
//    }
//    void deleteRoot() {
//        if (size == 0) {
//            cout << "Heap is Empty!";
//            return;
//        }
//        arr[1] = arr[size-1];
//        size--;
//        int index = 1;
//        while (index < size) {
//            int LeftChild = index * 2;
//            int RightChild = index * 2 + 1;
//            if (LeftChild < size && arr[LeftChild] > arr[index]) {
//                swap(arr[LeftChild], arr[index]);
//                index = LeftChild;
//            }
//            else if (RightChild < size && arr[RightChild] > arr[index]) {
//                swap(arr[RightChild], arr[index]);
//                index = RightChild;
//            }
//            else {
//                return;
//            }
//        }
//    }
//};
//int Heap::size = 1;
//void HeapifyMax(int arr[], int size, int index) {
//    int largest = index;
//    int LeftChild = index * 2;
//    int RightChild = index * 2 + 1;
//    if (LeftChild <= size && arr[LeftChild] > arr[largest]) {
//        largest = LeftChild;
//    }
//    if (RightChild <= size && arr[RightChild] > arr[largest]) {
//        largest = RightChild;
//    }
//    if (largest != index) {
//        swap(arr[largest], arr[index]);
//        HeapifyMax(arr, size, largest);
//    }
//}
// 
//void HeapifyMin(int arr[], int size, int index) {
//    int smallest = index;
//    int LeftChild = index * 2;
//    int RightChild = index * 2 + 1;
//    if (LeftChild <= size && arr[LeftChild] < arr[smallest]) {
//        smallest = LeftChild;
//    }
//    if (RightChild <= size && arr[RightChild] < arr[smallest]) {
//        smallest = RightChild;
//    }
//    if (smallest != index) {
//        swap(arr[smallest], arr[index]);
//        HeapifyMin(arr, size, smallest);
//    }
//}
//void HeapSort(int arr[], int n) {
//    int size = n;
//    while (size >= 1) {
//        swap(arr[1], arr[size]);
//        size--;
//        HeapifyMax(arr, size, 1);
//    }
//}
//int main()
//{
//   /* Heap h1(10);
//    h1.Insert(50);
//    h1.Insert(55);
//    h1.Insert(53);
//    h1.Insert(52);
//    h1.Insert(54);
//    h1.Print();*/
//    /*h1.deleteRoot();
//    h1.Print();*/
//    int arr[] = { -1,54,53,55,52,50 };
//    int size = 5;
//    for (int i = size / 2; i > 0; i--) {
//        HeapifyMax(arr, size, i);
//    }
//    for (int i = 1; i <= size; i++) {
//        cout << arr[i] << " ";
//    }
//   /* HeapSort(arr, size);
//    cout << endl;
//    for (int i = 1; i <= size; i++) {
//        cout << arr[i] << " ";
//    }*/
//}

#include<iostream>
using namespace std;
void HeapifyMax(int* arr, int size, int index) {
	int largest = index;
	int LeftChild = index * 2;
	int rightChild = (index * 2) + 1;
	if (LeftChild <= size && arr[LeftChild] > arr[largest])
	{
		largest = LeftChild;
	}
	if (rightChild <= size && arr[rightChild] > arr[largest])
	{
		largest = rightChild;
	}
	if (largest != index) {
		swap(arr[largest], arr[index]);
		HeapifyMax(arr, size, largest);
	}
}
void HeapifyMin(int* arr, int size, int index) {
	int smallest = index;
	int LeftChild = index / 2;
	int rightChild = (index / 2) + 1;
	if (LeftChild <= size && arr[LeftChild] < arr[smallest])
	{
		smallest = LeftChild;
	}
	if (rightChild <= size && arr[rightChild] < arr[smallest])
	{
		smallest = rightChild;
	}
	if (smallest != index) {
		swap(arr[smallest], arr[index]);
		HeapifyMin(arr, size, smallest);
	}
}
class Heap {
public:
	int* arr;
	int size=1;
	Heap(int a) :arr(new int[a]) {};
	void Insert(int a) {
		arr[size] = a;
		int index = size;
		while (index > 1 && arr[index] > arr[index / 2]) {
				swap(arr[index], arr[index/2]);
				index = index / 2;
		}
		size++;
	}
	void Print() {
		for (int i = 1; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void Delete() {
		arr[1] = arr[size];
		arr[size--] = -1;
		for (int index = 1; index < (size / 2) + 1; index++) {
			HeapifyMax(arr, size, index);
		}
	}
};
void HeapSort(int *arr,int size) {
	int n = size;
	while (n != 1) {
		swap(arr[1], arr[n--]);
		HeapifyMax(arr, n, 1);
	}
}
int main()
{
    Heap h1(10);
    h1.Insert(50);
    h1.Insert(55);
    h1.Insert(53);
    h1.Insert(52);
    h1.Insert(54);
    h1.Print();
	h1.Delete();
	h1.Print();
	int arr[] = { -1,54,53,55,52,50 };
	int size = 5;
	for (int i = size / 2; i > 0; i--) {
		HeapifyMax(arr, size, i);
	}
	for (int i = 1; i <= size; i++) {
		cout << arr[i] << " " ;
	}
	cout << endl;
	HeapSort(arr, size);
	for (int i = 1; i <= size; i++) {
		cout << arr[i] << " ";
	}
}
