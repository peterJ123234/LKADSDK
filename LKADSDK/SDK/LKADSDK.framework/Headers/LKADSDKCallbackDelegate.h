//
//  LKADSDKCallbackDelegate.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/8/5.
//  Copyright © 2019 兵伍. All rights reserved.
//
#import "LKADSDKProtocols.h"

#ifndef LKADSDKCallbackDelegate_h
#define LKADSDKCallbackDelegate_h

// 资讯详情回调事件
typedef NS_ENUM(NSInteger, LKADSDKNewsDetailCallbackEvent) {
    LKADSDKNewsDetailCallbackEventLoadSuccess,          // 加载成功
    LKADSDKNewsDetailCallbackEventLoadFaild,            // 加载失败
};

// 激励视频广告回调事件
typedef NS_ENUM(NSInteger, LKADSDKRewardVideoCallbackEvent) {
    LKADSDKRewardVideoCallbackEventAdLoadSuccess,       // 加载成功
    LKADSDKRewardVideoCallbackEventAdLoadError,         // 加载失败
    LKADSDKRewardVideoCallbackEventAdWillVisible,       // 即将展现
    LKADSDKRewardVideoCallbackEventAdDidClick,          // 点击广告
    LKADSDKRewardVideoCallbackEventAdPlayFinish,        // 播放结束
    LKADSDKRewardVideoCallbackEventAdPlayError,         // 播放出错
    LKADSDKRewardVideoCallbackEventAdDidClose,          // 点击关闭
    LKADSDKRewardVideoCallbackEventAdRewardSuccess,     // 奖励成功
};

// 开屏广告回调事件
typedef NS_ENUM(NSInteger, LKADSDKSplashAdCallbackEvent) {
    LKADSDKSplashAdCallbackEventNoAd,               // 没有广告
    LKADSDKSplashAdCallbackEventAdLoadSuccess,      // 加载成功
    LKADSDKSplashAdCallbackEventAdLoadError,        // 加载出错
    LKADSDKSplashAdCallbackEventAdWillVisible,      // 即将展现
    LKADSDKSplashAdCallbackEventAdDidClick,         // 点击广告
    LKADSDKSplashAdCallbackEventAdDidClose,         // 已经关闭
};

// Banner广告回调事件
typedef NS_ENUM(NSInteger, LKADSDKBannerAdCallbackEvent) {
    LKADSDKBannerAdCallbackEventAdLoadSuccess,      // 加载成功
    LKADSDKBannerAdCallbackEventAdLoadError,        // 加载出错
    LKADSDKBannerAdCallbackEventAdWillVisible,      // 即将展现
    LKADSDKBannerAdCallbackEventAdDidClick,         // 点击广告
    LKADSDKBannerAdCallbackEventAdDidClose,         // 点击关闭
};

// banner广告尺寸
typedef NS_ENUM(NSInteger, LKADBannerAdRatio) {
    LKADBannerAdRatio_640x100,
    LKADBannerAdRatio_600x150,
    LKADBannerAdRatio_600x300,
    LKADBannerAdRatio_600x400
};

// 插屏广告回调事件
typedef NS_ENUM(NSInteger, LKADSDKInterstitialAdCallbackEvent) {
    LKADSDKInterstitialAdCallbackEventAdLoadSuccess,      // 加载成功
    LKADSDKInterstitialAdCallbackEventAdLoadError,        // 加载出错
    LKADSDKInterstitialAdCallbackEventAdWillVisible,      // 即将展现
    LKADSDKInterstitialAdCallbackEventAdDidClick,         // 点击广告
    LKADSDKInterstitialAdCallbackEventAdDidClose,         // 点击关闭
};

// 插屏广告尺寸
typedef NS_ENUM(NSInteger, LKADInterstitialAdSize) {
    LKADInterstitialAdSize_random,
    LKADInterstitialAdSize_small,
    LKADInterstitialAdSize_middle,
    LKADInterstitialAdSize_big,
};

@protocol LKADSDKCallbackDelegate <NSObject>
@optional

#pragma mark - 资讯详情回调
/**
* SDK 资讯详情打开成功
* @param countDownView 倒计时视图实例
* @param info 包含 url、type
*
*/
- (void)lk_adSDKNewsDetailDidLoadSuccessWithInfo:(NSDictionary *)info countDownView:(UIView<LKADCountDownViewProtocol> *)countDownView;

/**
* SDK 资讯详情关闭
* @param info 包含 url、type
*
*/
- (void)lk_adSDKNewsDetailDidCloseWithInfo:(NSDictionary *)info;

/**
* SDK 资讯详情倒计时结束
* @param countDownView 倒计时视图实例
* @param info 包含 url、type
*
*/
- (void)lk_adSDKNewsDetailDidCountDownEndWithInfo:(NSDictionary *)info countDownView:(UIView<LKADCountDownViewProtocol> *)countDownView;

/**
* SDK 资讯详情点击倒计时
* @param countDownView 倒计时视图实例
*
*/
- (void)lk_adSDKNewsDetailCountDownViewDidClick:(UIView<LKADCountDownViewProtocol> *)countDownView;

#pragma mark - 激励视频广告回调
/**
 * SDK 激励视频广告回调接口
 * @param event LKADSDKRewardVideoCallbackEvent枚举类型
 * @param error 错误信息
 * @param info  包含 id、type
 *
 */
- (void)lk_adSDKRewardVideoCallbackWithEvent:(LKADSDKRewardVideoCallbackEvent)event error:(NSError *)error andInfo:(NSDictionary *)info;

#pragma mark - 开屏广告回调
/**
* SDK 开屏广告回调接口
* @param event LKADSDKSplashAdCallbackEvent枚举类型
* @param error 错误信息
* @param info  包含 id、type
*
*/
- (void)lk_adSDKSplashAdCallbackWithEvent:(LKADSDKSplashAdCallbackEvent)event error:(NSError *)error andInfo:(NSDictionary *)info;
@end

#pragma mark- 横幅广告回调

@class LKADBannerAdView;
@protocol LKADSDKBannerAdCallbackDelegate <NSObject>
@optional
/**
* SDK 横幅广告回调接口
* @param event LKADSDKBannerAdCallbackEvent枚举类型
* @param error 错误信息
* @param info  包含 id、type
*
*/
- (void)lk_adSDKBannerAdView:(LKADBannerAdView *)adView callbackWithEvent:(LKADSDKBannerAdCallbackEvent)event error:(NSError *)error andInfo:(NSDictionary *)info;
@end

#pragma mark - 插屏广告回调

@protocol LKADSDKInterstitialAdCallbackDelegate <NSObject>
@optional
/**
* SDK 插屏广告回调接口
* @param event LKADSDKInterstitialAdCallbackEvent枚举类型
* @param error 错误信息
* @param info  包含 id、type
*
*/
- (void)lk_adSDKInterstitialAdCallbackWithEvent:(LKADSDKInterstitialAdCallbackEvent)event error:(NSError *)error andInfo:(NSDictionary *)info;
@end

#pragma mark - 原生模板广告回调

@protocol LKADNativeExpressAdDelegete <NSObject>

@required
/**
 * 拉取原生模板广告成功/失败
 */
- (void)lk_adSDKNativeExpressAdFinishLoad:(NSArray<id<LKADNativeExpressAdProtocol>> *)ads error:(NSError *)error;

@optional
/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 */
- (void)lk_adSDKNativeExpressAdViewRenderSuccess:(id<LKADNativeExpressAdProtocol>)ad;

/**
 * 原生模板广告渲染失败
 */
- (void)lk_adSDKNativeExpressAdViewRenderFail:(id<LKADNativeExpressAdProtocol>)ad;

/**
 * 原生模板广告曝光回调
 */
- (void)lk_adSDKNativeExpressAdViewWillShow:(id<LKADNativeExpressAdProtocol>)ad;

/**
 * 原生模板广告点击回调
 */
- (void)lk_adSDKNativeExpressAdViewClicked:(id<LKADNativeExpressAdProtocol>)ad;

/**
 * 原生模板广告被关闭
 */
- (void)lk_adSDKNativeExpressAdViewClosed:(id<LKADNativeExpressAdProtocol>)ad reason:(NSString *)reason;
@end

#endif /* LKADSDKCallbackDelegate_h */
