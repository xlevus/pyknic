#include  <boost/python.hpp>
using namespace boost::python;

#include "examples.h"
using namespace Pyknic;

World::World(const std::string &country) {
	this->country = country;
}

std::string World::greet() const {
	return "Hello from " + country;
}
