#include <iostream>
#include <memory>

class IPrinter{
public: 
    virtual ~IPrinter() = default;
    virtual void print() const = 0;
};

class OldPrinter{
public: 
    void legacyPrint() const{
        std::cout << "Print from legacy printer" << std::endl;
    }
};

class PrinterAdapter : public IPrinter{
private: 
    std::shared_ptr<OldPrinter> adaptee;

public: 
    PrinterAdapter(std::shared_ptr<OldPrinter> old) : adaptee(std::move(old)) {}

    void print() const override{
        adaptee->legacyPrint();
    }
};

void printDocument(const IPrinter& printer){
    printer.print();
}

int main(){
    std::shared_ptr<OldPrinter> legacy = std::make_shared<OldPrinter>();
    PrinterAdapter adapter(legacy);

    printDocument(adapter);
}