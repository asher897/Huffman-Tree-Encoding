#include "huffman.h"
#include "node.h"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace SHRAAR001;
 
 int main(int argc, char* argv[]){
    HuffmanTree *huff = new HuffmanTree();

     //Read in file
     std::string fileName(argv[1]);
     huff -> readFile(fileName);

     //Construct Tree
     huff ->constructTree();

     //Build frequency table
     std::string bits = "";
     huff -> freqTable(bits, huff -> getRoot());

     //Output
     std::string output(argv[2]);
     huff -> encodeFile(fileName, output);

     return 0;
 }