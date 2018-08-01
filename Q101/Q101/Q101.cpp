// Q101.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>


int find(int **arr,size_t arr_size, int a,int &i, int &j){
	for (int i = 0; i < arr_size; i++){
		for (int j = 0; j < arr_size; j++){
			if (a == arr[i][j]){
				return i, j;
			}
		}
	}
}
void above(int **arr,int *a,size_t arr_size,int n){
	for (int i = n; i < arr_size;i++){  //要move的積木編號的array
		for (int j = 0; j < arr_size; j++){ //看該array裡的每個元素的值
			if ((j == a[i])&&(j!=n)){ //如果有其他不屬於該編號的積木
				for (int k = 0; k < arr_size; k++){
					if (arr[j][k]>arr_size){
						arr[j][k] = j;
						a[i] = 888888;
					}
				}
			}
		}

	}
}
void one(int **arr, size_t arr_size, int a, int b){
	int i,j=find(arr, arr_size, a,i,j);
	above(arr, arr[i], arr_size, j + 1);
	int k,w=find(arr, arr_size, b,k,w);
	above(arr, arr[k], arr_size, w + 1);
	arr[k][w + 1] = arr[i][j];
	arr[i][j] = 888888;
}
void two(int **arr, size_t arr_size, int a, int b){
	int i, j = find(arr, arr_size, a,i,j);
	above(arr, arr[i], arr_size, j + 1);
	int k, w = find(arr, arr_size, b,k,w);
	for (int x = w; x < arr_size; x++){
		if (arr[k][x]>arr_size){
			arr[k][x] = arr[i][j];
			arr[i][j] = 888888;
		}
	}
}
void three(int **arr, size_t arr_size, int a, int b){
	int i, j = find(arr, arr_size, a,i,j);
	int k, w = find(arr, arr_size, b,k,w);
	above(arr, arr[k], arr_size, w + 1);
	for (int x = j; x < arr_size; x++){
		arr[k][w+1] = arr[i][x];
		w=w + 1;
		arr[i][x] = 8888888;
	}
}
void four(int **arr, size_t arr_size, int a, int b){
	int i, j = find(arr, arr_size, a,i,j);
	int k, w = find(arr, arr_size, b,k,w);
	for (int x = w; x < arr_size; x++){
		if (arr[k][x]>arr_size){
			arr[k][x] = arr[i][j];
			arr[i][j] = 888888;
			j += 1;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int N= 0;
	cin >> N;
	int **arr;
	arr = new int*[N];
	for (int i = 0; i < N; i++){
		arr[i] = new int[N];
		arr[i][0] = i;
	}
	
	
	string s;
	int a, b;
	while (getline(cin,s)){
		//cin.get();
		if (s.find("move", 0) == 0 && s.find("onto", 7)){
			a = s[5];
			b = s[-1];
			one(arr, N, a, b);
		}
		else if (s.find("move", 0) == 0 && s.find("over", 7)){
			a = s[5];
			b = s[-1];
			two(arr, N, a, b);
		}
		else if (s.find("pile", 0) == 0 && s.find("onto", 7)){
			a = s[5];
			b = s[-1];
			three(arr, N, a, b);
		}
		else if (s.find("pile", 0) == 0 && s.find("over", 7)){
			a = s[5];
			b = s[-1];
			four(arr, N, a, b);
		}
		else{
			break;
		}

	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (arr[i][j] < N){
				cout << arr[i][j];
			}
		}
		cout << endl;
	}
	

	system("pause");
	return 0;
}

