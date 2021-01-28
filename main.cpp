
#include"BinomialTree.h"
#include"TreeAmerican.h"
#include"TreeEuropean.h"
#include<iostream>
#include"PayoffForward.h"
#include<cmath>
#include"PayOffBridge.h"
#include"BridgePattern_templatize.h"

using namespace std;

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nd\n";
    cin >> d;
    cout << "\nNumber of steps\n";
    cin >> Steps;

    PayOffCall thePayOff(Strike);
    Bridge<PayOffCall> bridgepayoff(thePayOff);
    PayOffBridge POB(thePayOff);
    // can either use this. if we use this. implicit conversion from ParamConst to Parameter while passing to tree
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    //or can use this. if we use this we are passing the pointer of param const to param and explicitly converting to param which
    // is then passed to tree.
    ParametersInner * ptr_r = new ParametersConstant(r);
    ParametersInner * ptr_d = new ParametersConstant(d);

    Parameters rParam_C(*ptr_r);
    Parameters dParam_C(*ptr_d);

    TreeEuropean europeanOption(Expiry,thePayOff);
    TreeAmerican americanOption(Expiry,thePayOff);
    SimpleBinomialTree theTree(Spot,rParam_C,dParam,Vol,Steps,Expiry);
    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    cout << "euro price" << euroPrice << "amer price" << americanPrice << "\n";

    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry,forwardPayOff);
    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree" << forwardPrice << "\n";
    double actualForwardPrice =exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);
    cout << "forward price" << actualForwardPrice << "\n";

    Steps++;
    SimpleBinomialTree theNewTree(Spot,rParam,dParam,Vol,Steps,Expiry);
    double euroNewPrice =theNewTree.GetThePrice(europeanOption);
    double americanNewPrice =theNewTree.GetThePrice(americanOption);
    cout << "euro new price" << euroNewPrice<< "amer new price" << americanNewPrice << "\n";
    double forwardNewPrice = theNewTree.GetThePrice(forward);
    cout << "forward price by new tree" << forwardNewPrice<< "\n";
    double averageEuro = 0.5*(euroPrice+euroNewPrice);
    double averageAmer = 0.5*(americanPrice+americanNewPrice);
    double averageForward = 0.5*(forwardPrice+forwardNewPrice);
    cout << "euro av price" << averageEuro << "amer av price"<< averageAmer << "\n";
    cout << "av forward" << averageForward << "\n";
    double tmp;
    cin >> tmp;
    return 0;
}

