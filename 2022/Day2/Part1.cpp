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
            points +=  1;
            if (inputLine[0] == 'A') {
               points += 3;
            } else if (inputLine[0] == 'B') {
               points += 0;
            } else if (inputLine[0] == 'C') {
               points += 6;
            }
         } else if (inputLine[2] == 'Y') {
            points +=  2;
            if (inputLine[0] == 'A') {
               points += 6;
            } else if (inputLine[0] == 'B') {
               points += 3;
            } else if (inputLine[0] == 'C') {
               points += 0;
            }
         } else if (inputLine[2] == 'Z') {
            points +=  3;
            if (inputLine[0] == 'A') {
               points += 0;
            } else if (inputLine[0] == 'B') {
               points += 6;
            } else if (inputLine[0] == 'C') {
               points += 3;
            }
         }
      }
   }

   cout << "Points: " << points << endl;

   inputFile.close();
}
