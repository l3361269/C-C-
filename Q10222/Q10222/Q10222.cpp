// Q10222.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string>

char Q(char c){
	string str = "1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
	for (int i = 0; i < str.size(); i++){
		if (c == str[i]){
			return str[i - 2];
		}
	}
	return ' ';
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	string *str = new string[];
	char c;
	int i = 0;
	while (cin >> c){
		str[i] = c;
		i++;
	}
	cout << str;
	*/
	/*
	string s;
	cin >> s;
	cout << s;
	*/
	string s;
	while (getline(cin, s)){
		for (int i = 0; i < s.length();i++){
			cout << Q(s[i]);
	}
	
	
	
	}

	system("pause");
	return 0;
}

