#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &a, int value, int low, int high);

int main(){
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int low = 0;
    int high = a.size() - 1;
    int value = 0;
	cout << "Please inout the number you want to search: ";
	cin >> value;

    int index =  binarySearch(a, value, low, high);

    if (index == -1) {
		cout << "the number you research is not exit" << endl;
	}
	else {
		cout << "the number you research is in the " 
			 << index << "'th position" << endl;
	}
	system("pause");
    return 0;
}

int binarySearch(vector<int> &a, int value, int low, int high){
    if (low > high){
        return -1;
    }
    
    int middle = 0;
    middle = (high + low) / 2;

    if (value == a[middle]){
        return middle;
    }
    else if (value > middle){
        return binarySearch(a, value, middle + 1, high);
    }
    else{
        return binarySearch(a, value, low, middle - 1);
    }
}