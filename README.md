pir-sensor-rpi
==============

* This code is released under the GNU General Public License.
* Developed by Gilles Lasnier
* Created 23th July  2014


Description
===========

A simple application to set up a PIR sensor detection system on the Raspberry Pi.
The application can take a picture and send an email is the PIR has been triggered.


Folders
=======

- pir-app-rpi   : the user application to send a mail and take a picture when 
                  the PIR is triggered
- pir-module-rpi: the linux kernel driver for the PIR (GPIO 18 set by default)
- cgi-bin       : the web-server python application
- daemon        : the daemon to start/stop the application
