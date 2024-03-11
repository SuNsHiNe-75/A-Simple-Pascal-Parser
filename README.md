#### Introduction
This is the second assignment of the "Design and Implementation of Compiler" course at NSYSU, aiming to implement a **simple pascal parser**.

In this assignment, you must complete a parser that conforms to the Pascal grammar. You can modify the first assignment - the scanner - to tokenize input and pass it to the parser.

You must consider the following issues:
- Your parser should generate good error messages when encountering errors, such as the line number where the error occurred and an explanation of the error.
- When the parser encounters an error, it should strive to process the input as much as possible, meaning the parser should perform recovery when encountering errors.

About YACC:
- YACC treats input as a sequence of tokens.
  - One or more consecutive tokens can be represented as a grammar.
- The purpose of YACC is to check whether the syntax is valid.
- Lex is just one routine of YACC responsible for returning tokens to YACC.

#### Establishing Environment
Refer to [Report](https://github.com/SuNsHiNe-75/A-Simple-Pascal-Parser/blob/main/Report.pdf).

#### Run
Refer to [Report](https://github.com/SuNsHiNe-75/A-Simple-Pascal-Parser/blob/main/Report.pdf).
