//
// Created by Parth Parakh on 20/12/20.
//

#include "PayoffForward.h"
double PayOffForward::operator()(double Spot) const
{
    return Spot-Strike;
}

PayOffForward::PayOffForward(double Strike_) : Strike(Strike_){}

PayOff* PayOffForward::clone() const
{
    return new PayOffForward(*this);
}