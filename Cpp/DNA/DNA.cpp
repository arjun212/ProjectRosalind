#include <iostream>
#include <string>
#include <fstream>

/*TO ACTUALLY RUN THIS CODE...*/
//ensure rosalind_dna.txt is in the local directory for the project

int main() {
		
	std::string dataString = ""; //overall data string
	std::string lineString = ""; 
	std::ifstream dataFile;
	
	dataFile.open("rosalind_dna.txt", std::ifstream::in); 
	
	if (dataFile.is_open()) { //if you could open the file proceed...
		while (std::getline(dataFile, lineString)) {
			dataString += lineString; //cache and update until end-of-file in case data spans multiple lines
		}
	}
	else { std::cout << "Couldn't find Rosalind Data .txt" << std::endl; } 
	
	std::cout << "Counts for " 
		<<   "A: " << std::to_string(std::count(dataString.begin(), dataString.end(), 'A')) //std::count returns int
		<< ", T: " << std::to_string(std::count(dataString.begin(), dataString.end(), 'T'))
		<< ", C: " << std::to_string(std::count(dataString.begin(), dataString.end(), 'C'))
		<< ", G: " << std::to_string(std::count(dataString.begin(), dataString.end(), 'G'))
		<< std::endl;

	std::cout << "Press any key to exit" << std::endl;
	std::getchar();

	return 0;
}