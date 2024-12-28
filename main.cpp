#include "calc.h"
// 0+12+45+49- 13*79*46 +13

void yourself(int a, int b, char op){
	std::cout<<a<<op<<b<<"\n"<<"сам считай\n";
}


int main(){
	//std::vector<double> numbers;
	//std::getline(std::cin, str);
	//std::cout<<str<<"\n";

	std::string str="-2-2-", operations="+-/+/+";
	Spaceless(str);
	std::vector<double> numbers{12, 13, 10, 5, 3, 2, 6};

	bool operationsSuccess = true, numbersSuccess = true;

	try{
	    try{
    	    operations = GetOperations(str);
    	}catch (const std::invalid_argument& ex){
        	operationsSuccess=false;
        	std::cout<<"Error in GetOperations: "<<ex.what()<<"\n";
    	}

	    try{
    	    numbers=GetNumbers(str);
    	}catch(const std::invalid_argument& ex) {
    		numbersSuccess=false;
        	std::cout << "Error in GetNumbers: " << ex.what() << "\n";
	    }
	}catch(...){
    	std::cout << "Unhandled exception occurred.\n";
	}

	
	if( numbersSuccess==true && operationsSuccess==true ){
		for (char i : operations)
           	std::cout << i << ' ';
	    std::cout << "\n";
	    for (double a : numbers)
            std::cout << a << " ";
	    std::cout << "\n";
	    try{
	    	std::cout<<func(numbers, operations);
	    }catch(const std::runtime_error& ex){
	    	std::cout << ex.what() << "\n";
	    }
	}

	/*try{
		dev(numbers, operations);
	}catch(const std::runtime_error& ex){
		std::cout<<ex.what()<<"\n";
	}*/



return 0;	
}



















