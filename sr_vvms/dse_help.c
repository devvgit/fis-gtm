/****************************************************************
 *								*
 *	Copyright 2001, 2009 Fidelity Information Services, Inc	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

#include "mdef.h"
#include "gdsroot.h"
#include "gtm_facility.h"
#include "fileinfo.h"
#include "gdsbt.h"
#include "gdsfhead.h"
#include "release_name.h"
#include <ssdef.h>
#include <climsgdef.h>
#include <descrip.h>
#include "util.h"
#include "dse.h"

#define HLP$M_PROMPT 1
#define HELP_LIBRARY "GTM$HELP:DSE"

void dse_help(void)
{

	uint4 flags;
	char buff[256];
	$DESCRIPTOR(line, buff);
	$DESCRIPTOR(libr, HELP_LIBRARY);
	$DESCRIPTOR(ent, "QUERY");

	if (CLI$PRESENT(&ent) != CLI$_PRESENT || CLI$GET_VALUE(&ent,&line) != SS$_NORMAL)
		line.dsc$w_length = 0;
	flags = HLP$M_PROMPT;
	lbr$output_help(lib$put_output,0,&line,&libr,&flags,lib$get_input);
	return;

}

void dse_version(void)
{
	/*
	 * The following assumptions have been made in this function
	 * 1. GTM_RELEASE_NAME is of the form "GTM_PRODUCT VERSION THEREST"
	 *    (Refer file release_name.h)
	 * 2. A single blank separates GTM_PRODUCT and VERSION
	 * 3. If THEREST exists, it is separated from VERSION by atleast
	 *    one blank
	 */
	char gtm_rel_name[] = GTM_RELEASE_NAME;
	char dse_rel_name[SIZEOF(GTM_RELEASE_NAME) - SIZEOF(GTM_PRODUCT)];
	int  dse_rel_name_len;
	char *cptr;

	for (cptr = gtm_rel_name + SIZEOF(GTM_PRODUCT), dse_rel_name_len = 0;
	     *cptr != ' ' && *cptr != '\0';
	     dse_rel_name[dse_rel_name_len++] = *cptr++);
	dse_rel_name[dse_rel_name_len] = '\0';
	util_out_print("!AD", TRUE, dse_rel_name_len, dse_rel_name);
	return;
}
