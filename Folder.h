#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <set>
#include "Message.h"

class Folder{
    friend class Message;
public:
    explicit Folder(const std::string &str = ""): name(str) {}
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void addMsg(const Message&);
    void remMsg(const Message&);

private:
    std::string name;
    std::set<Message*> megs;
    // Folder 类拷贝的工具
    void add_to_Msgs(const Folder&);
    void remove_from_Msgs();
};

#endif