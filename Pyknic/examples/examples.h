#include <string>
#include <iostream>

namespace Pyknic {
	class Base {
		public:
			virtual int f() { return 0; };

            virtual ~Base() { std::cout << "Base died" << std::endl; };
	};

	class World {
		public:
			World(const std::string &country);
			std::string greet() const;
		private:
			std::string country;
	};
};
