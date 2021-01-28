//
// Created by Parth Parakh on 20/12/20.
//

#include"TreeEuropean.h"
#include<algorithm>

//TreeEuropean::TreeEuropean(double FinalTime,const PayOffBridge& ThePayOff_): TreeProduct(FinalTime),ThePayOff(ThePayOff_){}

TreeEuropean::TreeEuropean(double FinalTime, const Bridge<PayOff> &Py): TreeProduct(FinalTime),py(Py) {}

double TreeEuropean::FinalPayOff(double Spot) const
{
    //return ThePayOff(Spot);
    return py.operator()(Spot);
}
double TreeEuropean::PreFinalValue(double,double,double DiscountedFutureValue) const
{
    return DiscountedFutureValue;
}
TreeProduct* TreeEuropean::clone() const
{
    return new TreeEuropean(*this);
}

