/**********************************************************************
 * ѡ���������ҳ���������СԪ��������A[0]��������Ȼ���ҳ���СԪ�أ���A[1]*
 *�������������ƣ�                                                     *
 *��д����ʱ������һ��bug������֮ǰû����flag��ǣ�����A[min]�е�Ԫ�ر����*
 *һ��Ԫ�ش��档                                                       *
***********************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> A{ 10, 20, 8, 40, 60, 5, 4, 100, 2, 50 };

	int len = A.size();
	int key = 0;
	int min = 0;
	bool flag = false; 
	for (int i = 0; i < len; ++i) {
		key = A[i];
		int j = i + 1;                     

		while (j < len) {   // �ҵ���������С��ֵ
			if (key > A[j]) {
				key = A[j];
				min = j;   // min����������ǵ��ҵ���Сֵʱ����Сֵ����λ��
				flag = true;  //���ڱ��min��ֵ�Ƿ����ı�
			}
			++j;         
		}
		
		if (flag == true) {
			A[min] = A[i];
			A[i] = key;
			flag = false;
		}
		
	}

	for (auto i = A.cbegin(); i != A.cend(); ++i) {
		cout << *i << endl;
	}

	system("pause");
	return 0;
}