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

void Spaceless(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

std::vector<std::pair<char, int>> f(const std::string& str){
    std::vector<std::pair<char, int>> result;
    size_t j=0;
    for(size_t i=0; i!=str.size(); i++){
        if( str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            result.push_back({str[i], i});
            j++;
        }
    }
    return result;
}

bool isNumeric_1_dot(const std::string& str){
    bool result=true;
    int amount_of_dots=0;
    if(str[0]<'0' || str[0]>'9')
        return false;
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] == '.') {
            amount_of_dots++;
            if (amount_of_dots > 1) return false;
        } else if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

std::string clear_from_operations(const std::string&str){
    std::string result=str;
    for(int i=0; i!=str.size(); i++){
        
    }
}

void str_to_(const std::string& str, std::string& op, std::vector<double>& numbers) {
    op.clear();
    numbers.clear();

    std::vector<std::pair<char, int>> operations_indexes=f(str);


}




























