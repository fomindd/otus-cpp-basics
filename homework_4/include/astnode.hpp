#ifndef ASTNODE_HPP
#define ASTNODE_HPP

#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
  public:
    explicit ASTNode(const std::string &repr);

    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    ASTNode(const ASTNode &other) = delete;

    ASTNode &operator=(const ASTNode &other) = delete;

    ~ASTNode();

    std::string repr() const { return repr_; }

    void print(std::ostream &out) const;

  private:
    void inner_print(std::ostream &out, size_t indent) const;

    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;
};

class Add : public ASTNode {
  public:
    Add(ASTNode* left, ASTNode* right)
        : ASTNode("+", left, right ) {}

};

class Sub : public ASTNode {
  public:
    Sub(ASTNode* left, ASTNode* right)
        : ASTNode("-", left, right )  {}

};

class Mul : public ASTNode {
  public:
    Mul(ASTNode* left, ASTNode* right)
        : ASTNode("*", left, right ) {}
};

class Div : public ASTNode {
  public:
    Div(ASTNode* left, ASTNode* right)
        : ASTNode("/", left, right) {}
};

class Number : public ASTNode {
  public:
    Number(int val)
        : ASTNode(std::to_string(val))
        , val_(val) {}

    int value() const { return val_; }

  private:
    int val_;
};

class Variable : public ASTNode {
  public:
    Variable(std::string val)
        : ASTNode(val)
        , val_(val) {}

    std::string value() const { return val_; }

  private:
    std::string val_;
};

#endif