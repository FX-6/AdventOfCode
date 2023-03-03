#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   int points = 0;

   while (getline(inputFile, inputLine)) {
      if (inputLine != "") {
         if (inputLine[2] == 'X') {
            points +=  0;
            if (inputLine[0] == 'A') {
               points += 3;
            } else if (inputLine[0] == 'B') {
               points += 1;
            } else if (inputLine[0] == 'C') {
               points += 2;
            }
         } else if (inputLine[2] == 'Y') {
            points +=  3;
            if (inputLine[0] == 'A') {
               points += 1;
            } else if (inputLine[0] == 'B') {
               points += 2;
            } else if (inputLine[0] == 'C') {
               points += 3;
            }
         } else if (inputLine[2] == 'Z') {
            points +=  6;
            if (inputLine[0] == 'A') {
               points += 2;
            } else if (inputLine[0] == 'B') {
               points += 3;
            } else if (inputLine[0] == 'C') {
               points += 1;
            }
         }
      }
   }

   cout << "Points: " << points << endl;

   inputFile.close();
}
