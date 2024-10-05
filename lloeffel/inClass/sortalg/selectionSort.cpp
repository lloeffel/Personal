#include <iostream>
#include <vector>
using namespace std;

void swap(int i1, int i2, vector <int> &vec) {
	int temp = vec[i1];
	vec[i1] = vec[i2];
	vec[i2] = temp;
}

void printVector(vector <int> &vec) {
	for (int i = 0; i < vec.size(); i++){
		cout << " " << vec.at(i);
	}
	cout << "\n";
}

void bubbleSort(vector <int> &vec){
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < vec.size()-1; j++){
			if (vec[j] > vec[j+1]){
				int temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}	
		}
	}
}

void selectionSort(vector <int> &vec){
	for(int i = 0; i < vec.size()-1; i++){
		int min = i;
		for(int j = i+1; j < vec.size(); j++){
			if (vec[j] < vec[min]){
				min = j;
			}
		}
		if (min != i){
			int temp = vec[min];
			vec[min] = vec[i];
			vec[i] = temp;
		}
	}
}

void insertionSort(vector <int> &vec){
	int insertPosition, valueToInsert;
	for(int i = 1; i < vec.size(); i++){
		valueToInsert = vec[i];
		insertPosition = i;

		while (insertPosition > 0 && vec[insertPosition] > valueToInsert){
			vec[insertPosition] = vec[insertPosition - 1];
			insertPosition = insertPosition - 1;
		}
		vec[insertPosition] = valueToInsert;
	}
}

int main() {
	vector <int> data = {4, 1, 5, 6, 3, 2};
	printVector(data);
	insertionSort(data);
	printVector(data);
	return 0;
}
