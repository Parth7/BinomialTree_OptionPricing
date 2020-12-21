
#include"BinomialTree.h"
#include"TreeAmerican.h"
#include"TreeEuropean.h"
#include<iostream>
#include"PayoffForward.h"
#include<cmath>

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
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);
    TreeEuropean europeanOption(Expiry,thePayOff);
    TreeAmerican americanOption(Expiry,thePayOff);
    SimpleBinomialTree theTree(Spot,rParam,dParam,Vol,Steps,Expiry);
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

