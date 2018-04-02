#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vec{5,2,4,6,1,3};

    for (auto i = vec.cbegin(); i != vec.cend(); ++i){
        cout << *i << " ";
    }
    cout << endl;

    int len = vec.size();
    int key = 0;
    for (int i = 1; i < len; ++i){
        key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key){
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = key;
    }

    for (auto i : vec){
        cout << i << " ";
    }

    cout << endl;

    system("pause");
    return 0;
}