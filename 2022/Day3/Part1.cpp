#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   int priorities = 0;

   while (getline(inputFile, inputLine)) {
      string firstPart = inputLine.substr(0, inputLine.length() / 2);
      string secondPart = inputLine.substr(inputLine.length() / 2);

      for (char const &ele : firstPart) {
         if (secondPart.find(ele) != string::npos) {
            priorities += ((ele - '`') > 0 ? (ele - '`') : (ele - '`' + 58));
            break;
         }
      }
   }

   inputFile.close();

   cout << "Priorities: " << priorities << endl;
}
