#include <iostream>
#include <memory>
#include <string>

class Document{
public: 
    virtual void display() const = 0;
    virtual ~Document() = default;
};

class RealDocument : public Document{
public: 
    RealDocument(const std::string& filename) : filename_(filename) {
        std::cout << "[Downloading document: " << filename_ << "]" << std::endl;
    }

    void display() const override{
        std::cout << "Showing the document: " << filename_ << "]" << std::endl;
    }

private:
    std::string filename_;
};

class DocumentProxy : public Document{
public: 
    DocumentProxy(const std::string& filename) : filename_(filename) {}

    void display() const override{
        if(!realDoc){
            realDoc = std::make_unique<RealDocument>(filename_);
        }

        realDoc->display();
    }

private: 
    mutable std::unique_ptr<RealDocument> realDoc;
    std::string filename_;
};


int main(){
    std::unique_ptr<Document> doc = std::make_unique<DocumentProxy>("report.pdf");

    std::cout << "Doc created. Not showing now." << std::endl;

    doc->display();
    doc->display();
}