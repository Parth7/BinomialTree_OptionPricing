//
// Created by Parth Parakh on 20/12/20.
//

#ifndef BINARYTREE_OPTIONS_PAYOFFFORWARD_H
#define BINARYTREE_OPTIONS_PAYOFFFORWARD_H

#include"PayOff.h"
class PayOffForward : public PayOff
{
public:
    PayOffForward(double Strike_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffForward(){}
    virtual PayOff* clone() const;
private:
    double Strike;
};

#endif //BINARYTREE_OPTIONS_PAYOFFFORWARD_H
