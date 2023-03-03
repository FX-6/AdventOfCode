#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   getline(inputFile, inputLine);
   int pos;
   string part;
   bool noDoubleFound = true;

   for (pos = 13; pos < inputLine.length(); pos++) {
      part = inputLine.substr(pos - 13, 14);

      for (int i = 0; i < part.length() - 1; i++) {
         if (part.find(part[i], i + 1) != string::npos) { noDoubleFound = false; }
      }

      if (noDoubleFound) { break; } else { noDoubleFound = true; }
   }

   inputFile.close();

   cout << "Position: " << ++pos << endl;
}
