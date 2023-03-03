#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;
using ull = unsigned long long;

class File {
  private:
   string _name;
   ull _size;

  public:
   File(ull size, string name) : _name(name), _size(size) {}

   string name() { return _name; }
};

struct Folder {
  private:
   string _name;
   Folder *_parent;
   ull _size = 0;

  public:
   list<Folder*> _folders;
   list<File*> _files;

   Folder(string name) : _name(name), _parent(nullptr) {}

   Folder(string name, Folder *parent) : _name(name), _parent(parent) {}

   void folder(string name) {
      this->_folders.push_back(new Folder(name, this));
   }

   void file(string size, string name) {
      ull fileSize = stoull(size);

      _files.push_back(new File(fileSize, name));

      this->size(fileSize);
   }

   void size(ull sizeToAdd) {
      _size += sizeToAdd;
      if (_parent != nullptr) { _parent->size(sizeToAdd); }
   }

   Folder* parent() { return _parent; }

   string name() { return _name; }

   ull size() { return _size; }
};

int main() {
   ifstream inputFile("input.txt");
   string inputLine;

   Folder *rootFolder = new Folder("/");
   Folder *currentFolder = rootFolder;
   string currentArg;

   getline(inputFile, inputLine);

   while (getline(inputFile, inputLine)) {
      if (inputLine.substr(0, 4) == "$ cd") {
         currentArg = inputLine.substr(5);

         if (currentArg == "..") {
            currentFolder = currentFolder->parent();
         } else if (currentArg == "/") {
            currentFolder = rootFolder;
         } else {
            for (Folder *child : currentFolder->_folders) {
               if (child->name() == currentArg) {
                  currentFolder = child;
                  break;
               }
            }
         }
      } else if (inputLine.substr(0, 3) == "dir") {
         currentFolder->folder(inputLine.substr(4));
      } else if (inputLine.substr(0, 1) != "$") {
         currentFolder->file(inputLine.substr(0, inputLine.find(" ")), inputLine.substr(inputLine.find(" ")));
      }
   }

   inputFile.close();

   ull spaceToFree = rootFolder->size() - 40000000;
   Folder *folderToDelete = rootFolder;
   list<Folder*> fifo;

   fifo.push_back(rootFolder);

   while (!fifo.empty()) {
      currentFolder = fifo.front();
      fifo.pop_front();

      if (currentFolder->size() >= spaceToFree && currentFolder->size() < folderToDelete->size()) {
         folderToDelete = currentFolder;
      }

      for (Folder *child : currentFolder->_folders) {
         fifo.push_back(child);
      }
   }

   cout << "Size of directory to delete: " << folderToDelete->size();
}
