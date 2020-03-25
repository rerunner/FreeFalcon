#ifndef _SIMDATATOGGLE_H
#define _SIMDATATOGGLE_H

#include "F4vu.h"
#include "mission.h"
#include "FalcMesg.h"

//sfr: checks
#include "InvalidBufferException.h"

#pragma pack (1)

/*
 * Message Type Sim Data Toggle
 */
class FalconSimDataToggle : public FalconEvent
{
		public:
				FalconSimDataToggle(VU_ID entityId, VuTargetEntity *target, VU_BOOL loopback=TRUE);
				FalconSimDataToggle(VU_MSG_TYPE type, VU_ID senderid, VU_ID target);
				~FalconSimDataToggle(void);
				virtual int Size() const { return sizeof(dataBlock) + FalconEvent::Size();};
				int Decode (VU_BYTE **buf, long *rem) {
					long init = *rem;

					FalconEvent::Decode (buf, rem);
					memcpychk(&dataBlock, buf, sizeof (dataBlock), rem);
					return init - *rem;
				};
				int Encode (VU_BYTE **buf)
				{
					int size;

					size = FalconEvent::Encode (buf);
					memcpy (*buf, &dataBlock, sizeof (dataBlock));
					*buf += sizeof (dataBlock);
					size += sizeof (dataBlock);
					return size;
				};
				class DATA_BLOCK
				{
						public:

								VU_ID entityID;
								int flag ;
				} dataBlock;

		protected:
				int Process(uchar autodisp);
};
#pragma pack ()

#endif
