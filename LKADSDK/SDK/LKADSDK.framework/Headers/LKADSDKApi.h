//
//  LKADSDKApi.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/3/15.
//  Copyright © 2019 兵伍. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LKADConfigModel.h"
#import "LKADSDKCallbackDelegate.h"
#import "LKADBannerAdView.h"
#import "LKADExpressDrawVideoAd.h"


@interface LKADSDKApi : NSObject
/**当前：2.4.3(1)
 * @return SDK 版本，如，1.0.0(1)
 */
+ (NSString *)sdkVersion;

/**
 * SDK 初始化接口
 * @param config 配置类对象
 * @return 是否初始化成功，1：成功；0：失败；
 */
+ (BOOL)setupWithConfig:(LKADConfigModel *)config;

/**
 * 获取配置类对象
 * @return 配置类LKADConfigModel实例
 */
+ (LKADConfigModel *)getConfig;

/**
 * 设置SDK回调接口代理
 * @param delegate 代理对象
 */
+ (void)setCallbackDelegate:(id<LKADSDKCallbackDelegate>)delegate;

#pragma mark - 资讯

/**
 * 返回多频道的ViewController
 * @param params 非下级页传nil，下级页可传入@{@"title": @"资讯"}设置导航标题
 * @return 多频道的ViewController实例
 */
+ (UIViewController *)multiTabFeedListWithParams:(NSDictionary *)params;

/**
 * 返回单频道的ViewController
 * @param channel 频道名称，如：推荐，热点，科技。。。（多频道的ViewController中的channel）
 * @return 单频道的ViewController实例
 */
+ (UIViewController *)singleTabFeedListWithChannel:(NSString *)channel;

#pragma mark - 激励视频

/**
 * 获取激励视频的ViewController
 * @param fromVC 广告展示基于的viewController
 * @param timeout 请求超时时间
 * @param completion 请求完成的block，例如可以在请求前显示loading，block里移除loading
 */

+ (void)showRewardVideoFromViewController:(UIViewController *)fromVC timeout:(CGFloat)timeout completion:(void (^) (NSError *error))completion;

#pragma mark - 开屏广告

/**
 * 显示开屏广告（不需要自己添加View）
 * 无占位开屏图，无自定义视图，3秒超时
 * @param window App根window
 */
+ (UIView *)splashAdViewFromWindow:(UIWindow *)window;

/**
* 显示开屏广告（不需要自己添加View）
* @param window App根window
* @param placeholder 开屏占位视图
* @param customView 覆盖在开屏广告上的自定义视图
* @param timeout 超时时间（1-10秒）
*/
+ (UIView *)splashAdViewFromWindow:(UIWindow *)window placeHolder:(UIView *)placeholder customView:(UIView *)customView timeout:(CGFloat)timeout;

#pragma mark - 横幅广告

/**
 * 获取横幅广告
 * 根据广告内容大小自动适配尺寸
 * @param frame 位置大小，高度会根据宽度和ratio自动计算
 * @param ratio banner宽高比例
 * @param vc 广告展示基于的viewController
 * @param delegate 回调代理
 * @param interval 轮播的间隔 30-120（单位：秒）
 */
+ (LKADBannerAdView *)bannerAdViewWithFrame:(CGRect)frame bannerRadio:(LKADBannerAdRatio)ratio viewController:(UIViewController *)vc delegate:(id<LKADSDKBannerAdCallbackDelegate>)delegate interval:(NSInteger)interval;

/**
* 获取横幅广告
* 不会根据广告内容大小自动适配尺寸，可能会出现上下留白，因为多源的广告尺寸不能完全一致
* @param frame 位置大小，高度会根据宽度和ratio自动计算
* @param ratio banner宽高比例
* @param vc 广告展示基于的viewController
* @param delegate 回调代理
* @param interval 轮播的间隔 30-120（单位：秒）
*/
+ (LKADBannerAdView *)multiSourceBannerAdViewWithFrame:(CGRect)frame bannerRadio:(LKADBannerAdRatio)ratio viewController:(UIViewController *)vc delegate:(id<LKADSDKBannerAdCallbackDelegate>)delegate interval:(NSInteger)interval;

#pragma mark - 插屏广告

/**
* 显示插屏广告
* 随机显示不同大小的插屏广告
* @param vc 广告展示基于的viewController
* @param delegate 回调代理
*/
+ (void)showInterstitialAdWithViewController:(UIViewController *)vc delegate:(id<LKADSDKInterstitialAdCallbackDelegate>)delegate;

#pragma mark - Draw视频广告

/**
* 加载Draw视频广告
* @param vc 广告展示基于的viewController
* @param delegate 回调代理
* @param count 加载个数(以实际返回的为准)
* @param size 视频宽高
* @param cfg 其他配置信息（bottomOffset:按钮距离底部距离）
*/
+ (void)loadVideoAdWithViewController:(UIViewController *)vc delegate:(id<LKADExpressDrawVideoAdDelegate>)delegate adCount:(NSInteger)count adSize:(CGSize)size config:(NSDictionary *)cfg;

/**
 * 释放Draw视频广告资源
 */
+ (void)endDrawVideoAd;
@end


