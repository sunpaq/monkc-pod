#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MCArray.h"
#import "MCArrayList.h"
#import "MCBits.h"
#import "MCBuffer.h"
#import "MCClock.h"
#import "MCContext.h"
#import "MCException.h"
#import "MCGeometry.h"
#import "MCGraph.h"
#import "MCHeap.h"
#import "MCIO.h"
#import "MCJNI.h"
#import "MCLexer.h"
#import "MCLinkedList.h"
#import "MCMap.h"
#import "MCMath.h"
#import "MCProcess.h"
#import "MCSet.h"
#import "MCSocket.h"
#import "MCSort.h"
#import "MCString.h"
#import "MCThread.h"
#import "MCTree.h"
#import "MCUnitTest.h"
#import "monkc.h"
#import "monkc_export.h"

FOUNDATION_EXPORT double monkcVersionNumber;
FOUNDATION_EXPORT const unsigned char monkcVersionString[];

