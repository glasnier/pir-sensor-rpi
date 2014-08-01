pir-app
=======

* This code is released under the GNU General Public License.
* Developed by Gilles Lasnier
* Created 23th July  2014


Description
===========

Linux user application for dealing with the Passive InfRared (PIR) sensor.
This application uses the pir-sensor linux kernel module which allows 
blocking on read().

The application sends an email if the PIR sensor has been triggered. 


Hardware dependencies
=====================

- Raspberry Pi Model B
- HC-SR501 PIR Motion Sensor from the Raspberry Pi YouTube Workshop Kit


Software dependencies
=====================

- pir-module-rpi: the PIR sensor character device driver
- packages: mailutils, ssmtp and mpack


