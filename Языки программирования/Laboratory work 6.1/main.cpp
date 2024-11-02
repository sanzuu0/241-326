#include <iostream>
#include <stack>


// Проверить правильность скобочного выражения
// Написать функцию для проверки правильности расстановки скобок (,),[,],{,} в введенном пользователем выражении  (наборе различных символов) за линейное время (один просмотр выражения).
// 2+4-5(87192479_7348){72648]76823[] -> no
// ({}) -> yes
// ({)} -> no
//
// Алгоритм решения
//
// Считываем элемент.
// Если это (,[ или {, то помещаем ее в стек.
// Если это ),] или }, то сравниваем с верхним элементом стека.
// Если образовалась пара, то верхний элемент стека удаляем.
// Иначе - выражение неправильное.
//
// Когда все элементы считали, то проверяем стек на пустоту.
// Если стек пуст, то выражение правильное.
// Иначе - выражение неправильное.


std::string stack_check(std::string line) {

    std::stack<std::string> stack;

    for (int i = 0; i < line.size(); i++) {

        switch (line[i]) {

            case '(':
                stack.push("(");
                break;

            case ')':
                if (stack.top() == "(") {
                    stack.pop();
                    break;
                } else {
                    return "no";
                }

            case '{':
                stack.push("{");
                break;

            case '}':
                if (stack.top() == "{") {
                    stack.pop();
                    break;
                } else {
                    return "no";
                }

            case '[':
                stack.push("[");
                break;

            case ']':
                if (stack.top() == "[") {
                    stack.pop();
                    break;
                } else {
                    return "no";
                }
        }
    }

    return (stack.size() == 0) ? "yes" : "no";
}

int main() {

    std::cout << "Введите строку" << std::endl;

    std::cout << stack_check("(asdfafafa){}[]fafa{}[{}]([)]");
    return 0;
}
