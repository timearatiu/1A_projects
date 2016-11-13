#include <iostream>
#include <stdlib.h>

using namespace std;

void newArray (char array[], int shifts, int size){
	for (int i = size-shifts-1; i<=size-2; i++){
		cout << array [i];
	}
	for (int i = 0; i < size-shifts-1;i++){
		cout << array[i]; 
	}
}

int main(){
	char array [61] = {'!', 'E', 'C', 'E', '1', '5', '0', '!'};
	
	for (int i=8; i<=60; i++){
		array[i] = ' ';
	}
	array[60] = 0;
	
	int rotations;
	cout << "Enter the number of rotations: ";
	cin >> rotations;
	
	
	
	for (int j=0; j<rotations;j++){
		
		
		for (int i=0; i<60;i++){
			cout << "============================================================" << endl;	
			newArray (array, i, 61);
			cout << endl;
			cout << "============================================================" << endl;
			system("cls");
		}
		
	}
	
	cout << "============================================================" << endl;	
	cout << array << endl;
	cout << "============================================================" << endl;	

	return 0;
}

