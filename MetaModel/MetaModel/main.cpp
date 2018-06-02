#include <iostream>

#include "FuzzyFactory.h"
#include "ValueModel.h"
#include "NotMinus1.h"
#include "And.h"
#include "AndMin.h"
#include "OrMax.h"
#include "ThenMin.h"
#include "CogDefuzz.h"
#include "IsTriangle.h"
#include "AggMax.h"

int main()
{
    NotMinus1<int> opNot;
    AndMin<int> opAnd;
    OrMax<int> opOr;
    ThenMin<int> opThen;
    CogDefuzz<int> opDefuzz;
    //fuzzy expession factory
    FuzzyFactory<int> f(&opNot, &opAnd, &opOr, &opThen, &opOr, &opDefuzz);
    //membership function
    IsTriangle<int> poor(-5, 0, 5);
    IsTriangle<int> good(0, 5, 10);
    IsTriangle<int> excellent(5, 10, 15);
    IsTriangle<int> cheap(0, 5, 10);
    IsTriangle<int> average(10, 15, 20);
    IsTriangle<int> generous(20, 25, 30);
    //values
    ValueModel<int> service(0);
    ValueModel<int> food(0);
    ValueModel<int> tips(0);
    Expression *r = f.newAgg(
        f.newAgg(
            f.newThen(
                f.newIs(&service, &poor),
                f.newIs(&tips, &cheap)),
            f.newThen(
                f.newIs(&service, &good),
                f.newIs(&tips, &average))),
        f.newThen(
            f.newIs(&service, &excellent),
            f.newIs(&tips, &generous)));
    //defuzzification
    Expression* system = f.newDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float s;
    while (true)
    {
        std::cout << "service : ";
        std::cin >> s;
        service.setValue(s);
        std::cout << "tips -> " << system->Evaluate() << std::endl;
    }
}