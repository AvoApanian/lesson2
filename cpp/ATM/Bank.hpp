#ifndef BANK_HPP
#define BANK_HPP
#include <string>

class Bank{
	private:
		int bankMoney = 0;
		int userMoney = 0;
		static constexpr int moneyTypeSize = 4;
		int moneyType[moneyTypeSize]{1000,5000,10000,20000};
		int moneySize[moneyTypeSize]{100,50,25,75};
		std::string userId;

	public:
		Bank(std::string id);

		void addMoney(int money);
		void withdrawMoney(int money);
		void showAccount();
};

#endif
