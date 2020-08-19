// Factory_Method(Virtual_Constructor)_Design_Pattern.cpp 

#include <iostream>
#include <string>

/*
 * Product
 * products implement the same interface so that the classes can refer
 * to the interface not the concrete product
 */
class Document
{
public:
    virtual ~Document() {}

    virtual std::string open() = 0;
    
};

/*
 * Concrete Product
 * define product to be created
 */
class WordDocument : public Document
{
public:
    ~WordDocument() {}

    std::string open()
    {
        return "WordDocument is opened";
    }
    
};

/*
 * Concrete Product
 * define product to be created
 */
class ExcelDocument : public Document
{
public:
    ~ExcelDocument() {}

    std::string open()
    {
        return "ExcelDocument is opened";
    }
   
};

/*
 * Creator
 * contains the implementation for all of the methods
 * to manipulate products except for the factory method
 */
class Application
{
public:
    virtual ~Application() {}

    virtual Document* createDocument() = 0;
    virtual void removeDocument(Document* doc) = 0;

   
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class WordApplication : public Application
{
public:
    ~WordApplication() {}
    
    Document* createDocument()
    {
        return new WordDocument();
    }

    void removeDocument(Document* doc)
    {
        std::cout << "Word Document is removed" << std::endl;
        delete doc;
    }
    
};

class ExcelApplication : public Application
{
public:
    ~ExcelApplication() {}

  
    Document* createDocument()
    {
        return new ExcelDocument();
    }

    void removeDocument(Document* doc)
    {
        std::cout << "Excel Document is removed" << std::endl;
        delete doc;
    }

};


int main()
{
    Application* application1 = new WordApplication();

    Document* doc1 = application1->createDocument();
    std::cout << "Document: " << doc1->open() << std::endl;
    application1->removeDocument(doc1);

    Application* application2 = new ExcelApplication();

    Document* doc2 = application2->createDocument();
    std::cout << "Document: " << doc2->open() << std::endl;
    application2->removeDocument(doc2);

    
    delete application1;
    delete application2;
    return 0;
}