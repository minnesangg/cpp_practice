#include <iostream>
#include <memory>
#include <vector>
#include <string>


class FileSystemComponent{
public: 
    virtual void display(int indent = 0) const = 0;
    virtual ~FileSystemComponent() = default;
};

class File : public FileSystemComponent{
    std::string name;

public: 
    explicit File(std::string n) : name(std::move(n)) {}

    void display(int indent = 0) const override{
        std::cout << std::string(indent, ' ') << "- " << name << std::endl;
    }
};

class Directory : public FileSystemComponent{
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public: 
    explicit Directory(std::string n) : name(std::move(n)) {}

    void add(const std::shared_ptr<FileSystemComponent>& component){
        children.push_back(component);
    }

    void display(int indent = 0) const override{
        std::cout << std::string(indent, ' ') << "+ " << name << std::endl;

        for(const auto& child : children){
            child->display(indent + 2);
        }
    }
};


int main(){
    auto root = std::make_shared<Directory>("root");
    auto bin = std::make_shared<Directory>("bin");
    auto usr = std::make_shared<Directory>("usr");

    bin->add(std::make_shared<File>("bash"));
    bin->add(std::make_shared<File>("ls"));

    usr->add(std::make_shared<File>("readme.txt"));

    root->add(bin);
    root->add(usr);
    root->add(std::make_shared<File>("system.log"));

    root->display();
}