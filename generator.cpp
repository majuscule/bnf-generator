#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/time.h>
#include <iostream>

using namespace std;

string prg();
string expr();
string arthexpr();
string ifexpr();
string operand();
string op();
string signumber();
string number();
string nonzerodigit();
string digit();

int main(int argc, char *argv[]) {
    int numberOfPrograms = 0;
    while (!numberOfPrograms) {
      printf("How many programs should be generated?: ");
      string input;
      getline(cin, input);
      numberOfPrograms = atoi(input.c_str());
    }

    srand(time(NULL));
    FILE *output = fopen("bnf-valid-programs.txt", "w");
    for (int i = numberOfPrograms; i > 0; i--) {
        fprintf(output, "%s\n", prg().c_str());
        if (i-1) fprintf(output, "\n");
    }
    fclose(output);

    return 0;
}

string prg() {
    string prg = expr();
    if (rand() % 5 == 0)
        prg += "\n" + expr();
    return prg;
}

string expr() {
    string expr = "";
    if (rand() % 5 != 0)
        expr += arthexpr();
    else
        expr += ifexpr();
    return expr;
}

string arthexpr() {
    string arthexpr = "("
                    + operand() + " "
                    + operand() + " "
                    + op() + ")";
    return arthexpr;
}

string ifexpr() {
    string ifexpr = "IF "
                  + operand() + " "
                  + operand() + " "
                  + operand() + " "
                  + operand();
    return ifexpr;
}

string operand() {
    string operand = "";
    if (rand() % 5 == 0)
        operand = expr();
    else
        operand = signumber();
    return operand;
}

string signumber() {
    string signumber = nonzerodigit();
    if (rand() % 5 == 0)
        signumber += digit();
    return signumber;
}

string number() {
    string number = digit();
    if (rand() % 5 == 0)
        number += digit();
    return number;
}

string nonzerodigit() {
    string digits = "123456789";
    return digits.substr((rand() % 9), 1);
}

string digit() {
    string digits = "0123456789";
    return digits.substr((rand() % 10), 1);
}

string op() {
    string ops = "+x/-";
    return ops.substr((rand() % 4), 1);
}
