#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Expression{
    virtual ~Expression() = default;
    virtual void print(ostringstream& oss) = 0;
};

struct DoubleExpression : Expression{
    double value;
    DoubleExpression(double value) : value(value){}
    void print(ostringstream& oss) override{
        oss << value;
    }
};

struct AdditionExpression : Expression{
    Expression *left, *right;
    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}
     ~AdditionExpression(){
        delete left;
        delete right;
    }
    void print(ostringstream& oss) override{
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
};

int main(int ax, char* av[]){
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new AdditionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };
    ostringstream oss;
    e->print(oss);
    cout << oss.str()<<endl;
    delete e;
    return 0;
}