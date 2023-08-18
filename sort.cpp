#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Hàm sinh ngau nhien 1 so trong khoang [min, max]
int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Hàm sinh ngau nhien ki tu tu a-z
char random_character() {
   int random_case = random_number(0, 1); // Chon ngau nhien chu thuong hoac chu hoa
    if (random_case == 0) {
        return static_cast<int>(random_number(97, 122)); // Chu thuong: a-z
    } else {
        return static_cast<int>(random_number(65, 90)); // Chu hoa: A-Z
    }
}

// Hàm tao chuoi ngau nhien co do dai tu 1-5 ki tu
std::string generate_random_string() {
    int length = random_number(1, 5);
    std::string str;
    
    for (int i = 0; i < length; ++i) {
        str += random_character();
    }
    
    return str;
}

//HAM SAP XEP NOI BOT
void bubbleSort(std::string random_array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (random_array[j] > random_array[j + 1]) {
                // Hoán doi phan tu
                std::string temp = random_array[j];
                random_array[j] = random_array[j + 1];
                random_array[j + 1] = temp;
            }
        }
    }
}

//HAM SAP XEP CHON
void selectionSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Hoan doi phan tu nho nhat voi phan tu dau tien chua dc sap xep
        std::string temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// HAM SAP XEP QUICKSORT
int partition(std::string arr[], int low, int high) {
    std::string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(std::string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(std::string arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout<<"pt"<<i << arr[i] << " ";
}
//

int main() {
    // Khoi tao seed cho hàm random
    srand(time(0));
	
    // Tao mang gom 1000 phan tu , ki tu a-z voi do dai 1-5 ki tu
    std::string random_array[1000];
	int n = sizeof(random_array) / sizeof(random_array[0]);
   // Tao cac chuoi ngau nhien va luu vao mang
    for (int i = 0; i < 1000; ++i) {
        random_array[i] = generate_random_string();
        std::cout<<"Phan tu thu : "<<i<<": "<<random_array[i] << "\n";
    }

	// Su dung ham SORT de sap xep theo thu tu tang dan 
	std::sort(random_array, random_array + 1000); 
	for (int i = 0; i < 1000; ++i) {
        std::cout <<"Sap xep theo thu tu tang dan "<<i<<":"<< random_array[i] << "\n";
    }
    
    std::cout<<"----------------------------------------------------------------------------------------------------";
    
	// Su dung ham SORT de sap xep theo thu tu giam dan 
	std::sort(random_array, random_array + 1000, std::greater<std::string>());
    for (int i = 0; i < 1000; ++i) {
        std::cout <<"Sap xep theo thu tu giam dan "<<i<<":"<< random_array[i] << "\n";
    }
    
	std::cout<<"----------------------------------------------------------------------------------------------------";
	
	// In mang ra man hinh sau khi sap xep NOI BOT
    bubbleSort(random_array, n);
    std::cout<<"Sap xep noi bot: ";
    for (int i = 0; i < n; i++) {
        std::cout<<"pt"<<i<<": " << random_array[i] << " ";
    }
	std::cout<<"----------------------------------------------------------------------------------------------------";
	
	//In mang ra man hinh sau khi goi ham sap xep Chon
	selectionSort(random_array, n);
    std::cout << "Mang sau khi sap xep Chon: ";
    for (int i = 0; i < n; i++) {
    	std::cout<<"pt"<<i << random_array[i] << " ";
	}
	std::cout<<"----------------------------------------------------------------------------------------------------";
	
	// In ra man hinh sau khi goi ham QUICKSORT
	quickSort(random_array, 0, n - 1);
	std::cout << "Mang sau khi sap xep Quick Sort: ";
	printArray(random_array,n);
   return 0;
}

