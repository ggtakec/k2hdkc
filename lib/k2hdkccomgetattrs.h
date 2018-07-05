/*
 * 
 * K2HDKC
 * 
 * Copyright 2016 Yahoo Japan Corporation.
 * 
 * K2HDKC is k2hash based distributed KVS cluster.
 * K2HDKC uses K2HASH, CHMPX, FULLOCK libraries. K2HDKC supports
 * distributed KVS cluster server program and client libraries.
 * 
 * For the full copyright and license information, please view
 * the license file that was distributed with this source code.
 *
 * AUTHOR:   Takeshi Nakatani
 * CREATE:   Wed Jul 20 2016
 * REVISION:
 * 
 */

#ifndef	K2HDKCCOMGETATTRS_H
#define	K2HDKCCOMGETATTRS_H

#include "k2hdkccombase.h"

//---------------------------------------------------------
// K2hdkcComGetAttrs Class
//---------------------------------------------------------
class K2hdkcComGetAttrs : public K2hdkcCommand
{
	using	K2hdkcCommand::SetResponseData;
	using	K2hdkcCommand::CommandSend;
	using	K2hdkcCommand::GetResponseData;

	protected:
		virtual PDKCCOM_ALL MakeResponseOnlyHeadData(dkcres_type_t subcode = DKC_RES_SUBCODE_NOTHING, dkcres_type_t errcode = DKC_RES_ERROR);
		bool SetResponseData(const unsigned char* pAttrs, size_t attrslength);

		virtual void RawDumpComAll(const PDKCCOM_ALL pComAll) const;

	public:
		K2hdkcComGetAttrs(K2HShm* pk2hash = NULL, ChmCntrl* pchmcntrl = NULL, uint64_t comnum = K2hdkcComNumber::INIT_NUMBER, bool without_self = true, bool is_routing_on_server = false, bool is_wait_on_server = false);
		virtual ~K2hdkcComGetAttrs(void);

		virtual bool CommandProcessing(void);

		bool CommandSend(const unsigned char* pkey, size_t keylength);
		bool CommandSend(const unsigned char* pkey, size_t keylength, K2HAttrs** ppAttrsObj, dkcres_type_t* prescode);
		bool GetResponseData(K2HAttrs** ppAttrsObj, dkcres_type_t* prescode) const;
};

#endif	// K2HDKCCOMGETATTRS_H

/*
 * VIM modelines
 *
 * vim:set ts=4 fenc=utf-8:
 */
