#ifndef SUBJECT_H
#define SUBJECT_H


class Subject {
public:
    virtual ~Subject(){}
    virtual void notify()= 0;
    virtual void attach() = 0;
    virtual void detach() = 0;
};

#endif // SUBJECT_H
