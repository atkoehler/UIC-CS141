#pragma once

#include <string>

using namespace std;

class Person
{
    private:
        string first;
        string last;
    public:
        Person(const string &f, const string &l)
        {
            first = f;
            last = l;
        }

        string getName() const
        {
            return first + " " + last;
        }
};

class Connection
{
    private:
        Person *prime;
        Connection* nxt;

    public:
        Connection(Person* prime)
        {
            this->prime = prime;
            nxt = nullptr;
        }

        Connection(const string &f, const string &l)
        {
            prime = new Person(f, l);
            nxt = nullptr;
        }

        virtual ~Connection()
        {
            delete prime;
        }

        Connection* next() const
        {
            return nxt;
        }
        void setNext(Connection *nxt)
        {
            this->nxt = nxt;
        }

        Person* getPerson() const
        {
            return prime;
        }
        void setPerson(const string &f, const string &l)
        {
            delete prime;
            prime = new Person(f, l);
        }

        string toString() const
        {
            return prime->getName();
        }
};


class ConnectionPath
{
    private:
        Connection* start;
        Connection* end;
    
    public:
        ConnectionPath();
        virtual ~ConnectionPath();

        Connection* getStart() const;
        int length() const;

        void printPath() const;
        void printConAddresses() const;

        void addBack(Connection* toAdd);
        void deleteFront();       
};