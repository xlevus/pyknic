#include <iostream>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
using boost::static_pointer_cast;

#include<string>
using std::string;

#include  <boost/python.hpp>
using namespace boost::python;

#include "Pyknic/examples/examples.h"
#include "extract.h"

template < class T >
class PyHolder {
    private:
        object *pyObj;
        T *cObj;

    public:
        PyHolder(const char *pyModule, const char *pyClass)
        {
            object module = import(pyModule);
            pyObj = new object(module.attr(pyClass)());
            this->cObj = extract<T*>(*this->pyObj);
        }

        ~PyHolder() { delete pyObj; }

        T *ptr() { return cObj; }
};

int main(int argc, char*argv[])
{
    Py_Initialize();
    std::cout << std::endl << "---" << std::endl;

    /* // Most basic method
    object module = import("Pyknic.examples");
    object b1 = module.attr("Base")();
    Pyknic::Base &B1 = extract<Pyknic::Base&>(b1);
    */

    // Also works, slightly less dumb
    shared_ptr< PyHolder<Pyknic::Base>  > ph( new PyHolder<Pyknic::Base>("Pyknic.examples", "Base2") );
    std::cout << ph->ptr()->f(); //) << std::endl << ph->obj_ptr()->attr("f")();

    object t = object(ph->ptr());
    t.attr("f");

    std::cout << std::endl << "---" << std::endl;
	return 0;
}
