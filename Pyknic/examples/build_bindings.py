
import os
from pyplusplus import module_builder

#Creating an instance of class that will help you to expose your declarations
mb = module_builder.module_builder_t( [r"/home/xin/code/pyknic/Pyknic/examples/examples.h"]
                                      , gccxml_path=r"" 
                                      , working_directory=r"/home/xin/code/pyknic/Pyknic/examples"
                                      , include_paths=['/home/xin/code/pyknic/Pyknic/examples']
                                      , define_symbols=[] )

#Creating code creator. After this step you should not modify/customize declarations.
mb.build_code_creator( module_name='_examples' )

#Writing code to file.
mb.write_module( './bindings.cpp' )
