#include<iostream>
using namespace std;

int main () {
	
//	Weekly Air Quality Index (AQI) Tracker 
	int aqi[4][28];
	float mAvg[4];
	float wAvgs[4][4];
	int sum, monthSum;

	for (int i = 0; i < 4; i++) {
		monthSum = 0;
		for (int week = 0; week < 4; week++) {
			sum = 0;
			cout << "Enter AQI for City " << i + 1 << " in Week " << week + 1 << ": ";
			for (int j = 0; j < 7; j++) {
				cin >> aqi[i][j + (week * 7)];
				sum += aqi[i][j + (week * 7)];
			}
			monthSum += sum;
			wAvgs[i][week] = sum / 7.0;
		}
		mAvg[i] = monthSum / 28.0; 
	}
	
//	Identifying the City with most Improved Air Quality
	int bestCity = -1;
	int maxDrop = -10000.0;
	for (int i = 0; i < 4; i++) {
		float drop = wAvgs[i][1] - wAvgs[i][3];
		if (drop > maxDrop) {
			maxDrop = drop;
			bestCity = i;
		}
	}
	
//	Data Visualization
	int maxStars, numStars;

	cout << "\n\nData Visualization:\n";
	for (int i = 0; i < 4; i++) {
		cout << "\nCity " << i + 1 << endl;
		maxStars = 0;
		for (int j = 0; j < 28; j++) {
			numStars = aqi[i][j] / 50;
			if (numStars > maxStars) {
				maxStars = numStars;
			}
		}
		
		for (int j = maxStars; j > 0; j--) {
			cout << "    	";
			for (int k = 0; k < 28; k++) {
				if (k % 7 == 0 && k != 0) {
					cout << "   ";
				}
				numStars = aqi[i][k] / 50;
				if (numStars < j) {
					cout << "  ";
				} else {
					cout << "* "; 
				}
			}
			cout << "\n";
		}
		cout << "------------------------------------------------------------------------\n";		
		cout << "Days	1 2 3 4 5 6 7    1 2 3 4 5 6 7    1 2 3 4 5 6 7    1 2 3 4 5 6 7\n";		
		cout << "    	   Week 1           Week 2           Week 3           Week 4    \n";
	}

//	Generate a report
	cout << "\n\n------------ Detailed Report ------------";
	          
	int max = 0, worstCity = 0;                                                 
	cout << "\n\nMonthly Average AQI for Each City:\n";
	for (int i = 0; i < 4; i++) {
		cout << "\nCity " << i + 1 << ": " << mAvg[i];
		if (mAvg[i] > max) {
			max = mAvg[i];
			worstCity = i;
		}
	}
	cout << "\n\nCity " << worstCity + 1 << " has the Worst Air Quality.\n";
	
	
	cout << "\n\nCity " << bestCity + 1 << " has the most Improved Air Quality!\n";
	cout <<"	AQI Average Dropped from " << wAvgs[bestCity][1] << " in Week 1 to " << wAvgs[bestCity][3] << " in Week 4\n";
	
	cout << "\nWeekly AQI Averages for Each City:\n";
	for (int i = 0; i < 4; i++) {
		cout << "\nCity " << i + 1;
		for (int j = 0; j < 4; j++) {
			cout << "\n	Week " << j + 1 << ": " << wAvgs[i][j]; 
		}
	}	
	
	//	Identify Critical Pollution Days
	cout << "\n\nCritical Days for Each City:\n";
	for (int i = 0; i < 4; i++) {
		int found = 0;
		cout << "\nCity " << i + 1 << ":";
		for (int j = 0; j < 28; j++) {
			if (aqi[i][j] > 150) {
				cout << " " << j + 1;
				found = 1;
			}
		}
		if (found == 0) {
			cout << " No Critical Days Found!";
		}
	}
	
	//	Comparison of Highest and Lowest AQI values over the month
	cout << "\n\nComparison of Highest and Lowest AQI Values over the month for:\n";
	for (int i = 0; i < 4; i++) {
		int highest = 0;
		int lowest = 10000;
		
		cout << "\nCity " << i + 1 << " --> ";
		for (int j = 0; j < 28; j++) {
			if (aqi[i][j] > highest) {
				highest = aqi[i][j];
			}
			if (aqi[i][j] < lowest) {
				lowest = aqi[i][j];
			}	
		}
		cout << "Highest: " << highest << ", Lowest = " << lowest;
	}
}