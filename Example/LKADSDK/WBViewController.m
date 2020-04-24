//
//  WBViewController.m
//  LKADSDK
//
//  Created by PeterJames4719 on 04/24/2020.
//  Copyright (c) 2020 PeterJames4719. All rights reserved.
//

#import "WBViewController.h"
#import <LKADSDK/LKADSDK.h>

@interface WBViewController ()

@end

@implementation WBViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [LKADSDKApi setupWithConfig:nil];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
