//
// Created by Parth Parakh on 28/01/21.
//

#ifndef BINARYTREE_OPTIONS_BRIDGEPATTERN_TEMPLATIZE_H
#define BINARYTREE_OPTIONS_BRIDGEPATTERN_TEMPLATIZE_H

#include"PayOff.h"

template<class inner>
class Bridge
{
public:
    Bridge(const Bridge& original);
    Bridge(const inner& innerP);
    double operator()(double Spot) const;
    ~Bridge();
    Bridge& operator=(const Bridge& original);
private:
    inner* Ptr;
};


// specialised version of the bridge for payoff
template<>
class Bridge<class PayOff>
{
private:
    PayOff * ThePayOffPtr;
public:
    Bridge(const Bridge &original)
    {
        ThePayOffPtr = original.ThePayOffPtr->clone();
    }
    Bridge(const PayOff &innerPayoff)
    {
        ThePayOffPtr = innerPayoff.clone();
    }
    double operator()(double Spot) const
    {
        return (*ThePayOffPtr)(Spot);
    }
    ~Bridge()
    {
        delete ThePayOffPtr;
    }
    Bridge& operator=(const Bridge& original)
    {
        if (this != &original)
        {
            delete ThePayOffPtr;
            ThePayOffPtr = original.ThePayOffPtr->clone();
        }
        return *this;
    }
};


#endif //BINARYTREE_OPTIONS_BRIDGEPATTERN_TEMPLATIZE_H
