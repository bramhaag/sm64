#ifndef _AUDIO_LOAD_H
#define _AUDIO_LOAD_H

#include "internal.h"

#define AUDIO_FRAME_DMA_QUEUE_SIZE 0x40

#define PRELOAD_BANKS 2
#define PRELOAD_SEQUENCE 1

#define IS_SEQUENCE_CHANNEL_VALID(ptr) ((u32)(ptr) != (u32)&gSequenceChannelNone)

extern struct Note *gNotes;

// Music in SM64 is played using 3 players:
// gSequencePlayers[0] is level background music
// gSequencePlayers[1] is misc music, like the puzzle jingle
// gSequencePlayers[2] is sound
extern struct SequencePlayer gSequencePlayers[SEQUENCE_PLAYERS];

extern struct SequenceChannel gSequenceChannels[32];

#ifdef VERSION_JP
extern struct SequenceChannelLayer D_802245D8[48];
#else
extern struct SequenceChannelLayer D_802245D8[52];
#endif

extern struct SequenceChannel gSequenceChannelNone;

extern struct AudioListItem gLayerFreeList;
extern struct NotePool gNoteFreeLists;

extern OSMesgQueue gCurrAudioFrameDmaQueue;
extern u32 gSampleDmaNumListItems;
extern ALSeqFile *gAlTbl;
extern u8 *gAlBankSets;

void audio_dma_partial_copy_async(u32 *devAddr, u8 **vAddr, s32 *remaining, OSMesgQueue *queue, OSIoMesg *mesg);
void decrease_sample_dma_ttls(void);
void *dma_sample_data(u8 *arg0, u32 arg1, s32 arg2, u8 *arg3);
void func_8031758C(s32 arg0);
void func_8031784C(struct AudioBank *arg0, u8 *offset, u32 arg2, u32 arg3);
void preload_sequence(u32 seqId, u8 preloadMask);
void load_sequence(u32 player, u32 seqId, s32 loadAsync);

#endif /* _AUDIO_LOAD_H */
