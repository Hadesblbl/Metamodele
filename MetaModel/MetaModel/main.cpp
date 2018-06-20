#include <iostream>

#include "ValueModel.h"
#include "AndMin.h"
#include "AndMult.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "AggMax.h"
#include "CogDefuzz.h"
#include "IsTriangle.h"
#include "NotMinus1.h"
#include "ThenMin.h"
#include "SugenoThen.h"
#include "SugenoConclusion.h"
#include "SugenoDefuzz.h"
#include "FuzzyFactory.h"
#include <iostream>

using namespace fuzzy;
using namespace core;

int main()
{
    NotMinus1<float> opNot;
    AndMin<float> opAnd;
    OrMax<float> opOr;
	AggMax<float> opAgg;
    ThenMin<float> opThen;
    CogDefuzz<float> opDefuzz;
    //fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz);
    //membership function
    IsTriangle<float> poor(-5, 0, 5);
    IsTriangle<float> good(0, 5, 10);
    IsTriangle<float> excellent(5, 10, 15);
    IsTriangle<float> cheap(0, 5, 10);
    IsTriangle<float> average(10, 15, 20);
    IsTriangle<float> generous(20, 25, 30);
    //values
	ValueModel<float> service(0);
    ValueModel<float> food(0);
    ValueModel<float> tips(0);
    Expression<float>* r = f.newAgg(
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
    Expression<float>* system = f.newDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float s;
    while (true)
    {
        std::cout << "service : ";
        std::cin >> s;
        service.setValue(s);
        std::cout << "tips -> " << system->evaluate() << std::endl;
    }
}
