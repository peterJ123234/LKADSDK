//
//  LKADExpressDrawVideoAd.h
//  LKADSDK
//
//  Created by 兵伍 on 2020/4/7.
//  Copyright © 2020 兵伍. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LKADPlayerPlayState) {
    LKADPlayerStateFailed    = 0,
    LKADPlayerStateBuffering = 1,
    LKADPlayerStatePlaying   = 2,
    LKADPlayerStateStopped   = 3,
    LKADPlayerStatePause     = 4,
    LKADPlayerStateDefalt    = 5
};

@class LKADExpressDrawVideoAd;
@protocol LKADExpressDrawVideoAdDelegate <NSObject>

// 加载成功
- (void)drawVideoAdLoadSuccess:(NSArray<LKADExpressDrawVideoAd *> *)ads;
// 加载失败
- (void)drawVideoAdLoadFail:(NSError *)error;

// 广告即将展现
- (void)drawVideoAdViewWillShow:(NSString *)adId;
// 广告点击
- (void)drawVideoAdViewDidClick:(NSString *)adId;

// 视频播放状态改变
- (void)drawVideoAdView:(NSString *)adId stateDidChanged:(LKADPlayerPlayState)playerState;
// 视频播放结束
- (void)drawVideoAdPlayerDidPlayFinish:(NSString *)adId error:(NSError *)error;

@end

@interface LKADExpressDrawVideoAd : NSObject
@property (nonatomic, strong) UIView *adView;
- (void)render;
- (void)unbind;
@end


