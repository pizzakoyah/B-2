
#include <vector>
#include <string>

class transaction
{
private:
	int amt;
	std::string type;
public:
	transaction(int amt, std::string type);
	std::string report();
};