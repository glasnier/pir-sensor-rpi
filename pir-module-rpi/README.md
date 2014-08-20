pir-module-rpi
==============

* This code is released under the GNU General Public License.
* Developed by Gilles Lasnier
* Created 23th July  2014


Description
===========

Simple linux kernel module for dealing with the Passive InfRared (PIR) sensor.
This module is implemented as a character device driver and allows a process
to be blocked on read().


Deployment
==========

If you want to use the default configuration (GPIO Pin 18), run the command:

sudo insmod pir-sensor.ko

else, you can set the GPIO Pin by using the 'gpio_trigger' parameter, as:

sudo insmod pir-sensor.ko gpio_trigger=18


Hardware dependencies
=====================

- Raspberry Pi Model B
- HC-SR501 PIR Motion Sensor from the Raspberry Pi YouTube Workshop Kit


References
==========

This implementation is inspired from two posts of Christophe Blaess blog:
- http://www.blaess.fr/christophe/2014/01/22/gpio-du-raspberry-pi-mesure-de-frequence/
- http://www.blaess.fr/christophe/2014/07/22/ajouter-un-module-noyau-personnel-dans-buildroot/ (driver rotation-sensor-module)


