#ifndef NODE_H
#define NODE_H

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>

namespace SHRAAR001{}

class HuffmanNode{
    private:
        std::shared_ptr<HuffmanNode> left, right = nullptr;
        char value;
        int fx;

    public:
        HuffmanNode();
        HuffmanNode(char&, int&);
        HuffmanNode(const HuffmanNode & rhs);
        HuffmanNode& operator=(const HuffmanNode& rhs);
        HuffmanNode(HuffmanNode && rhs);
        HuffmanNode& operator=(HuffmanNode && rhs);
        ~HuffmanNode();
        char getValue() const;
        int getFx() const;
        void setValue(char c);
        void setFx(int f);
        std::shared_ptr<HuffmanNode> getLeft() const;
        std::shared_ptr<HuffmanNode> getRight() const;
        void setLeft(const std::shared_ptr<HuffmanNode> l);
        void setRight(const std::shared_ptr<HuffmanNode> r);
        friend bool operator<(const HuffmanNode &lhs, const HuffmanNode &rhs);
        friend bool operator>(const HuffmanNode &lhs, const HuffmanNode &rhs);
};

#endif