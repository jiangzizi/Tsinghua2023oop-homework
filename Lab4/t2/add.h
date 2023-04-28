/*#pragma once
#include "operation.h"
class AddNode :public OperationNodeTwo
{
    public:
        //using OperationNodeTwo::OperationNodeTwo;
        //using OperationNodeTwo::OperationNodeTwo;
        virtual void calc() override;
        void Updatevalue(); 

        virtual ~AddNode() ;


};*/

#pragma once

#include "operation.h"

class AddNode: public OperationNodeTwo{
public:
   // using OperationNodeTwo::OperationNodeTwo;
    AddNode(string name, Node *x1, Node *x2) :OperationNodeTwo(name,x1,x2)//: Node(name), input1(x1), input2(x2)
    {

    }
    void calc() override;
    void UpdateValue() override;
    ~AddNode(){};
};