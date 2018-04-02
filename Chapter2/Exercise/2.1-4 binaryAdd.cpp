#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> A{1, 0, 0, 1, 0, 0, 1, 1};
    vector <int> B{1, 1, 1, 1, 1, 1, 1, 1};
    vector <int> C;

    int reminder = 0;

    for (int i = A.size(); i >= 0; --i){
        int add = A[i] + B[i] + reminder;
        C[i + 1] = add % 2;
        reminder = add / 2;
    }

    if (reminder > 0){
        C[0] = 1;
    }

    for (auto iter = C.begin(); iter != C.end(); ++iter){
        auto p = C.begin();
        if (*p == 0){
            cout << "";
        }
       
        cout << *iter << " , ";
    }

    cout << endl;

    system("pause");
    return 0;
}