//
//  LKADSDKProtocols.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/11/11.
//  Copyright © 2019 兵伍. All rights reserved.
//

#ifndef LKADSDKProtocols_h
#define LKADSDKProtocols_h

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

@protocol  LKADSplashAdViewProtocol <NSObject>
- (void)loadAdData;
@end


#endif /* LKADSDKProtocols_h */
