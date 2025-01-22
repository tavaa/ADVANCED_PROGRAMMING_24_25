/*
* Abstract base class Music Entity
*/

#ifndef MUSICENTITY_HPP
#define MUSICENTITY_HPP

#include <string>

class MusicEntity {

    public:

        // Constructor
        MusicEntity(int id, const std::string& name) : id(id), name(name) {}
        
        // getters for name and Id
        int getId() const { return id; }
        std::string getName() const { return name; }

        // pure virtual methods
        virtual void printDetails() const = 0;
        virtual int getDuration() const = 0;

        // virtual destructor
        virtual ~MusicEntity() = default;

    protected:

        int id;
        std::string name;
};

#endif // MUSICENTITY_HPP
