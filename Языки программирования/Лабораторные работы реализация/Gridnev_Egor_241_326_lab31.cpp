#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;


void bubbleSort(vector<int>& arr) {

    int size = arr.size();
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) ? swap(arr[j], arr[j + 1]);
        }
    }
}




int main() {




    
    return 0;
}