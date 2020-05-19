//
//  LKADSDKProtocols.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/11/11.
//  Copyright © 2019 兵伍. All rights reserved.
//

#ifndef LKADSDKProtocols_h
#define LKADSDKProtocols_h

#pragma mark - 资讯

@protocol LKADCountDownViewDelegate <NSObject>
- (void)countDownViewDidStart:(UIView *)view;
- (void)countDownViewDidTimeout:(UIView *)view;
- (void)countDownViewDidClick:(UIView *)view;
@end

@protocol  LKADCountDownViewProtocol <NSObject>
@property (nonatomic, weak) id<LKADCountDownViewDelegate> delegate;
@property (nonatomic, assign) CGFloat scrollDelay;

- (void)startWithDuration:(NSInteger)duration frame:(CGRect)rect scrollDelay:(CGFloat)delay;
- (void)pause;
- (void)resume;
- (void)showRewardWithInfo:(NSString *)info;
@end

#pragma mark - 原生模板

@protocol LKADNativeExpressAdDelegete;
@protocol LKADNativeExpressAdManagerProtocol <NSObject>
- (void)loadNativeExpressAdWithCount:(NSInteger)count delegate:(id<LKADNativeExpressAdDelegete>)delegate;

@end

@protocol  LKADNativeExpressAdProtocol <NSObject>
@property (nonatomic, weak, readwrite) UIViewController *viewController;
@property (nonatomic, strong, readonly) NSString *adId;
@property (nonatomic, strong, readonly) UIView *adView;
@property (nonatomic, strong, readonly) NSNumber *adHeight;
- (void)render;
@end


#endif /* LKADSDKProtocols_h */
