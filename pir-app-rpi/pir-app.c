/*
 * PIR sensor application.
 *
 * (c) 2014 Gilles Lasnier <gilles.lasnier@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define FILE_DEVICE    "/dev/pir_sensor"  /* Char device driver file. */


int main(int argc, char *argv[])
{
  char buf[16];
  char command[120];
  int fp, mailnb, sdmail, gpict;

  /* Init variables. */    
  sdmail = 0;
  gpict = 0;

  /* Command line arguments. */
  while ((argc > 1) && (argv[1][0] == '-'))
    {
      switch (argv[1][1])
	{
	case 's':
	  sdmail = 1;
	  break;

	case 'p':
	  gpict = 1;
	  break;

	default:
	  printf("Wrong Argument: %s\n", argv[1]);
	}

      ++argv;
      --argc;
    }
  
  /* Mail counter for debug. */
  mailnb = 0;

  /* Clear buffer. */
  memset(buf, 0, 16);

  /* Open char device driver. */
  fp = open(FILE_DEVICE, O_RDONLY);
  if (fp < 0) {
    perror("pir-sensor-app: open() pir-sensor driver failed: reason ");
    exit (-1);
  }

  /* Infinite loop, the process will sleep if there is nothing to read. */
  while(1) {
    if (read(fp, buf, 16) < 0) {
      perror("pir-sensor-app: read() pir-sensor driver failed: reason ");
      exit (-1);
    }

    /* Dummy print for debug. */
    /* printf("pir-sensor-app: value read =%s", buf); */

    /* Send mail if option is set. */
    if (sdmail) {

      /* Mail system command. */
      strcpy(command, 
	     "echo \"<your_message>\" | mail -s \"<your_mail_head>\" <your.mail@yourmail.com");

      if (system(command) < 0) {
	fprintf(stderr, "pir-sensor-app: system() failed to send mail");
	exit (-1);
      }
      
      mailnb++;

      /* Dummy print for debug. */
      /* printf("pir-sensor-app: mail number %d sent.\n", mailnb); */
    }

    if (gpict) {
      /* Pi camera command. */
      strcpy(command, "sudo raspistill -h 680 -w 1024 -q 100 -o /var/www/picture.jpg");
      
      if (system(command) < 0) {
        fprintf(stderr, "pir-sensor-app: system() failed to take picture.");
        exit (-1);
      }

    }
    /* Clear buffer. */
    memset(buf, 0, 16);
  }

  return 0;
}
