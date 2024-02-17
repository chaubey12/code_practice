#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int RemainingInt(const vector<int>& digits, int idx){
    int val = 0;
    for(int i=idx; i < digits.size(); ++i){
        val = val*10 + digits[i];
    }
    return val;
}

int Evaluate(const vector<int>& operands, const vector<char>& operators){
    stack<int> intermediate_operands;
    int operand_idx = 0;
    for(char oper : operators){
        if(oper == '*'){
            int product = intermediate_operands.top()*operands[operand_idx++];
            intermediate_operands.pop();
            intermediate_operands.push(product);
        }else{
            intermediate_operands.push(operands[operand_idx++]);
        }
    }
    int sum = 0;
    while(!intermediate_operands.empty()){
        sum += intermediate_operands.top();
        intermediate_operands.pop();
    }
    return sum;
}

bool DirectedExpressionSynthesis(const vector<int>& digits, int target, int current_term, int offset,
                                 vector<int>* operands, vector<char>* operators){
    current_term = current_term*10 + digits[offset];
    if(offset == digits.size() - 1){
        operands->emplace_back(current_term);
        if(Evaluate(*operands, *operators) == target){
            return true;
        }
        operands->pop_back();
        return false;
    }
    if(DirectedExpressionSynthesis(digits, target, current_term, offset + 1, operands, operators)){
        return true;
    }
    operands->emplace_back(current_term);
    operators->emplace_back('*');
    if(DirectedExpressionSynthesis(digits, target, 0, offset + 1, operands, operators)){
        return true;
    }
    operands->pop_back();
    operators->pop_back();
    operands->emplace_back(current_term);
    if(target - Evaluate(*operands, *operators) <= RemainingInt(digits, offset + 1)){
        operators->emplace_back('+');
        if(DirectedExpressionSynthesis(digits, target, 0, offset+1, operands, operators)){
            return true;
        }
        operators->pop_back();
    }
    operands->pop_back();
    return false;
}


bool ExpressionSynthesis(const vector<int>& digits, int target){
    vector<char> operators;
    vector<int> operands;
    return DirectedExpressionSynthesis(digits, target, 0, 0, &operands, &operators);
}

int main(){
    vector<int> digits{1,2,3,2,5,3,7,8,5,9};
    int target = 995;
    if(ExpressionSynthesis(digits, target)){
        cout << "POSSIBLE"<<endl;
    }else{
        cout << "NOT POSSIBLE"<<endl;
    }
    return 0;
}