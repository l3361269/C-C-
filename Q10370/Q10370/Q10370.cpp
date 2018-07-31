// Q10370.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cmath>
#include <iomanip>


int _tmain(int argc, _TCHAR* argv[])
{
	int C, N;
	cin >> C;
	int *s;
	int t;
	int n;
	float m = 0;
	for (int i = 0; i < C; i++){
		cin >> N;
		s = new int[N];
		t = 0;
		for (int j = 0; j < N; j++){
			cin >> s[j];
			t += s[j];
		}
		m = (float)t / (float)N;
		n = 0;
		for (int k = 0; k < N; k++){
			if (s[k]>m){
				n++;
			}
		}
		
		cout << fixed<<setprecision(3) << (float)n/(float)N*100 << "%" << endl;
		delete[] s;
	}


	system("pause");
	return 0;
}

