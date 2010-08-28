/* SysHost Module for the SmoothWall SUIDaemon                           */
/* For setting the system time                                              */
/* (c) 2010 SmoothWall Ltd                                                */
/* ----------------------------------------------------------------------  */
/* Original Author  : Lawrence Manning                                     */
/* Translated to C++: M. W. Houston                                        */
/* Butchered beyond all recognition by:  Thomas Adam
 */

/* include the usual headers.  iostream gives access to stderr (cerr)     */
/* module.h includes vectors and strings which are important              */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <syslog.h>
#include <signal.h>

#include "module.h"
#include "ipbatch.h"
#include "setuid.h"

extern "C" {
	int load(std::vector<CommandFunctionPair> & );
	int set_host(std::vector<std::string> & parameters, std::string & response);
}

int load(std::vector<CommandFunctionPair> & pairs)
{
	/* CommandFunctionPair name("command", "function"); */
	CommandFunctionPair set_host("sethost", "set_host", 0, 0);
	
	pairs.push_back(set_host);

	return (0);
}

int set_host(std::vector<std::string> & parameters, std::string & response)
{
	int error = 0;
    const char* cmd = "/usr/share/swe3/bin/writehosts.pl";

	error = simplesecuresysteml(cmd);

	if (error)
		response = "Writing hosts file failed";
	else
		response = "Hosts file written out to disk correctly.";

	return error;
}
