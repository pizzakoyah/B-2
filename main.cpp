#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "account.h"

using namespace std;

int main()
{
	account a1;
	if (a1.deposit(100))
	{
		cout << "Balance after depositing: " << a1.getBalance() << endl;
		for (auto s : a1.report())
		{
			cout << s << endl;
		}
	}
	if (a1.withdraw(90))
	{
		cout << "Balance after withdrawing: " << a1.getBalance() << endl;
		for (auto s : a1.report())
		{
			cout << s << endl;
		}
	}
	return 0;
}