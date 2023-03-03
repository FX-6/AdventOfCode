#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct crateStack {
   struct crate {
      char _value;
      crate *_next;

      crate(char value, crate *next) : _value(value), _next(next) {}
   };

   crate *head = nullptr;
   int length = 0;

   crateStack() {}

   char pop() {
      char returnVal = head->_value;
      head = head->_next;
      length--;
      return returnVal;
   }

   char pop(int index) {
      crate *prev = nullptr;
      crate *target = head;

      for (int i = 0; i < (index - 1); i++) {
         prev = target;
         target = target->_next;
      }

      char returnVal = target->_value;
      if (prev != nullptr) {
         prev->_next = target->_next;
      } else {
         head = target->_next;
      }
      length--;
      return returnVal;
   }

   void push(char value) {
      crate *next = head;
      head = new crate(value, next);
      length++;
   }
};

int main() {
   ifstream inputFile("input.txt");
   string inputLine;
   crateStack stacks[9];
   string lines[8];

   for (int i = 0; i < 8; i++) {
      getline(inputFile, lines[i]);
   }

   for (int i = 7; i >= 0; i--) {
      for (int j = 0; j < 9; j++) {
         if (lines[i][1 + 4 * j] != ' ') { stacks[j].push(lines[i][1 + 4 * j]); }
      }
   }

   while (getline(inputFile, inputLine)) {
      if (inputLine.find("move") == -1) { continue; }

      int amount = stoi(inputLine.substr(inputLine.find("move") + 5, inputLine.find(" ")));
      int from = stoi(inputLine.substr(inputLine.find("from") + 5, inputLine.find(" ", inputLine.find("from") + 5))) - 1;
      int to = stoi(inputLine.substr(inputLine.find("to") + 3, inputLine.find(" ", inputLine.find("to") + 3))) - 1;

      for (int i = 0; i < amount; i++) {
         if (stacks[from].length >= (amount - i)) { stacks[to].push(stacks[from].pop(amount - i)); }
      }
   }

   inputFile.close();

   for (int i = 0; i < 9; i++) {
      if (stacks[i].length > 0) { cout << stacks[i].pop(); }
   }

   cout << endl;
}
