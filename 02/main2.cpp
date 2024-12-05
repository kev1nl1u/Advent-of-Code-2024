// Problem Dampener - part 2
// check if [i+2] meet req
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool check(vector<int>); // returns index of element to remove
void print(vector<int> v){
	for(int n : v) cout << n << " ";
	cout << endl;
}

int main() {
    fstream in;

    in.open("input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }

	int safe = 0;
    while(!in.eof()){
    	vector<int> report;
    	// read line
    	while(in.peek() != '\n' && !in.eof()){
	    	int n;
	    	in >> n;
			report.push_back(n);
		}
		in.ignore(); // skip '\n'
		
		if(check(report)) safe++;
		else{
			// try to brute force remove one and see if it works
			// remove [0]
			int i = 0;
			while(i < report.size()){
				// dummy
				vector<int> dummy = report;
				dummy.erase(dummy.begin() + i);
				if(check(dummy)){
					// ok
					safe++;
					break;
				}
				i++;
			}
		}
		
	}
	
	cout << safe;



	return 0;
    
}

bool check(vector<int> v){
	// check if level is increasing
	bool is_increasing = true;
	int i = 0;
	
	while(is_increasing && i < v.size()-1){
		// if [i] > [i+1] decreasing or if gap too big
		if(v[i] >= v[i+1] || v[i] + 3 < v[i+1]) is_increasing = false;

		i++;
	}
	
	// check if level is decreasing
	bool is_decreasing = true;
	i = 0;
	while(is_decreasing && i < v.size()-1){
		// if [i] < [i+1] increasing or if gap too big
		if(v[i] <= v[i+1] || v[i] - 3 > v[i+1]) is_decreasing = false;
		i++;
	}
	
	return is_increasing || is_decreasing;
	
}
