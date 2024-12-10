#include "calc.h"
// 1 + 3 + 789 * 78 - 56464 * 879 *4984 *84 
// 1 3 789 78 56464 879 4984 84
//  +  +  *  -     *   *    *
int result=0;

void func(std::vector<int>& numbers, std::string& operations){
	for(size_t i=0; i!=sizeof(operations); i++){
		if(&operations[i]=="*"){
			numbers[i]*=numbers[i+1];
			numbers.erase(begin+i);
			operations.erase(begin+i);
		}
	}
	for(auto n: numbers)
		std::cout<<n<<" ";
		
	for(auto n: operations)
		std::cout<<n<<" ";
}

int add(int a, int b){
	return a+b;
}

int sub(int a, int b){
	return a-b;
}

int mult(int a, int b){
	return a*b;
}

double dev(double a, double b){
	return a/b;
}

