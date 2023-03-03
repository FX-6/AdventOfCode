#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   int topCals[3] = {0, 0, 0};
   int currentCals = 0;

   while (getline(inputFile, inputLine)) {
      if (inputLine == "") {
         if (currentCals > topCals[0]) {
            topCals[2] = topCals[1];
            topCals[1] = topCals[0];
            topCals[0] = currentCals;
         } else if (currentCals > topCals[1]) {
            topCals[2] = topCals[1];
            topCals[1] = currentCals;
         } else if (currentCals > topCals[2]) {
            topCals[2] = currentCals;
         }
         currentCals = 0;
      } else {
         currentCals += stoi(inputLine);
      }
   }

   cout << "Max Cals: " << topCals[0] + topCals[1] + topCals[2] << endl;

   inputFile.close();
}
