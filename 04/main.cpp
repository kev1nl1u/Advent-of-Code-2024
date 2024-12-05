#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void printm(vector<vector<char>> m){
	for(vector<char> line : m){
		for(char n : line){
			cout << n << " ";
		}
		cout << endl;
	}
}

int main(){
	fstream in;

    in.open("input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }

	// read matrix
	vector<vector<char>> m;
	while(!in.eof()){
		vector<char> v;
		// read line
    	while(in.peek() != '\n' && !in.eof()){
	    	char c;
	    	in.get(c);
			v.push_back(char(c));
		}
		in.ignore(); // skip '\n'
		
		m.push_back(v);
	}
	//printm(m);
	
	// find XMAS
	int count = 0;
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++){
			
			if(m[i][j] == 'X'){
				//cout << "X at " << i << " " << j << endl;
				
				string xmas = "X";
				// cerca dx
				for(int k = 1; k < 4 && j+k < m[i].size(); k++) xmas += m[i][j+k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " dx" << endl;
				
				xmas = m[i][j];
				// cerca sx
				for(int k = 1; k < 4 && j-k >= 0; k++) xmas += m[i][j-k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " sx" << endl;
				
				xmas = m[i][j];
				// cerca basso
				for(int k = 1; k < 4 && i+k < m.size(); k++) xmas += m[i+k][j];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " down" << endl;
				
				xmas = m[i][j];
				// cerca alto
				for(int k = 1; k < 4 && i-k >= 0; k++) xmas += m[i-k][j];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " up" << endl;
				
				xmas = m[i][j];
				// cerca diagonale dx basso
				for(int k = 1; k < 4 && j+k < m[i].size() && i+k < m.size(); k++) xmas += m[i+k][j+k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " dx down" << endl;
				
				xmas = m[i][j];
				// cerca diagonale dx alto
				for(int k = 1; k < 4 && j+k < m[i].size() && i-k >= 0; k++) xmas += m[i-k][j+k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " dx up" << endl;
				
				xmas = m[i][j];
				// cerca diagonale sx basso
				for(int k = 1; k < 4 && j-k >= 0 && i+k < m.size(); k++) xmas += m[i+k][j-k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " sx down" << endl;
				
				xmas = m[i][j];
				// cerca diagonale sx alto
				for(int k = 1; k < 4 && j-k >= 0 && i-k >= 0; k++) xmas += m[i-k][j-k];
				count += !xmas.compare("XMAS");
				//cout << "\t" << xmas << "\t" << " sx up" << endl;
				
			}
			
		}
		
		
	}
	
	cout << count;
	
	in.close();
	
	return 0;
}
