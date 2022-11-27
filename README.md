# Piscine_CPP

{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	"class": {
		"prefix": "class ",
		"body": [
		"#ifndef ${2:header}_HPP",
		" #define ${2:header}_HPP",
		"#include <iostream>",	
		  "class   ${1:example}:",
		  "{",
		  "    public:",
		  "        ${1:example}();",
		  "        ${1:example}(std::string const &);",
		  "        ${1:example}(${1:example} const &);",
		  "        ${1:example}& operator=(${1:example} const &);",
		  "        ~${1:example}();",
		  "    private:",
		  "};",
		  "#endif",
		],
		"description": "class template"
	  },
	
	"cons": {
		"prefix": "cons",
		"body": [
		  "/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/",

		  "${1:NAME}::${1:NAME}()",
		  "{",
		  "std::cout << \"${1:NAME} created\" << std::endl;",
		  "return;",
		  "}",
		  "",
		  "${1:NAME}::${1:NAME}( ${1:NAME} const & src)",
		  "{",
		  "std::cout << \"${1:NAME} Copy constructor called\" << std::endl;",
		  "*this = src;",
		  "return;",
		  "}",
		  "",
		  "${1:NAME} & ${1:NAME}::operator=(${1:NAME} const & rhs)",
		  "{",
		  "std::cout << \"${1:NAME} Copy assignment operator called\" << std::endl;",
		  "return  *this;",
		  "}",
		  "",
		  "${1:NAME}::~${1:NAME}( void )",
		  "{",
		  "std::cout << \"${1:NAME} destroyed\" << std::endl;",
		  "return;",
		  "}",
		  "/**************************** SETTERS & GETTERS *****************************/",
		  "/*********************** PUBLIC MEMBER FUNCTION *****************************/",
		],
		"description": "canonical form"
		}
}
