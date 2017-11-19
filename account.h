
#include <vector>
#include <string>

class account
{
	//Private member variables
private:
	int balance;
	std::vector<transaction> log;

public:
	account();
	std::vector<std::string> report();
	bool deposit(int amt);
	bool withdraw(int amt);

	//Inline functions
	int getBalance() { return balance; }
};