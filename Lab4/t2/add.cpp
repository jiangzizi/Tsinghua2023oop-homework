#include"add.h"
void AddNode::calc()
{
    OperationNodeTwo::calc();
}
void AddNode::UpdateValue()
{
    value_=input1->value()+input2->value();
}