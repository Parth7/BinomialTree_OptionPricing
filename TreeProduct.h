//
// Created by Parth Parakh on 20/12/20.
//
#ifndef BINARYTREE_OPTIONS_TREEPRODUCT_H
#define BINARYTREE_OPTIONS_TREEPRODUCT_H

class TreeProduct
{
public:
    TreeProduct(double FinalTime_);
    virtual double FinalPayOff(double Spot) const=0;
    virtual double PreFinalValue(double Spot,double Time,double DiscountedFutureValue)const=0;
    virtual ~TreeProduct(){}
    virtual TreeProduct* clone() const=0;
    double GetFinalTime() const;
private:
    double FinalTime;
};

#endif //BINARYTREE_OPTIONS_TREEPRODUCT_H
