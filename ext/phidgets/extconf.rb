require 'mkmf'

HEADER_DIRS = [ '/Library/Frameworks/Phidget22.framework/Headers' ]

find_header 'phidget22.h', *HEADER_DIRS
find_library 'phidget22', 'Phidget_getLibraryVersion', '/usr/lib/'
have_framework('Phidget22')
have_library('phidget22')
dir_config("phidgets")

have_header('ruby/thread.h')
have_func('rb_thread_blocking_region')
have_func('rb_thread_call_without_gvl')

create_makefile("phidgets")

