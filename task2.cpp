/*
  Нужно отказаться от перечисления и использовать другие конструкции, которые позволяют 
  в последствии легче масштабировать проект. 
  В данном случае выбран путь использование класса-интерфейса iLanguage от которого потом 
  наследуются классы, реализующие необходимые нам языки программирования.
*/
#include <iostream>

class iLanguage
{
public:
	virtual ~iLanguage(){}
	
	virtual std::string generateCode() = 0;
	virtual std::string someCodeRelatedThing() = 0;
	
};

class Cpp_Lang: public iLanguage
{
public:
	Cpp_Lang() {std::cout << "Cpp_Lang object created" << std::endl;}
	
	virtual std::string generateCode()
	{
		std::string ret("return");
		std::cout << "C++ generateCode!" << std::endl;

		return ret;
	}
	
	virtual std::string someCodeRelatedThing()
	{
		std::string ret("return");
		std::cout << "C++ someCodeRelatedThing!" << std::endl;

		return ret;
	}
	
};

class Java_Lang: public iLanguage
{
public:
	Java_Lang() {std::cout << "Java_Lang object created" << std::endl;}
	
	virtual std::string generateCode()
	{
		std::string ret("return");
		std::cout << "Java generateCode!" << std::endl;

		return ret;
	}
	
	virtual std::string someCodeRelatedThing()
	{
		std::string ret("return");
		std::cout << "Java someCodeRelatedThing!" << std::endl;

		return ret;
	}
};

class CodeGenerator
{
public:
  CodeGenerator(){std::cout << "CodeGenerator created!" << std::endl;};
  ~CodeGenerator(){};

  void doLanguageFeature(iLanguage *obj)
  {
    obj->generateCode();
    obj->someCodeRelatedThing();
  }

};

int main()
{
	CodeGenerator *cg = new CodeGenerator();

	iLanguage *cppLang = new Cpp_Lang();
	cg->doLanguageFeature(cppLang);
	
	iLanguage *javaLang = new Java_Lang();
	cg->doLanguageFeature(javaLang);
	
	return 0;
}
