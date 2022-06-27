#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;


///bubble sort
void bubble_sort(int *ary, int length){

  for(int i=0; i<length; i++){
    for(int j=0; j<length-i; j++){
      if(ary[j] > ary[j+1]){
      ///swapint values.
        int temp = ary[j];
        ary[j] = ary[j+1];
        ary[j+1] = temp;
      }
    }
  }
}

///quicksort

int partition(int *arr, int low, int high){
  int pivot = arr[high]; ///considering the highest value as pivot
  int index = low - 1;

  for(int i=low; i<= high-1; i++){
    if(arr[i] < pivot){
      index++;
      ///swaping value.
      int temp = arr[index];
      arr[index] = arr[i];
      arr[i] = temp;
    }
  }
  ///swaping
  int temp = arr[index+1];
  arr[index+1] = arr[high];
  arr[high] = temp;

  return index+1;

}


void quickSort(int *ary, int low, int high){
  if(low < high){
  ///calling partion funtion to determine partition index.
    int partitionIndex = partition(ary, low, high);

  ///calling left recursion.
    quickSort(ary, low, partitionIndex-1);

  ///calling right recursion.
    quickSort(ary, partitionIndex+1, high);
  }
}

int main()
{
  int ary[] = {10, 12, 16, 18, 20, 22, 24, 26, 28, 30,1, 3, 2, 6, 5,  8, 4, 100, 99, 55, 23,
   43, 34, 54, 45, 65, 56, 67, 76, 87, 89, 9, 12 ,21, 32, 23, 43, 34,
    7, 88, 87, 86, 85, 84, 83, 82, 81, 71, 79, 78, 77, 76, 75,10, 12,
     16, 18, 20, 22, 24, 26, 28, 30,1, 3, 2, 6, 5,  8, 4, 100, 99, 55, 23,
   43, 34, 54, 45, 65, 56, 67, 76, 87, 89, 9, 12 ,21, 32, 23, 43, 34,
    7, 88, 87, 86, 85, 84, 83, 82, 81, 71, 79, 78, 77, 76, 75};

  int low = 0, high = (sizeof(ary) / sizeof(ary[0])) - 1;

  ///bubble sort
  auto start = high_resolution_clock::now(); ///calculating the starting time
  bubble_sort(ary, high);///calling bubble sort function.
  auto stop = high_resolution_clock::now(); ///calculating the end time

  auto bubble_sort_complexity = duration_cast<microseconds>(stop - start); /// calculating the performance time.
  cout << "\nSorting time taken by Bubble Sort: "<< bubble_sort_complexity.count() << " microseconds." << endl;


///quick sort.
  auto start1 = high_resolution_clock::now();///calculating the starting time
  quickSort(ary, low, high);
  auto stop1 = high_resolution_clock::now();///calculating the end time


  auto quick_sort_complexity = duration_cast<microseconds>(stop1 - start1);/// calculating the performance time.
  cout <<"\nSorting time taken by Quick Sort: "<< quick_sort_complexity.count()<< " microseconds." << endl;

  /*
  cout << "sorted array: ";
  for(int value: ary)
     cout << value <<" ";
     */

    return 0;

}
