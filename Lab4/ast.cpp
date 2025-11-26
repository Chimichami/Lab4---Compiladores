#include "ast.h"
#include <iostream>

using namespace std;

// ------------------ Exp ------------------
Exp::~Exp() {}

string Exp::binopToChar(BinaryOp op) {
    switch (op) {
        case PLUS_OP:  return "+";
        case MINUS_OP: return "-";
        case MUL_OP:   return "*";
        case DIV_OP:   return "/";
        case POW_OP:   return "**";
        case LE_OP:   return "<";
        default:       return "?";
    }
}

// ------------------ BinaryExp ------------------
BinaryExp::BinaryExp(Exp* l, Exp* r, BinaryOp o)
    : left(l), right(r), op(o) {

        if (right->isnumber and left->isnumber)
        {
            isnumber = true;
            switch (o)
            {
            case PLUS_OP:
                valor = left->valor + right->valor;
                break;
            case MINUS_OP:
                valor = left->valor - right->valor;
                break;
            case MUL_OP:
                valor = left->valor * right->valor;
                break;
          };
        }
        else{
            isnumber = false;
            valor = 0;
        }
        

        hoja = false; 
        if (left->hoja==true)
        {
            left->etiqueta=1;
        }
        if (left->etiqueta ==right->etiqueta)
        {
            etiqueta = left->etiqueta + 1; 
        }
        else{
            etiqueta = max(left->etiqueta,right->etiqueta); 
        }
}

    
NumberExp::NumberExp(int v) : value(v) {etiqueta=0;hoja=true;isnumber=true;valor = v;}

IdExp::IdExp(string v) : value(v) {etiqueta=0;hoja=true;isnumber=false;valor = 0;}

FcallExp::FcallExp(){etiqueta=0;hoja=true;isnumber=false;valor = 0;}



BinaryExp::~BinaryExp() {
    delete left;
    delete right;
}



// ------------------ NumberExp ------------------


NumberExp::~NumberExp() {}


// ------------------idExp ------------------


IdExp::~IdExp() {}


Stm::~Stm(){}

PrintStm::~PrintStm(){}

AssignStm::~AssignStm(){}

IfStm::IfStm(Exp* c, Body* t, Body* e): condition(c), then(t), els(e) {}


WhileStm::WhileStm(Exp* c, Body* t): condition(c), b(t) {}


PrintStm::PrintStm(Exp* expresion){
    e=expresion;
}

AssignStm::AssignStm(string variable,Exp* expresion){
    id = variable;
    e = expresion;
}



VarDec::VarDec() {}

VarDec::~VarDec() {}

Body::Body(){
    declarations=list<VarDec*>();
    StmList=list<Stm*>();
}

Body::~Body(){}

SwitchStm::SwitchStm(Exp* e, list<CaseStmt*> c): switch_exp(e), case_list(c) {}
CaseStmt::CaseStmt(Exp* c, Body* t): case_val(c), then(t) {}