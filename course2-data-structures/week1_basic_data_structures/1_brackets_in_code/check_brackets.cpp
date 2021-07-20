#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if(opening_brackets_stack.empty())
                opening_brackets_stack.push(Bracket(next, position));
            else{
                Bracket c = opening_brackets_stack.top();
                if(c.Matchc(next))
                    opening_brackets_stack.pop();
                else{
                    opening_brackets_stack.push(Bracket(next, position));
                }
            }            
        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.empty())
        std::cout << "Success" << std::endl;
    else{
        int i = -1, j = -1;
        while(!opening_brackets_stack.empty()){
            if(opening_brackets_stack.top().type == ')' || opening_brackets_stack.top().type == ']' || opening_brackets_stack.top().type == '}')
                i = opening_brackets_stack.top().position;
            else
                j = opening_brackets_stack.top().position;            
            opening_brackets_stack.pop();
        }
        std::cout << ((i < 0) ? (j+1) : (i+1)) << std::endl;
    }
    return 0;
}
