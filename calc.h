#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

void mult(std::vector<double>& numbers, std::string& operations);
void dev(std::vector<double>& numbers, std::string& operations);
double func(std::vector<double>& numbers, std::string& operations);
void str_to_(const std::string& str, std::string& op, std::vector<double>& numbers);
void Spaceless(std::string& str);
std::vector<std::pair<char, int>> GetOperationsFromStr(const std::string& str);
bool isNumeric_1_dot(const std::string& str);
std::vector<double> GetNumbers(const std::string&str);
std::string GetOperations(const std::string& str);
template <typename T>
bool operator==(const std::vector<T>& vec1, const std::vector<T>& vec2);
