#include "calc.h"
// 0+12+45+49- 13*79*46 +13

void yourself(int a, int b, char op){
	std::cout<<a<<op<<b<<"\n"<<"сам считай\n";
}


int main(){
	int a;
	std::string op;
	std::vector<int> numbers;
	std::string operations;
	
	while(std::cin>>a>>op){
		numbers.push_back(a);
		operations.append(op);
	}
	
	for(auto i: numbers)
		std::cout<<i<<" ";
		
	for(auto i: operations)
		std::cout<<i<<" ";
	
	func(numbers, operations);
	
	for(auto i: numbers)
		std::cout<<i<<" ";
		
	for(auto i: operations)
		std::cout<<i<<" ";	

	
return 0;	
}
