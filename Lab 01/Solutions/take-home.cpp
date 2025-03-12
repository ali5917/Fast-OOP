#include<iostream>
using namespace std;

int main () {
	
//	Weekly Air Quality Index (AQI) Tracker 
//	int aqi[4][7];
	float avgAqi[4];
	int sum;
	
	int aqi[4][7] = {
	    {150, 175, 200, 300, 120, 80, 95},  // City 1
	    {140, 85, 105, 220, 160, 150, 300}, // City 2
	    {230, 200, 150, 300, 195, 90, 65},  // City 3
	    {100, 300, 190, 70, 85, 150, 250}   // City 4
	};
	
	for (int i = 0; i < 4; i++) {
		sum = 0;
		for (int j = 0; j < 7; j++) {
//			cout << "Enter AQI for City " << i + 1 << " on Day " << j + 1 << ": ";
//			cin >> aqi[i][j];
			sum += aqi[i][j];
		}
		avgAqi[i] = sum / 7.0;
	}
	
	int max = 0, worstCity = 0;
	cout << "\nAverage AQI for Each City:\n";
	for (int i = 0; i < 4; i++) {
		cout << "\nCity " << i + 1 << ": " << avgAqi[i];
		if (avgAqi[i] > max) {
			max = avgAqi[i];
			worstCity = i;
		}
	}
	cout << "\nCity " << worstCity + 1 << " has the Worst Air Quality.\n";
	
//	Identify Critical Pollution Days
	cout << "\nCritical Days for Each City:\n";
	for (int i = 0; i < 4; i++) {
		int found = 0;
		cout << "\nCity " << i + 1 << ":";
		for (int j = 0; j < 7; j++) {
			if (aqi[i][j] > 150) {
				cout << " " << j + 1;
				found = 1;
			}
		}
		if (found == 0) {
			cout << " No Critical Days Found!";
		}
	}
	
//	Data Visualization
	int maxStars, numStars;

	cout << "\n\nData Visualization:\n";
	for (int i = 0; i < 4; i++) {
		cout << "\nCity " << i + 1 << endl;
		maxStars = 0;
		for (int j = 0; j < 7; j++) {
			numStars = aqi[i][j] / 50;
			if (numStars > maxStars) {
				maxStars = numStars;
			}
		}
		
		for (int j = maxStars; j > 0; j--) {
			cout << "    	";
			for (int k = 0; k < 7; k++) {
				numStars = aqi[i][k] / 50;
				if (numStars < j) {
					cout << "  ";
				} else {
					cout << "* "; 
				}
			}
			cout << "\n";
		}
		cout << "---------------------\n";		
		cout << "Days	1 2 3 4 5 6 7\n";		
	}
	
	
}