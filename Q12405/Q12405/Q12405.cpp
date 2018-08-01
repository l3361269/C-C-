// Q12405.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	cin >> T;
	int n;
	char *arr;
	int t;
	for (int i = 0; i < T; i++){
		t = 0;
		cin >> n;
		arr = new char[n];
		for (int j = 0; j < n; j++){
			cin >> arr[j];
		}
		for (int k = 0; k < n; k++){
			if ((arr[k] == '#') && (arr[k + 1] == '.') && (arr[k + 2] == '#')){
				t++; 
				k += 2;
			}
			else if ((arr[k] == '#')&&(arr[k+1] == '.')){
				t++;
			}
			else if ((arr[k] == '.')&(arr[k+1] == '#')){
				t++;
				k += 1;
			}
		}
		cout << t<<endl;
		delete[] arr;
	}


	system("pause");
	return 0;
}

