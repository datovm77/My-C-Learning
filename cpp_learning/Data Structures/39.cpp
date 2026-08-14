#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

bool IsOperator(const std::string &token) {
    return token == "+" || token == "-" ||
           token == "*" || token == "/";
}

bool ParseNumber(const std::string &token, double &value) {
    std::size_t used = 0;

    try {
        value = std::stod(token, &used);
    } catch (const std::invalid_argument &) {
        return false;
    } catch (const std::out_of_range &) {
        return false;
    }

    return used == token.size();
}

bool ApplyOperator(
    const std::string &op,
    double left,
    double right,
    double &result
) {
    if (op == "+") {
        result = left + right;
    } else if (op == "-") {
        result = left - right;
    } else if (op == "*") {
        result = left * right;
    } else if (op == "/") {
        if (right == 0) {
            return false;
        }
        result = left / right;
    } else {
        return false;
    }

    return true;
}

bool EvaluatePostfix(
    const std::string &expression,
    double &answer
) {
    std::istringstream input(expression);
    std::stack<double> values;
    std::string token;

    while (input >> token) {
        if (!IsOperator(token)) {
            double number;

            if (!ParseNumber(token, number)) {
                return false;
            }

            values.push(number);
            continue;
        }

        if (values.size() < 2) {
            return false;
        }

        double right = values.top();
        values.pop();

        double left = values.top();
        values.pop();

        double result;

        if (!ApplyOperator(token, left, right, result)) {
            return false;
        }

        values.push(result);
    }

    if (values.size() != 1) {
        return false;
    }

    answer = values.top();
    return true;
}

bool EvaluatePrefix(
    const std::string &expression,
    double &answer
) {
    std::istringstream input(expression);
    std::vector<std::string> tokens;
    std::string token;

    while (input >> token) {
        tokens.push_back(token);
    }

    std::stack<double> values;

    for (int i = static_cast<int>(tokens.size()) - 1;
         i >= 0;
         --i) {
        const std::string &current = tokens[i];

        if (!IsOperator(current)) {
            double number;

            if (!ParseNumber(current, number)) {
                return false;
            }

            values.push(number);
            continue;
        }

        if (values.size() < 2) {
            return false;
        }

        double left = values.top();
        values.pop();

        double right = values.top();
        values.pop();

        double result;

        if (!ApplyOperator(current, left, right, result)) {
            return false;
        }

        values.push(result);
    }

    if (values.size() != 1) {
        return false;
    }

    answer = values.top();
    return true;
}

void PrintPostfixResult(const std::string &expression) {
    double answer;

    std::cout << "Postfix \"" << expression << "\" -> ";

    if (EvaluatePostfix(expression, answer)) {
        std::cout << answer << '\n';
    } else {
        std::cout << "invalid expression\n";
    }
}

void PrintPrefixResult(const std::string &expression) {
    double answer;

    std::cout << "Prefix \"" << expression << "\" -> ";

    if (EvaluatePrefix(expression, answer)) {
        std::cout << answer << '\n';
    } else {
        std::cout << "invalid expression\n";
    }
}

int main() {
    PrintPostfixResult("8 2 / 3 +");
    PrintPostfixResult("5 3 - 8 2 / +");
    PrintPostfixResult("4 0 /");
    PrintPostfixResult("1 +");

    PrintPrefixResult("- 8 / 6 2");
    PrintPrefixResult("+ 2 * 3 4");
    PrintPrefixResult("/ 4 0");
    PrintPrefixResult("+ 1");

    return 0;
}
