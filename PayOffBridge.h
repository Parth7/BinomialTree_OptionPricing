//
// Created by Parth Parakh on 20/12/20.
//

#ifndef BINARYTREE_OPTIONS_PAYOFFBRIDGE_H
#define BINARYTREE_OPTIONS_PAYOFFBRIDGE_H

#include"PayOff.h"

class PayOffBridge
{
public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);
    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);
private:
    PayOff* ThePayOffPtr;
};
inline double PayOffBridge::operator()(double Spot) const
{
    return ThePayOffPtr->operator()(Spot);
}



#endif //BINARYTREE_OPTIONS_PAYOFFBRIDGE_H
