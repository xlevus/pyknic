#include <boost/python/extract.hpp>
using namespace boost::python;

namespace Pyknic {
    
    template < class T >
    struct extract : converter::select_extract<T>::type
    {
        private:
            typedef typename converter::select_extract<T>::type base;
            object o;
        public:
            typedef typename base::result_type result_type;

            operator result_type() const {
                return (*this)();
            }

            extract(const char *pyModule, const char *pyClass);
    };

    template <class T>
    inline extract<T>::extract(const char *pyModule, const char *pyClass)
        //: base(o.ptr())
    {
        object module = import(pyModule);
        this->o = module.attr(pyClass)();
        base::base(o.ptr());
    }

};
