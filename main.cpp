#include "calc.h"
// 0+12+45+49- 13*79*46 +13

void yourself(int a, int b, char op){
	std::cout<<a<<op<<b<<"\n"<<"сам считай\n";
}


int main(){
	std::string str, op;
	std::vector<double> numbers;
	std::getline(std::cin, str);
	//std::cout<<str<<"\n";
	Spaceless(str);
	//std::cout<<str<<"\n";

	if(isNumeric_1_dot(str))
		std::cout<<"да\n";
	else
		std::cout<<"нет\n";

	//std::cout<<str<<"\n";

	/*double a;
	std::string op;
	std::vector<double> numbers;
	std::string operations;
	
	while(std::cin>>a>>op){
		numbers.push_back(a);
		operations.append(op);
	}
    std::cin>>a;
    numbers.push_back(a);
	std::cout<<"\n";
	
	for(auto i: numbers)
		std::cout<<i<<" ";
	std::cout<<"\n";
	
	for(auto i: operations)
		std::cout<<i<<" ";
	std::cout<<"\n";

	mult(numbers, operations);
	std::cout<<"\n";	
	
	for(auto i: numbers)
		std::cout<<i<<" ";
	std::cout<<"\n";		
	
	for(auto i: operations)
		std::cout<<i<<" ";	
	std::cout<<"\n";

	dev(numbers, operations);
	std::cout<<"\n";	
	
	for(auto i: numbers)
		std::cout<<i<<" ";
	std::cout<<"\n";		
	
	for(auto i: operations)
		std::cout<<i<<" ";	
	std::cout<<"\n";	

	std::cout<<func(numbers, operations)<<"\n";*/

return 0;	
}



















