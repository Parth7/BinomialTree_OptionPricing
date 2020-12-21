//
// Created by Parth Parakh on 20/12/20.
//

#ifndef BINARYTREE_OPTIONS_TREEEUROPEAN_H
#define BINARYTREE_OPTIONS_TREEEUROPEAN_H

#include "TreeProduct.h"
#include "PayOffBridge.h"
class TreeEuropean : public TreeProduct
{
public:
    TreeEuropean(double FinalTime,const PayOffBridge& ThePayOff_);
    virtual TreeProduct* clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot,double Time,double DiscountedFutureValue)const;
    virtual ~TreeEuropean(){}
private:
    PayOffBridge ThePayOff;
};

#endif //BINARYTREE_OPTIONS_TREEEUROPEAN_H
