//
//  LKADBannerAdView.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/9/19.
//  Copyright © 2019 兵伍. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LKADSDKCallbackDelegate.h"

@interface LKADBannerAdView : UIView
@property (nonatomic, weak) id<LKADSDKBannerAdCallbackDelegate> delegate;
- (void)loadAdData;
@end

