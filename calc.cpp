#include "calc.h"
// 1 + 3 + 789 * 78 - 56464 * 879 *4984 *84 
// 1 3 789 78 56464 879 4984 84
//  +  +  *  -     *   *    *

void mult(std::vector<double>& numbers, std::string& operations){
    for(size_t i=0; i<operations.size();){
        if(operations[i]=='*'){
            numbers[i]*=numbers[i + 1];
            numbers.erase(numbers.begin()+i+1);
            operations.erase(operations.begin()+i);
        }else
            ++i;
    }
}

void dev(std::vector<double>& numbers, std::string& operations){
    for(size_t i=0; i<operations.size();){
        if(operations[i]=='/'){
            numbers[i]/=numbers[i + 1];
            numbers.erase(numbers.begin()+i+1);
            operations.erase(operations.begin()+i);
        }else
            ++i;
    }
}

double func(std::vector<double>& numbers, std::string& operations){
	mult(numbers, operations);
	dev(numbers, operations);
	double result=numbers[0];
	for(size_t i=0; i!=operations.size(); i++){
		if(operations[i]=='+')
			result+=numbers[i+1];
		else if(operations[i]=='-')
			result-=numbers[i+1];
		else
			std::cout<<"ERROR Incorrect operation!!!\n";

	}
return result;
}