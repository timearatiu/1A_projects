#include <iostream>
#include <math.h>

using namespace std;

int main () {
	char colour[4];
	bool inputValid = true;
	
	cout << "Enter the four resistor color codes: ";
	
	cin >> colour;
		
	double values[4];
	
	for (int counter = 1; counter <= 4; counter++){ 
		switch (colour[counter-1]){
			case 'k':
				if (counter == 4){ // for fourth band only
					inputValid = false;
				}
				else{ // anything but fourth band
					values [counter-1] = 0;
				}
				break;
			case 'n':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.01;
				}
				else{ // anything but fourth band
					values [counter-1] = 1;
				}
				break;
			case 'R':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.02;
				}
				else{ // anything but fourth band
					values [counter-1] = 2;
				}
				break;
			case 'O':
				if (counter == 4){ // for fourth band only
					inputValid = false;
				}
				else{ // anything but fourth band
					values [counter-1] = 3;
				}
				break;
			case 'Y':
				if (counter == 4){ // for fourth band only
					inputValid = false;
				}
				else{ // anything but fourth band
					values [counter-1] = 4;
				}
				break;
			case 'G':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.005;
				}
				else{ // anything but fourth band
					values [counter-1] = 5;
				}
				break;
			case 'B':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.0025;
				}
				else{ // anything but fourth band
					values [counter-1] = 6;
				}
				break;
			case 'V':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.001;
				}
				else{ // anything but fourth band
					values [counter-1] = 7;
				}
				break;
			case 'y':
				if (counter == 4){ // for fourth band only
					values[counter-1] = 0.0005;
				}
				else{ // anything but fourth band
					values [counter-1] = 8;
				}
				break;
			case 'W':
				if (counter == 4){ // for fourth band only
					inputValid = false;
				}
				else{ // anything but fourth band
					values [counter-1] = 9;
				}
				break;
			case 'd': // can only be used on third or fourth band
				if (counter == 4){
					values [counter-1] = 0.05;
				}
				else if (counter == 3) {
					values [counter-1] = -1; // 10 to the power of -1;
				}
				else{
					inputValid = false;
				}
				break;
			case 'S': // can only be used on third or fourth band
				if (counter == 4){
					values [counter-1] = 0.1;
				}
				else if (counter == 3){
					values [counter-1] = -2; // 10 to the power of -2;
				}
				else{
					inputValid = false;
				}
				break;
			case 'N': // can only be used on fourth band
				if (counter == 4){
					values [counter-1] = 0.2; // N (none) can only be used for the 4th value which is for tolerance of 20%
				}
				else {
					inputValid = false; // if N appears anywhere other than for the 4th value, it's invalid
				}
				break;
			default:
				inputValid = false; 
				break;
		}
	}
	if (inputValid == true){
		
		cout << "Resistance is " << (values[0]*10 + values [1]) * pow (10, values [2]) << " ohms (+/-" << (values[0]*10 + values [1]) * pow (10, values [2]) * values [3] << " ohms tolerance)" << endl;  
	}
	else {
		cerr << "Error: Invalid color code entered!" << endl;
	}
	return 0;
	}