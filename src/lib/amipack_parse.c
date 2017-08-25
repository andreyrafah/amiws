/* Generated by re2c 0.15.3 */
#line 1 "src/lib/amipack_parse.re"
/**
 * amiws -- Library with functions for read/create AMI packets
 * Copyright (C) 2016, Stas Kobzar <staskobzar@modulis.ca>
 *
 * This file is part of amiws.
 *
 * amiws is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * amiws is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with amiws.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file amipack_parse.c
 * @brief AMI (Asterisk Management Interface) packet parser.
 *
 * @author Stas Kobzar <stas.kobzar@modulis.ca>
 */

#include <stdio.h>
#include <string.h>
#include "amipack.h"

/**
 * Commands to run when known header parsed.
 * @param name    Header type
 */
#define SET_HEADER(name)  len = cur - tok; \
                          hdr_name = strdup(name); \
                          goto yyc_key;

/**
 * Commands to run on Command AMI response header.
 * @param offset  Header name offset
 * @param name    Header type
 */
#define CMD_HEADER(offset, name) len = cur - tok - offset; tok += offset; \
                          while(*tok == ' ') { tok++; len--; } \
                          len -= 2; \
                          char *val = strndup(tok, len); \
                          amipack_append (pack, strdup(name), strlen(name), val, len); \
                          tok = cur; goto yyc_command;

// introducing types:re2c for AMI packet
/*! re2c parcing conditions. */
enum yycond_pack {
  yyckey,
  yycvalue,
  yyccommand,
  yycqueue
};

AMIPacket *amiparse_pack (const char *pack_str)
{
  AMIPacket *pack = amipack_init ();
  const char *marker = pack_str;
  const char *cur    = marker;
  const char *ctxmarker;
  int c = yyckey;
  int len = 0;

  const char *tok = marker;
  char *hdr_name;


#line 77 "src/lib/amipack_parse.c"
{
	unsigned char yych;
	unsigned int yyaccept = 0;
	switch (c) {
	case yyckey: goto yyc_key;
	case yycvalue: goto yyc_value;
	case yyccommand: goto yyc_command;
	}
/* *********************************** */
yyc_command:
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy5;
	case '-':	goto yy7;
	case 'A':
	case 'a':	goto yy8;
	case 'M':
	case 'm':	goto yy9;
	case 'O':
	case 'o':	goto yy10;
	case 'P':
	case 'p':	goto yy11;
	default:	goto yy3;
	}
yy3:
	yyaccept = 0;
	yych = *(marker = ++cur);
	goto yy13;
yy4:
#line 97 "src/lib/amipack_parse.re"
	{
              printf("====== UNKNOWN ERROR =====\n");
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 114 "src/lib/amipack_parse.c"
yy5:
	++cur;
yy6:
#line 154 "src/lib/amipack_parse.re"
	{ goto yyc_command; }
#line 120 "src/lib/amipack_parse.c"
yy7:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case '-':	goto yy62;
	default:	goto yy13;
	}
yy8:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'C':
	case 'c':	goto yy49;
	default:	goto yy13;
	}
yy9:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'E':
	case 'e':	goto yy37;
	default:	goto yy13;
	}
yy10:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'U':
	case 'u':	goto yy29;
	default:	goto yy13;
	}
yy11:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'R':
	case 'r':	goto yy15;
	default:	goto yy13;
	}
yy12:
	++cur;
	yych = *cur;
yy13:
	switch (yych) {
	case '\n':	goto yy14;
	default:	goto yy12;
	}
yy14:
	yych = *++cur;
	goto yy6;
yy15:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy16;
	default:	goto yy13;
	}
yy16:
	yych = *++cur;
	switch (yych) {
	case 'V':
	case 'v':	goto yy17;
	default:	goto yy13;
	}
yy17:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy18;
	default:	goto yy13;
	}
yy18:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy19;
	default:	goto yy13;
	}
yy19:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy20;
	default:	goto yy13;
	}
yy20:
	yych = *++cur;
	switch (yych) {
	case 'G':
	case 'g':	goto yy21;
	default:	goto yy13;
	}
yy21:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy22;
	default:	goto yy13;
	}
yy22:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy23;
	default:	goto yy13;
	}
yy23:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy14;
	case '\r':	goto yy25;
	default:	goto yy23;
	}
yy25:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy27;
	case '\r':	goto yy25;
	default:	goto yy23;
	}
yy27:
	++cur;
#line 150 "src/lib/amipack_parse.re"
	{ CMD_HEADER(10, "Privilege"); }
#line 246 "src/lib/amipack_parse.c"
yy29:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy30;
	default:	goto yy13;
	}
yy30:
	yych = *++cur;
	switch (yych) {
	case 'P':
	case 'p':	goto yy31;
	default:	goto yy13;
	}
yy31:
	yych = *++cur;
	switch (yych) {
	case 'U':
	case 'u':	goto yy32;
	default:	goto yy13;
	}
yy32:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy33;
	default:	goto yy13;
	}
yy33:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy34;
	default:	goto yy13;
	}
yy34:
	yyaccept = 1;
	yych = *(marker = ++cur);
	switch (yych) {
	case ' ':	goto yy36;
	default:	goto yy13;
	}
yy35:
#line 153 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_command; }
#line 291 "src/lib/amipack_parse.c"
yy36:
	yyaccept = 1;
	yych = *(marker = ++cur);
	goto yy13;
yy37:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy38;
	default:	goto yy13;
	}
yy38:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy39;
	default:	goto yy13;
	}
yy39:
	yych = *++cur;
	switch (yych) {
	case 'A':
	case 'a':	goto yy40;
	default:	goto yy13;
	}
yy40:
	yych = *++cur;
	switch (yych) {
	case 'G':
	case 'g':	goto yy41;
	default:	goto yy13;
	}
yy41:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy42;
	default:	goto yy13;
	}
yy42:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy43;
	default:	goto yy13;
	}
yy43:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy14;
	case '\r':	goto yy45;
	default:	goto yy43;
	}
yy45:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy47;
	case '\r':	goto yy45;
	default:	goto yy43;
	}
yy47:
	++cur;
#line 152 "src/lib/amipack_parse.re"
	{ CMD_HEADER(8, "Message"); }
#line 357 "src/lib/amipack_parse.c"
yy49:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy50;
	default:	goto yy13;
	}
yy50:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy51;
	default:	goto yy13;
	}
yy51:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy52;
	default:	goto yy13;
	}
yy52:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy53;
	default:	goto yy13;
	}
yy53:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy54;
	default:	goto yy13;
	}
yy54:
	yych = *++cur;
	switch (yych) {
	case 'D':
	case 'd':	goto yy55;
	default:	goto yy13;
	}
yy55:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy56;
	default:	goto yy13;
	}
yy56:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy14;
	case '\r':	goto yy58;
	default:	goto yy56;
	}
yy58:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy60;
	case '\r':	goto yy58;
	default:	goto yy56;
	}
yy60:
	++cur;
#line 151 "src/lib/amipack_parse.re"
	{ CMD_HEADER(9, "ActionID"); }
#line 426 "src/lib/amipack_parse.c"
yy62:
	yych = *++cur;
	switch (yych) {
	case 'E':	goto yy63;
	default:	goto yy13;
	}
yy63:
	yych = *++cur;
	switch (yych) {
	case 'N':	goto yy64;
	default:	goto yy13;
	}
yy64:
	yych = *++cur;
	switch (yych) {
	case 'D':	goto yy65;
	default:	goto yy13;
	}
yy65:
	yych = *++cur;
	switch (yych) {
	case ' ':	goto yy66;
	default:	goto yy13;
	}
yy66:
	yych = *++cur;
	switch (yych) {
	case 'C':	goto yy67;
	default:	goto yy13;
	}
yy67:
	yych = *++cur;
	switch (yych) {
	case 'O':	goto yy68;
	default:	goto yy13;
	}
yy68:
	yych = *++cur;
	switch (yych) {
	case 'M':	goto yy69;
	default:	goto yy13;
	}
yy69:
	yych = *++cur;
	switch (yych) {
	case 'M':	goto yy70;
	default:	goto yy13;
	}
yy70:
	yych = *++cur;
	switch (yych) {
	case 'A':	goto yy71;
	default:	goto yy13;
	}
yy71:
	yych = *++cur;
	switch (yych) {
	case 'N':	goto yy72;
	default:	goto yy13;
	}
yy72:
	yych = *++cur;
	switch (yych) {
	case 'D':	goto yy73;
	default:	goto yy13;
	}
yy73:
	yych = *++cur;
	switch (yych) {
	case '-':	goto yy74;
	default:	goto yy13;
	}
yy74:
	yych = *++cur;
	switch (yych) {
	case '-':	goto yy75;
	default:	goto yy13;
	}
yy75:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy76;
	default:	goto yy13;
	}
yy76:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy77;
	default:	goto yy12;
	}
yy77:
	yyaccept = 2;
	yych = *(marker = ++cur);
	switch (yych) {
	case '\r':	goto yy78;
	default:	goto yy6;
	}
yy78:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy80;
	default:	goto yy79;
	}
yy79:
	cur = marker;
	switch (yyaccept) {
	case 0: 	goto yy4;
	case 1: 	goto yy35;
	default:	goto yy6;
	}
yy80:
	++cur;
#line 155 "src/lib/amipack_parse.re"
	{
              len = cur - tok - 19; // output minus command end tag
              char *val = strndup(tok, len);
              amipack_append (pack, strdup("Output"), 6, val, len);
              goto done;
            }
#line 546 "src/lib/amipack_parse.c"
/* *********************************** */
yyc_key:
	yych = *cur;
	switch (yych) {
	case '\r':	goto yy86;
	case ' ':	goto yy87;
	case ':':	goto yy89;
	case 'A':
	case 'a':	goto yy91;
	case 'E':
	case 'e':	goto yy92;
	case 'R':
	case 'r':	goto yy93;
	default:	goto yy84;
	}
yy84:
	++cur;
	yych = *cur;
	goto yy95;
yy85:
#line 136 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              hdr_name = strndup(tok, len);
              goto yyc_key;
            }
#line 573 "src/lib/amipack_parse.c"
yy86:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy137;
	default:	goto yy95;
	}
yy87:
	++cur;
#line 97 "src/lib/amipack_parse.re"
	{
              printf("====== UNKNOWN ERROR =====\n");
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 589 "src/lib/amipack_parse.c"
yy89:
	yyaccept = 0;
	yych = *(marker = ++cur);
	goto yy129;
yy90:
#line 105 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_value; }
#line 597 "src/lib/amipack_parse.c"
yy91:
	yych = *++cur;
	switch (yych) {
	case 'C':
	case 'c':	goto yy122;
	default:	goto yy95;
	}
yy92:
	yych = *++cur;
	switch (yych) {
	case 'V':
	case 'v':	goto yy117;
	default:	goto yy95;
	}
yy93:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy96;
	default:	goto yy95;
	}
yy94:
	++cur;
	yych = *cur;
yy95:
	switch (yych) {
	case ' ':
	case ':':	goto yy85;
	default:	goto yy94;
	}
yy96:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy97;
	default:	goto yy95;
	}
yy97:
	yych = *++cur;
	switch (yych) {
	case 'P':
	case 'p':	goto yy98;
	default:	goto yy95;
	}
yy98:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy99;
	default:	goto yy95;
	}
yy99:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy100;
	default:	goto yy95;
	}
yy100:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy101;
	default:	goto yy95;
	}
yy101:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy102;
	default:	goto yy95;
	}
yy102:
	yyaccept = 1;
	yych = *(marker = ++cur);
	switch (yych) {
	case ' ':	goto yy103;
	case ':':	goto yy104;
	default:	goto yy94;
	}
yy103:
#line 123 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_RESPONSE);
              SET_HEADER("Response");
            }
#line 684 "src/lib/amipack_parse.c"
yy104:
	++cur;
	yych = *cur;
	switch (yych) {
	case ' ':	goto yy104;
	case 'F':
	case 'f':	goto yy107;
	default:	goto yy106;
	}
yy106:
	cur = marker;
	if (yyaccept == 0) {
		goto yy90;
	} else {
		goto yy103;
	}
yy107:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy108;
	default:	goto yy106;
	}
yy108:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy109;
	default:	goto yy106;
	}
yy109:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy110;
	default:	goto yy106;
	}
yy110:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy111;
	default:	goto yy106;
	}
yy111:
	yych = *++cur;
	switch (yych) {
	case 'W':
	case 'w':	goto yy112;
	default:	goto yy106;
	}
yy112:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy113;
	default:	goto yy106;
	}
yy113:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy114;
	default:	goto yy106;
	}
yy114:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy115;
	default:	goto yy106;
	}
yy115:
	++cur;
#line 116 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              tok = cur;
              amipack_type (pack, AMI_RESPONSE);
              amipack_append(pack, strdup("Response"), 8, strdup("Follows"), 7);
              goto yyc_command;
            }
#line 765 "src/lib/amipack_parse.c"
yy117:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy118;
	default:	goto yy95;
	}
yy118:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy119;
	default:	goto yy95;
	}
yy119:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy120;
	default:	goto yy95;
	}
yy120:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy121;
	default:	goto yy94;
	}
yy121:
#line 131 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_EVENT);
              SET_HEADER("Event");
            }
#line 800 "src/lib/amipack_parse.c"
yy122:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy123;
	default:	goto yy95;
	}
yy123:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy124;
	default:	goto yy95;
	}
yy124:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy125;
	default:	goto yy95;
	}
yy125:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy126;
	default:	goto yy95;
	}
yy126:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy127;
	default:	goto yy94;
	}
yy127:
#line 127 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_ACTION);
              SET_HEADER("Action");
            }
#line 842 "src/lib/amipack_parse.c"
yy128:
	yyaccept = 0;
	marker = ++cur;
	yych = *cur;
yy129:
	switch (yych) {
	case '\r':	goto yy130;
	case ' ':	goto yy128;
	default:	goto yy90;
	}
yy130:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy131;
	default:	goto yy106;
	}
yy131:
	yych = *++cur;
	ctxmarker = cur;
	switch (yych) {
	case '\r':	goto yy132;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy133;
	default:	goto yy106;
	}
yy132:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy135;
	default:	goto yy106;
	}
yy133:
	++cur;
	cur = ctxmarker;
#line 106 "src/lib/amipack_parse.re"
	{
              tok = cur;
              amipack_append(pack, hdr_name, strlen(hdr_name), strdup(""), 0);
              goto yyc_key;
            }
#line 933 "src/lib/amipack_parse.c"
yy135:
	++cur;
#line 111 "src/lib/amipack_parse.re"
	{
              tok = cur;
              amipack_append(pack, hdr_name, strlen(hdr_name), strdup(""), 0);
              goto done;
            }
#line 942 "src/lib/amipack_parse.c"
yy137:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy138;
	default:	goto yy95;
	}
yy138:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy139;
	default:	goto yy95;
	}
yy139:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy140;
	default:	goto yy94;
	}
yy140:
#line 103 "src/lib/amipack_parse.re"
	{ goto done; }
#line 965 "src/lib/amipack_parse.c"
/* *********************************** */
yyc_value:
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy145;
	case '\r':	goto yy147;
	default:	goto yy144;
	}
yy143:
#line 143 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              char *val = strndup(tok, len);
              amipack_append(pack, hdr_name, strlen(hdr_name), val, len);
              goto yyc_value;
            }
#line 982 "src/lib/amipack_parse.c"
yy144:
	yych = *++cur;
	goto yy156;
yy145:
	++cur;
yy146:
#line 97 "src/lib/amipack_parse.re"
	{
              printf("====== UNKNOWN ERROR =====\n");
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 996 "src/lib/amipack_parse.c"
yy147:
	yych = *(marker = ++cur);
	switch (yych) {
	case '\n':	goto yy148;
	default:	goto yy146;
	}
yy148:
	yych = *++cur;
	ctxmarker = cur;
	switch (yych) {
	case '\r':	goto yy150;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy151;
	default:	goto yy149;
	}
yy149:
	cur = marker;
	goto yy146;
yy150:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy153;
	default:	goto yy149;
	}
yy151:
	++cur;
	cur = ctxmarker;
#line 142 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_key; }
#line 1076 "src/lib/amipack_parse.c"
yy153:
	++cur;
#line 103 "src/lib/amipack_parse.re"
	{ goto done; }
#line 1081 "src/lib/amipack_parse.c"
yy155:
	++cur;
	yych = *cur;
yy156:
	switch (yych) {
	case '\n':
	case '\r':	goto yy143;
	default:	goto yy155;
	}
}
#line 161 "src/lib/amipack_parse.re"


done:
  return pack;
}
