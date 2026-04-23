#include "Teacher.h"

void Teacher::freeSubjects()
{
    for (size_t i = 0; i < subjectsCount; i++)
    {
        delete[] subjects[i];
        subjects[i] = nullptr;
    }

    delete[] subjects;
    subjects = nullptr;
    subjectsCount = 0;
}

void Teacher::free()
{
    freeSubjects();
}

void Teacher::copy(const Teacher& other)
{
    setSubjects(other.subjects, other.subjectsCount);
}

void Teacher::move(Teacher&& other)
{
    subjects = other.subjects;
    subjectsCount = other.subjectsCount;
    other.subjects = nullptr;
}

void Teacher::print(std::ostream& os) const
{
    Person::print(os);

    for (size_t i = 0; i < subjectsCount; i++)
    {
        os << " " << subjects[i];
    }
}

Teacher::Teacher(const char* name, unsigned age, const char* const* subjects, unsigned count)
    : Person(name, age)
{
    std::cout << "Const Teacher" << std::endl;
    setSubjects(subjects, count);
}

Teacher::Teacher(const Teacher& other) : Person(other)
{
    std::cout << "Copy Teacher" << std::endl;
    copy(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
    std::cout << "op= Teacher" << std::endl;
    if (this != &other)
    {
        Person::operator=(other);

        free();
        copy(other);
    }

    return *this;
}

Teacher::Teacher(Teacher&& other) : Person(std::move(other))
{
    std::cout << "Move Teacher" << std::endl;
    move(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other)
{
    std::cout << "Move op= Teacher" << std::endl;
    if (this != &other)
    {
        Person::operator=(std::move(other));
        free();
        move(std::move(other));
    }

    return *this;
}

Teacher::~Teacher()
{
    std::cout << "Dest Teacher" << std::endl;
    free();
}

unsigned Teacher::getSubjectsCount() const
{
    return subjectsCount;
}

const char* const* Teacher::getSubjects() const
{
    return subjects;
}

void Teacher::setSubjects(const char* const* subjects, unsigned count)
{
    if (this->subjects == subjects || subjects == nullptr)
        return;

    freeSubjects();

    this->subjects = new char* [count];

    for (size_t i = 0; i < count; i++)
    {
        this->subjects[i] = new char[strlen(subjects[i]) + 1];
        strcpy(this->subjects[i], subjects[i]);
    }
    subjectsCount = count;
}

std::ostream& operator<<(std::ostream& os, const Teacher& t)
{
    t.print(os);
    os << std::endl;
    return os;
}
