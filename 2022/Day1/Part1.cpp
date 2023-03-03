#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   int maxCals = 0;
   int currentCals = 0;

   while (getline(inputFile, inputLine)) {
      if (inputLine == "") {
         if (currentCals > maxCals) { maxCals = currentCals; }
         currentCals = 0;
      } else {
         currentCals += stoi(inputLine);
      }
   }

   cout << "Max Cals: " << maxCals << endl;

   inputFile.close();
}
