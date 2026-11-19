
#include <iostream>
#include "Bank.hpp"

int main(){

	std::string userId;
	int choice;
	int money;

	std::cout<<"enter user id: ";
	std::cin>>userId;

	Bank user(userId);

	while (true){

		std::cout<<"\n1. add money"<<std::endl;
		std::cout<<"2. withdraw money"<<std::endl;
		std::cout<<"3. show account"<<std::endl;
		std::cout<<"4. exit"<<std::endl;

		std::cout<<"choose: ";
		std::cin>>choice;

		switch(choice){

			case 1:
				std::cout<<"enter amount: ";
				std::cin>>money;

				user.addMoney(money);
				break;

			case 2:
				std::cout<<"enter amount: ";
				std::cin>>money;

				user.withdrawMoney(money);
				break;

			case 3:
				user.showAccount();
				break;

			case 4:
				return 0;

			default:
				std::cout<<"wrong choice"<<std::endl;
		}
	}

	return 0;
}
