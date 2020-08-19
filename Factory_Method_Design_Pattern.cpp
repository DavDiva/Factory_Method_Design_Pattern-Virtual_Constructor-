// Factory_Method_Design_Pattern.cpp 

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

    virtual Document* createWordDocument() = 0;
    virtual Document* createExcelDocument() = 0;

    virtual void removeDocument(Document* doc) = 0;

   
};

/*
 * Concrete Creator
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the products
 */
class MyApplication : public Application
{
public:
    ~MyApplication() {}
    
    Document* createWordDocument()
    {
        return new WordDocument();
    }

    Document* createExcelDocument()
    {
        return new ExcelDocument();
    }

    void removeDocument(Document* doc)
    {
        std::cout << "Document is removed" << std::endl;
        delete doc;
    }
    
};


int main()
{
    Application* application = new MyApplication();

    Document* doc1 = application->createWordDocument();
    std::cout << "Document: " << doc1->open() << std::endl;
    application->removeDocument(doc1);

    Document* doc2 = application->createExcelDocument();
    std::cout << "Document: " << doc2->open() << std::endl;
    application->removeDocument(doc2);

    
    delete application;
    return 0;
}