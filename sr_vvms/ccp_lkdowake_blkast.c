/****************************************************************
 *								*
 *	Copyright 2001 Sanchez Computer Associates, Inc.	*
 *								*
 *	This source code contains the intellectual property	*
 *	of its copyright holder(s), and is made available	*
 *	under a license.  If you do not know the terms of	*
 *	the license, please stop and do not read further.	*
 *								*
 ****************************************************************/

#include "mdef.h"
#include "gdsroot.h"
#include "ccp.h"
#include "ccpact.h"

/* blocking ast for lock wake up, request from another machine to do a lock wake up */

void ccp_lkdowake_blkast(db)
ccp_db_header *db;
{
	assert(lib$ast_in_prog());
	db->remote_wakeup = TRUE;
	return;
}
