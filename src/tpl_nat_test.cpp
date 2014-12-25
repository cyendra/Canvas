
#include "../include/tpl.h"
#include "../include/unittest.h"
#include "../include/tpl/debug.h"

#include <typeinfo>
#include <iostream>
using namespace std;

using namespace tpl::nat;
using namespace tpl::nat::relation;
using namespace tpl::list;
using namespace tpl::list::util;
using namespace tpl::list::iter;

template<class Num>
struct addone{
    using value = succ<Num>;
};


class A;


TestCase(TPL_THE_TEMPLATE_PROGRAMMING_LIBRARY){
    /// equal


    AssertAll<
            is_equal<one, one>::value,
            is_equal<one, two::pred>::value,
            is_equal<succ<one>, two>::value
        >();

    /// add mul
    AssertAll<
            is_equal<add<one, two>::value, three>::value,
            is_equal<mul<five, two>::value, ten>::value
        >();

    /// less_than
    AssertAll<
            is_less_than<mul<two,three>::value, add<two,five>::value>::value,
            is_less_equal<mul<two, three>::value, add<one, five>::value>::value
        >();
    /// decimal
    cout<<typeid(is_equal<decimal<one,one>::value,add<one,ten>::value>::value).name()<<endl;
    cout<<typeid(is_equal<decimal<one,zero,zero>::value, mul<ten,ten>::value>::value).name() << endl;

    cout<<typeid(is_equal<sub<three,one>::value, two>::value).name() << endl;
    cout<<typeid(is_equal<sub<zero,zero>::value, zero>::value).name() << endl;

    ///  10 / 3 == 3 ... 1
    cout<<typeid(eq<div<i2,i1>::value,i2>::value).name()<<endl;
    cout<<typeid(eq<div<i10,i3>::value,i3>::value).name()<<endl;
    cout<<typeid(eq<div<i10,i3>::rem,i1>::value).name()<<endl;

    ///  10 / 100 == 0 ... 10
    cout<<typeid(eq<div<i10,i100>::value,i0>::value).name()<<endl;
    cout<<typeid(eq<div<i10,i100>::rem,i10>::value).name()<<endl;

    /// length / first / rest / concat
    cout<<typeid(eq<typename list<i1,i2,i3>::length, three>::value).name() <<endl;
    cout<<typeid(eq<typename list<i1,i2,i3>::value::rest::rest::first, three>::value).name() <<endl;
    cout<<typeid(eq<typename list<i1,i2,i3>::value, concat<list<i1,i2,i3>::value,nil>::value>::value).name() <<endl;
    cout<<typeid(eq<
                        typename list<i1,i2,i5,i6>::length,
                        concat<
                                list<i1,i2,i5,i6>::value,
                                nil
                            >::length
                    >::value).name() <<endl;

    /// take
    cout<<typeid(eq<typename list<i1,i2,i3>::value, take<i3,list<i1,i2,i3,i4>::value>::value>::value).name() <<endl;
    cout<<typeid(eq<typename list<i1,i2,i3>::length, take<i3,list<i1,i2,i4,i3>::value>::length>::value).name() <<endl;

    /// map
    cout<<typeid(eq<
                        typename list<i2,i3,i4>::value,
                        map<addone, typename list<i1,i2,i3>::value >::value
                    >::value).name() <<endl;
    /// fold_left
    cout<<typeid(eq<
                        typename fold_left<add, i0, typename list<i1,i2,i3,i4>::value> :: value,
                        i10
                 >::value).name()<<endl;
    cout<<typeid(eq<
                        typename fold_left<mul, i1, typename list<i1,i2,i3,i4>::value> :: value,
                        typename mul<i8, i3>::value
                 >::value).name()<<endl;
    cout<<typeid(eq<
                        typename fold_left<operators::max, i1, typename list<i1,i2,i3,i4>::value> :: value,
                        i4
                 >::value).name()<<endl;
    cout<<typeid(eq<
                        typename fold_left<operators::min, i1, typename list<i0,i2,i3,i4>::value> :: value,
                        i0
                 >::value).name()<<endl;
}
