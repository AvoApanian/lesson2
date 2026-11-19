#include <iostream>
#include "Bank.hpp"

Bank::Bank(std::string id){
	userId = id;

	int a;

	for (int i = 0;i < moneyTypeSize;i++){
		a = moneyType[i] * moneySize[i];
		bankMoney += a;
	}
}

void Bank::addMoney(int money){
	if (money <= 0){
		std::cout<<"invalid amount"<<std::endl;
		return;
	}

	userMoney += money;

	std::cout<<"money added"<<std::endl;
	std::cout<<"current balance: "<<userMoney<<std::endl;
}

void Bank::withdrawMoney(int money){
	if (money <= 0){
		std::cout<<"invalid amount"<<std::endl;
		return;
	}

	if (money > userMoney){
		std::cout<<"not enough money in your account"<<std::endl;
		return;
	}

	if (money > bankMoney){
		std::cout<<"not enough money in atm"<<std::endl;
		return;
	}

	int remainingMoney = money;
	int tempMoneySize[moneyTypeSize];

	for (int i = 0;i < moneyTypeSize;i++){
		tempMoneySize[i] = moneySize[i];
	}

	int bills[moneyTypeSize]{0};

	for (int i = moneyTypeSize - 1;i >= 0;i--){
		while (remainingMoney >= moneyType[i] && tempMoneySize[i] > 0){
			remainingMoney -= moneyType[i];
			tempMoneySize[i]--;
			bills[i]++;
		}
	}

	if (remainingMoney != 0){
		std::cout<<"atm cant give this amount"<<std::endl;
		return;
	}

	userMoney -= money;
	bankMoney -= money;

	for (int i = 0;i < moneyTypeSize;i++){
		moneySize[i] = tempMoneySize[i];
	}

	std::cout<<"here is your money"<<std::endl;

	for (int i = moneyTypeSize - 1;i >= 0;i--){
		if (bills[i] > 0){
			std::cout<<moneyType[i]<<" x "<<bills[i]<<std::endl;
		}
	}

	std::cout<<"final amount: "<<money<<std::endl;
	std::cout<<"remaining balance: "<<userMoney<<std::endl;
}

void Bank::showAccount(){
	std::cout<<"user id: "<<userId<<std::endl;
	std::cout<<"account balance: "<<userMoney<<std::endl;
	std::cout<<"atm money: "<<bankMoney<<std::endl;
}
