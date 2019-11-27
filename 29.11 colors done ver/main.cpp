//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
#include <locale>
using namespace std;

int check_boxs(int x, int y, int** mat, int num);
void cout_array(int** mat, int num);

int main()
{
	//setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int num = 0;
	cout << "Enter your number: ";
	cin >> num;
	int** mat = new int*[num];
	// mat_kopi используется для отслеживания проверенных цветов
	// помечаются они как: -1
	int** mat_kopi = new int*[num+1];
	for (int i = 0; i < num; i++){
		mat[i] = new int[num];
	}
	for (int i = 0; i <= num+1; i++){
		mat_kopi[i] = new int[num+1];
	}
	for (int i = 0; i < num; i++){
		for (int n = 0; n < num; n++)
		{
			mat[i][n] = rand() % 7 + 1;
			mat_kopi[i+1][n+1] = mat[i][n];
		}
	}
	for (int i = 0; i <= num+1; i++){
		for (int n = 0; n <= num+1; n++){
			if (i == (num+1) || n == num+1 || (i == 0) || (n == 0)) {
				mat_kopi[i][n] = 0;
			}
		}
	}



	for (int i = 0; i < num; i++)
	{
		for (int n = 0; n < num; n++)
		{
			if (mat[i][n] == 1)
			{
				cout<<1<<' ';
			}
			if (mat[i][n] == 2)
			{
				cout<<2<<' ';
			}
			if (mat[i][n] == 3)
			{
				cout<<3<<' ';
			}
			if (mat[i][n] == 4)
			{
				cout<<4<<' ';
			}
			if (mat[i][n] == 5)
			{
				cout<<5<<' ';
			}
			if (mat[i][n] == 6)
			{
				cout<<6<<' ';
			}
            if (mat[i][n] == 7)
			{
				cout<<7<<' ';
			}
		}
		cout << endl;
	}
	/*HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);*/

	
	int max = 0;

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			int number_current = check_boxs(j, i, mat_kopi, num+1) + 1 ;
			//cout_array(mat_kopi, num);
			if (max < number_current){
				max = number_current;
			}
		}
	}
	//cout << endl << num << endl;
	cout << "Max near boxes: " << max << endl;
	//cout_array(mat_kopi, num);
}


int check_boxs(int x, int y, int** mat, int num) {
	int result = 1;
	/* Проверка угловых ячеек */  
	if (x == 1 && y == 1 && mat[y][x] != 0){
		// go down
		if (mat[y + 1][x] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		 }else
		// go right
		if (mat[y][x + 1] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}
	else if (x == num && y == 1 && mat[y][x] != 0) {
		// go down
		if (mat[y + 1][x] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		}else
		// go left
		if (mat[y][x - 1] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x - 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}
	else if (x == num && y == num && mat[y][x] != 0) {
		// go up
		if (mat[y - 1][x] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x, y - 1, mat, num);
			return result;
		}else
		// go left
		if (mat[y][x - 1] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x - 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}
	else if (x == 1 && y == num-1 && mat[y][x] != 0) {
		// go up
		if (mat[y - 1][x] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x, y - 1, mat, num);
			return result;
		}else
		// go right
		if (mat[y][x + 1] == mat[y][x]) {
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}

	/* Проверка всех боковых граней,кроме угловых ячеек */
	// Вверхняя грань
	if (y == 1 && x > 1 && mat[y][x] != 0) {
		// go down
		if (mat[y + 1][x] == mat[y][x] && mat[y + 1][x] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		}
		else if (mat[y][x + 1] == mat[y][x] && mat[y][x + 1] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}
	// Правая грань
	else if (x == (num - 1) && y > 0 && mat[y][x] != 0) {
		// go down
		if (mat[y + 1][x] == mat[y][x] && mat[y + 1][x] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		}else
		// go left
		if (mat[y][x - 1] == mat[y][x] && mat[y][x - 1] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x - 1, y, mat, num);
			return result;
		}
		else{
			mat[y][x] = 0;
			
			return 1;
		}
	}
	// Нижняя грань
	else if (y == (num - 1) && x < (num-1) && mat[y][x] != 0) {
		// go up
		if (mat[y - 1][x] == mat[y][x] && mat[y - 1][x] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x, y - 1, mat, num);
			return result;
		}else
		// go left
		if (mat[y][x - 1] == mat[y][x] && mat[y][x - 1] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x - 1, y, mat, num);
			return result;
		}else 	
		// go right	
		if (mat[y][x + 1] == mat[y][x] && mat[y][x + 1] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
			return 1;
		}
	}
	// Левая грань
	else if (x == 0 && y < (num-1) && mat[y][x] != 0) {
		// go down
		if (mat[y + 1][x] == mat[y][x] && mat[y + 1][x] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		}else
		// go right
		if (mat[y][x + 1] == mat[y][x] && mat[y][x + 1] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}else{
			mat[y][x] = 0;
			return 1;
		}
	}
	
	/* Проверка середины*/
	else {
		if (mat[y - 1][x] == mat[y][x] && mat[y - 1][x] != 0) {
			mat[y][x] = 0;
			result += check_boxs(x, y - 1, mat, num);
			return result;
		}
		else if (mat[y][x + 1] == mat[y][x] && mat[y][x + 1] != 0) {
		// go right
			mat[y][x] = 0;
			result += check_boxs(x + 1, y, mat, num);
			return result;
		}
		else if (mat[y + 1][x] == mat[y][x] && mat[y + 1][x] != 0) {
		// go down
			mat[y][x] = 0;
			result += check_boxs(x, y + 1, mat, num);
			return result;
		}
		else if (mat[y][x - 1] == mat[y][x] && mat[y][x - 1] != 0){
		// go left
			mat[y][x] = 0;
			result += check_boxs(x - 1, y, mat, num);
			return result;
		}
		else {
			mat[y][x] = 0;
				 return 1;
		}
		
	}
	
	return 0;
}
void cout_array(int** mat, int num) {
	num += 1;
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= num; j++) {
				cout << mat[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}