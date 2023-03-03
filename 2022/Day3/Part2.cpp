#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ifstream inputFile("input.txt");
   string lineOne, lineTwo, lineThree;
   int priorities = 0;

   while (getline(inputFile, lineOne)) {
      getline(inputFile, lineTwo);
      getline(inputFile, lineThree);

      for (char const &ele : lineOne) {
         if (lineTwo.find(ele) != string::npos && lineThree.find(ele) != string::npos) {
            priorities += ((ele - '`') > 0 ? (ele - '`') : (ele - '`' + 58));
            break;
         }
      }
   }

   inputFile.close();

   cout << "Priorities: " << priorities << endl;
}
