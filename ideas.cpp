#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getIdeas(){
	string ideas;
	ifstream file;
	file.open("ideas.txt");
	if (file){
		while(!file.eof()){
			getline(file, ideas);
			cout << ideas <<endl;
		}
	}else{
		cout << "Failed opening file. Creating one." <<endl;
		ofstream file("ideas.txt");
	}
	file.close();
}

void AddIdeas(string idea){
	ifstream readFile;
	readFile.open("ideas.txt");
	if(readFile){
		ofstream file("ideas.txt", ios::ate | ios::in);
		file << idea << "\n" << "\n" <<endl;
		file.close();
	}
}

int main(){
	string idea;
	string input;
	cout << "Choose" <<endl;
	cout << "1. Get Ideas \n2. Add Ideas" <<endl;
	cin >> input;
	if(input == "1")
		getIdeas();
	else
		cout << "Please enter the idea. Use '\\n' to break a line, not Enter." << endl;
		getline(cin >> idea, idea);
		AddIdeas(idea);
	return 0;
}