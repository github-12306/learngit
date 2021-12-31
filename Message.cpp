#include "Message.h"
#include "Folder.h"

void Message::save(Folder &f){
    folders.insert(&f);
    f.addMsg(*this);
}

void Message::remove(Folder &f){
    folders.erase(&f);
    f.remMsg(*this);
}

void Message::add_to_Folders(const Message &m){
    for(auto f: m.folders){
        f->addMsg(*this);
    }
}

void Message::remove_from_Folders(){
    for(auto f: folders){
        f->remMsg(*this);
    }
}

// 拷贝构造函数
Message::Message(const Message& m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

// 析构函数
Message::~Message(){
    remove_from_Folders();
}

// 拷贝赋值运算符，需要执行拷贝构造函数和析构函数的工作
Message& Message::operator=(const Message& rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}