#include "calc.h"
// 0+12+45+49- 13*79*46 +13

void yourself(int a, int b, char op){
	std::cout<<a<<op<<b<<"\n"<<"сам считай\n";
}


int main(){
	//std::vector<double> numbers;
	//std::getline(std::cin, str);
	/*//std::cout<<str<<"\n";
	Spaceless(str);
	//std::cout<<str<<"\n";

	if(isNumeric_1_dot(str))
		std::cout<<"да\n";
	else
		std::cout<<"нет\n";*/
	
	std::string str=".123+-789/-4.65..6564+-4984*-4984+98498", op;
	/*std::vector<double> numbers;

	try{
		str_to_(str, op, numbers);
		for(auto a: op)
			std::cout<<a<<' ';
		std::cout<<"\n";
		for(auto a: numbers)
			std::cout<<a<<' ';
		std::cout<<"\n";

	}catch(const std::invalid_argument& ex){
		std::cout<<ex.what();
	}
*/

	try{
		std::vector<double> vec=GetNumbers(str);
		for(double a: vec)
			std::cout<<a<<" ";
		std::cout<<"\n";
	}catch(const std::invalid_argument& ex){
		std::cout<<ex.what()<<"\n";
	}
	


/*
	std::vector<std::string> result;
	boost::split(result, str, boost::is_any_of("+/*-"));*/


return 0;	
}



















