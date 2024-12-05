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

void printv(vector<int> v){
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
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
	vector<string> coords; // trovo tutti i MAS e controllo se 2 hanno stesse coordinate per 'A' centro
	// find MAS
	int count = 0;
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++){
			
			if(m[i][j] == 'M'){
				//cout << "M at " << i << " " << j << endl;
				
				string mas = "M";
				
				string c;
				mas = m[i][j];
				// cerca diagonale dx basso
				for(int k = 1; k < 3 && j+k < m[i].size() && i+k < m.size(); k++) mas += m[i+k][j+k];
				if(mas == "MAS"){
					c = to_string(i+1) + "," + to_string(j+1);
					coords.push_back(c);
				}
				//cout << "\t" << mas << "\t" << " dx down" << endl;
				
				mas = m[i][j];
				// cerca diagonale dx alto
				for(int k = 1; k < 3 && j+k < m[i].size() && i-k >= 0; k++) mas += m[i-k][j+k];
				if(mas == "MAS"){
					c = to_string(i-1) + "," + to_string(j+1);
					coords.push_back(c);
				}
				//cout << "\t" << mas << "\t" << " dx up" << endl;
				
				mas = m[i][j];
				// cerca diagonale sx basso
				for(int k = 1; k < 3 && j-k >= 0 && i+k < m.size(); k++) mas += m[i+k][j-k];
				if(mas == "MAS"){
					c = to_string(i+1) + "," + to_string(j-1);
					coords.push_back(c);
				}
				//cout << "\t" << mas << "\t" << " sx down" << endl;

				mas = m[i][j];
				// cerca diagonale sx alto
				for(int k = 1; k < 3 && j-k >= 0 && i-k >= 0; k++) mas += m[i-k][j-k];
				if(mas == "MAS"){
					c = to_string(i-1) + "," + to_string(j-1);
					coords.push_back(c);
				}
				//cout << "\t" << mas << "\t" << " sx up" << endl;
				
			}
			
		}
		
		
	}
	
	for(int i = 0; i < coords.size(); i++){
					
		for(int j = i+1; j < coords.size(); j++){
			
			if(coords[i] == coords[j]){
				count++;
				//cout << "\tif " << coords[i] << " " << coords[j] << endl;
			}
			
		}
		
	}
	
	cout << count;
	
	in.close();
	
	return 0;
}
