//CURSO : COMPILADORES GRUPO : CCOMP8-1
//ALUMNO : ALVARO DIEGO DURAND MANRIQUE

#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using std::cout; using std::cin;

using std::endl; using std::string;
using std::vector; using std::istringstream;

using std::stringstream;
constexpr int CHAR_LENGTH = 1;

using std::cout; using std::cin;
using std::endl; using std::string;

void limitadores(string s){
	cout<<"LIMITADOR"<<endl;
}

int tamstring(const char *s)
{
	int size = 0;
	
	while (*s) {
		size += 1;
		s +=1;
	}
	
	return size;
}

//Los delimitadores son : , ; : ()[] .
bool delimitadores(char c){
	if (c=='('||c==')'||c=='['||c==']'||c==':'||c==';'||c==','){return true;}
	return false;
}
	
	//Los operadores son los siguientes : +-*/ : = = <> < <= >= > ^ an dor not div mod in
	bool operadores(char c){
		if (c == '*' || c == '/' || c == '^' || c == '%' || c == '+' || c == '-' || c == '=' || c == '>' || c == '<')
			return true;
		return false;
	}
		
		void error(void){cout << "\nCadena no valida" << endl;exit(-1);}
		
		//Las palabras reservadas son : array downto function of repeat until begin else goto packed set var
		//case end if procedure then while const file label program to with do for nil record type
		//Los operadores son los siguientes: + - * / := = <> < <= >= > ^ and or not div mod in
		string gettoken(string lexema){
			static string reservadas2[] = {":=","=","<>","<=",">= ","and","or","not","div","mod","in" };
			static string reservadas3[] = {"0","1","2","3","4","5","6","7","8","9"};
			static string reservadas4[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q"
				,"r","s","t","u","v","w","x","y","z" };
			static string reservadas[] = { "array", "downto", "function", "of", "repeat", "until",
				"begin", "else", "goto","packed", "set", "var", "case", "end", "if","then","while","const"
				,"file" ,"label" ,"program" ,"to" ,"with" ,"do" ,"for" ,"nil" ,"record" ,"type","procedure" };
			for (int i = 0; i < 29; i++) {
				if (reservadas[i] == lexema){return "PALABRA RESERVADA";}
				if (reservadas2[i] == lexema) { return "OPERADOR"; }
				/*if (lexema[i + 1] == '0' or lexema[i + 1] == '1' or lexema[i + 1] == '2' or lexema[i + 1] == '3'
				and lexema[i + 1] == '4' or lexema[i + 1] == '5' or lexema[i + 1] == '6'
				and lexema[i + 1] == '7' or lexema[i + 1] == '8' or lexema[i + 1] == '9') {
				return "CARACTER";
				}*/
			}
			for (int i = 1; i < lexema.size(); i++) {
				if (lexema[i] == '0' or lexema[i] == '1' or lexema[i] == '2' or lexema[i] == '3' or lexema[i] == '4'
					or lexema[i] == '5' or lexema[i] == '6' or lexema[i] == '7' or lexema[i] == '8' or lexema[i] == '9') {
					return "IDENTIFICADOR";
				}
			}
			return "CARACTER";
		}
/*char getchar(string s){
	while (pos < s.length()){
		while(s[pos]=='\n'||s[pos]=='\t'||s[pos]==' '){pos++;}
		return s[pos++];
	}
}*/

int main()
{
	
	FILE * archivo;
	long medida;
	char * texto;
	archivo = fopen ("prueba1.txt", "r");
	fseek (archivo , 0 , SEEK_END);
	
	medida = ftell (archivo);
	rewind (archivo);
	
	texto = (char*) malloc (sizeof(char)*medida);
	fread(texto, medida+1, 1, archivo);
	
	string text;
	fclose(archivo);

	int i=0;
	
	while(texto[i]!='\0'){
		
		text.push_back(texto[i]);
	
		i++;
	
	}
	
	for(int j=0;j<i-18;j++){
	
		cout <<text[j];
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	
	cout<<endl;
	cout<<"ANALIZADOR LEXICO"<<endl;
	cout<<"<TOKENTYPE> ------ <TOKENTYPE> "<<endl;
	cout<<endl;
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	string space_delimiter = " ";
	vector<string> words{};
	
	size_t pos = 0;
	
	while ((pos = text.find(space_delimiter)) != string::npos) 
	{
		words.push_back(text.substr(0, pos));
		text.erase(0, pos + space_delimiter.length());
	}
	
	bool tipo=true;
	
	for(int i=0;i<words.size();i++)
	{
		if(words[i]=="and"||words[i]=="or"||words[i]=="not"||words[i]=="div"||words[i]=="mod"||words[i]=="in")
		{
			cout<<"OPERADOR "<<words[i]<<endl;
			
		}
		if(words[i]=="array"||words[i]=="downto"||words[i]=="function"||words[i]=="of"||words[i]=="repeat"
		   ||words[i]=="until"||words[i]=="begin"||words[i]=="else"||words[i]=="goto"||words[i]=="packed"
		   ||words[i]=="set"||words[i]=="var"||words[i]=="case"||words[i]=="end"||words[i]=="if"||words[i]=="procedure"
		   ||words[i]=="then"||words[i]=="while"||words[i]=="const"||words[i]=="file"||words[i]=="label"||words[i]=="program"
		   ||words[i]=="to"||words[i]=="with"||words[i]=="do"||words[i]=="for"||words[i]=="nil"||words[i]=="record"||words[i]=="type")
		{
			cout<<"PALABRA RESERVADA "<<words[i]<<endl;
			
		}
		
		if(words[i]=="{" )
		{
			cout<<"COMENTARIO "<<words[i]<<" "<<words[i+1]<<" "<<words[i+2]<<" "<<words[i+3]<<endl;
		}

		for(int j=0;j<words[i].length();j++)
		{
			
			bool bandera=true;
			
			if(words[i][j]=='*'||words[i][j]=='/'| words[i][j]=='^'||words[i][j]=='%'||
				words[i][j]=='+'||words[i][j]=='-'||words[i][j]=='='||words[i][j]=='>'||words[i][j]=='<')
			{
				cout<<"OPERADOR "<<words[i]<<endl;
				break;
				
				
			}
				
			else if(words[i][j]==39 and words[i+1][j+1]==39 and words[i+2][j+2]==39)
				{
					cout<<"CADENA NO PERMITIDA "<<words[i]<<endl;
					
					bandera=false;
					
				}
			
			if((words[i][j]=='('||words[i][j]==')'||words[i][j]=='['||words[i][j]==']'||
				words[i][j]==':'||words[i][j]==';'||words[i][j]==',')and !(words[i][j+1]>=48 && words[i][j+1]<=57) and
				(words[i][j+1]!='('&&words[i][j+1]!=')'&&words[i][j+1]!='['&&words[i][j+1]!=']'&& 
					words[i][j+1]!=':'&&words[i][j+1]!=';'&&words[i][j+1]!=',')and
				(words[i][j-1]!='('&&words[i][j-1]!=')'&&words[i][j-1]!='['&&words[i][j-1]!=']'&&
					words[i][j-1]!=':'&&words[i][j-1]!=';'&&words[i][j-1]!=','))
			{
				
				cout<<"DELIMITADOR "<<words[i]<<endl;
				
			}

			else if(words[i][j]=='{ }')
					{
					cout<<"COMENTARIO "<<words[i]<<endl;
					bandera=false;
				}
			
			else if(((words[i][j]==39)&&((words[i][(words[i].length())-1]==39))))
			{
					if((words[i][j+1]>=97 && words[i][j+1]<=122)||(words[i][j+1]>=65&& words[i][j+1]<=90)|| words[i+1][j+1]==' ')
					{
						cout<<"CARACTER "<<words[i]<<endl;	
						
					}
					
					else{
						cout<<"NO CARACTER "<<words[i]<<endl;
					}
				}
			
			if((words[i][j]>=48 && words[i][j]<=57)&&(words[i][j+1]=='e')&&(words[i][j+2]>=48 && words[i][j+2]<=57))
			{
				cout<<"NUMERO EXPONENCIAL "<<words[i]<<endl;
				break;
				
			}
			
			if((words[i][j]>=48 && words[i][j]<=57) and !((words[i][j+1]!='.')and(words[i][j+2]>=48 && words[i][j+2]<=57)))
			{
				cout<<"NUMERO DECIMAL "<<words[i]<<endl;
				
				break;
				
			}
			else if((words[i][j]>47 && words[i][j]<58) and ((words[i][j+1]!='.')and (words[i][j+2]>=48 && words[i][j+2]<=57)))
			{
				cout<<"NUMERO ENTERO "<<words[i]<<endl;
				break;
				
			}
			
			else if(bandera and((words[i]!="and"&&words[i]!="or"&&words[i]!="not"&&words[i]!="div"&&words[i]!="mod"
								 &&words[i]!="in"&&words[i]!="array"
					  &&words[i]!="downto"&&words[i]!="function"&&words[i]!="of"&&words[i]!="repeat"
					  &&words[i]!="until"&&words[i]!="begin"&&words[i]!="else"&&words[i]!="goto"&&words[i]!="packed"
					  &&words[i]!="set"&&words[i]!="val(1..8)"&&words[i]!="var"&&words[i]!="case"&&words[i]!="end"
								 &&words[i]!="if"&&words[i]!="procedure"
					  &&words[i]!="then"&&words[i]!="reserved"&&words[i]!="words"&&words[i]!="operators"
								 &&words[i]!="while"&&words[i]!="const"
					  &&words[i]!="file"&&words[i]!="label"&&words[i]!="program"&&words[i]!="toktype(1)"
								 &&words[i]!="can"&&words[i]!="unsigned"&&words[i]!="val"
					  &&words[i]!="toktype(1),"&&words[i]!="val"&&words[i]!="point"&&words[i]!="floating"
								 &&words[i]!="range"&&words[i]!="val"
					  &&words[i]!="delimers"&&words[i]!="to"&&words[i]!="with"&&words[i]!="do"&&words[i]!="for"
								 &&words[i]!="nil"&&words[i]!="record"&&words[i]!="type"))
				and((words[i][j]>=97 && words[i][j]<=122)||(words[i][j]>=65 && words[i][j]<=90))and(words[i+1][j]!='{')
					and(words[i+2][j]!='{')
				and(words[i][j+1]!=')')and(words[i][j+1]!='(')){
				if(((words[i][j+1]>=97&&words[i][j+1]<=122)||(words[i][j+1]>=65&&words[i][j+1]<=90))
					||(words[i][j+1]>=48&&words[i][j+1]<=57)){
					if((words[i][j+2]!=')' and words[i][j+2]!='(' and words[i][j+2]!='{' and words[i][j+2]!='}')
						and (words[i][j]==39 and words[i+1][j+1]==39)){
						cout<<"IDENTIFICADOR "<<words[i]<<endl;
						break;
					}
					
				}
			}
			
		}
		
	}	
	return EXIT_SUCCESS;
}
	
