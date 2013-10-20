require 'mkmf'

HEADER_DIRS = [ '/Library/Frameworks/Phidget21.framework/Headers' ]

find_header 'phidget21.h', *HEADER_DIRS
find_library 'libphidget21', 'CPhidget_getLibraryVersion', '/usr/lib/'
have_framework('Phidget21') unless RUBY_VERSION < '1.9.0' 
have_library('phidget21') 
dir_config("phidgets")

$CFLAGS += ' -DPH_CALLBACK' unless RUBY_VERSION < '1.9.0'

create_makefile("phidgets")

