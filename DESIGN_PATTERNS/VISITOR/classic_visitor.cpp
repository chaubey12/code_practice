#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct DoubleExpression;
struct AdditionExpression;
struct SubtractionExpression;

struct ExpressionVisitor{
    virtual void visit(DoubleExpression *de) = 0;
    virtual void visit(AdditionExpression *de) = 0;
    virtual void visit(SubtractionExpression *de) = 0;
};

struct ExpressionPrinter : ExpressionVisitor{
    ostringstream oss;
    string str() const { return oss.str(); }
    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *se) override;
};

struct ExpressionEvaluator : ExpressionVisitor{
    double result;
    void visit(DoubleExpression *de) override;
    void visit(AdditionExpression *ae) override;
    void visit(SubtractionExpression *se) override;
};

struct Expression{
    virtual void accept(ExpressionVisitor* visitor) = 0;
};

struct DoubleExpression : Expression{
    double value;
    DoubleExpression(double value) : value(value){}

    void accept(ExpressionVisitor *visitor) override{
        visitor->visit(this);
    }
};

struct AdditionExpression : Expression{
    Expression *left, *right;
    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}

    void accept(ExpressionVisitor *visitor) override{
        visitor->visit(this);
    }
};

struct SubtractionExpression : Expression{
    Expression *left, *right;
    SubtractionExpression(Expression *left, Expression *right) : left(left), right(right) {}

    void accept(ExpressionVisitor *visitor) override{
        visitor->visit(this);
    }
};

void ExpressionPrinter::visit(DoubleExpression *de){
    oss << de->value;
}

void ExpressionPrinter::visit(AdditionExpression *ae){
    bool need_braces = dynamic_cast<AdditionExpression*>(ae);
    if(need_braces) oss << "(";
    ae->left->accept(this);
    oss << "+";
    ae->right->accept(this);
    if(need_braces) oss << ")";
}

void ExpressionPrinter::visit(SubtractionExpression *se){
    bool need_braces = dynamic_cast<SubtractionExpression*>(se);
    if(need_braces) oss << "(";
    se->left->accept(this);
    oss << "-";
    se->right->accept(this);
    if(need_braces) oss << ")";
}

// Evaluation
void ExpressionEvaluator::visit(DoubleExpression *de) {
    result = de->value;
}

void ExpressionEvaluator::visit(AdditionExpression *ae) {
    ae->left->accept(this);
    auto temp = result;
    ae->right->accept(this);
    result += temp;
}

void ExpressionEvaluator::visit(SubtractionExpression *se) {
    se->left->accept(this);
    auto temp = result;
    se->right->accept(this);
    result = temp - result;
}


int main(int ax, char* av[]){
    auto e = new AdditionExpression{
        new DoubleExpression{1},
        new SubtractionExpression{
            new DoubleExpression{2},
            new DoubleExpression{3}
        }
    };

    ExpressionPrinter ep;
    ep.visit(e);
    cout << ep.str()<<endl;

    ExpressionEvaluator evaluator;
    evaluator.visit(e);
    cout << ep.str() << "="<<evaluator.result<<endl;;
    return 0;
}