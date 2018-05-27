#ifndef SINGLETON_H
#define SINGLETON_H


template <class T> class Singleton
{
private:
    struct Handler
    {
        T* instanceUnique;
        Handler():instanceUnique(nullptr) {}
        ~Handler(){delete instanceUnique;}
    };
    Singleton(){}
    ~Singleton(){}

protected:
    static Handler* handler;


public:
    static T& getInstance();


};

#endif // SINGLETON_H
