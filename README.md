pir-sensor-rpi
==============

* This code is released under the GNU General Public License.
* Developed by Gilles Lasnier
* Created 23th July  2014


Description
===========

Linux kernel module for dealing with the Passive InfRared (PIR) sensor.
This module is implemented as a character device driver and allows a process
to be blocked on read().


Folders
=======

- pir-app-rpi   : the user application to send a mail and take a picture when 
                  the PIR is triggered
- pir-module-rpi: the linux kernel driver for the PIR
- cgi-bin       : the web-server python application
- daemon        : the daemon to start/stop the application
