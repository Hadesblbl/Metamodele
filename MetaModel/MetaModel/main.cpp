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
    NotMinus1 opNot;
    AndMin opAnd;
    OrMax opOr;
    ThenMin opThen;
    CogDefuzz opDefuzz;
    //fuzzy expession factory
    FuzzyFactory f(&opNot, &opAnd, &opOr, &opThen, &opOr, &opDefuzz);
    //membership function
    IsTriangle poor(-5, 0, 5);
    IsTriangle good(0, 5, 10);
    IsTriangle excellent(5, 10, 15);
    IsTriangle cheap(0, 5, 10);
    IsTriangle average(10, 15, 20);
    IsTriangle generous(20, 25, 30);
    //values
    ValueModel service(0);
    ValueModel food(0);
    ValueModel tips(0);
    Expression *r = f.NewAgg(
        f.NewAgg(
            f.NewThen(
                f.NewIs(&service, &poor),
                f.NewIs(&tips, &cheap)),
            f.NewThen(
                f.NewIs(&service, &good),
                f.NewIs(&tips, &average))),
        f.NewThen(
            f.NewIs(&service, &excellent),
            f.NewIs(&tips, &generous)));
    //defuzzification
    Expression *system = f.NewDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float s;
    while (true)
    {
        cout << "service : ";
        cin >> s;
        service.SetValue(s);
        cout << "tips -> " << system->Evaluate() << endl;
    }
}