#include <iostream>

using namespace std;

// argv = {"Statistics", "108", "2", "3", "4", "5"}
// array = {108,0 , , , }
int ConvertToIntArray(int argc, char* argv[], int array[]){
	if(argc < 2){
		cerr << "Error" << endl;
		return -1;
	}
	if(argc > 21){
		cerr << "Error: too many inputs; maximum 20 permitted." << endl;
		return -21;
	}
	
	for (int i = 1; i <= argc - 1; i++){
		array[i-1] = 0;
		int sign = 1;
		for (int j = 0;; j++){
			if (argv[i][j] == '\0'){
				break;
			}
			if (j==0 && argv[i][j] == 45){
				sign = -1;
			}
			else if (argv[i][j]>= 48 && argv[i][j]<= 57){
				array[i-1] = (array[i-1]*10)+(argv[i][j]-48);
				if (array[i-1] < 0 && sign == 1){
					cerr << "Error: integer at argument " << i << " is too big" << endl;
					return -1*i;
				}
				else if (array[i-1] < 0 && sign == -1){
					cerr << "Error: integer at argument " << i << " is too small" << endl;
					return -1*i;				
				}
			}
			else{
				cerr << "Error: Argument " << i << " is not an integer.";
				return -1*i;
			}
		}
		if (sign == -1){
			array[i-1] = array[i-1]*-1;
		}
	}
	
	return (argc - 1);
}

int findMax (int array[], int numElements){
	int intMax = array[0];

	for(int i = 1; i < numElements; i++){
		if(intMax < array[i]) {
			intMax = array[i];
		}
	}
	return intMax;
}

int findMin (int array[], int numElements){
	int intMin = array[0];
	for(int i = 1; i < numElements; i++){
		if(intMin > array[i]) {
			intMin = array[i];
		}
	}
	return intMin;
}

float average (int array[], int numElements){
	float sum = 0;
	
	for (int i = 0; i < numElements; i++){
		sum += array[i];
	} 
	float ave = sum / numElements;
	
	return ave;
}


int main (int argc, char* argv[]){

	int array [argc-1];
	int numElements;
	
	numElements = ConvertToIntArray (argc, argv, array);
	
	if (numElements > 0){
		int max = findMax(array, numElements);
		
		int min = findMin(array, numElements);
		
		float aver = average(array, numElements);

		cout << "Maximum: " << max << endl;
		cout << "Minimum: " << min << endl;
		cout << "Average: " << aver << endl;
	}
	
	return 0;
}