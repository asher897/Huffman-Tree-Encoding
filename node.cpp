#include "node.h"

using namespace SHRAAR001;

//Constructors

//Constructor with parameters
HuffmanNode::HuffmanNode(char &val, int &f){
    value = val;
    fx = f;
}

//Default constructor
HuffmanNode::HuffmanNode() : left(nullptr), right(nullptr), value('\0'), fx(0){};


//Destructor
HuffmanNode::~HuffmanNode(){
    left = nullptr;
    right = nullptr;
}


//Move constructor
HuffmanNode::HuffmanNode(HuffmanNode && rhs) {
    this -> left = std::move(rhs.left);
    this -> right = std::move(rhs.right);
    this -> value = std::move(rhs.value);
    this -> fx = std::move(rhs.fx);
    }

//Move Assignment Operator
HuffmanNode& HuffmanNode::operator=(HuffmanNode && rhs){
    if(this != &rhs){
        this -> left = std::move(rhs.left);
        this -> right = std::move(rhs.right);
        this -> value = std::move(rhs.value);
        this -> fx = std::move(rhs.fx);
    }
    return *this;

}


//Copy Constructor
HuffmanNode::HuffmanNode(const HuffmanNode & rhs){
    this->left = rhs.left;
    this->right = rhs.right;
    this->value = rhs.value;
    this->fx = rhs.fx;
}


//Copy Assignment Operator
HuffmanNode& HuffmanNode::operator=(const HuffmanNode& rhs){
    if(this != &rhs){
        this->left = rhs.left;
        this->right = rhs.right;
        this->value = rhs.value;
        this->fx = rhs.fx;

    }
    return *this;
}


char HuffmanNode::getValue() const{
    return value;
}

int HuffmanNode::getFx() const{
    return fx;
}
void HuffmanNode::setValue(char c) {
    value = c;
}

std::shared_ptr<HuffmanNode> HuffmanNode::getLeft() const{
    return left;
}
std::shared_ptr<HuffmanNode> HuffmanNode::getRight() const{
    return right;
}

void HuffmanNode::setLeft(const std::shared_ptr<HuffmanNode> l){
    left = l;
}
void HuffmanNode::setRight(const std::shared_ptr<HuffmanNode> r){
    right = r;
}


void HuffmanNode::setFx(int f){
    fx = f;
}



bool operator<(const HuffmanNode &lhs, const HuffmanNode &rhs){
    return !(lhs.getFx() < rhs.getFx());
}

bool operator>(const HuffmanNode &lhs, const HuffmanNode &rhs){
    return !(lhs.getFx() > rhs.getFx());
}