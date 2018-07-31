// Q12650.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	int N[2]; 
	//cin >> N[0] >> N[1];
	//int *n = new int[N[0]];
	//int *R = new int[N[1]];
	int *n;
	int *R;
	while (cin >> N[0] >> N[1]){
		n = new int[N[0]];
		R = new int[N[1]];
		for (int i = 0; i < N[0]; i++)
		{
			n[i] = i + 1;
		}
		for (int i = 0; i < N[1]; i++)
		{
			cin >> R[i];
		}
		for (int i = 0; i < N[1]; i++){
			for (int j = 0; j < N[0]; j++){
				if (n[j] == R[i]){
					n[j] = NULL;
				}
			}
		}
		if (N[0] == N[1]){
			cout << '*';
		}
		else{
			for (int i = 0; i < N[0]; i++){
				if (n[i] != 0)
					cout << n[i] << ' ';
			}
		}
		delete [] n;
		delete [] R;
	}
	
		system("pause");
		return 0;
}

