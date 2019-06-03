//Christopher Butler
//This program simplifies a fraction as much as possible.

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getFactors(int number); //Declare the function to find factors

int main() {
    
	int num;
	int den;

	cout << "Enter numerator:\n";
	cin >> num;

	cout << "Enter denominator:\n";
	cin >> den;

	int simpNum;
	int simpDen;

	int gcf; //greatest common factor
	
	double decimal_approximation;
	
	vector<int> numFactors = getFactors(num);
	vector<int> denFactors = getFactors(den);

	//now need to find common factors...

	int max_size = numFactors.size() + denFactors.size();

	vector<int> commonFactors(max_size);

	for (int i = 0; i < numFactors.size(); i++) {  //finds common factors
		
		for (int j = 0; j < denFactors.size(); j++) {
			if (numFactors[i] == denFactors[j]) {
				commonFactors[i] = numFactors[i];
			}
		}
	}

	gcf = *max_element(commonFactors.begin(), commonFactors.end()); //finds greatest common factor

	simpNum = num / gcf;
	simpDen = den / gcf;

	decimal_approximation = (double)num / den;

	//OUTPUT SECTION
	if (simpNum == simpDen) {
		cout << num << "/" << den << " = " << 1;
	}
	else if (simpDen == 1) {
		cout << num << "/" << den << " = " << simpNum;
	}
	else if (simpNum != simpDen) {
		cout << num << "/" << den << " = " << simpNum << "/" << simpDen;
	}
}

vector<int> getFactors(int number) { //returns all factors of an integer
	
	vector<int> Factors;
	
	for (int i = 1; i <= number; i++) {
		if ((number%i) == 0) {
			Factors.push_back(i);
		}
	}
	return Factors;
}