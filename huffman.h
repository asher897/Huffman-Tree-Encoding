#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <memory>
#include <unordered_map>
#include <cstring>
#include <bitset>
#include "node.h"

namespace SHRAAR001{}

class HuffmanTree{
    private:
        std::shared_ptr<HuffmanNode> root = nullptr;
        std::priority_queue<HuffmanNode> pq;
        std::unordered_map<char, std::string> table;
        std::unordered_map<char, int> map;

    public:
    HuffmanTree(std::shared_ptr<HuffmanNode> r);
    HuffmanTree();
    HuffmanTree(HuffmanTree && rhs);
    HuffmanTree& operator=(HuffmanTree && rhs);
    HuffmanTree(const HuffmanTree && rhs);
    HuffmanTree& operator=(const HuffmanTree& rhs);
    ~HuffmanTree();
    void readFile(std::string fileName);
    void constructTree();
    void freqTable(std::string bits, std::shared_ptr<HuffmanNode> node);
    std::shared_ptr<HuffmanNode> getRoot();
    std::priority_queue<HuffmanNode> getHeap();
    std::unordered_map<char, std::string> getTable();
    std::unordered_map<char, int> getMap();
    void setRoot(std::shared_ptr<HuffmanNode> r);
    void emptyHeap();
    void clearTable();
    std::string find(char c);
    void encodeFile(std::string &inputFile, std::string &output_file);


};

#endif

