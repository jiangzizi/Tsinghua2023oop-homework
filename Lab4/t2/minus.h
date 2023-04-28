#pragma once
#include "operation.h"

class MinusNode: public OperationNodeTwo{
public:
    // using OperationNodeTwo::OperationNodeTwo;
    MinusNode(string name, Node *x1, Node *x2) :OperationNodeTwo(name,x1,x2)//: Node(name), input1(x1), input2(x2)
    {

    }
    void calc() override;
    void UpdateValue() override;
    ~MinusNode(){};
};