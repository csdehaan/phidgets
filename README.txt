= phidgets

* http://phidgets.rubyforge.org

== DESCRIPTION:

Phidgets are a set of "plug and play" building blocks for low cost USB sensing and control from your PC.
This gem provides a ruby interface to the phidgets library.

== FEATURES/PROBLEMS:

* This gem uses DL to call the c functions in the Phidgets shared library, so the library must be installed and working.
* The gem has been tested to work on both Linux and Windows.
* Not all the devices have been implemented, and not all of the devices that have been implemented have been fully tested.
* The gem will attempt to guess the name of the phidgets library based on the platform it is run on (Linux, Windows or OS X).
  If it guesses incorrectly please leave a message to let me know what your platform sets for Config::CONFIG['target_os'] and
  what is the name of the phidgets library.

== SYNOPSIS:

  require 'phidgets'

  begin
    ik = Phidgets::InterfaceKit.new(-1,2000)

    puts "Device Name     = #{ik.getDeviceName}"
    puts "Serial Number   = #{ik.getSerialNumber}"
    puts "Device Version  = #{ik.getDeviceVersion}"

    ik.close

  rescue Phidgets::Exception => e
    puts "Phidgets Error (#{e.code}). #{e}"
  end


  The gem now installs a command line program that will list all phidgets devices that are attached, as well as allowing any
  valid method for a given phidget type to be called. For example:
  
  To list all phidgets attached to the local computer:
    => phidget list
       ----------------------------------------------------------------------
       | SerialNumber          | Device Name                                |
       ----------------------------------------------------------------------
       | 73723                 | Phidget InterfaceKit 0/0/8                 |
       | 88103                 | Phidget InterfaceKit 0/0/4                 |
       ----------------------------------------------------------------------

  To list all phidgets attached to a remote computer:
    => phidget 192.168.100.67 list
       ----------------------------------------------------------------------
       | SerialNumber          | Device Name                                |
       ----------------------------------------------------------------------
       | 73782                 | Phidget InterfaceKit 0/0/8                 |
       ----------------------------------------------------------------------

  To call a method for a specific local phidget:
    => phidget 73723 setOutputState 0 1
    
  To call a method for a specific remote phidget:
    => phidget 192.168.100.67:73782 setOuputState 2 0

== REQUIREMENTS:

* The Phidgets library (http://www.phidgets.com/)

== INSTALL:

* sudo gem install phidgets

== LICENSE:

Copyright (C) 2009  Craig DeHaan

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
