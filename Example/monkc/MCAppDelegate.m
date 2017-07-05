//
//  MCAppDelegate.m
//  monkc
//
//  Created by Sun YuLi on 01/14/2017.
//  Copyright (c) 2017 Sun YuLi. All rights reserved.
//

#import "MCAppDelegate.h"

#import <monkc/MCSort.h>
#import <monkc/monkc.h>
#import <monkc/MCString.h>

@implementation MCAppDelegate

+(NSString*) compressString:(NSString*)string
{
    const char* cstring = [string cStringUsingEncoding:NSUTF8StringEncoding];
    //Monk-C debut!
    MCString* compressed = ff(MCString_newWithCString(cstring), copyCompressedString, 0);
    
    NSString* result = [NSString stringWithUTF8String:compressed->buff];
    
    release(compressed);
    //Monk-C end
    return result;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    return YES;
}

@end
