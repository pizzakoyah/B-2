#include <iostream>
#include <vector>
#include <string>
#include "transaction.h"

using namespace std;

transaction::transaction(int amt, string type) :amt(amt), type(type)
{
}

string transaction::report()
{
	string report;
	report += "  ";
	report += type;
	report += " ";
	report += to_string(amt);
	return report;
}
