from _examples import *

class Base2(Base):
    def f(self):
        return 2

class Base3(Base):
    def f(self):
        return super(Base3, self).f()*3
