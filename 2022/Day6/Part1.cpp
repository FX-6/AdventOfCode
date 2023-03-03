#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   getline(inputFile, inputLine);
   bool fourSame = false;
   int pos;

   for (pos = 3; pos < inputLine.length(); pos++) {
      if (
         inputLine[pos] == inputLine[pos - 1] ||
         inputLine[pos] == inputLine[pos - 2] ||
         inputLine[pos] == inputLine[pos - 3] ||
         inputLine[pos - 1] == inputLine[pos - 2] ||
         inputLine[pos - 1] == inputLine[pos - 3] ||
         inputLine[pos - 2] == inputLine[pos - 3]
      ) { continue; } else { break; }
   }

   inputFile.close();

   cout << "Position: " << ++pos << endl;
}
