#!/usr/bin/env python

# Raspberry PI PIR detector python cgi script
# Gilles Lasnier <gilles.lasnier@gmail.com>

import cgi
import cgitb
import sys
import subprocess as sub

# print the HTTP header
def printHTTPheader():
    print "Content-type: text/html\n\n"


# print the HTML head section
# arguments is the page title
def printHTMLHead(title):
    print "<head>"
    print " <title>"
    print title
    print " </title>"
    print "</head>"


# return the value of the option passed to the script                           
def getOption(opt):
    form=cgi.FieldStorage()
    if str(opt) in form:
        return form[str(opt)].value
    else:
        return None


# return True if the file exist
def isFilePresent(pidfile):
    try:
        fileobj = open(pidfile,'r')
        fileobj.close()
        return True
    except:
        return False


# returns the command result 
def exec_syscmd(str_command):
    p = sub.Popen(['/bin/bash', '-c', str_command], stdout=sub.PIPE, stderr=sub.STDOUT)
    return p.stdout.read()


# main function
# This is where the program starts
def main():

    # get pir-sensor-app status, launched if True
    launchedapp = isFilePresent("/var/run/pir-sensor-app.pid")

    # get pir kernel module status
    kmodule = exec_syscmd("lsmod | grep pir_sensor")
    if str(kmodule) == "":
        pirmod = "disabled"
    else:
        pirmod = "enabled"

    # get option
    action = getOption("activate")
    if action == "enable" and not launchedapp and pirmod == "enabled":
        exec_syscmd("sudo service pirsensord start")

    if action == "disable" and launchedapp and pirmod == "enabled":
        exec_syscmd("sudo service pirsensord stop")

    # recheck if pir-sensor-app status
    launchedapp = isFilePresent("/var/run/pir-sensor-app.pid")
    if launchedapp:
        pidapp = exec_syscmd("cat /var/run/pir-sensor-app.pid")

    cgitb.enable()

    # print the HTTP header
    printHTTPheader()

    # start printing the page
    print "<html>"
    
    printHTMLHead("Raspberry Pi PIR Sensor")

    # print the page body
    print "<body>"
    print "<h1>Raspberry Pi PIR Sensor</h1>"

    if launchedapp:
        print "<p> pir sensor daemon status=%s pid=%d </p>" % (str(launchedapp), int(pidapp))
    else:
        print "<p> pir sensor daemon status=not launched </p>"

    print "<p> pir sensor module status=%s </p>" % str(pirmod)
    print "</body>"
    print "</html>"

    sys.stdout.flush()

if __name__=="__main__":
    main()
