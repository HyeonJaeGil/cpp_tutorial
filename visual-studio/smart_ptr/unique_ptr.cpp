#include <iostream>
#include <memory>
#include "Investment.h"

auto deleteInv = [](Investment* pInvestment) {delete pInvestment; };

template<typename... Ts>
std::unique_ptr<Investment> makeInvestment(Ts&&... param) {
	std::unique_ptr<Investment> pInv(nullptr);

	if (/* a Stock object should be created */)
		pInv.reset(new Stock(std::forward<Ts>(params)...));

	else if ( /* a Bond object should be created */)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if ( /* a RealEstate object should be created */)
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}
}

template<typename... Ts>
std::unique_ptr<Investment, decltype(deleteInv)> makeInvestmentCustomDelete(Ts&&... param) {
	std::unique_ptr<Investment, decltype(deleteInv)> pInv(nullptr, deleteInv);

	if (/* a Stock object should be created */)
		pInv.reset(new Stock(std::forward<Ts>(params)...));

	else if ( /* a Bond object should be created */)
	{
		pInv.reset(new Bond(std::forward<Ts>(params)...));
	}
	else if ( /* a RealEstate object should be created */)
	{
		pInv.reset(new RealEstate(std::forward<Ts>(params)...));
	}

}


