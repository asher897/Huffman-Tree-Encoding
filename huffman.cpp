#include "huffman.h"
#include "node.h"

using namespace SHRAAR001;
HuffmanTree::HuffmanTree(std::shared_ptr<HuffmanNode> r){
    root = r;
}

HuffmanTree::HuffmanTree(){};



//Move Constructor
HuffmanTree::HuffmanTree(HuffmanTree && rhs)
{
    this -> root = std::move(rhs.root);
    this -> pq = std::move(rhs.pq);
    this -> table = std::move(rhs.table); 
}

//Move Assignment Operator
HuffmanTree& HuffmanTree::operator=(HuffmanTree && rhs){
    if(this != &rhs){
        this -> root = std::move(rhs.root);
        this -> pq = std::move(rhs.pq);
        this -> table = std::move(rhs.table);
    }
    return *this;
}

//Copy Constructor
HuffmanTree::HuffmanTree(const HuffmanTree && rhs){
    this->root = rhs.root;
    this->pq = rhs.pq;
    this->table = rhs.table;
}

//Copy Assignment Operator
HuffmanTree& HuffmanTree::operator=(const HuffmanTree& rhs){
    if(this != &rhs){
        this->root = rhs.root;
        this->pq = rhs.pq;
        this->table = rhs.table;

    }
    return *this;
}


HuffmanTree::~HuffmanTree(){
    root = nullptr;
}

void HuffmanTree::readFile(std::string fileName){
     
     //Read in file
     std::ifstream input(fileName + ".txt");
     char letter;
     //std::unordered_map<char, int> map;
     int search;

     //Create Unordered Map (Hash Map)
     while(input.get(letter)){
        map[letter] += 1;
     }
     input.close();


    //Create min heap from the unordered map
     for(std::pair<char, int> element : map){
         pq.push(HuffmanNode(element.first, element.second));
     }

}

    //Create Huffman Tree

    void HuffmanTree::constructTree(){
    //Create Internal node
     HuffmanNode temp = HuffmanNode();
     while(pq.size() != 1){
         //Get top node from pq
         temp.setLeft(std::make_shared<HuffmanNode>(pq.top()));
         pq.pop();
         //Get next node
         temp.HuffmanNode::setRight(std::make_shared<HuffmanNode>(pq.top()));
         pq.pop();
         //Set fx of new node equal to sum of its two children nodes
         temp.setFx(temp.getLeft() -> getFx() + temp.getRight() -> getFx());
         //Insert new node into pq
         pq.push(temp);

     }
     root = std::make_shared<HuffmanNode>(pq.top());
    }

//Recursive function to build the freq table
void HuffmanTree::freqTable(std::string bits, std::shared_ptr<HuffmanNode> node){
    if(node.get() -> getLeft().get() != nullptr){
        freqTable(bits + "0", node.get() -> getLeft());
    }
    if(node.get() -> getRight().get() != nullptr){
        freqTable(bits + "1", node.get() -> getRight());
    }
    if((node.get() -> getRight().get() == nullptr) && (node.get() -> getLeft().get() == nullptr)){
        table[node -> getValue()] = bits;
    }
 }


std::string HuffmanTree::find(char c){
    return table[c];
}

void HuffmanTree::encodeFile(std::string &inputFile, std::string &output_file){
    char c;                                                 //declare c
    std::string buffer = "";                                //Declare string buffer
    std::ifstream input(inputFile + ".txt");                //Open ASCII text file
    input >> std::noskipws;

    //Convert letter to bits and create buffer
    while(input.get(c)){
        buffer += table[c];
    }
    input.close();

    //Write buffer to output file
    //const char *byte_str = buffer.c_str();           //Convert to c_str()
    std::ofstream output(output_file + ".txt");
    for(char c : buffer){
        output << c;
    }
    output.close();

    //Create header file
    std::ofstream hdr(output_file + "hdr" + ".txt");
    hdr << table.size() << std::endl;
    for(std::pair<char, std::string> element : table){
        hdr << element.first << " " << element.second << std::endl;
    }
}



std::shared_ptr<HuffmanNode> HuffmanTree::getRoot(){
    return root;
}

std::priority_queue<HuffmanNode> HuffmanTree::getHeap(){
    return pq;
}

std::unordered_map<char, std::string> HuffmanTree::getTable(){
    return table;
}

void HuffmanTree::setRoot(std::shared_ptr<HuffmanNode> r){
    root = r;
}
void HuffmanTree::emptyHeap(){
    while(!pq.empty()){
        pq.pop();
    }
}
void HuffmanTree::clearTable(){
    table.clear();
}

std::unordered_map<char, int> HuffmanTree::getMap(){
    return map;
}

