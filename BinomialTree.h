//
// Created by Parth Parakh on 20/12/20.
//

#ifndef BINARYTREE_OPTIONS_BINOMIALTREE_H
#define BINARYTREE_OPTIONS_BINOMIALTREE_H

#include"TreeProduct.h"
#include<vector>
#include"arrays.h"
#include"parameters.h"

using namespace std;

class SimpleBinomialTree
{
public:
    SimpleBinomialTree(double Spot_,const Parameters& r_,const Parameters& d_,double Volatility_,unsigned long Steps,double Time);
    double GetThePrice(const TreeProduct& TheProduct);
protected:
    void BuildTree();
private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;
    vector<vector<std::pair<double, double> > >TheTree;
    MJArray Discounts;
};

#endif //BINARYTREE_OPTIONS_BINOMIALTREE_H