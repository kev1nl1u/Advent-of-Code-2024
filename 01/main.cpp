#include <iostream>
#include <fstream>
using namespace std;

void print(int[], int[], int);
void sort(int[], int, int);
void swap(int*, int*);

int main() {
    fstream in;

    in.open("input.txt", ios::in);

    if(in.fail()) {
        cout << "Errore nell'apertura del file";
        return 0;
    }
    
    // get lenght of ids
    int temp;
    int dim = 0;
    while(in >> temp >> temp){
    	dim++;
	}
	
	// reset file pointer
	in.close();
	in.open("input.txt", ios::in);
	
	// create 2 arrays 
    int v1[dim], v2[dim];
    
    // read
    int i = 0;
    while(in >> v1[i] >> v2[i]) i++;
	
	// sort
	sort(v1, 0, dim-1);
	sort(v2, 0, dim-1);
	
	// sum
	int sum = i = 0;
	for(i = 0; i < dim; i++){
		if(v1[i] > v2[i]) sum += (v1[i] - v2[i]);
		else sum += (v2[i] - v1[i]);
	}
	
	cout << sum << endl;
	
	/*** similarity score ***/
	int j = i = sum = 0;
	// for each n in v1
	for(i = 0; i < dim; i++){
		// count how many times in v2
		int count = 0;
		for(j = 0; j < dim; j++)
			if(v1[i] == v2[j]) count++;
		sum += v1[i] * count;
	}
	
	cout << sum << endl;
    
    return 0;
}

void print(int v1[], int v2[], int dim){
	int i;
	for(i = 0; i < dim; i++) cout << v1[i] << "\t" << v2[i] << "\n";
}

// quicksort di culpo
void sort(int v[], int sin, int des)
{
    int i, j, media;
    media = (v[sin]+v[des]) / 2;
    i = sin;
    j = des;
    do {
        while(v[i]<media) i++;
        while(media<v[j]) j--;
        if(i<=j) {
            swap(&v[i], &v[j]);
            i++;
            j--;
        }
    }while (j>=i);
    if(sin<j) sort(v,sin,j);
    if(i<des) sort(v,i,des);
}

void swap(int *a, int *b)
{
    int box;
    box = *a;
    *a = *b;
    *b = box;
}
