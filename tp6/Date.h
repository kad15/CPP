#ifndef DATE_H
#define DATE_H
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <iostream>

using namespace std;

class Date
{
    int jour,mois,annee;

    friend class boost::serialization::access;

    template <class Archive>

    void serialize(Archive & ar, const unsigned int version){

    ar & jour;
    ar & mois;
    ar & annee;

    }

    friend istream& operator>>(istream& i, Date&  d);

public:
    Date();

    Date(int,int,int);

    int comparer(const Date&) const ;

    int operator <(const Date& d) const;

    Date& operator++() ;

    void affiche() const ;

    virtual ~Date();
};

ostream& operator<<(ostream& o, const Date& d);
ostream& operator<<(ostream& o, const Date* d);

#endif // DATE_H
