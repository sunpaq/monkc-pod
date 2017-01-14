//
//  MCViewController.m
//  monkc
//
//  Created by Sun YuLi on 01/14/2017.
//  Copyright (c) 2017 Sun YuLi. All rights reserved.
//

#import "MCViewController.h"
#import "MCAppDelegate.h"

@interface MCViewController ()

@end

@implementation MCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (IBAction)onCompressButtonClicked:(id)sender
{
    if(self.inputText.text.length > 0) {
        self.outputText.text = [MCAppDelegate compressString:self.inputText.text];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
