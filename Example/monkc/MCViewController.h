//
//  MCViewController.h
//  monkc
//
//  Created by Sun YuLi on 01/14/2017.
//  Copyright (c) 2017 Sun YuLi. All rights reserved.
//

@import UIKit;

@interface MCViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *inputText;
@property (weak, nonatomic) IBOutlet UITextView *outputText;

- (IBAction)onCompressButtonClicked:(id)sender;

@end
