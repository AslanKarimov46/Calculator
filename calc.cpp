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

void Spaceless(std::string& str){
    for(size_t i=0; i<str.size(); i++){
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            while(i>0 && str[i-1]==' '){
                str.erase(str.begin()+i-1);
                i--; 
            }
            while(i+1<str.size() && str[i+1]==' '){
                str.erase(str.begin()+i+1);
            }
        }
    }

    while(!str.empty() && str[0]==' '){
        str.erase(str.begin());
    }

    while(!str.empty() && str.back()==' '){
        str.pop_back();
    }

}

std::vector<std::pair<char, int>> GetOperationsFromStr(const std::string& str){
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
    bool result=false;
    int amount_of_dots=0;
    if( ( str[0]<='9'||str[0]>='0' ) || str[0]=='.' || str[0]=='-')
       result=true ;
    for(size_t i=1; i<str.size(); i++){
        if(str[i]=='.'){
            amount_of_dots++;
            if(amount_of_dots>1)
                return false;
        }else if(str[i]<'0' || str[i]>'9'){
            return false;
        }
    }
    return true;
}


/*std::vector<double> GetNumbers(const std::string& str){
    std::vector<double> result;
    std::string str1=str;
    std::vector<std::pair<char, int>> Operations=GetOperationsFromStr(str);

    int i=1;
    while(i!=str1.size()){
        if( str1[i]=='+' || str1[i]=='-' || str1[i]=='*' || str1[i]=='/' ){
            str1[i]=' ';
            if(str1[i+1]=='-'){
                i++;
            }
        }
        i++;
    }

    int j=0; 
    std::string temp;


    int LastIndex=0;
    for(int i=0; i<str1.size(); i++){

        if(str1[i]==' '){
            if(isNumeric_1_dot(str1.substr(LastIndex, i-LastIndex))){
                std::cout<<"##### "<<str1.substr(LastIndex, i-LastIndex)<<"|"<<"\n";
                result.push_back(std::stod(str1.substr(LastIndex, LastIndex+i)));
                LastIndex=i+1;        
            }else{
                throw std::invalid_argument("Некорректное значение в строке: " + str1.substr(LastIndex, i - LastIndex));
            }
        }
    }

    if(isNumeric_1_dot(str1.substr(LastIndex+1, str1.size()-1)))
        result.push_back(std::stod(str1.substr(LastIndex+1, str1.size()-1)));
    else
        throw std::invalid_argument("Некорректное значение в строке: " + str1.substr(LastIndex, str1.size() - LastIndex));
    
    return result;

}*/

std::vector<double> GetNumbers(const std::string& str) {
    std::vector<double> result;
    std::string str1 = str;

    // Удаление операций с заменой на пробелы
    for (size_t i = 1; i < str1.size(); ++i) {
        if (str1[i] == '+' || str1[i] == '-' || str1[i] == '*' || str1[i] == '/') {
            str1[i] = ' ';
            if (i + 1 < str1.size() && str1[i + 1] == '-') {
                ++i;
            }
        }
    }

    size_t LastIndex = 0;

    for (size_t i = 0; i <= str1.size(); ++i) {
        if (i == str1.size() || str1[i] == ' ') {
            if (i > LastIndex) {
                std::string segment = str1.substr(LastIndex, i - LastIndex);
                if (isNumeric_1_dot(segment)) {
                    result.push_back(std::stod(segment));
                } else {
                    throw std::invalid_argument("Некорректное значение в строке: " + segment);
                }
            }
            LastIndex = i + 1; // Сдвиг на следующий символ
        }
    }

    return result;
}


void str_to_(const std::string& str, std::string& op, std::vector<double>& numbers) {
    op.clear();
    numbers.clear();

    std::string str1=str;
    Spaceless(str1);
    std::vector<std::pair<char, int>> Operations=GetOperationsFromStr(str1);
    int i=0;
    while(i<Operations.size()-1){
        if( ((Operations[i].second+1)==Operations[i+1].second) && Operations[i+1].first=='-' ){
            Operations.erase(Operations.begin()+i+1);
        }
        i++;
    }

    /*for(int i=0; i!=Operations.size(); i++)
        std::cout<<Operations[i].first<<" "<<Operations[i].second<<"\n";*/

    for(int i=1; i!=Operations.size(); i++){
        if(Operations[i].second==(Operations[i-1].second-1)){
            std::cout<<"Слишком много операций\n";
            break;
        }
    }

    for(int i=0; i!=Operations.size(); i++){
        op+=Operations[i].first;
    }

    numbers=GetNumbers(str1);


    /*for(int i=0; i!=Operations.size(); i++){
        std::cout<<Operations[i].first<<' '<<Operations[i].second<<" ";
    }
    std::cout<<"\n";*/

}

/*void str_to_(const std::string& str, std::string& op, std::vector<double>& numbers) {
    op.clear();
    numbers.clear();

    std::string str1 = str;
    Spaceless(str1); // Удаляем пробелы из строки
    std::vector<std::pair<char, int>> Operations = GetOperationsFromStr(str1);

    // Удаляем лишние знаки "-" после других операций
    for (size_t i = 0; i < Operations.size() - 1; ) {
        if ((Operations[i].second + 1) == Operations[i + 1].second && Operations[i + 1].first == '-') {
            Operations.erase(Operations.begin() + i + 1);
        } else {
            ++i;
        }
    }

    // Проверка на слишком много операций подряд
    for (size_t i = 1; i < Operations.size(); ++i) {
        if (Operations[i].second == (Operations[i - 1].second - 1)) {
            throw std::invalid_argument("Ошибка: Слишком много операций подряд в строке.");
        }
    }
    if(std::isdigit(Operations[Operations.size()-1].second) || Operations[Operations.size()-1].second=='.')
        throw std::invalid_argument("Строка не моет заканчиваться операцией.");

    // Собираем строку операций
    for (const auto& operation : Operations) {
        op += operation.first;
    }

    // Получаем числа из строки
    try {
        numbers = GetNumbers(str1);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка при разборе чисел: " << e.what() << "\n";
        throw; // Перепросить исключение, чтобы вызвать могла обработать
    }
}*/

