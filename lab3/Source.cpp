#include <iostream>
#include "Vector.h"
#include <stdlib.h>

using namespace std;

int main() {
	
	double v[4] = { 25.3, 12.4, 45.6, 0.5 };
	
	TVector vec(v, 4);
	TVector voc;
	voc = vec;
	
	voc.print();
	vec.print();
	
	cout << voc[2] << " " << vec[0] << endl;
	
	voc[1] = 10.5;
	voc.print();
	
	double * mas = voc + vec;
	for (int i = 0; i < 8; i++)
		cout << mas[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}