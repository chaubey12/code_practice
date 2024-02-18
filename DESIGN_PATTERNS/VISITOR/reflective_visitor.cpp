#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Expression{
    virtual ~Expression() = default;
};

struct DoubleExpression : Expression{
    double value;
    DoubleExpression(double value) : value(value){}
};

struct AdditionExpression : Expression{
    Expression *left, *right;
    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}
     ~AdditionExpression(){
        delete left;
        delete right;
    }
};

struct ExpressionPrinter{
    ostringstream oss;
    void print(Expression* e){
        if(auto de = dynamic_cast<DoubleExpression*>(e)){
            oss << de->value;
        }else if(auto ae = dynamic_cast<AdditionExpression*>(e)){
            oss << "(";
            print(ae->left);
            oss << "+";
            print(ae->right);    
            oss << ")";
        }
    }
    string str() const { return oss.str();}  
};

int main(int ax, char* av[]){
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };
    ExpressionPrinter ep;
    ep.print(e);
    cout << ep.str()<<endl;
    delete e;
    return 0;
}