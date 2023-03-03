#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   int firstElve[2], secondElve[2], numOfContainments;

   while (getline(inputFile, inputLine)) {
      firstElve[0] = stoi(inputLine.substr(0, inputLine.find("-")));
      firstElve[1] = stoi(inputLine.substr(inputLine.find("-") + 1, inputLine.find(",")));
      secondElve[0] = stoi(inputLine.substr(inputLine.find(",") + 1, inputLine.find_last_of("-")));
      secondElve[1] = stoi(inputLine.substr(inputLine.find_last_of("-") + 1, inputLine.length()));

      if ((firstElve[0] <= secondElve[0] && firstElve[1] >= secondElve[1]) || (firstElve[0] >= secondElve[0] && firstElve[1] <= secondElve[1])) { numOfContainments++; }
   }

   inputFile.close();

   cout << "Priorities: " << numOfContainments << endl;
}
