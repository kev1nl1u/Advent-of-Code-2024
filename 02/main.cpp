#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    fstream in;

    in.open("input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }
    
    // controllo 1 report per volta
    int safe = 0;
    while(!in.eof()){
    	vector<int> report;
	    while(in.peek() != '\n' && !in.eof()){
	    	int n;
	    	in >> n;
	    	//cout << n << " ";
			report.push_back(n);
		}
		//cout << endl;

		in.ignore(); // skip '\n'

		// check report req
		int i;
		
		if(report.size() == 0) break; // idk i havent read doc of eof
		// check if they are all increasing or decreasing by 1 to 3
		// if they are all increasing
		for(i = 0; i < report.size() - 1; i++){
			if((report[i] >= report[i+1]) // if [i] > [i+1] --> not increasing
			|| (report[i] + 3 < report[i+1])) // gap bigger than 3
			{
				break;
			}
 		}
		if(i == report.size()-1){
			for(int r : report) cout << r << " ";
			cout << endl;
			safe++;
			continue;
		}
	
		// check if they are all decreasing
		for(i = 0; i < report.size() - 1; i++){
			if((report[i] <= report[i+1]) // if [i] < [i+1] --> not decreasing
			|| (report[i] - 3 > report[i+1])) // gap bigger than 3
			{
				break;
			}
 		}
		if(i == report.size()-1){
			for(int r : report) cout << r << " ";
			cout << endl;
			safe++;
		}

	}
		
	cout << safe;

	return 0;
    
}
