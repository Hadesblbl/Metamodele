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
	SugenoThen<float> opSThen;
    CogDefuzz<float> opDefuzz(0, 25, 1);
	SugenoConclusion<float> conclusionCheap(std::vector<float>({ 1,2,3 }));
	SugenoConclusion<float> conclusionGenerous(std::vector<float>({ 2,1,3 }));
	SugenoDefuzz<float> opSugDefuzz(std::vector<SugenoConclusion<float>*>({ &conclusionCheap,&conclusionGenerous }));
    //fuzzy expession factory
	FuzzyFactory<float> f(&opNot, &opAnd, &opOr, &opThen, &opAgg, &opDefuzz, &opSugDefuzz);
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
	Expression<float> *expl =
		f.newThen(
			f.newOr(
				f.newIs(&service, &poor),
				f.newIs(&food, &poor)
			),
			f.newValue(conclusionCheap.evaluate(std::vector<Expression<float>*>({ &food,&service })))
		);
	Expression<float> *expr =
		f.newThen(
			f.newOr(
				f.newIs(&service, &excellent),
				f.newIs(&food, &excellent)
			),
			f.newValue(conclusionCheap.evaluate(std::vector<Expression<float>*>({ &food,&service })))
		);
	//defuzzification
	Expression<float>* system = f.newDefuzz(&tips, r, 0, 25, 1);
    //apply input
    float s;
    while (true)
    {
		std::cout << "methode (mamdani : 1 , sugeno : 2) : "; std::cin >> s;
		if (s == 1) {
			//defuzzification
			Expression<float> *system = f.newDefuzz(&tips, r, 0, 25, 1);
			f.changeThen(&opThen);
			std::cout << "service : "; std::cin >> s;
			service.setValue(s);
			std::cout << "food : "; std::cin >> s;
			food.setValue(s);
			std::cout << "tips -> " << system->evaluate() << std::endl;
		}
		else {
			//defuzzification
			Expression<float> *system = f.newSugeno(std::vector<Expression<float>*>({ &food,&service,expl,expr }));
			f.changeThen(&opSThen); 
			for (int i = 0; i < 11; i++) {
				for (int j = 0; j < 11; j++) {
					service.setValue(i);
					std::cout << "Service -> " << service.evaluate() << std::endl;
					food.setValue(j);
					std::cout << "Food -> " << food.evaluate() << std::endl;
					std::cout << "Tips -> " << system->evaluate() << std::endl;
				}
			}
		}
    }
	return 0;
}
